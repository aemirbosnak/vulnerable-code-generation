//MISTRAL-7B DATASET v1.0 Category: Memory Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define ELEMENTS_NUMBER 6

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int i, j, userInputX, userInputY, hiddenNumber, revealedNumber = 0;
    int shuffledIndices[ELEMENTS_NUMBER];

    srand(time(NULL));

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = -1;
        }
    }

    hiddenNumber = rand() % ELEMENTS_NUMBER;
    shuffledIndices[hiddenNumber] = 0;

    for (i = 0; i < ELEMENTS_NUMBER; i++) {
        if (i != hiddenNumber) {
            int tempIndex = rand() % (ELEMENTS_NUMBER - i) + i;
            int temp = shuffledIndices[i];
            shuffledIndices[i] = shuffledIndices[temp];
            shuffledIndices[temp] = temp;
        }
    }

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            int index = shuffledIndices[revealedNumber / 2];
            int row = index / BOARD_SIZE;
            int col = index % BOARD_SIZE;
            if (i == row && j == col) {
                board[i][j] = 0;
                revealedNumber++;
            }
            if (board[i][j] == -1) {
                printf(" _ ");
            } else {
                printf(" %d ", board[i][j]);
            }
        }
        printf("\n");
    }

    do {
        printf("\nEnter row and column: ");
        scanf("%d%d", &userInputX, &userInputY);

        if (userInputX < 0 || userInputX >= BOARD_SIZE || userInputY < 0 || userInputY >= BOARD_SIZE) {
            printf("Invalid move!\n");
        }

        if (board[userInputX][userInputY] == -1) {
            int index = userInputX * BOARD_SIZE + userInputY;
            int temp = shuffledIndices[revealedNumber / 2];

            if (shuffledIndices[index / 2] == temp) {
                board[userInputX][userInputY] = 0;
                revealedNumber++;

                if (revealedNumber == ELEMENTS_NUMBER) {
                    printf("\nCongratulations! You've found all the numbers.\n");
                }
            } else {
                printf("Try again!\n");
            }
        }

    } while (revealedNumber < ELEMENTS_NUMBER);

    return 0;
}