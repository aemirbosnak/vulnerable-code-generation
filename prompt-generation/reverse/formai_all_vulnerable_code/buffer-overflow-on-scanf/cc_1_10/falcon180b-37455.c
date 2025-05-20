//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COINS 100
#define MAX_VALUES 100

typedef struct {
    int value;
    int index;
} Coin;

Coin coins[MAX_COINS];
int num_coins;

int get_value(int index) {
    return coins[index].value;
}

void add_coin(int value) {
    if (num_coins >= MAX_COINS) {
        printf("Too many coins!\n");
        exit(1);
    }
    coins[num_coins].value = value;
    coins[num_coins].index = num_coins;
    num_coins++;
}

void sort_coins() {
    int i, j;
    Coin temp;
    for (i = 0; i < num_coins - 1; i++) {
        for (j = i + 1; j < num_coins; j++) {
            if (get_value(i) > get_value(j)) {
                temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }
}

int main() {
    int i, n, target, sum = 0;
    char input[MAX_VALUES];

    printf("Enter the number of coins: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the value of coin %d: ", i + 1);
        scanf("%d", &coins[i].value);
        add_coin(coins[i].value);
    }

    sort_coins();

    printf("Enter the target amount: ");
    scanf("%d", &target);

    for (i = num_coins - 1; i >= 0 && sum < target; i--) {
        if (sum + get_value(i) <= target) {
            sum += get_value(i);
        }
    }

    if (sum == target) {
        printf("Minimum number of coins: %d\n", num_coins);
        for (i = 0; i < num_coins; i++) {
            printf("%d ", get_value(i));
        }
        printf("\n");
    } else {
        printf("Target amount not achievable\n");
    }

    return 0;
}