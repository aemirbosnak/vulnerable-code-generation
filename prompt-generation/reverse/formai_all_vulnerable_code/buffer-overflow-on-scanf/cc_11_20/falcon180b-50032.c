//Falcon-180B DATASET v1.0 Category: Educational ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
    int board[SIZE][SIZE];
    int player = 1;
    int choice;
    int flag = 0;
    int count = 0;

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = rand() % 2;
        }
    }

    while (flag == 0) {
        system("clear");
        printf("Player 1: X and Player 2: O\n");
        printf("Player %d's Turn\n", player);
        printf("Score: Player 1: %d and Player 2: %d\n", count, SIZE - count);

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == 1) {
                    printf("X");
                } else if (board[i][j] == 2) {
                    printf("O");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        printf("Enter your move: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > SIZE) {
            printf("Invalid Move! Try Again.\n");
        } else if (board[choice - 1][0]!= 0) {
            printf("Column Full! Try Again.\n");
        } else {
            board[choice - 1][0] = player;
            count++;

            if (count == SIZE) {
                flag = 1;
                printf("Player %d wins!\n", player);
            } else if (count == SIZE - 1) {
                player = 3 - player;
            }
        }
    }

    return 0;
}