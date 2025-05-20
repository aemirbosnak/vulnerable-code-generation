//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000

int main() {
    int size;
    double *array1, *array2, *result;
    double sum = 0.0, product = 1.0;
    time_t start_time, end_time;
    double elapsed_time;

    printf("Enter the size of the arrays (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);

    array1 = (double *) malloc(size * sizeof(double));
    array2 = (double *) malloc(size * sizeof(double));
    result = (double *) malloc(size * sizeof(double));

    if (array1 == NULL || array2 == NULL || result == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter elements of array1:\n");
    for (int i = 0; i < size; i++) {
        scanf("%lf", &array1[i]);
    }

    printf("Enter elements of array2:\n");
    for (int i = 0; i < size; i++) {
        scanf("%lf", &array2[i]);
    }

    time(&start_time);
    for (int i = 0; i < size; i++) {
        result[i] = array1[i] + array2[i];
        sum += result[i];
        product *= result[i];
    }
    time(&end_time);
    elapsed_time = difftime(end_time, start_time);

    printf("The sum of the elements in the result array is: %lf\n", sum);
    printf("The product of the elements in the result array is: %lf\n", product);
    printf("The elapsed time for the computation is: %lf seconds\n", elapsed_time);

    free(array1);
    free(array2);
    free(result);

    return 0;
}