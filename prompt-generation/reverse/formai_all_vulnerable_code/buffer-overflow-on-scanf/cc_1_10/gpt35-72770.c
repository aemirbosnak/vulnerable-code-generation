//FormAI DATASET v1.0 Category: Table Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// function to print the game board
void printBoard(char board[][3]){
    printf("\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

// checks if the given move is valid or not
bool isValidMove(char board[][3], int row, int col) {
    if(row < 0 || row >= 3 || col < 0 || col >= 3) return false;
    if(board[row][col] != ' ') return false;
    return true;
}

// checks if the game is over or not
bool isGameOver(char board[][3], char player) {
    // check for row win
    for(int i=0; i<3; i++){
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }
    // check for column win
    for(int j=0; j<3; j++){
        if(board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;
    }
    // check for diagonal win
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

// function to get the best move for the computer
void getBestMove(char board[][3], int* row, int* col) {
    // initialize random number generator
    srand(time(NULL));
    do {
        *row = rand() % 3;
        *col = rand() % 3;
    } while(!isValidMove(board, *row, *col));
}

int main(){
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char player1 = 'X';
    char player2 = 'O';
    char currentPlayer = player1;

    printf("\nWelcome to Tic Tac Toe Game!\n");
    printBoard(board);

    while(true){
        int row, col;
        if(currentPlayer == player1){
            printf("Player 1's turn (X): ");
            scanf("%d %d", &row, &col);
            while(!isValidMove(board, row, col)){
                printf("Invalid move! Please choose a valid move: ");
                scanf("%d %d", &row, &col);
            }
            board[row][col] = 'X';
            printBoard(board);
            if(isGameOver(board, 'X')){
                printf("Player 1 (X) wins!\n");
                break;
            }
            currentPlayer = player2;
        }
        else{
            printf("Computer's turn (O):\n");
            getBestMove(board, &row, &col);
            board[row][col] = 'O';
            printBoard(board);
            if(isGameOver(board, 'O')){
                printf("Computer (O) wins!\n");
                break;
            }
            currentPlayer = player1;
        }
    }
    return 0;
}