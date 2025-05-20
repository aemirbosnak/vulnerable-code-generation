//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_coins, target_value;
    printf("Enter the number of coins: ");
    scanf("%d", &num_coins);

    int coins[num_coins];

    printf("Enter the values of the coins: ");
    for(int i = 0; i < num_coins; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter the target value: ");
    scanf("%d", &target_value);

    int num_used_coins[num_coins];

    for(int i = 0; i < num_coins; i++) {
        num_used_coins[i] = 0;
    }

    int current_value = 0;
    int i = 0;

    while(current_value != target_value) {
        if(current_value + coins[i] <= target_value) {
            current_value += coins[i];
            num_used_coins[i]++;
        }
        else {
            i++;
        }

        if(i == num_coins) {
            i = 0;
        }
    }

    printf("Target value achieved with minimum coins:\n");
    int total_num_coins_used = 0;

    for(int i = 0; i < num_coins; i++) {
        if(num_used_coins[i] > 0){
            printf("%d coin(s) of value %d\n", num_used_coins[i], coins[i]);
            total_num_coins_used += num_used_coins[i];
        }
    }

    printf("\nTotal number of coins used: %d", total_num_coins_used);

    return 0;
}