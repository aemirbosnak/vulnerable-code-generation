//FormAI DATASET v1.0 Category: Table Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function prototypes
void fillBoard(char board[][3]);
void drawBoard(char board[][3]);
int checkWin(char board[][3], char marker);

int main(){

    char board[3][3]; //creating a 2D array for the game board
    char player1 = 'X'; //player 1's marker
    char player2 = 'O'; //player 2's marker
    char currentPlayer = player1; //start with player 1
    int turn = 1; //counter for number of turns taken
    int row, col; //variables for storing user input

    fillBoard(board); //function call to fill the board with blank spaces

    printf("Welcome to Tic Tac Toe!\n\n");

    //game loop
    do{
        printf("Player %c's turn:\n", currentPlayer);
        drawBoard(board);

        //get user input for row and column
        do{
            printf("Enter row (1-3): ");
            scanf("%d", &row);
        }while(row < 1 || row > 3);
        do{
            printf("Enter column (1-3): ");
            scanf("%d", &col);
        }while(col < 1 || col > 3 || board[row-1][col-1] != ' ');

        //place marker on board
        board[row-1][col-1] = currentPlayer;

        if(checkWin(board, currentPlayer)){
            printf("Player %c wins!\n", currentPlayer);
            drawBoard(board);
            return 0; //exit program
        }

        //check for tie game
        if(turn == 9){
            printf("Tie game.\n");
            drawBoard(board);
            return 0; //exit program
        }

        //switch to other player's turn
        if(currentPlayer == player1){
            currentPlayer = player2;
        }
        else{
            currentPlayer = player1;
        }

        turn++; //increment turn counter

    }while(1); //loop forever

    return 0;
}

//fills the board with blank spaces
void fillBoard(char board[][3]){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}

//draws the current state of the board
void drawBoard(char board[][3]){
    printf("\n   1   2   3\n");
    printf("1  %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("  ---+---+---\n");
    printf("2  %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("  ---+---+---\n");
    printf("3  %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

//checks if a player has won the game
int checkWin(char board[][3], char marker){
    //check rows
    int i;
    for(i = 0; i < 3; i++){
        if(board[i][0] == marker && board[i][1] == marker && board[i][2] == marker){
            return 1; //player has won
        }
    }

    //check columns
    int j;
    for(j = 0; j < 3; j++){
        if(board[0][j] == marker && board[1][j] == marker && board[2][j] == marker){
            return 1; //player has won
        }
    }

    //check diagonals
    if(board[0][0] == marker && board[1][1] == marker && board[2][2] == marker){
        return 1; //player has won
    }
    if(board[0][2] == marker && board[1][1] == marker && board[2][0] == marker){
        return 1; //player has won
    }

    return 0; //no winner yet
}