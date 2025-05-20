//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 1000
#define MAX_VALUES 1000
#define MAX_ITEMS 1000

int main() {
    int numCoins, numValues, numItems;
    int coins[MAX_COINS];
    int values[MAX_VALUES];
    int items[MAX_ITEMS];
    int i, j;

    printf("Enter number of coins: ");
    scanf("%d", &numCoins);

    printf("Enter number of values: ");
    scanf("%d", &numValues);

    printf("Enter number of items: ");
    scanf("%d", &numItems);

    printf("Enter coins: ");
    for (i = 0; i < numCoins; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter values: ");
    for (i = 0; i < numValues; i++) {
        scanf("%d", &values[i]);
    }

    printf("Enter items: ");
    for (i = 0; i < numItems; i++) {
        scanf("%d", &items[i]);
    }

    int maxValue = 0;
    for (i = 0; i < numValues; i++) {
        if (values[i] > maxValue) {
            maxValue = values[i];
        }
    }

    int maxItems = numItems;

    int bag[MAX_ITEMS];
    int bagSize = 0;
    int bagValue = 0;

    for (i = 0; i < numItems; i++) {
        for (j = 0; j < numValues; j++) {
            if (items[i] == values[j]) {
                if (bagSize == 0 || bagValue + values[j] <= maxValue) {
                    bag[bagSize++] = values[j];
                    bagValue += values[j];
                }
            }
        }
    }

    if (bagSize == 0) {
        printf("No items fit in the bag.\n");
    } else {
        printf("Items in the bag:\n");
        for (i = 0; i < bagSize; i++) {
            printf("%d ", bag[i]);
        }
        printf("\nBag value: %d\n", bagValue);
    }

    return 0;
}