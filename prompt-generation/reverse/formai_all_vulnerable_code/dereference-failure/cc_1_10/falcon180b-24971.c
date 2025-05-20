//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

int main() {
    int size;
    int *arr;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Memory could not be allocated.\n");
        exit(1);
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    int product = 1;
    int max = arr[0];
    int min = arr[0];
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
        sum += arr[i];
        product *= arr[i];
    }

    printf("Sum of the array: %d\n", sum);
    printf("Product of the array: %d\n", product);
    printf("Maximum element in the array: %d\n", max);
    printf("Minimum element in the array: %d\n", min);
    printf("Average of the array: %f\n", (float)sum / size);

    free(arr);

    return 0;
}