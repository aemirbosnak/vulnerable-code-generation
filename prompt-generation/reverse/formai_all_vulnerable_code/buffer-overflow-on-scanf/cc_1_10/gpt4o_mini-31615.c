//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: modular
#include <stdio.h>

#define MAX_COINS 100
#define MAX_DENOMINATIONS 50

// Function prototypes
void inputDenominations(int denominations[], int *numDenominations);
int calculateMinimumCoins(int amount, int denominations[], int numDenominations);
void displayResult(int amount, int numCoins);

int main() {
    int denominations[MAX_DENOMINATIONS];
    int numDenominations;
    int amount;

    // Input denominations
    inputDenominations(denominations, &numDenominations);

    // Input amount
    printf("Enter the amount to be changed: ");
    scanf("%d", &amount);

    // Calculate and display result
    int numCoins = calculateMinimumCoins(amount, denominations, numDenominations);
    displayResult(amount, numCoins);

    return 0;
}

// Function to input coin denominations
void inputDenominations(int denominations[], int *numDenominations) {
    printf("Enter the number of different denominations: ");
    scanf("%d", numDenominations);

    printf("Enter the coin denominations in descending order:\n");
    for (int i = 0; i < *numDenominations; i++) {
        scanf("%d", &denominations[i]);
    }
}

// Function to calculate minimum number of coins required
int calculateMinimumCoins(int amount, int denominations[], int numDenominations) {
    int numCoins = 0;
    
    for (int i = 0; i < numDenominations; i++) {
        while (amount >= denominations[i]) {
            amount -= denominations[i];
            numCoins++;
        }
    }
    
    if (amount > 0) {
        printf("Amount cannot be completely changed with the given denominations.\n");
        return -1;
    }
    
    return numCoins;
}

// Function to display the result
void displayResult(int amount, int numCoins) {
    if (numCoins >= 0) {
        printf("To form amount %d, minimum number of coins required: %d\n", amount, numCoins);
    }
}