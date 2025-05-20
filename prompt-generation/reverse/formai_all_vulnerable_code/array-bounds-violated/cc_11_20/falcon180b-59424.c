//Falcon-180B DATASET v1.0 Category: Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

int main() {
    int board[ROWS][COLS] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1;
    int choice;
    int valid_move = 0;

    srand(time(NULL));

    while (valid_move == 0) {
        system("clear");
        printf("Player %d's turn\n", player);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == 0) {
                    printf(" %d ", i*3+j+1);
                } else if (board[i][j] == 1) {
                    printf(" X ");
                } else {
                    printf(" O ");
                }
            }
            printf("\n");
        }
        printf("\n");

        valid_move = 1;
        while (valid_move) {
            printf("Enter your move (1-%d): ", ROWS*COLS);
            scanf("%d", &choice);
            if (choice >= 1 && choice <= ROWS*COLS) {
                int row = choice / COLS;
                int col = choice % COLS;

                if (board[row][col] == 0) {
                    board[row][col] = player;
                    valid_move = 0;
                }
            } else {
                printf("Invalid move. Please try again.\n");
            }
        }

        if (player == 1) {
            player = 2;
        } else {
            player = 1;
        }
    }

    if (player == 1) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }

    return 0;
}