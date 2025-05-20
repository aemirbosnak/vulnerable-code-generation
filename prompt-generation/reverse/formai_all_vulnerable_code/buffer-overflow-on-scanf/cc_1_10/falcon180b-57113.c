//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_COINS 1000

int main() {
    int num_coins[MAX_NUM_COINS];
    int num_coins_used;
    int num_coins_left;
    int num_coins_total;
    int num_coins_left_copy;
    int i;

    // Initialize the array of coin values
    num_coins[0] = 1;
    num_coins[1] = 2;
    num_coins[2] = 5;
    num_coins[3] = 10;
    num_coins[4] = 20;

    // Prompt the user for the total amount to be changed
    printf("Enter the total amount to be changed: ");
    scanf("%d", &num_coins_total);

    // Initialize the number of coins used to 0
    num_coins_used = 0;

    // Initialize the number of coins left to num_coins_total
    num_coins_left = num_coins_total;

    // Initialize a copy of num_coins_left
    num_coins_left_copy = num_coins_left;

    // Loop until num_coins_left is 0
    while (num_coins_left > 0) {
        // Find the smallest coin value that can be used
        for (i = 0; i < num_coins_left_copy; i++) {
            if (num_coins[i] <= num_coins_left) {
                num_coins_used += num_coins[i];
                num_coins_left -= num_coins[i];
                break;
            }
        }

        // If num_coins_left is still greater than 0,
        // update num_coins_left_copy to num_coins_left
        if (num_coins_left > 0) {
            num_coins_left_copy = num_coins_left;
        }
    }

    // Print the number of coins used
    printf("The minimum number of coins needed is: %d\n", num_coins_used);

    return 0;
}