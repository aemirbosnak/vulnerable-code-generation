//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int num_arrays, i, j, k;
    int *arr;
    int size, sum, diff, prod;

    if (argc < 3) {
        printf("Usage: %s <number_of_arrays> <size_of_each_array>\n", argv[0]);
        return 1;
    }

    sscanf(argv[1], "%d", &num_arrays);
    sscanf(argv[2], "%d", &size);

    arr = (int *)calloc(num_arrays * size, sizeof(int));
    if (arr == NULL) {
        perror("Calloc Failed");
        return 1;
    }

    for (i = 0; i < num_arrays; i++) {
        printf("Enter elements for array %d:\n", i + 1);
        for (j = 0; j < size; j++) {
            scanf("%d", &arr[i * size + j]);
        }
    }

    printf("\nArray Elements:\n");
    for (i = 0; i < num_arrays; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", arr[i * size + j]);
        }
        printf("\n");
    }

    printf("\nSum of corresponding elements:\n");
    for (i = 0; i < num_arrays; i++) {
        sum = 0;
        for (j = 0; j < size; j++) {
            sum += arr[i * size + j];
        }
        printf("Array %d: Sum = %d\n", i + 1, sum);
    }

    printf("\nDifference between first and second elements of each array:\n");
    for (i = 0; i < num_arrays; i++) {
        if (i == 0) {
            diff = arr[i * size] - arr[(i + 1) * size];
        } else {
            diff = arr[i * size] - arr[(i - 1) * size];
        }
        printf("Array %d: Difference = %d\n", i + 1, diff);
    }

    printf("\nProduct of first and last elements of each array:\n");
    for (i = 0; i < num_arrays; i++) {
        prod = arr[i * size] * arr[(i * size) + (size - 1)];
        printf("Array %d: Product = %d\n", i + 1, prod);
    }

    free(arr);

    return 0;
}