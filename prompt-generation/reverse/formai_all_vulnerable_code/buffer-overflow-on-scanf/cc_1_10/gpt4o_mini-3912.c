//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: cheerful
#include <stdio.h>

void printArray(int arr[], int size) {
    printf("Here are your magical coins collected: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int greedyCoinChange(int coins[], int n, int value) {
    // Cheerfully counting the number of coins used
    int coinCount[n];
    for (int i = 0; i < n; i++) {
        coinCount[i] = 0;
    }

    printf("Gather around for a magical coin adventure!\n");
    printf("You need to make change for %d units using the following coin values:\n", value);

    for (int i = 0; i < n; i++) {
        printf("%d ", coins[i]);
    }
    printf("\n\n");

    int totalCoins = 0;
    for (int i = 0; i < n; i++) {
        while (value >= coins[i]) {
            value -= coins[i];
            coinCount[i]++;
            totalCoins++;
            printf("Using a coin of value %d, remaining value to collect: %d\n", coins[i], value);
        }
    }

    // Reporting the cheerful results
    printf("\nHurray! We have made the change!\n");
    printf("Total coins used: %d\n", totalCoins);
    for (int i = 0; i < n; i++) {
        if (coinCount[i] > 0) {
            printf("Coin of value %d: used %d times.\n", coins[i], coinCount[i]);
        }
    }
    
    // Returning the total number of coins used
    return totalCoins;
}

int main() {
    printf("Welcome to the Magical Coin Change Adventure!\n");
    
    int coins[] = {1, 5, 10, 25}; // Magical coin values (in some whimsical currency)
    int n = sizeof(coins) / sizeof(coins[0]);
    
    int value;
    printf("Please enter the amount of magical currency you want changed (in units): ");
    scanf("%d", &value);
    
    // Performing the Greedy Coin Change
    greedyCoinChange(coins, n, value);

    printf("\nThank you for joining our adventure! May your pockets be filled with treasures!\n");
    return 0;
}