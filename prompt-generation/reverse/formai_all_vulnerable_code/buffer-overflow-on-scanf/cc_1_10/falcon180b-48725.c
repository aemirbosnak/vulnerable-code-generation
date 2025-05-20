//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

void init_array(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selection_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array (<= %d): ", MAX_SIZE);
    scanf("%d", &size);

    init_array(arr, size);
    printf("Unsorted array:\n");
    print_array(arr, size);

    selection_sort(arr, size);
    printf("Sorted array:\n");
    print_array(arr, size);

    return 0;
}