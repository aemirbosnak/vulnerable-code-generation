//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COINS 100
#define MAX_VALUES 100

int main() {
    int num_coins, i, j, max_value;
    int coins[MAX_COINS];
    int values[MAX_VALUES];

    printf("Welcome to the Greedy Algorithm Coin Collector!\n");
    printf("How many coins do you want to collect? ");
    scanf("%d", &num_coins);

    // Initialize coins with random values
    srand(time(NULL));
    for (i = 0; i < num_coins; i++) {
        coins[i] = rand() % 100;
    }

    // Sort coins in descending order
    for (i = 0; i < num_coins - 1; i++) {
        for (j = i + 1; j < num_coins; j++) {
            if (coins[i] < coins[j]) {
                int temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }

    printf("\nThe coins are:\n");
    for (i = 0; i < num_coins; i++) {
        printf("%d ", coins[i]);
    }
    printf("\n");

    // Initialize values with 0
    for (i = 0; i < num_coins; i++) {
        values[i] = 0;
    }

    // Greedily collect coins
    max_value = 0;
    for (i = 0; i < num_coins; i++) {
        if (coins[i] > max_value) {
            max_value = coins[i];
        }
    }

    printf("\nThe maximum value you can collect is %d.\n", max_value);

    return 0;
}