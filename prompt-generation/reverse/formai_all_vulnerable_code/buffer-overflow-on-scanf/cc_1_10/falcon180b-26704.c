//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int val;
    int pos;
} Item;

int compare(const void* a, const void* b) {
    Item* itemA = (Item*)a;
    Item* itemB = (Item*)b;
    if (itemA->val > itemB->val) {
        return 1;
    } else if (itemA->val < itemB->val) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    int n, i, j;
    Item items[MAX_SIZE];
    int bagCapacity = 50;
    int bagValue = 0;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the value and position of item %d: ", i+1);
        scanf("%d %d", &items[i].val, &items[i].pos);
    }

    qsort(items, n, sizeof(Item), compare);

    for (i = 0, j = n-1; i < n && bagValue < bagCapacity; i++) {
        if (bagValue + items[i].val <= bagCapacity) {
            bagValue += items[i].val;
            printf("Item %d added to bag (value = %d, position = %d)\n", i+1, items[i].val, items[i].pos);
        } else {
            for (j--; j >= 0 && items[j].val > items[i].val; j--) {
                items[j].pos = items[j-1].pos;
                items[j].val = items[j-1].val;
            }
            items[j].pos = i;
            items[j].val = items[i].val;
            printf("Item %d removed from bag (value = %d, position = %d)\n", i+1, items[i].val, items[i].pos);
            i--;
        }
    }

    printf("Maximum bag value = %d\n", bagValue);

    return 0;
}