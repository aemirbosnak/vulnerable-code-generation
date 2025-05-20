//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_COINS 1000
#define MAX_VALUE 1000

int coins[MAX_NUM_COINS];
int num_coins;

int make_change(int value) {
    int i;
    int num_coins_used = 0;
    for (i = 0; i < num_coins; i++) {
        if (value >= coins[i]) {
            value -= coins[i];
            num_coins_used++;
        }
    }
    if (value == 0) {
        return num_coins_used;
    } else {
        return -1;
    }
}

void greedy_algorithm(int values[], int num_values, int num_coins) {
    int i;
    int num_coins_used = 0;
    for (i = 0; i < num_values; i++) {
        int j = 0;
        while (j < num_coins && coins[j] <= values[i]) {
            j++;
        }
        if (j < num_coins) {
            coins[num_coins_used++] = coins[j];
        }
    }
}

int main() {
    int num_values;
    scanf("%d", &num_values);
    int values[num_values];
    for (int i = 0; i < num_values; i++) {
        scanf("%d", &values[i]);
    }
    scanf("%d", &num_coins);
    int coins_values[num_coins];
    for (int i = 0; i < num_coins; i++) {
        scanf("%d", &coins_values[i]);
    }
    greedy_algorithm(values, num_values, num_coins);
    printf("Number of coins used: %d\n", make_change(values[0]));
    return 0;
}