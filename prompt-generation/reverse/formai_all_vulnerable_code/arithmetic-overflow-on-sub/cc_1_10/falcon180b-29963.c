//Falcon-180B DATASET v1.0 Category: Sorting ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} Item;

void swap(Item array[], int i, int j) {
    int temp = array[i].data;
    array[i].data = array[j].data;
    array[j].data = temp;

    temp = array[i].index;
    array[i].index = array[j].index;
    array[j].index = temp;
}

int partition(Item array[], int low, int high) {
    int pivot = array[high].data;
    array[high].index = high;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (array[j].data < pivot) {
            i++;
            swap(array, i, j);
        }
    }
    swap(array, i + 1, high);
    return (i + 1);
}

void quicksort(Item array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);

        quicksort(array, low, pi - 1);
        quicksort(array, pi + 1, high);
    }
}

void printArray(Item array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i].data);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Item array[MAX_SIZE];

    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        array[i].data = rand() % 100;
        array[i].index = i;
    }

    printf("Before Sorting:\n");
    printArray(array, n);

    quicksort(array, 0, n - 1);

    printf("After Sorting:\n");
    printArray(array, n);

    return 0;
}