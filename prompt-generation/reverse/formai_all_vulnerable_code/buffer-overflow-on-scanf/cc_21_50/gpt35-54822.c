//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 5

int main() {
    int playerCard[ROWS][COLUMNS] = {{0}};
    int cpuCard[ROWS][COLUMNS] = {{0}};
    int randomNumber, row, column, i, j;
    int playerBingo = 0, cpuBingo = 0;
    int numberOfRounds, round;
    srand(time(NULL));

    // Player selects his/her numbers
    printf("Please select your numbers from 1 to 25:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            printf("Enter a number for row %d, column %d: ", i+1, j+1);
            scanf("%d", &playerCard[i][j]);
        }
    }

    // Generate random numbers for CPU card
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            do {
                randomNumber = rand() % 25 + 1;
            } while (cpuCard[i][j] == randomNumber);
            cpuCard[i][j] = randomNumber;
        }
    }

    // Print player and CPU cards
    printf("\nPlayer card:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            printf("%d\t", playerCard[i][j]);
        }
        printf("\n");
    }

    printf("\nCPU card:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            printf("%d\t", cpuCard[i][j]);
        }
        printf("\n");
    }

    // Play multiple rounds
    printf("\nHow many rounds do you want to play? ");
    scanf("%d", &numberOfRounds);
    for (round = 1; round <= numberOfRounds; round++) {
        printf("\nRound %d\n", round);

        // Player draws a number and crosses it off on his/her card
        do {
            printf("Player, please enter a number from 1 to 25: ");
            scanf("%d", &randomNumber);
        } while (randomNumber < 1 || randomNumber > 25);

        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLUMNS; j++) {
                if (playerCard[i][j] == randomNumber) {
                    playerCard[i][j] = -1;
                    break;
                }
            }
        }

        // CPU draws a number and crosses it off on its card
        do {
            row = rand() % ROWS;
            column = rand() % COLUMNS;
            randomNumber = cpuCard[row][column];
        } while (randomNumber == -1);

        cpuCard[row][column] = -1;

        // Print updated player and CPU cards
        printf("\nPlayer card:\n");
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLUMNS; j++) {
                if (playerCard[i][j] == -1) {
                    printf("X\t");
                } else {
                    printf("%d\t", playerCard[i][j]);
                }
            }
            printf("\n");
        }

        printf("\nCPU card:\n");
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLUMNS; j++) {
                if (cpuCard[i][j] == -1) {
                    printf("X\t");
                } else {
                    printf("%d\t", cpuCard[i][j]);
                }
            }
            printf("\n");
        }

        // Check for Bingo
        playerBingo = 0;
        cpuBingo = 0;

        // Check rows for player and CPU
        for (i = 0; i < ROWS; i++) {
            int playerCount = 0, cpuCount = 0;
            for (j = 0; j < COLUMNS; j++) {
                if (playerCard[i][j] == -1) {
                    playerCount++;
                }
                if (cpuCard[i][j] == -1) {
                    cpuCount++;
                }
            }
            if (playerCount == COLUMNS) {
                playerBingo = 1;
            }
            if (cpuCount == COLUMNS) {
                cpuBingo = 1;
            }
        }

        // Check columns for player and CPU
        for (j = 0; j < COLUMNS; j++) {
            int playerCount = 0, cpuCount = 0;
            for (i = 0; i < ROWS; i++) {
                if (playerCard[i][j] == -1) {
                    playerCount++;
                }
                if (cpuCard[i][j] == -1) {
                    cpuCount++;
                }
            }
            if (playerCount == ROWS) {
                playerBingo = 1;
            }
            if (cpuCount == ROWS) {
                cpuBingo = 1;
            }
        }

        // Check diagonals for player and CPU
        int playerCount1 = 0, cpuCount1 = 0, playerCount2 = 0, cpuCount2 = 0;
        for (i = 0; i < ROWS; i++) {
            if (playerCard[i][i] == -1) {
                playerCount1++;
            }
            if (cpuCard[i][i] == -1) {
                cpuCount1++;
            }
            if (playerCard[i][COLUMNS-i-1] == -1) {
                playerCount2++;
            }
            if (cpuCard[i][COLUMNS-i-1] == -1) {
                cpuCount2++;
            }
        }
        if (playerCount1 == ROWS || playerCount2 == ROWS) {
            playerBingo = 1;
        }
        if (cpuCount1 == ROWS || cpuCount2 == ROWS) {
            cpuBingo = 1;
        }

        // Declare winner of round (if any)
        if (playerBingo == 1) {
            printf("\nPlayer wins Round %d!\n", round);
        } else if (cpuBingo == 1) {
            printf("\nCPU wins Round %d!\n", round);
        }
    }

    printf("\nEnd of game.");

    return 0;
}