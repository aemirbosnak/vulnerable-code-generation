//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

// Function to find the minimum number of coins
void find_minimum_coins(int coin_values[], int n, int amount) 
{
    int i, j, k; 
    int coin_count[MAX_N];
    int coin_used[MAX_N][MAX_N];
    int best_amount[MAX_N];

    // Initialize arrays
    for (i = 0; i <= amount; i++) {
        coin_count[i] = 0;
        best_amount[i] = 0;
    }
    
    // Find minimum coins needed for each amount up to the given amount
    for (i = 1; i <= amount; i++) {
        int min_count = i, new_coin_value = 1;
        
        for (j = 0; j < n; j++) {
            if (coin_values[j] > i) {
                continue;
            }
            
            if (coin_count[i - coin_values[j]] + 1 < min_count) {
                min_count = coin_count[i - coin_values[j]] + 1;
                new_coin_value = coin_values[j];
            }
        }
        
        coin_count[i] = min_count;
        best_amount[i] = new_coin_value;

        for (k = 0; k < i; k++) {
            coin_used[i][k] = coin_used[i - new_coin_value][k];
        }
        for (k = 0; k < n; k++) {
            if (coin_values[k] == new_coin_value) {
                coin_used[i][k]++;
                break;
            }
        }
    }

    // Print the results
    printf("Minimum number of coins to get to amount %d: %d\n", amount, coin_count[amount]);
    printf("Coins used:\n");
    for (i = 0; i < n; i++) {
        printf("%d: %d\n", coin_values[i], coin_used[amount][i]);
    }
}

int main() 
{
    int n, amount, i;
    int coin_values[MAX_N];

    printf("Enter the number of coins: ");
    scanf("%d", &n);

    printf("Enter the coin values:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &coin_values[i]);
    }

    printf("Enter the amount: ");
    scanf("%d", &amount);

    find_minimum_coins(coin_values, n, amount);

    return 0;
}