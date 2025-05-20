//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COINS 6

// Structure to represent a coin
typedef struct {
    int value;
    char name[10];
} Coin;

// Function to generate random coin values
void generateCoins(Coin coins[]) {
    srand(time(NULL));

    for (int i = 0; i < MAX_COINS; i++) {
        coins[i].value = rand() % 100;
        sprintf(coins[i].name, "Coin %d", i + 1);
    }
}

// Function to sort coins in descending order based on their values
void sortCoins(Coin coins[]) {
    for (int i = 0; i < MAX_COINS - 1; i++) {
        for (int j = i + 1; j < MAX_COINS; j++) {
            if (coins[i].value < coins[j].value) {
                Coin temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }
}

// Function to print the selected coins
void printCoins(Coin coins[], int n) {
    printf("Selected coins:\n");
    for (int i = 0; i < n; i++) {
        printf("%s (%d)\n", coins[i].name, coins[i].value);
    }
}

// Function to find the maximum value of coins that can be selected without exceeding the given amount
int findMaxValue(Coin coins[], int n, int amount) {
    int maxValue = 0;

    for (int i = 0; i < n; i++) {
        if (coins[i].value <= amount) {
            maxValue += coins[i].value;
        } else {
            return maxValue;
        }
    }

    return maxValue;
}

// Greedy algorithm to find the minimum number of coins required to make a given amount
int minCoins(Coin coins[], int n, int amount) {
    sortCoins(coins);

    int selectedCoins = 0;
    int remainingAmount = amount;

    while (remainingAmount > 0) {
        int maxValue = findMaxValue(coins, n, remainingAmount);

        if (maxValue == 0) {
            break;
        }

        selectedCoins++;
        remainingAmount -= maxValue;
    }

    return selectedCoins;
}

int main() {
    Coin coins[MAX_COINS];
    generateCoins(coins);

    int amount;
    printf("Enter the amount: ");
    scanf("%d", &amount);

    int minCoinsRequired = minCoins(coins, MAX_COINS, amount);

    printf("Minimum number of coins required: %d\n", minCoinsRequired);

    return 0;
}