//Falcon-180B DATASET v1.0 Category: Sorting ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size;
    int i, j, temp;
    int (*compare)(int, int);

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter 1 for ascending order, 2 for descending order: ");
    scanf("%d", &compare);

    srand(time(NULL));
    for (i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    printf("Original array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    if (compare == 1) {
        for (i = 0; i < size - 1; i++) {
            for (j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    } else if (compare == 2) {
        for (i = 0; i < size - 1; i++) {
            for (j = 0; j < size - i - 1; j++) {
                if (arr[j] < arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    printf("Sorted array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}