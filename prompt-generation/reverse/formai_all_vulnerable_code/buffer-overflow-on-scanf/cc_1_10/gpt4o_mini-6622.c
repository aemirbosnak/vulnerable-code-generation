//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: excited
#include <stdio.h>

void calculateMinimumCoins(int denominations[], int numDenominations, int amount) {
    int coinsUsed = 0;
    int coinCount[100] = {0}; // Array to count coins of each denomination

    printf("\n🤩 Let's calculate the minimum coins needed for %d using greedy approach! 🤩\n", amount);

    for (int i = 0; i < numDenominations; i++) {
        while (amount >= denominations[i]) {
            coinsUsed++;
            amount -= denominations[i];
            coinCount[i]++; // Counting how many coins of this denomination we used
            printf("💰 We used one %d coin! Total coins so far: %d\n", denominations[i], coinsUsed);
        }
    }

    if (amount > 0) {
        printf("😢 Oh no! We couldn't make the exact amount. Remaining: %d\n", amount);
    } else {
        printf("🎉 Hooray! We made the exact amount using %d coins! 🎉\n", coinsUsed);
        printf("🔍 Here's a breakdown of the coins used:\n");
        for (int i = 0; i < numDenominations; i++) {
            if (coinCount[i] > 0) {
                printf("✌️ %d coin(s) of denomination %d\n", coinCount[i], denominations[i]);
            }
        }
    }
}

int main() {
    printf("🎈 Welcome to the Coin Change Solver! 🎈\n");

    int denominations[] = {25, 10, 5, 1}; // Coin denominations
    int numDenominations = sizeof(denominations) / sizeof(denominations[0]);
    int amount;

    printf("Please enter the amount you need to make change for: ");
    scanf("%d", &amount);

    if (amount < 0) {
        printf("🚫 Negative amount! Please enter a non-negative integer.\n");
        return 1;
    }

    calculateMinimumCoins(denominations, numDenominations, amount);

    printf("\nThank you for using the Coin Change Solver! ✨\n");
    return 0;
}