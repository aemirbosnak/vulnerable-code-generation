//FormAI DATASET v1.0 Category: Table Game ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function prototypes
void displayBoard();
void play();
int checkWin();

//Global variables
char board[9]={'1','2','3','4','5','6','7','8','9'};
char player='X';

//Main function
int main(){
    printf("Welcome to Tic Tac Toe Game! \n\n");
    displayBoard();
    play();
    return 0;
}

//Display the game board
void displayBoard(){
    printf("\t\t %c | %c | %c\n", board[0], board[1], board[2]);
    printf("\t\t---|---|---\n");
    printf("\t\t %c | %c | %c\n", board[3], board[4], board[5]);
    printf("\t\t---|---|---\n");
    printf("\t\t %c | %c | %c\n\n", board[6], board[7], board[8]);
}

//Function to play the game
void play(){
    int input, index;
    srand(time(NULL));
    int firstTurn = rand() % 2; //Randomly selecting who will play first

    if(firstTurn == 0){
        printf("Player X will go first.\n");
    }
    else{
        printf("Player O will go first.\n");
        player = 'O'; //Assigning player O as the first player
    }

    while(1){
        printf("Player %c, enter your move: ", player);
        scanf("%d", &input);

        if(input < 1 || input > 9){  //Check if input is valid
            printf("Invalid move. Please enter a number between 1-9.\n");
            continue;
        }

        index = input - 1; //Convert input into array index

        if(board[index] == 'X' || board[index] == 'O'){  //Check if the cell is already occupied
            printf("Cell already occupied. Please select a different cell.\n");
            continue;
        }

        board[index] = player;
        displayBoard();

        if(checkWin()){  //Check if any player has won
            printf("\nCongratulations! Player %c has won the game.\n", player);
            break;
        }
        else if(board[0]!='1'&&board[1]!='2'&&board[2]!='3'&&board[3]!='4'&&board[4]!='5'&&board[5]!='6'&&board[6]!='7'&&board[7]!='8'&&board[8]!='9')
        {  //Check if the game is a tie
            printf("\nGame is a tie.\n");
            break;
        }

        //Switch players after each move
        player = (player == 'X') ? 'O' : 'X';
    }
}

//Function to check if any player has won the game
int checkWin(){
    if(board[0] == board[1] && board[1] == board[2])
        return 1;
    else if(board[3] == board[4] && board[4] == board[5])
        return 1;
    else if(board[6] == board[7] && board[7] == board[8])
        return 1;
    else if(board[0] == board[3] && board[3] == board[6])
        return 1;
    else if(board[1] == board[4] && board[4] == board[7])
        return 1;
    else if(board[2] == board[5] && board[5] == board[8])
        return 1;
    else if(board[0] == board[4] && board[4] == board[8])
        return 1;
    else if(board[2] == board[4] && board[4] == board[6])
        return 1;
    else
        return 0;
}