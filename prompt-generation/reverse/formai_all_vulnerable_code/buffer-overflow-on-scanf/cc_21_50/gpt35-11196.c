//FormAI DATASET v1.0 Category: Table Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Initialize player scores */
    int player1_score = 0;
    int player2_score = 0;

    /* Initialize board */
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    /* Variable to keep track of current player */
    int current_player = 1;

    /* Loop through each turn */
    for(int i = 0; i < 9; i++) {

        /* Print board */
        printf("\n");
        printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
        printf("---+---+---\n");
        printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
        printf("---+---+---\n");
        printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
        printf("\n");

        /* Check if there is a winner */
        if(player1_score >= 3 || player2_score >= 3) {

            /* Check rows */
            for(int j = 0; j < 3; j++) {
                if(board[j][0] == 'X' && board[j][1] == 'X' && board[j][2] == 'X') {
                    printf("Player 1 wins!\n");
                    return 0;
                }
                else if(board[j][0] == 'O' && board[j][1] == 'O' && board[j][2] == 'O') {
                    printf("Player 2 wins!\n");
                    return 0;
                }
            }

            /* Check columns */
            for(int j = 0; j < 3; j++) {
                if(board[0][j] == 'X' && board[1][j] == 'X' && board[2][j] == 'X') {
                    printf("Player 1 wins!\n");
                    return 0;
                }
                else if(board[0][j] == 'O' && board[1][j] == 'O' && board[2][j] == 'O') {
                    printf("Player 2 wins!\n");
                    return 0;
                }
            }

            /* Check diagonals */
            if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') {
                printf("Player 1 wins!\n");
                return 0;
            }
            else if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {
                printf("Player 2 wins!\n");
                return 0;
            }
            else if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') {
                printf("Player 1 wins!\n");
                return 0;
            }
            else if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {
                printf("Player 2 wins!\n");
                return 0;
            }
        }

        /* Get user input */
        int row, col;
        printf("Player %d's turn.\n", current_player);
        printf("Enter row number (1-3): ");
        scanf("%d", &row);
        printf("Enter column number (1-3): ");
        scanf("%d", &col);

        /* Check if input is valid */
        if(row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid input. Try again.\n");
            i--;
            continue;
        }
        else if(board[row-1][col-1] == 'X' || board[row-1][col-1] == 'O') {
            printf("That spot is already taken. Try again.\n");
            i--;
            continue;
        }

        /* Update board */
        if(current_player == 1) {
            board[row-1][col-1] = 'X';
        }
        else {
            board[row-1][col-1] = 'O';
        }

        /* Update score */
        if(current_player == 1) {
            player1_score++;
        }
        else {
            player2_score++;
        }

        /* Switch player */
        if(current_player == 1) {
            current_player = 2;
        }
        else {
            current_player = 1;
        }
    }

    /* If game reaches here, it is a tie */
    printf("It's a tie!\n");

    return 0;
}