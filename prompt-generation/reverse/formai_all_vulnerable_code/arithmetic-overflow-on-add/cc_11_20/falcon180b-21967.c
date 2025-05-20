//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, n, count = 0;
    char bingo[5][5]; // 2D array to store the bingo cards
    char temp[5][5]; // 2D array to temporarily store the generated bingo card
    int num; // variable to store the generated number
    int flag = 0; // flag to check if there is a winner

    srand(time(NULL)); // seed the random number generator with the current time

    printf("Enter the number of players: ");
    scanf("%d", &n);

    printf("Enter the number of cards per player: ");
    scanf("%d", &count);

    // initialize the bingo cards with random numbers from 1 to 75
    for (i = 0; i < n; i++) {
        for (j = 0; j < count; j++) {
            do {
                num = rand() % 75 + 1; // generate a random number between 1 and 75
            } while (bingo[i][j] == num); // check if the number is already in the bingo card

            bingo[i][j] = num; // store the generated number in the bingo card
        }
    }

    // print the bingo cards
    printf("\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < count; j++) {
            printf("%d ", bingo[i][j]);
        }
        printf("\n");
    }

    // start the game
    while (flag == 0) {
        printf("\nRound %d:\n", ++count);

        // generate a random number
        num = rand() % 75 + 1;

        // check if the number is already in the bingo cards
        for (i = 0; i < n; i++) {
            for (j = 0; j < count; j++) {
                if (bingo[i][j] == num) {
                    printf("Player %d wins!\n", i + 1);
                    flag = 1;
                    break;
                }
            }
        }

        // check if there is a tie
        if (flag == 0) {
            for (i = 0; i < n; i++) {
                for (j = 0; j < count; j++) {
                    if (bingo[i][j] == num) {
                        bingo[i][j] = 0; // mark the number as used
                    }
                }
            }
        }
    }

    return 0;
}