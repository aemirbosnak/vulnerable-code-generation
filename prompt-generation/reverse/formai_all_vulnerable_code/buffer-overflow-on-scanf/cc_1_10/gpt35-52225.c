//FormAI DATASET v1.0 Category: Table Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to initialize the game board
void initBoard(char board[3][3]){
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            board[i][j] = ' ';
        }
    }
}

// function to print the game board
void printBoard(char board[3][3]){
    int i, j;
    printf("-------------\n");
    for(i=0; i<3; i++){
        printf("|");
        for(j=0; j<3; j++){
            printf(" %c |", board[i][j]);
        }
        printf("\n-------------\n");
    }
}

// function to check if a player has won
int checkWin(char board[3][3], char player){
    int i;
    for(i=0; i<3; i++){
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player){
            return 1;
        }
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player){
            return 1;
        }
    }
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
        return 1;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player){
        return 1;
    }
    return 0;
}

// main function to play the game
int main(){
    char board[3][3];
    char player1 = 'X';
    char player2 = 'O';
    char currentPlayer = player1;
    int row, col, moveCount = 0;

    // initialize random number generator
    srand(time(NULL));

    // initialize game board
    initBoard(board);

    printf("Welcome to Retro Tic Tac Toe!\n");

    while(1){
        printf("Current player is %c\n", currentPlayer);
        printf("Enter row (1-3): ");
        scanf("%d", &row);
        printf("Enter column (1-3): ");
        scanf("%d", &col);

        // make sure move is valid
        if(row<1 || row>3 || col<1 || col>3){
            printf("Invalid move, please try again.\n");
            continue;
        }
        if(board[row-1][col-1] != ' '){
            printf("That spot is already taken, please try again.\n");
            continue;
        }

        // update game board and move count
        board[row-1][col-1] = currentPlayer;
        moveCount++;

        // print updated game board
        printBoard(board);

        // check if current player has won or the game is tied
        if(checkWin(board, currentPlayer)){
            printf("Player %c wins!\n", currentPlayer);
            break;
        }
        if(moveCount == 9){
            printf("It's a tie!\n");
            break;
        }

        // switch to next player
        if(currentPlayer == player1){
            currentPlayer = player2;
        }else{
            currentPlayer = player1;
        }
    }

    return 0;
}