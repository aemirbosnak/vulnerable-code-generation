//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COINS 1000

typedef struct {
    int value;
    int index;
} Coin;

void bubble_sort(Coin coins[], int n);

int main(int argc, char *argv[]) {
    int n, i, j;
    Coin coins[MAX_COINS];
    char input[100];
    int value;

    printf("Enter the number of coins: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the value of coin %d: ", i + 1);
        scanf("%d", &value);
        coins[i].value = value;
        coins[i].index = i;
    }

    bubble_sort(coins, n);

    printf("Sorted coins by value:\n");
    for (i = 0; i < n; i++) {
        printf("%d - %d\n", coins[i].value, coins[i].index + 1);
    }

    return 0;
}

void bubble_sort(Coin coins[], int n) {
    int i, j, temp_index;
    Coin temp_coin;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (coins[j].value > coins[j + 1].value) {
                temp_index = coins[j].index;
                coins[j].index = coins[j + 1].index;
                coins[j + 1].index = temp_index;

                temp_coin = coins[j];
                coins[j] = coins[j + 1];
                coins[j + 1] = temp_coin;
            }
        }
    }
}