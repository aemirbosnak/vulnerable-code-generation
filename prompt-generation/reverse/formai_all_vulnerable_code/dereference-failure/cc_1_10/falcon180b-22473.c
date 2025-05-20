//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int value;
    int index;
} Item;

void swap(Item* a, Item* b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Item arr[], int low, int high, int pivotIndex) {
    Item pivot = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[high]);
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].value <= pivot.value) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(Item arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = rand() % (high - low + 1) + low;
        int pivotPosition = partition(arr, low, high, pivotIndex);
        quickSort(arr, low, pivotPosition - 1);
        quickSort(arr, pivotPosition + 1, high);
    }
}

int main() {
    srand(time(NULL));
    Item arr[MAX_SIZE];
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the items (value index):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].value, &arr[i].index);
    }
    quickSort(arr, 0, n - 1);
    printf("Sorted items:\n");
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", arr[i].value, arr[i].index);
    }
    return 0;
}