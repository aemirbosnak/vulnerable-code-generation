//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size;

    srand(time(NULL));
    size = rand() % MAX_SIZE + 1;

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    printf("Array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    printf("Sum of array elements: %d\n", sum);

    int product = 1;
    for (int i = 0; i < size; i++) {
        product *= arr[i];
    }

    printf("Product of array elements: %d\n", product);

    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    printf("Max element: %d\n", max);
    printf("Min element: %d\n", min);

    return 0;
}