//Falcon-180B DATASET v1.0 Category: System administration ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000000
#define MAX_ITERATIONS 1000

int main() {
    int size = 0;
    int iterations = 0;
    int *array = NULL;
    int *array2 = NULL;
    int sum = 0;
    int i, j, k;
    double avg = 0.0;
    double start_time, end_time, elapsed_time;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid size of array.\n");
        return 1;
    }

    array = (int *)malloc(sizeof(int) * size);
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the elements of the array: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);

    if (iterations <= 0 || iterations > MAX_ITERATIONS) {
        printf("Invalid number of iterations.\n");
        free(array);
        return 1;
    }

    array2 = (int *)malloc(sizeof(int) * size);
    if (array2 == NULL) {
        printf("Memory allocation failed.\n");
        free(array);
        return 1;
    }

    start_time = clock();
    for (i = 0; i < iterations; i++) {
        for (j = 0; j < size; j++) {
            array2[j] = array[j] * array[j];
        }
        for (k = 0; k < size; k++) {
            sum += array2[k];
        }
    }
    end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    avg = (double)sum / (double)iterations;

    printf("The average of the squares of the elements in the array is: %.2lf\n", avg);
    printf("The elapsed time is: %.2lf seconds\n", elapsed_time);

    free(array);
    free(array2);

    return 0;
}