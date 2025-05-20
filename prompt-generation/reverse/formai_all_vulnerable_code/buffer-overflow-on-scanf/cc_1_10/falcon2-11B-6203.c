//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Define constants
#define MAX_ROW 3
#define MAX_COL 3
#define EMPTY '-'

// Define the board
char board[MAX_ROW][MAX_COL] = {EMPTY, EMPTY, EMPTY,
                                   EMPTY, EMPTY, EMPTY,
                                   EMPTY, EMPTY, EMPTY};

// Function to print the board
void printBoard(void) {
    for(int row = 0; row < MAX_ROW; row++) {
        for(int col = 0; col < MAX_COL; col++) {
            printf("%c", board[row][col]);
        }
        printf("\n");
    }
}

// Function to check for a winning move
int winningMove(char player, int row, int col) {
    // Check rows
    for(int i = 0; i < MAX_ROW; i++) {
        if(board[i][col] == player && board[i][col] == board[i][col + 1] && board[i][col] == board[i][col + 2])
            return 1;
    }
    // Check columns
    for(int i = 0; i < MAX_COL; i++) {
        if(board[row][i] == player && board[row][i] == board[row + 1][i] && board[row][i] == board[row + 2][i])
            return 1;
    }
    // Check diagonals
    if(board[0][0] == player && board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return 1;
    if(board[2][0] == player && board[2][0] == board[1][1] && board[2][0] == board[0][2])
        return 1;
    return 0;
}

// Function to check if the game is over
int gameOver(void) {
    // Check if a player has won
    for(int row = 0; row < MAX_ROW; row++) {
        for(int col = 0; col < MAX_COL; col++) {
            if(board[row][col] == EMPTY)
                return 0;
        }
    }
    return 1;
}

// Function to make a move
void makeMove(int row, int col, char player) {
    if(board[row][col] == EMPTY) {
        board[row][col] = player;
        printBoard();
    } else {
        printf("Invalid move!\n");
    }
}

// Main function
int main(void) {
    char player = 'X';
    int move;

    while(1) {
        printf("Player %c, make a move (0-%d 0-%d): ", player, MAX_ROW, MAX_COL);
        scanf("%d", &move);
        if(move < 0 || move >= MAX_ROW || move < 0 || move >= MAX_COL)
            continue;
        makeMove(move / MAX_COL, move % MAX_COL, player);

        if(gameOver()) {
            if(winningMove(player, move / MAX_COL, move % MAX_COL))
                printf("%c wins!\n", player);
            else
                printf("It's a tie!\n");
            break;
        }

        if(winningMove('O', move / MAX_COL, move % MAX_COL)) {
            player = 'O';
            printf("Player %c, it's your turn.\n", player);
            continue;
        }

        printf("Computer's turn.\n");
    }

    return 0;
}