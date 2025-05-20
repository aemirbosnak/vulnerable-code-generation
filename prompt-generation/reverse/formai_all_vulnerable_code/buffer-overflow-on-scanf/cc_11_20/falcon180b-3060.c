//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100
#define MAX_VALUE 100

int main() {
    int num_values;
    int values[MAX_NUMBERS];
    int max_value = 0;

    // Get number of values from user
    printf("Enter the number of values (up to 100): ");
    scanf("%d", &num_values);

    // Get values from user
    printf("Enter %d integers:\n", num_values);
    for (int i = 0; i < num_values; i++) {
        scanf("%d", &values[i]);

        // Update max value
        if (values[i] > max_value) {
            max_value = values[i];
        }
    }

    // Generate random coins
    int num_coins = rand() % (max_value + 1);
    int coins[MAX_NUMBERS];
    for (int i = 0; i < num_coins; i++) {
        coins[i] = rand() % max_value + 1;
    }

    // Sort coins in descending order
    for (int i = 0; i < num_coins - 1; i++) {
        for (int j = i + 1; j < num_coins; j++) {
            if (coins[i] < coins[j]) {
                int temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }

    // Initialize variables for greedy algorithm
    int sum = 0;
    int num_used_coins = 0;
    int last_used_coin = 0;

    // Use greedy algorithm to make change
    for (int i = 0; i < num_values; i++) {
        if (values[i] <= sum) {
            sum += values[i];
        } else {
            int max_coin = 0;
            for (int j = 0; j < num_coins; j++) {
                if (coins[j] <= sum + values[i] && coins[j] > max_coin) {
                    max_coin = coins[j];
                }
            }
            sum += max_coin;
            num_used_coins++;
            last_used_coin = max_coin;
        }
    }

    printf("Minimum number of coins required: %d\n", num_used_coins);

    return 0;
}