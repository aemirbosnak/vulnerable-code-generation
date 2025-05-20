//FormAI DATASET v1.0 Category: Table Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLUMNS 3

int main(void) {
    char board[ROWS][COLUMNS];
    char playerChar = 'X', computerChar = 'O';
    int row, column, currentPlayer = 0;
    int winner = 0, emptySpaces = ROWS * COLUMNS;
    srand(time(NULL));

    // Initialize the board
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            board[i][j] = ' ';
        }
    }

    // Print the initial board
    printf("Welcome to the Tic Tac Toe game!\n");
    printf("Here is the initial board:\n");
    printf("-------------\n");
    for(int i = 0; i < ROWS; i++) {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-------------\n");
    }

    while(winner == 0 && emptySpaces > 0) {
        if(currentPlayer == 0) {
            // Player's turn
            printf("Enter the row and column number (1~3) for your move: ");
            scanf("%d %d", &row, &column);
            row--;
            column--;
            if(board[row][column] == ' ') {
                board[row][column] = playerChar;
                printf("You placed %c at (%d, %d).\n", playerChar, row + 1, column + 1);
                currentPlayer = 1;
                emptySpaces--;
            } else {
                printf("The cell is already occupied. Please try again.\n");
            }
        } else {
            // Computer's turn
            printf("It's computer's turn.\n");
            row = rand() % ROWS;
            column = rand() % COLUMNS;
            if(board[row][column] == ' ') {
                board[row][column] = computerChar;
                printf("Computer placed %c at (%d, %d).\n", computerChar, row + 1, column + 1);
                currentPlayer = 0;
                emptySpaces--;
            }
        }

        // Check for winner
        for(int i = 0; i < ROWS; i++) {
            if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
                winner = currentPlayer == 0 ? 1 : 2;
            }
            if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
                winner = currentPlayer == 0 ? 1 : 2;
            }
        }
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
            winner = currentPlayer == 0 ? 1 : 2;
        }
        if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
            winner = currentPlayer == 0 ? 1 : 2;
        }

        // Print the current board
        printf("-------------\n");
        for(int i = 0; i < ROWS; i++) {
            printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
            printf("-------------\n");
        }
    }

    printf("\n");
    if(winner == 0) {
        printf("The game ended in a tie!\n");
    } else if(winner == 1) {
        printf("Congratulations! You won!\n");
    } else {
        printf("Sorry, you lost. Better luck next time.\n");
    }

    return 0;
}