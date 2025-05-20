//Falcon-180B DATASET v1.0 Category: Table Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int main() {
    int board[MAX_ROWS][MAX_COLS] = {{0}};
    int player = 1;
    int choice;
    int row, col;
    int flag = 0;

    srand(time(0));

    while (!flag) {
        system("clear");
        printf("Player 1: X and Player 2: O\n");
        printf("Enter your choice(1/2): ");
        scanf("%d", &player);

        if (player == 1)
            printf("Player 1's Turn\n");
        else
            printf("Player 2's Turn\n");

        printf("Board:\n");
        for (row = 0; row < MAX_ROWS; row++) {
            for (col = 0; col < MAX_COLS; col++) {
                printf(" %d ", board[row][col]);
            }
            printf("\n");
        }

        if (player == 1) {
            choice = rand() % 3;
        } else {
            choice = rand() % 3;
        }

        switch (choice) {
        case 0:
            row = rand() % MAX_ROWS;
            col = rand() % MAX_COLS;

            if (board[row][col]!= 1 && board[row][col]!= 2) {
                board[row][col] = 1;
                printf("Player %d placed X at (%d,%d)\n", player, row, col);
            } else {
                printf("Invalid move. Try again.\n");
            }
            break;

        case 1:
            row = rand() % MAX_ROWS;
            col = rand() % MAX_COLS;

            if (board[row][col]!= 1 && board[row][col]!= 2) {
                board[row][col] = 2;
                printf("Player %d placed O at (%d,%d)\n", player, row, col);
            } else {
                printf("Invalid move. Try again.\n");
            }
            break;

        case 2:
            printf("Game Over. Player %d wins!\n", player);
            flag = 1;
            break;
        }
    }

    return 0;
}