//
//  main.cpp
//  project 2
//
//  Created by SUBHRA KANUNGO on 08/02/2018.
//  Copyright © 2018 SUBHRA KANUNGO. All rights reserved.
//
/*
    Program2memory.cpp
 
    Program #2: Memory game of guessing which X or O changed.
    Class: CS 141
    Author: Subhra Kanungo
    Lab: Tuesday 5pm
    System:  C++ Mac Xcode
 
    Grading Rubric:
 
    50 Execution points
        5 Displays header info on screen when run
        5 Displays instructions
        5 Output is formatted as shown in sample output
        3 Handles both upper and lower case input
        2 Input of 'x' in first prompt exits program
        5 Input can be adjacent or have spaces between them
       15 Displayed boards all have odd parity in rows and columns
        5 Repeated input of 'r' gives new valid random board each time
        5 Gives appropriate end of program messages
 
    45 Programming Style (Given only if program runs substantially correctly)
        5 Program naming convention is followed
       10 Meaningful identifier names
       10 Comments: Has header.  Comments on each block of code
       10 Appropriate data and control structures (-20 if using arrays or strings)
       10 Code Layout: Appropriate indentation and blank lines
 */
#include <iostream> // For cin and cout
#include <cstdlib>
#include <time.h> // for rand() function
using namespace std;

//Global variable declared to be used in the program.
//these 36 characters declared for each character in the 6x6 matrix
char p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10;
char p11, p12, p13, p14, p15, p16, p17, p18, p19, p20;
char p21, p22, p23, p24, p25, p26, p27, p28, p29, p30;
char p31, p32, p33, p34, p35;

//display character for the 6x6 matrix which are 'O' and 'X'
char X = 'O';
char Y = 'X';


int col_Num; //the colunm number in the grid
char toPerform; // the variable to let the compiler know which function to execute, R,X OR LETTER CHANGE
char changeChar; // the variable representing the position to change the value in the grid
int changedNum; // the variable representing the postition to change the value in the grid

//Function to display the header info
void displayHeaderInfo(){
    cout << "Author:  Subhra Kanungo\n";
    cout << "Class:   CS 141, Spring 2018\n";
    cout << "Lab:     Tuesday 5PM\n";
    cout << "Program: #2, Memory Game\n";
}

//Function to display the instruction of the game
void displayInstructions(){
    cout << "\nWelcome to the memory game!\n";
    cout << "\nLook away from the board and have a helper enter r" << endl
         << "to randomize the board until they have a random board" << endl
         << "that they like.  Then you glance at it and try to"  << endl
         << "imprint it in your mind and look away.  Your helper" << endl
         << "will then select a single piece to be flipped by" << endl
         << "choosing its row and column.  The changed board is then" << endl
         << "displayed. You then must try to guess which one it was." << endl
         << "Enter x to exit the program.\n\n" << endl;
}

//function to check whether the number of 'X's in the rows and columns are odd.
//checks 6 characters at a time for a particular row or column
char oddParity(char x1, char x2, char x3, char x4, char x5, char x6){
    int oddParityCount = 0;//count integer to keep track of the number of x's in the row or column
    
    if(x1 == 'X'){
        oddParityCount++;
    }

    if(x2 == 'X'){
        oddParityCount++;
    }

    if(x3 == 'X'){
        oddParityCount++;
    }

    if(x4 == 'X'){
        oddParityCount++;
    }

    if(x5 == 'X'){
        oddParityCount++;
    }

    if(x6 == 'X'){
        oddParityCount++;
    }
    return oddParityCount++;//returns the integer value back to the function call
}

//Function to set the individual gridvalues to 'X' or 'O' by generating random numbers. If number is even then value set is 'X' and if odd then 'O'
char gridValues(){

    int g = rand() % 2; // Random funciton generates the randomized number from 0-2
    if(( g % 2) == 0){
        return X;
    }
    if((g % 2) == 1){
        return Y;
    }
    return 0;
}

//when the user enters the position to be changed the character in the position is to be checked and replaced with the other.
char checkChar(char p){
    if(p == 'O'){
        return Y;//if character is 'O' change to 'X' and return the value to function call
    }
    if(p == 'X'){
        return X;//if character is 'X' change to 'O' and return the value to function call
    }
    return 0;
}

//fucntion to output the final grid with the changed values.
void finalGrid(){
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "     1 2 3 4 5 6\n";
    cout << "   - - - - - - - -\n";
    cout << " A | " << p0 << " " << p1 << " " << p2 << " " << p3 << " " << p4 << " " << p5 << " " << "| A\n";
    cout << " B | " << p6 << " " << p7 << " " << p8 << " " << p9 << " " << p10 << " " << p11 << " " << "| B\n";
    cout << " C | " << p12 << " " << p13 << " " << p14 << " " << p15 << " " << p16 << " " << p17 << " " << "| C\n";
    cout << " D | " << p18 << " " << p19 << " " << p20 << " " << p21 << " " << p22 << " " << p23 << " " << "| D\n";
    cout << " E | " << p24 << " " << p25 << " " << p26 << " " << p27 << " " << p28 << " " << p29 << " " << "| E\n";
    cout << " F | " << p30 << " " << p31 << " " << p32 << " " << p33 << " " << p34 << " " << p35 << " " << "| F\n";
    cout << "   - - - - - - - -\n";
    cout << "\n What piece do you think it was?"; //asking the user to enter which position might have changed.
    
    //to check whether the number and letter representing the position entered by the user is correct of wrong.
    //accordingly the messages will be outputed.
    cin >> changeChar;
    changeChar = toupper(changeChar);
    cin >> changedNum;
    
    if(changedNum == col_Num && changeChar == toPerform){
        cout <<"\n *** Congratulations, you did it! *** \n" << endl;
    }
    else {
        cout <<"\n Sorry, it was " << toPerform << col_Num << ". Better luck next time.\n" << endl;
    }
    return;
}

//Function is to display the grid with the randomized values in the grid.
void displayGrid(){
    int loopCounter = 1;
    while (loopCounter != 0){
        //calling the function gridvalue to set the 36 characters to either 'X' or 'Y'
        p0 = gridValues();
        p1 = gridValues();
        p2 = gridValues();
        p3 = gridValues();
        p4 = gridValues();
        p5 = gridValues();
        p6 = gridValues();
        p7 = gridValues();
        p8 = gridValues();
        p9 = gridValues();
        p10 = gridValues();
        p11 = gridValues();
        p12 = gridValues();
        p13 = gridValues();
        p14 = gridValues();
        p15 = gridValues();
        p16 = gridValues();
        p17 = gridValues();
        p18 = gridValues();
        p19 = gridValues();
        p20 = gridValues();
        p21 = gridValues();
        p22 = gridValues();
        p23 = gridValues();
        p24 = gridValues();
        p25 = gridValues();
        p26 = gridValues();
        p27 = gridValues();
        p28 = gridValues();
        p29 = gridValues();
        p30 = gridValues();
        p31 = gridValues();
        p32 = gridValues();
        p33 = gridValues();
        p34 = gridValues();
        p35 = gridValues();
        
        //This parity checker is to check the number of 'X's are odd or even.
        int checkParity1 = oddParity(p0, p1, p2, p3, p4, p5);//row1
        if(checkParity1 % 2 == 0){
            continue; // if even then has to return back to the beginning of the loop to get odd numbers of 'X's
        }
        int checkParity2 = oddParity(p6, p7, p8, p9, p10, p11);//row2
        if(checkParity2 % 2 == 0){
            continue;// if even then has to return back to the beginning of the loop to get odd numbers of 'X's
        }
        int checkParity3 = oddParity(p12, p13, p14, p15, p16, p17);//row3
        if(checkParity3 % 2 == 0){
            continue;// if even then has to return back to the beginning of the loop to get odd numbers of 'X's
        }
        int checkParity4 = oddParity(p18, p19, p20, p21, p22, p23);//row4
        if(checkParity4 % 2 == 0){
            continue;// if even then has to return back to the beginning of the loop to get odd numbers of 'X's
        }
        int checkParity5 = oddParity(p24, p25, p26, p27, p28, p29);//row5
        if(checkParity5 % 2 == 0){
            continue;// if even then has to return back to the beginning of the loop to get odd numbers of 'X's
        }
        int checkParity6 = oddParity(p30, p31, p32, p33, p34, p35);//row6
        if(checkParity6 % 2 == 0){
            continue;// if even then has to return back to the beginning of the loop to get odd numbers of 'X's
        }
        int checkParity7 = oddParity(p0, p6, p12, p18, p24, p30);//col1
        if(checkParity7 % 2 == 0){
            continue;// if even then has to return back to the beginning of the loop to get odd numbers of 'X's
        }
        int checkParity8 = oddParity(p1, p7, p13, p19, p25, p31);//col2
        if(checkParity8 % 2 == 0){
            continue;// if even then has to return back to the beginning of the loop to get odd numbers of 'X's
        }
        int checkParity9 = oddParity(p2, p8, p14, p20, p26, p32);//col3
        if(checkParity9 % 2 == 0){
            continue;// if even then has to return back to the beginning of the loop to get odd numbers of 'X's
        }
        int checkParity10 = oddParity(p3, p9, p15, p21, p27, p33);//col4
        if(checkParity10 % 2 == 0){
            continue;// if even then has to return back to the beginning of the loop to get odd numbers of 'X's
        }
        int checkParity11 = oddParity(p4, p10, p16, p22, p28, p34);//col5
        if(checkParity11 % 2 == 0){
            continue;// if even then has to return back to the beginning of the loop to get odd numbers of 'X's
        }
        int checkParity12 = oddParity(p5, p11, p17, p23, p29, p35);//col6
        if(checkParity12 % 2 == 0){
            continue;// if even then has to return back to the beginning of the loop to get odd numbers of 'X's
        }
        break;
    }
    
    //once checked the odd parity is satisfied the grid is dispayed with its randomized values.
    cout << "     1 2 3 4 5 6\n";
    cout << "   - - - - - - - -\n";
    cout << " A | " << p0 << " " << p1 << " " << p2 << " " << p3 << " " << p4 << " " << p5 << " " << "| A\n";
    cout << " B | " << p6 << " " << p7 << " " << p8 << " " << p9 << " " << p10 << " " << p11 << " " << "| B\n";
    cout << " C | " << p12 << " " << p13 << " " << p14 << " " << p15 << " " << p16 << " " << p17 << " " << "| C\n";
    cout << " D | " << p18 << " " << p19 << " " << p20 << " " << p21 << " " << p22 << " " << p23 << " " << "| D\n";
    cout << " E | " << p24 << " " << p25 << " " << p26 << " " << p27 << " " << p28 << " " << p29 << " " << "| E\n";
    cout << " F | " << p30 << " " << p31 << " " << p32 << " " << p33 << " " << p34 << " " << p35 << " " << "| F\n";
    cout << "   - - - - - - - -\n";
    cout << "\nEnter r to randomize to board, or row and column to change a value ->" << endl; // output message to ask user to execute one of the funcitons. 
    
    
}

int main() {
    
    srand((unsigned)time(0)); // function is to set different sets of number for the randomization process.
    
    displayHeaderInfo();//function call to display header info
    displayInstructions();//funciton call to display instructions
    displayGrid();//function call to display randomized grid with odd parity
    
    int loopCount = 1;
    while(loopCount != 0){
        cin >> toPerform;
        while (isspace(toPerform)){
            //as long as there is a 'whitespace' in the input by the user, this will ask u to input a character again which is valid
            cin >> toPerform;
        }
        toPerform = toupper(toPerform);//converts to uppercase character
        
        if(toPerform == 'R'){//to execute the randomized function to display the grid
            displayGrid();
        }
        if(toPerform == 'X'){// to exit the game.
            break;
        }
        
        //To execute the changed position value by the user. to change the grid value in the position declared by the user
        if(toPerform != 'X' && toPerform != 'R'){
            cin >> col_Num;
            while (isspace(toPerform)){
                //as long as there is a 'whitespace' in the input by the user, this will ask u to input a character again which is valid
                cin >> col_Num;
            }
            //checks all the grid position value according row adn col number.
            //if character is found then function call to change the character.
            //then funciton call to display the final grid with the changed value
            if(toPerform == 'A' && col_Num == 1){
                p0 = checkChar(p0);
                finalGrid();
            }
            else if(toPerform == 'A' && col_Num == 2){
                p1 = checkChar(p1);
                finalGrid();
            }
            else if(toPerform == 'A' && col_Num == 3){
                p2 = checkChar(p2);
                finalGrid();
            }
            else if(toPerform == 'A' && col_Num == 4){
                p3 = checkChar(p3);
                finalGrid();
            }
            else if(toPerform == 'A' && col_Num == 5){
                p4 = checkChar(p4);
                finalGrid();
            }
            else if(toPerform == 'A' && col_Num == 6){
                p5 = checkChar(p5);
                finalGrid();
            }
            else if(toPerform == 'B' && col_Num == 1){
                p6 = checkChar(p6);
                finalGrid();
            }
            else if(toPerform == 'B' && col_Num == 2){
                p7 = checkChar(p7);
                finalGrid();
            }
            else if(toPerform == 'B' && col_Num == 3){
                p8 = checkChar(p8);
                finalGrid();
            }
            else if(toPerform == 'B' && col_Num == 4){
                p9 = checkChar(p9);
                finalGrid();
            }
            else if(toPerform == 'B' && col_Num == 5){
                p10 = checkChar(p10);
                finalGrid();
            }
            else if(toPerform == 'B' && col_Num == 6){
                p11 = checkChar(p11);
                finalGrid();
            }
            else if(toPerform == 'C' && col_Num == 1){
                p12 = checkChar(p12);
                finalGrid();
            }
            else if(toPerform == 'C' && col_Num == 2){
                p13 = checkChar(p13);
                finalGrid();
            }
            else if(toPerform == 'C' && col_Num == 3){
                p14 = checkChar(p14);
                finalGrid();
            }
            else if(toPerform == 'C' && col_Num == 4){
                p15 = checkChar(p15);
                finalGrid();
            }
            else if(toPerform == 'C' && col_Num == 5){
                p16 = checkChar(p16);
                finalGrid();
            }
            else if(toPerform == 'C' && col_Num == 6){
                p17 = checkChar(p17);
                finalGrid();
            }
            else if(toPerform == 'D' && col_Num == 1){
                p18 = checkChar(p18);
                finalGrid();
            }
            else if(toPerform == 'D' && col_Num == 2){
                p19 = checkChar(p19);
                finalGrid();
            }
            else if(toPerform == 'D' && col_Num == 3){
                p20 = checkChar(p20);
                finalGrid();
            }
            else if(toPerform == 'D' && col_Num == 4){
                p21 = checkChar(p21);
                finalGrid();
            }
            else if(toPerform == 'D' && col_Num == 5){
                p22 = checkChar(p22);
                finalGrid();
            }
            else if(toPerform == 'D' && col_Num == 6){
                p23 = checkChar(p23);
                finalGrid();
            }
            else if(toPerform == 'E' && col_Num == 1){
                p24 = checkChar(p24);
                finalGrid();
            }
            else if(toPerform == 'E' && col_Num == 2){
                p25 = checkChar(p25);
                finalGrid();
            }
            else if(toPerform == 'E' && col_Num == 3){
                p26 = checkChar(p26);
                finalGrid();
            }
            else if(toPerform == 'E' && col_Num == 4){
                p27 = checkChar(p27);
                finalGrid();
            }
            else if(toPerform == 'E' && col_Num == 5){
                p28 = checkChar(p28);
                finalGrid();
            }
            else if(toPerform == 'E' && col_Num == 6){
                p29 = checkChar(p29);
                finalGrid();
            }
            else if(toPerform == 'F' && col_Num == 1){
                p30 = checkChar(p30);
                finalGrid();
            }
            else if(toPerform == 'F' && col_Num == 2){
                p31 = checkChar(p31);
                finalGrid();
            }
            else if(toPerform == 'F' && col_Num == 3){
                p32 = checkChar(p32);
                finalGrid();
            }
            else if(toPerform == 'F' && col_Num == 4){
                p33 = checkChar(p33);
                finalGrid();
            }
            else if(toPerform == 'F' && col_Num == 5){
                p34 = checkChar(p34);
                finalGrid();
            }
            else if(toPerform == 'F' && col_Num == 6){
                p35 = checkChar(p35);
                finalGrid();
            }
            else {
                break;
            }
            break;
        }
        
    }
  
    //ending message to finish playing the game
    cout << "Thank you for playing.  Exiting..." << endl;
    return 0;
}//end main
