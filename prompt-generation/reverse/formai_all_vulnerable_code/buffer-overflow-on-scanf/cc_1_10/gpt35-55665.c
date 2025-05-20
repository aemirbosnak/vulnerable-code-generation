//FormAI DATASET v1.0 Category: Table Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void printBoard(char board[ROWS][COLS]) {
    printf("\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
        if(i < ROWS-1)
            printf("---|---|---\n");
    }
    printf("\n");
}

int checkWin(char board[ROWS][COLS], char player) {
    //Check columns
    for(int i=0; i<ROWS; i++) {
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1;
    }
    //Check rows
    for(int i=0; i<COLS; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
    }
    //Check diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;
    return 0;
}

void playGame() {
    char board[ROWS][COLS];
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = ' ';
        }
    }
    printBoard(board);
    
    int moves = 0;
    char currentPlayer = 'X';
    while(1) {
        //Get player's move
        int row, col;
        printf("Player %c's turn. Enter row (1-3): ", currentPlayer);
        scanf("%d", &row);
        printf("Enter column (1-3): ");
        scanf("%d", &col);
        if(row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid input. Try again.\n");
            continue;
        }
        if(board[row-1][col-1] != ' ') {
            printf("Cell already occupied. Try again.\n");
            continue;
        }
        board[row-1][col-1] = currentPlayer;
        printBoard(board);
        if(checkWin(board, currentPlayer)) {
            printf("Player %c wins!\n", currentPlayer);
            break;
        }
        moves++;
        if(moves == ROWS*COLS) {
            printf("Game ends in a draw.\n");
            break;
        }
        currentPlayer = currentPlayer == 'X' ? 'O' : 'X';
    }
}

int main() {
    printf("Welcome to Tic-Tac-Toe!\n");
    while(1) {
        playGame();
        char response;
        printf("Do you want to play again? (y/n) ");
        scanf(" %c", &response);
        if(response != 'y')
            break;
    }
    return 0;
}