//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int main() {
    int board[ROWS][COLS];
    int i, j, k, l, m, n;
    int player = 1;
    int flag = 0;
    int score = 0;
    int choice;
    int count = 0;
    int comp_choice;
    int match = 0;

    srand(time(NULL));

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = -1;
        }
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            do {
                k = rand() % 8;
                l = rand() % 8;
            } while (k == l);

            board[i][j] = k + l * 8;
        }
    }

    while (1) {
        system("clear");
        printf("Player %d's turn.\n", player);
        printf("Score: %d\n", score);

        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (board[i][j]!= -1) {
                    printf("%d ", board[i][j]);
                } else {
                    printf("-1 ");
                }
            }
            printf("\n");
        }

        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 8) {
            printf("Invalid choice.\n");
            continue;
        }

        count++;

        if (count % 2 == 0) {
            comp_choice = rand() % 8 + 1;
        } else {
            comp_choice = rand() % 8 + 1;
        }

        if (comp_choice == choice) {
            match = 1;
        } else {
            match = 0;
        }

        if (match) {
            printf("Match!\n");
            score += 10;
        } else {
            printf("Mismatch.\n");
        }

        if (player == 1) {
            player = 2;
        } else {
            player = 1;
        }

        if (score >= 50) {
            printf("\nPlayer %d wins!\n", player);
            break;
        }

        if (count >= 16) {
            printf("\nTie game.\n");
            break;
        }
    }

    return 0;
}