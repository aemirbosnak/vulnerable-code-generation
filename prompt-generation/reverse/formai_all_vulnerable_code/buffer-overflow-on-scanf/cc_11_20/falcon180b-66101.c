//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

int main() {
    int n;
    double *arr;
    int i, j;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    arr = (double *) malloc(n * sizeof(double));

    if (arr == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    printf("The elements of the array are:\n");
    for (i = 0; i < n; i++) {
        printf("%lf\n", arr[i]);
    }

    printf("\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                printf("%lf ", 1.0);
            } else {
                printf("%lf ", 0.0);
            }
        }
        printf("\n");
    }

    printf("\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                printf("%lf ", arr[i]);
            } else {
                printf("%lf ", 0.0);
            }
        }
        printf("\n");
    }

    printf("\n");

    double sum = 0.0;
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }

    printf("The sum of the elements of the array is: %lf\n", sum);

    free(arr);

    return 0;
}