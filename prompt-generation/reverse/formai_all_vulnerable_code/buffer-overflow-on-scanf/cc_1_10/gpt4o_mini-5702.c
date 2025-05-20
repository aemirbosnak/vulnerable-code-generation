//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a coin
struct Coin {
    int value;
    int count;
};

// Function to compare two coins based on their value
int compare(const void *a, const void *b) {
    struct Coin *coin1 = (struct Coin *)a;
    struct Coin *coin2 = (struct Coin *)b;
    return coin2->value - coin1->value; // Sort in decreasing order
}

// Function to calculate the minimum number of coins
void calculateMinCoins(int amount, struct Coin *coins, int coin_count) {
    int total_coins = 0;
    for (int i = 0; i < coin_count; i++) {
        if (amount == 0) 
            break;

        int max_use = amount / coins[i].value; // Maximum number of coins we can use
        if (max_use > coins[i].count) {
            max_use = coins[i].count; // We can't use more than available
        }

        total_coins += max_use; 
        amount -= max_use * coins[i].value; // Decrease the amount accordingly
    }

    if (amount > 0) {
        printf("Cannot make the exact change with the available coins.\n");
    } else {
        printf("Minimum coins required: %d\n", total_coins);
    }
}

// Function to display the available coins
void displayCoins(struct Coin *coins, int coin_count) {
    printf("Available coins:\n");
    for (int i = 0; i < coin_count; i++) {
        printf("Value: %d, Count: %d\n", coins[i].value, coins[i].count);
    }
}

int main() {
    // Example of available coins
    int total_coin_types = 5; // Number of different coin types
    struct Coin coins[] = {
        {25, 3},  // 25 cents x 3
        {10, 2},  // 10 cents x 2
        {5, 5},   // 5 cents x 5
        {1, 10},  // 1 cent x 10
        {50, 1}   // 50 cents x 1
    };

    int amount;
    
    // Displaying available coins
    displayCoins(coins, total_coin_types);
    
    // User input for the amount
    printf("Enter the amount to change (in cents): ");
    scanf("%d", &amount);

    // Sorting coins based on their value in descending order
    qsort(coins, total_coin_types, sizeof(struct Coin), compare);
    
    // Calculate minimum coins needed
    calculateMinCoins(amount, coins, total_coin_types);

    return 0;
}