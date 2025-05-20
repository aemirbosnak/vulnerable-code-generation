//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a coin
typedef struct {
    int value;
    int weight;
} Coin;

// Define a function to compare two coins based on their value-to-weight ratio
int compareCoins(const void* a, const void* b) {
    const Coin* coinA = (const Coin*)a;
    const Coin* coinB = (const Coin*)b;

    return (coinA->value / coinA->weight) - (coinB->value / coinB->weight);
}

// Define a function to read coins from a file
void readCoins(Coin* coins, int numCoins, FILE* file) {
    for (int i = 0; i < numCoins; i++) {
        fscanf(file, "%d %d", &coins[i].value, &coins[i].weight);
    }
}

// Define a function to print a coin
void printCoin(const Coin* coin) {
    printf("%d (%d cents)\n", coin->value, coin->value * 100 / coin->weight);
}

// Define a function to find the maximum value of a set of coins with a given weight limit
int findMaxValue(Coin* coins, int numCoins, int weightLimit) {
    qsort(coins, numCoins, sizeof(Coin), compareCoins);

    int maxValue = 0;
    for (int i = 0; i < numCoins && coins[i].weight <= weightLimit; i++) {
        maxValue += coins[i].value;
    }

    return maxValue;
}

// Define the main function
int main() {
    FILE* file = fopen("coins.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    int numCoins;
    fscanf(file, "%d", &numCoins);

    Coin* coins = malloc(numCoins * sizeof(Coin));
    readCoins(coins, numCoins, file);

    int maxValue = findMaxValue(coins, numCoins, 100);

    printf("Maximum value: $%d\n", maxValue / 100);

    for (int i = 0; i < numCoins; i++) {
        printCoin(&coins[i]);
    }

    free(coins);
    fclose(file);

    return 0;
}