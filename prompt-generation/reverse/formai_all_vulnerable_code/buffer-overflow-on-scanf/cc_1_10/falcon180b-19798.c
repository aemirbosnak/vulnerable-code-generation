//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COINS 1000
#define MAX_VALUES 1000

// Function to find the maximum value using greedy algorithm
int findMaxValue(int values[], int n, int coins[]) {
    int i, j, max_value = 0;

    // Sort the coins in decreasing order
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (coins[i] > coins[j]) {
                int temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }

    // Initialize the maximum value
    for (i = 0; i < n; i++) {
        if (values[i] > max_value) {
            max_value = values[i];
        }
    }

    // Apply the greedy algorithm
    for (i = 0; i < n; i++) {
        if (max_value >= values[i]) {
            max_value -= values[i];
        } else {
            int coin = 0;
            while (max_value < values[i]) {
                if (coins[coin] <= max_value) {
                    max_value += coins[coin];
                } else {
                    coin++;
                }
            }
            if (max_value < values[i]) {
                return -1;
            }
        }
    }

    return max_value;
}

int main() {
    int n, i, j, max_value;
    int values[MAX_VALUES], coins[MAX_COINS];

    // Read the number of values and coins
    printf("Enter the number of values: ");
    scanf("%d", &n);

    // Read the values and coins
    printf("Enter the values: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    printf("Enter the coins: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    // Find the maximum value using greedy algorithm
    max_value = findMaxValue(values, n, coins);

    // Print the result
    if (max_value == -1) {
        printf("No solution exists.\n");
    } else {
        printf("The maximum value is %d.\n", max_value);
    }

    return 0;
}