//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int index;
    int value;
    int position;
} Item;

void swap(Item* a, Item* b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

int compare(Item* a, Item* b) {
    return a->value - b->value;
}

void printArray(Item* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i].value);
    }
    printf("\n");
}

void greedyAlgorithm(Item* arr, int n) {
    int knapsackCapacity = 50;
    int currentCapacity = 0;
    int i = 0;

    while (i < n && currentCapacity < knapsackCapacity) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].value > arr[maxIndex].value) {
                maxIndex = j;
            }
        }

        if (arr[maxIndex].value <= knapsackCapacity - currentCapacity) {
            swap(&arr[i], &arr[maxIndex]);
            currentCapacity += arr[i].value;
            i++;
        } else {
            i++;
        }
    }

    printf("Selected items:\n");
    for (int j = 0; j < i; j++) {
        printf("%d ", arr[j].value);
    }
    printf("\nTotal value: %d\n", currentCapacity);
}

int main() {
    Item arr[MAX_SIZE];
    int n = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter item values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
        arr[i].index = i;
        arr[i].position = i;
    }

    qsort(arr, n, sizeof(Item), compare);

    greedyAlgorithm(arr, n);

    return 0;
}