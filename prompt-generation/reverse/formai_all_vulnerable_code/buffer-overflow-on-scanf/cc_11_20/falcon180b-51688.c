//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_CARDS 75

int main() {
    srand(time(NULL));
    int bingoCards[ROWS][COLS];
    int calledNumbers[MAX_CARDS];
    int numCards = 0;
    int numCalled = 0;
    int winner = -1;

    printf("Welcome to the C Bingo Simulator!\n");
    printf("How many bingo cards do you want to play with? (1-10): ");
    scanf("%d", &numCards);

    for (int i = 0; i < numCards; i++) {
        for (int j = 0; j < COLS; j++) {
            bingoCards[i][j] = rand() % 15 + 1;
        }
    }

    do {
        int num = rand() % 15 + 1;
        for (int i = 0; i < numCards; i++) {
            for (int j = 0; j < COLS; j++) {
                if (bingoCards[i][j] == num) {
                    printf("Bingo card %d: %d\n", i+1, num);
                }
            }
        }
        calledNumbers[numCalled++] = num;
    } while (numCalled < MAX_CARDS);

    for (int i = 0; i < numCards; i++) {
        int row = 0, col = 0;
        for (int j = 0; j < COLS; j++) {
            if (bingoCards[i][j] == calledNumbers[j]) {
                row = 1;
            }
        }
        for (int j = 0; j < ROWS; j++) {
            if (row) {
                printf("Bingo card %d: ", i+1);
                for (int k = 0; k < COLS; k++) {
                    printf("%d ", bingoCards[i][k]);
                }
                printf("\n");
                winner = i;
                break;
            }
            row = 0;
        }
    }

    if (winner == -1) {
        printf("No one won. :(\n");
    } else {
        printf("Bingo card %d wins!\n", winner+1);
    }

    return 0;
}