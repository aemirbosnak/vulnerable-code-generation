//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 11
#define MAX_VALUES 101

int values[MAX_VALUES] = {1, 5, 10, 25};
int coins[MAX_COINS] = {1, 5, 10, 25};
int nCoins = 0, i, j, nValues = 0, maxValue = 0;

void initialize() {
    for (i = 0; i < MAX_VALUES; i++) {
        values[i] = 0;
    }
    for (i = 0; i < MAX_COINS; i++) {
        coins[i] = 0;
    }
    nCoins = 0;
    nValues = 0;
    maxValue = 0;
}

void printCoins() {
    printf("Coins used: ");
    for (i = 0; i < MAX_COINS; i++) {
        if (coins[i] > 0) {
            printf("%d ", coins[i]);
        }
    }
    printf("\n");
}

void findMaxValue() {
    int i;
    maxValue = 0;
    for (i = 0; i < MAX_VALUES; i++) {
        if (values[i] > maxValue) {
            maxValue = values[i];
        }
    }
}

void greedyAlgorithm() {
    int i, j;
    for (i = 0; i < nValues; i++) {
        for (j = 0; j < MAX_COINS; j++) {
            if (coins[j] + values[i] <= MAX_VALUES) {
                coins[j] += values[i];
                nCoins++;
                break;
            }
        }
    }
}

int main() {
    int i, n;
    printf("Enter the number of values: ");
    scanf("%d", &n);
    initialize();
    printf("Enter the values:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }
    findMaxValue();
    printf("Maximum value: %d\n", maxValue);
    greedyAlgorithm();
    printCoins();
    return 0;
}