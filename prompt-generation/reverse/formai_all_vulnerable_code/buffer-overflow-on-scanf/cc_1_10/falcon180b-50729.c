//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 100
#define MAX_VALUES 100

int values[MAX_VALUES] = {1, 5, 10, 25};
int coins[MAX_COINS] = {1, 5, 10, 25};

void print_coins(int coins[], int n) {
    printf("Coins: ");
    for(int i=0; i<n; i++) {
        printf("%d ", coins[i]);
    }
    printf("\n");
}

void print_values(int values[], int n) {
    printf("Values: ");
    for(int i=0; i<n; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
}

void find_max_value(int values[], int n, int coins[], int m) {
    int max_value = 0;
    int max_coin = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(values[i] <= coins[j]) {
                if(coins[j] > max_value) {
                    max_value = coins[j];
                    max_coin = j;
                }
            }
        }
    }
    printf("Max value: %d\n", max_value);
    printf("Coins used: ");
    for(int i=0; i<m; i++) {
        if(i == max_coin) {
            printf("%d ", coins[i]);
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

int main() {
    int num_values, num_coins;
    printf("Enter number of values: ");
    scanf("%d", &num_values);
    printf("Enter number of coins: ");
    scanf("%d", &num_coins);

    for(int i=0; i<num_values; i++) {
        printf("Enter value %d: ", i+1);
        scanf("%d", &values[i]);
    }

    for(int i=0; i<num_coins; i++) {
        printf("Enter coin %d: ", i+1);
        scanf("%d", &coins[i]);
    }

    find_max_value(values, num_values, coins, num_coins);

    return 0;
}