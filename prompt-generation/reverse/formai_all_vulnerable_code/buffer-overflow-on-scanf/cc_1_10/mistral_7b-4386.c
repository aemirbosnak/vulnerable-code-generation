//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define NUM_COINS 4
#define MAX_CHANGE 100

// Define coins denominations in a cyberpunk style
typedef struct coin {
    int value;
    char symbol;
} coin_t;

coin_t coins[NUM_COINS] = {
    {5, 'P'},
    {10, 'E'},
    {25, 'R'},
    {50, 'N'}
};

// Function to find the minimum number of coins required
// to make given amount of change using Greedy Algorithm
int min_coins(int change) {
    int i = NUM_COINS - 1, count = 0;

    while (change > 0) {
        // Select the largest coin less than or equal to the change
        while (change >= coins[i].value && i >= 0) {
            change -= coins[i].value;
            count++;
            i--;
        }

        // If we exhausted all coins, return the current count as answer
        if (i == -1) {
            return count;
        }

        i = NUM_COINS - 1;
    }

    return count;
}

int main() {
    int change;

    printf("Welcome to the Cyberpunk Coin Changer!\n");
    printf("How much change do you want? (Up to %d)\n", MAX_CHANGE);
    scanf("%d", &change);

    if (change > MAX_CHANGE) {
        printf("Error: Amount too large!\n");
        return 1;
    }

    printf("You need %d coins to make %d change.\n", min_coins(change), change);

    return 0;
}