//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define MAX_NUM_COINS 500

typedef struct {
    int value;
    char name[MAX_LENGTH];
} Coin;

int main() {
    int num_coins, i, j, max_value = 0, value;
    char input[MAX_LENGTH];
    Coin coins[MAX_NUM_COINS];

    // Read in the number of coins
    printf("Enter the number of coins: ");
    scanf("%d", &num_coins);

    // Read in the names and values of the coins
    for (i = 0; i < num_coins; i++) {
        printf("Enter the name and value of coin %d (separated by a space): ", i + 1);
        scanf("%s %d", input, &value);
        strcpy(coins[i].name, input);
        coins[i].value = value;

        if (value > max_value) {
            max_value = value;
        }
    }

    // Initialize the array to store the maximum value for each amount
    int max_values[max_value + 1];
    for (i = 0; i <= max_value; i++) {
        max_values[i] = 0;
    }

    // Calculate the maximum value for each amount
    for (i = 0; i < num_coins; i++) {
        for (j = coins[i].value; j <= max_value; j++) {
            if (j - coins[i].value < max_values[j]) {
                max_values[j] = j - coins[i].value;
            }
        }
    }

    // Print the maximum value and the coins used to achieve it for each amount
    printf("\n");
    for (i = 0; i <= max_value; i++) {
        if (max_values[i] > 0) {
            printf("The maximum value for %d cents is %d cents using the following coins:\n", i, i + max_values[i]);
            for (j = 0; j < num_coins; j++) {
                if (coins[j].value == max_values[i]) {
                    printf("%s\n", coins[j].name);
                }
            }
        }
    }

    return 0;
}