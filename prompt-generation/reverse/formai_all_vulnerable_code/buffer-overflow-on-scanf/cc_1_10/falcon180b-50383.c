//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 5
#define MAX_ITEMS 5
#define MAX_VALUE 10

int main() {
    int num_items, i, j, max_value = 0;
    int coins[MAX_COINS], num_coins, value[MAX_ITEMS];

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    for (i = 0; i < num_items; i++) {
        printf("Enter the value of item %d: ", i+1);
        scanf("%d", &value[i]);
        if (value[i] > max_value) {
            max_value = value[i];
        }
    }

    printf("Enter the number of coins: ");
    scanf("%d", &num_coins);

    for (i = 0; i < num_coins; i++) {
        printf("Enter the value of coin %d: ", i+1);
        scanf("%d", &coins[i]);
    }

    printf("\nItem\tValue\n");
    for (i = 0; i < num_items; i++) {
        printf("%d\t%d\n", i+1, value[i]);
    }

    printf("\nCoin\tValue\n");
    for (i = 0; i < num_coins; i++) {
        printf("%d\t%d\n", i+1, coins[i]);
    }

    printf("\n");

    for (i = 0; i < num_items; i++) {
        for (j = 0; j < num_coins; j++) {
            if (value[i] <= coins[j]) {
                printf("Item %d can be bought with coin %d\n", i+1, j+1);
            }
        }
    }

    return 0;
}