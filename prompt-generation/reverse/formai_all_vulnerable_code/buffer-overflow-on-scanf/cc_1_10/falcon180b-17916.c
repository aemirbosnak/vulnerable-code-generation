//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000
#define PI 3.14159265358979323846
#define E 2.71828182845904523536

int main() {
    int n;
    double x, y, z, sum;
    int i;
    double *arr;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    arr = (double*) malloc(n * sizeof(double));

    if (arr == NULL) {
        printf("Memory could not be allocated.\n");
        exit(1);
    }

    printf("Enter the elements of the array:\n");

    for (i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    start = clock();

    for (i = 0; i < n; i++) {
        x = arr[i];
        y = sqrt(x);
        z = pow(x, 2);
        sum = y + z;
        printf("The square root of %lf is %lf and the sum of the square and the square root is %lf\n", x, y, sum);
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken by the program: %lf seconds\n", cpu_time_used);

    free(arr);
    return 0;
}