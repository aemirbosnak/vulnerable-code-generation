//FormAI DATASET v1.0 Category: Table Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // initialize random seed
    srand(time(NULL));

    // set up game board
    int board[3][3] = {{0,0,0},{0,0,0},{0,0,0}};

    // print game instructions
    printf("Welcome to the C Table Game!\n");
    printf("Player 1 will be X and Player 2 will be O.\n");
    printf("To make a move, enter the row and column numbers (1-3).\n");
    printf("Let's start the game!\n\n");

    // game loop
    int player = 1, choice = 0, row = 0, column = 0;
    while (1) {
        printf("Player %d's turn.\n", player);
        printf("Enter row number: ");
        scanf("%d", &row);
        printf("Enter column number: ");
        scanf("%d", &column);

        // check if move is valid
        if (row < 1 || row > 3 || column < 1 || column > 3) {
            printf("Invalid move. Please enter row and column numbers between 1 and 3.\n");
            continue;
        }
        if (board[row-1][column-1] != 0) {
            printf("That spot is already taken. Please choose a different spot.\n");
            continue;
        }

        // make move
        choice = player == 1 ? 1 : -1;
        board[row-1][column-1] = choice;

        // print updated board
        printf("\n  1 2 3\n");
        for (int i = 0; i < 3; i++) {
            printf("%d ", i+1);
            for (int j = 0; j < 3; j++) {
                char mark = board[i][j] == 1 ? 'X' : board[i][j] == -1 ? 'O' : ' ';
                printf("%c", mark);
                if (j < 2) {
                    printf("|");
                }
            }
            printf("\n");
            if (i < 2) {
                printf("  -----\n");
            }
        }
        printf("\n");

        // check for win or tie
        int sum_diag1 = 0, sum_diag2 = 0;
        for (int i = 0; i < 3; i++) {
            int sum_row = 0, sum_col = 0;
            for (int j = 0; j < 3; j++) {
                if (i == j) {
                    sum_diag1 += board[i][j];
                }
                if (i+j == 2) {
                    sum_diag2 += board[i][j];
                }
                sum_row += board[i][j];
                sum_col += board[j][i];
                if (board[i][j] == 0) {
                    break;
                }
            }
            if (abs(sum_row) == 3 || abs(sum_col) == 3) {
                printf("Player %d wins!\n", player);
                return 0;
            }
        }
        if (abs(sum_diag1) == 3 || abs(sum_diag2) == 3) {
            printf("Player %d wins!\n", player);
            return 0;
        }
        int count_empty = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    count_empty++;
                }
            }
        }
        if (count_empty == 0) {
            printf("Tie game.\n");
            return 0;
        }

        // switch to next player
        player = player == 1 ? 2 : 1;
    }

    return 0;
}