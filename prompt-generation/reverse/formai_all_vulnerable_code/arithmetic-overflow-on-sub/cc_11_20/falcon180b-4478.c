//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 1000
#define MAX_VALUES 1000

int main() {
    int num_coins[MAX_COINS], values[MAX_VALUES], n, m;
    int i, j, max_value, curr_value;

    // Read in the number of coins and their values
    printf("Enter the number of coins: ");
    scanf("%d", &n);

    printf("Enter the values of the coins: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &num_coins[i]);
    }

    // Read in the number of items and their values
    printf("Enter the number of items: ");
    scanf("%d", &m);

    printf("Enter the values of the items: ");
    for (i = 0; i < m; i++) {
        scanf("%d", &values[i]);
    }

    // Sort the coins in descending order
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (num_coins[i] < num_coins[j]) {
                int temp = num_coins[i];
                num_coins[i] = num_coins[j];
                num_coins[j] = temp;
            }
        }
    }

    // Initialize the maximum value
    max_value = 0;

    // Initialize the current value
    curr_value = 0;

    // Initialize the number of coins used
    int num_coins_used = 0;

    // Iterate over the items
    for (i = 0; i < m; i++) {
        // Find the smallest coin that is greater than or equal to the current item value
        int j = 0;
        while (j < n && num_coins[j] <= values[i]) {
            j++;
        }

        // If the smallest coin is greater than the current item value, we cannot make change
        if (j == n) {
            printf("Cannot make change for item %d\n", i + 1);
            return 0;
        }

        // Use the smallest coin to make change
        curr_value += num_coins[j];
        num_coins_used++;

        // If the current value is greater than the maximum value, update the maximum value
        if (curr_value > max_value) {
            max_value = curr_value;
        }
    }

    // Print the maximum value
    printf("The maximum value that can be obtained using the coins is: %d\n", max_value);

    // Print the number of coins used
    printf("The number of coins used is: %d\n", num_coins_used);

    return 0;
}