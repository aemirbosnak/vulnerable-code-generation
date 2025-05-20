//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_ARRAY_SIZE 1000000

int main() {
    int n;
    double *array;
    double sum = 0;
    double average;
    clock_t start_time, end_time;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n > MAX_ARRAY_SIZE) {
        printf("Array size too large.\n");
        return 1;
    }

    array = (double *) malloc(n * sizeof(double));

    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &array[i]);
        sum += array[i];
    }

    start_time = clock();
    for (int i = 0; i < n; i++) {
        array[i] = pow(array[i], 2);
    }
    end_time = clock();

    average = (double) (end_time - start_time) / CLOCKS_PER_SEC;

    printf("The average time taken to calculate the square of each element is %.2f seconds.\n", average);

    start_time = clock();
    for (int i = 0; i < n; i++) {
        sum += array[i];
    }
    end_time = clock();

    average = (double) (end_time - start_time) / CLOCKS_PER_SEC;

    printf("The average time taken to calculate the sum of the array is %.2f seconds.\n", average);

    printf("The sum of the array is %.2lf.\n", sum);

    free(array);
    return 0;
}