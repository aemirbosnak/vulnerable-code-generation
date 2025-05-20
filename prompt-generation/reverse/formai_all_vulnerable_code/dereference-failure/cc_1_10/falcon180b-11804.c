//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int rand_int(unsigned int min, unsigned int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL));

    int arr_size = rand_int(1, 100);
    int *arr = (int *)malloc(arr_size * sizeof(int));

    for (int i = 0; i < arr_size; i++) {
        arr[i] = rand_int(1, 1000);
    }

    printf("Original array:\n");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int sum = 0;
    for (int i = 0; i < arr_size; i++) {
        sum += arr[i];
    }

    printf("Sum of array elements: %d\n", sum);

    int product = 1;
    for (int i = 0; i < arr_size; i++) {
        product *= arr[i];
    }

    printf("Product of array elements: %d\n", product);

    int min = arr[0];
    for (int i = 1; i < arr_size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    printf("Minimum element in array: %d\n", min);

    int max = arr[0];
    for (int i = 1; i < arr_size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Maximum element in array: %d\n", max);

    int avg = sum / arr_size;
    printf("Average of array elements: %.2f\n", (float)avg / arr_size);

    free(arr);
    return 0;
}