//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 6
#define MAX_VALUES 6
#define MAX_ITEMS 6

int main() {
    int coins[MAX_COINS] = {1, 2, 5, 10, 20, 50};
    int values[MAX_VALUES] = {1, 5, 10, 25, 50, 100};
    int items[MAX_ITEMS] = {1, 2, 5, 10, 20, 50};
    int nCoins, nValues, nItems;
    int i, j, k, maxValue, value, change;

    printf("Enter the number of coins available: ");
    scanf("%d", &nCoins);
    printf("Enter the number of values to be calculated: ");
    scanf("%d", &nValues);
    printf("Enter the number of items to be bought: ");
    scanf("%d", &nItems);

    maxValue = 0;
    for (i = 0; i < nValues; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &values[i]);
        if (values[i] > maxValue) {
            maxValue = values[i];
        }
    }

    for (i = 0; i < nItems; i++) {
        printf("Enter item %d: ", i + 1);
        scanf("%d", &items[i]);
    }

    for (i = 0; i < nValues; i++) {
        printf("Value %d: ", i + 1);
        value = values[i];
        for (j = 0; j < nCoins; j++) {
            if (coins[j] <= value) {
                change = value - coins[j];
                if (change == 0) {
                    printf("Using %d cent coin\n", coins[j]);
                    break;
                } else if (change < 0) {
                    continue;
                }
            }
        }
        if (j == nCoins) {
            printf("Not possible\n");
        }
    }

    return 0;
}