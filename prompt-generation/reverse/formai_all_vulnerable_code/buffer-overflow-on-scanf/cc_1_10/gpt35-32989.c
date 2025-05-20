//FormAI DATASET v1.0 Category: Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAYSIZE 5
#define MAXGUESS 5

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int target[ARRAYSIZE];
    int guess[MAXGUESS][ARRAYSIZE];

    srand(time(NULL));

    for (int i = 0; i < ARRAYSIZE; i++) {
        target[i] = rand() % 10;
    }

    int attempts = 0;
    int correctCount = 0;
    int exitFlag = 0;

    while (attempts < MAXGUESS && !exitFlag) {
        printf("Guess #%d: ", attempts+1);
        for (int i = 0; i < ARRAYSIZE; i++) {
            scanf("%d", &guess[attempts][i]);
        }

        correctCount = 0;
        for (int i = 0; i < ARRAYSIZE; i++) {
            if (guess[attempts][i] == target[i]) {
                correctCount++;
            }
        }

        printf("Correct Count: %d\n", correctCount);
        if (correctCount == ARRAYSIZE) {
            printf("You Won!\n");
            exitFlag = 1;
        }

        attempts++;
    }

    if (!exitFlag) {
        printf("You Lost! The target array was: ");
        printArray(target, ARRAYSIZE);
    }

    return 0;
}