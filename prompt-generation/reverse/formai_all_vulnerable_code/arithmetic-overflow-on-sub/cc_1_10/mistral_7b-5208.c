//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void secure_sort(int arr[], int size) {
    int i, j, temp;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int arr[MAX_SIZE];
    int size, i;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    if (size > MAX_SIZE) {
        printf("Array size is too large. Maximum size is %d.\n", MAX_SIZE);
        return 1;
    }

    printf("Enter %d integers: ", size);

    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    secure_sort(arr, size);

    printf("\nSorted array: ");

    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}