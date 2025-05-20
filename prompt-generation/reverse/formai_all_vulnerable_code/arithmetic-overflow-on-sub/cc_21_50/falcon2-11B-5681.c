//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seed random number generator

    int board[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };

    // print initial board state
    printf("Initial board state:\n");
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // simulate player moves
    int player_turn = 1; // 1 for player 1, 2 for player 2
    int player_score = 0;
    int computer_score = 0;

    while (player_score < 3 && computer_score < 3) {
        printf("\nPlayer %d's turn.\n", player_turn);

        // prompt player to choose a cell to place their token
        int row, col;
        printf("Choose a row (1-7) and column (1-7): ");
        scanf("%d %d", &row, &col);

        // check if cell is empty
        if (board[row - 1][col - 1] == 0) {
            // mark cell as occupied
            board[row - 1][col - 1] = player_turn;

            // check for winning conditions
            int rows_won = 0;
            int cols_won = 0;
            int diags_won = 0;
            int anti_diags_won = 0;

            // check rows
            for (int i = 0; i < 7; i++) {
                if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][3] == board[i][4] && board[i][4] == board[i][5] && board[i][5] == board[i][6] && board[i][6] == board[i][7]) {
                    rows_won = 1;
                }
            }

            // check columns
            for (int j = 0; j < 7; j++) {
                if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] == board[3][j] && board[3][j] == board[4][j] && board[4][j] == board[5][j] && board[5][j] == board[6][j] && board[6][j] == board[7][j]) {
                    cols_won = 1;
                }
            }

            // check diagonals
            if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4] && board[4][4] == board[5][5] && board[5][5] == board[6][6] && board[6][6] == board[7][7]) {
                diags_won = 1;
            }

            if (board[0][6] == board[1][5] && board[1][5] == board[2][4] && board[2][4] == board[3][3] && board[3][3] == board[4][2] && board[4][2] == board[5][1] && board[5][1] == board[6][0] && board[6][0] == board[7][7]) {
                anti_diags_won = 1;
            }

            // check for winner
            if (rows_won == 1 || cols_won == 1 || diags_won == 1 || anti_diags_won == 1) {
                if (player_turn == 1) {
                    player_score++;
                    printf("Player 1 wins!\n");
                } else if (player_turn == 2) {
                    computer_score++;
                    printf("Computer wins!\n");
                }
            } else {
                // reset board if no one wins
                for (int i = 0; i < 7; i++) {
                    for (int j = 0; j < 7; j++) {
                        board[i][j] = 0;
                    }
                }

                // switch player turn
                player_turn = (player_turn % 2) + 1;
            }
        } else {
            printf("Invalid move! Try again.\n");
        }
    }

    // print final board state
    printf("Final board state:\n");
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}