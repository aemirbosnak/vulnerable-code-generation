//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int main() {
    int board[ROWS][COLS];
    int player = 1;
    int choice;
    int flag = 0;
    int count = 0;

    srand(time(NULL));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }

    while (flag == 0) {
        system("clear");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == 1) {
                    printf("O");
                } else {
                    printf("X");
                }
            }
            printf("\n");
        }

        printf("\nPlayer %d's turn.\n", player);
        printf("Enter your choice of row and column: ");
        scanf("%d %d", &choice, &choice);

        if (player == 1) {
            if (board[choice - 1][choice - 1] == 0) {
                board[choice - 1][choice - 1] = 1;
                count++;
            } else {
                printf("Invalid move. Try again.\n");
            }
        } else {
            if (board[choice - 1][choice - 1] == 1) {
                board[choice - 1][choice - 1] = 0;
                count++;
            } else {
                printf("Invalid move. Try again.\n");
            }
        }

        if (count == (ROWS * COLS) / 2) {
            flag = 1;
            printf("\nGame tied! ");
        } else if (player == 1 && count == (ROWS * COLS) / 2 + 1) {
            flag = 1;
            printf("\nPlayer 1 wins! ");
        } else if (player == 2 && count == (ROWS * COLS) / 2 + 1) {
            flag = 1;
            printf("\nPlayer 2 wins! ");
        }

        player = (player == 1)? 2 : 1;
        count = 0;
    }

    return 0;
}