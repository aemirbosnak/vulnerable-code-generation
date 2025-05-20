//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int main() {
    int i, j, flag = 0, count = 0;
    int board[ROWS][COLS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int choice, position;

    srand(time(0));

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = rand() % 16 + 1;
        }
    }

    printf("Welcome to Memory Game!\n");

    while (flag == 0) {
        system("clear");
        printf("Score: %d\n", count);
        printf("Press 1 to start the game or 0 to exit:\n");
        scanf("%d", &choice);

        if (choice == 1) {
            flag = 1;
            count = 0;

            for (i = 0; i < ROWS; i++) {
                for (j = 0; j < COLS; j++) {
                    printf("%d ", board[i][j]);
                }
                printf("\n");
            }

            printf("Press any two numbers to check if they match:\n");
            scanf("%d %d", &position, &position);

            if (board[position - 1][0] == board[position - 1][1]) {
                count++;
            } else {
                printf("Sorry, try again.\n");
            }
        } else {
            printf("Thank you for playing!\n");
            exit(0);
        }
    }

    return 0;
}