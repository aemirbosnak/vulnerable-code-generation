//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 10
#define DROPS 500

int main() {
    int board[SIZE][SIZE] = {0};
    int top[SIZE] = {0};
    int bottom[SIZE] = {0};
    int left[SIZE] = {0};
    int right[SIZE] = {0};
    int count = 0;
    int i, j, k, l, m, n;
    int x, y;
    int choice;
    int flag = 1;
    int num_drops = 0;

    srand(time(NULL));

    while (flag) {
        system("clear");
        printf("PERCOLATION SIMULATOR\n");
        printf("---------------------\n");
        printf("Press 1 to start the simulation\n");
        printf("Press 2 to stop the simulation\n");
        printf("Press 3 to reset the board\n");
        printf("---------------------\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                flag = 0;
                break;
            case 2:
                flag = 1;
                break;
            case 3:
                for (i = 0; i < SIZE; i++) {
                    for (j = 0; j < SIZE; j++) {
                        board[i][j] = 0;
                    }
                }
                count = 0;
                break;
            default:
                printf("Invalid choice\n");
        }

        if (flag) {
            while (num_drops < DROPS) {
                i = rand() % SIZE;
                j = rand() % SIZE;

                if (board[i][j] == 0) {
                    board[i][j] = 1;
                    num_drops++;
                }
            }

            for (i = 0; i < SIZE; i++) {
                top[i] = board[i][0];
                bottom[i] = board[i][SIZE - 1];
            }

            for (j = 0; j < SIZE; j++) {
                left[j] = board[0][j];
                right[j] = board[SIZE - 1][j];
            }

            for (i = 1; i < SIZE - 1; i++) {
                for (j = 1; j < SIZE - 1; j++) {
                    x = top[i - 1] + left[j - 1] + board[i][j] + right[j + 1] + bottom[i + 1];

                    if (x == 3) {
                        board[i][j] = 1;
                        count++;
                    }
                }
            }
        }

        printf("Number of drops: %d\n", num_drops);
        printf("Number of connected drops: %d\n", count);
        printf("---------------------\n");
        printf("Press any key to continue...\n");
        getchar();
    }

    return 0;
}