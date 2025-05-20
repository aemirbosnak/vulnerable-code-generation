//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 1000
#define MAX_COINS 6

int coinValues[MAX_COINS];

void generateRandomCoinValues(void) {
    srand(time(NULL));
    for (int i = 0; i < MAX_COINS; i++) {
        coinValues[i] = rand() % MAX_VALUE;
    }
}

int main() {
    generateRandomCoinValues();

    int targetValue = rand() % MAX_VALUE;

    printf("Sherlock Holmes needs to pay %d pounds.\n", targetValue);

    int solution[MAX_COINS];
    int solutionSize = 0;

    for (int i = 0; i < MAX_COINS; i++) {
        if (coinValues[i] <= targetValue) {
            if (targetValue == coinValues[i]) {
                solution[solutionSize++] = coinValues[i];
            } else {
                for (int j = i + 1; j < MAX_COINS; j++) {
                    if (coinValues[j] <= targetValue - coinValues[i]) {
                        solution[solutionSize++] = coinValues[i];
                        solution[solutionSize++] = coinValues[j];
                        targetValue -= coinValues[i] + coinValues[j];
                        break;
                    }
                }
            }
        }
    }

    printf("The minimum number of coins required is: %d\n", solutionSize);

    for (int i = 0; i < solutionSize; i++) {
        printf("%d ", solution[i]);
    }

    return 0;
}