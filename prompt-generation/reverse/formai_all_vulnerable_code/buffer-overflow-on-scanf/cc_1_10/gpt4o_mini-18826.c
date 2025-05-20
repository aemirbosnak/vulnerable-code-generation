//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a coin
typedef struct {
    int value;  // Coin value
    int weight; // Coin weight
} Coin;

// Function prototype
void sortCoins(Coin *coins, int n);
int getMaxValue(Coin *coins, int n, int maxWeight);

// Comparator function for qsort
int compare(const void *a, const void *b) {
    Coin *coinA = (Coin *)a;
    Coin *coinB = (Coin *)b;
    double r1 = (double)coinA->value / coinA->weight;
    double r2 = (double)coinB->value / coinB->weight;
    return (r1 < r2) - (r1 > r2); // Returns -1, 0, or 1
}

void sortCoins(Coin *coins, int n) {
    qsort(coins, n, sizeof(Coin), compare);
}

int getMaxValue(Coin *coins, int n, int maxWeight) {
    sortCoins(coins, n);

    int totalValue = 0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + coins[i].weight <= maxWeight) {
            currentWeight += coins[i].weight;
            totalValue += coins[i].value;
            printf("Adding coin of value %d and weight %d\n", coins[i].value, coins[i].weight);
        } else {
            int remainWeight = maxWeight - currentWeight;
            totalValue += coins[i].value * ((double)remainWeight / coins[i].weight);
            printf("Adding fraction of coin value %d (using weight %d)\n", coins[i].value, remainWeight);
            break; // Must reach maximum capacity
        }
    }

    return totalValue;
}

int main() {
    int n; // Number of different coins
    int maxWeight; // Maximum weight capacity

    printf("Enter the number of different coins: ");
    scanf("%d", &n);

    Coin *coins = (Coin *)malloc(n * sizeof(Coin));

    printf("Enter the coin values and weights:\n");
    for (int i = 0; i < n; i++) {
        printf("Coin %d -> Value: ", i + 1);
        scanf("%d", &coins[i].value);
        printf("Coin %d -> Weight: ", i + 1);
        scanf("%d", &coins[i].weight);
    }

    printf("Enter the maximum weight capacity: ");
    scanf("%d", &maxWeight);

    int maxValue = getMaxValue(coins, n, maxWeight);
    printf("Maximum value obtainable: %d\n", maxValue);

    free(coins); // Clean up
    return 0;
}