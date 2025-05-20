//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

typedef struct {
    int value;
    int index;
} Item;

void swap(Item* a, Item* b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void* a, const void* b) {
    const Item* itemA = a;
    const Item* itemB = b;

    if (itemA->value > itemB->value) {
        return 1;
    } else if (itemA->value < itemB->value) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    int n, i;
    int* arr = NULL;
    Item* items = NULL;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    items = (Item*)malloc(n * sizeof(Item));
    if (items == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    for (i = 0; i < n; i++) {
        items[i].value = arr[i];
        items[i].index = i;
    }

    qsort(items, n, sizeof(Item), compare);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", items[i].value);
    }

    free(arr);
    free(items);

    return 0;
}