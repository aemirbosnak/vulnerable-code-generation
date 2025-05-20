//LLAMA2-13B DATASET v1.0 Category: Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, m, i, j, k;
    double x, y, z, w;
    double *arr1, *arr2, *arr3;

    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n);

    arr1 = (double*) malloc(n * sizeof(double));
    for (i = 0; i < n; i++) {
        printf("Enter element %d of the first array: ", i + 1);
        scanf("%lf", &arr1[i]);
    }

    printf("Enter the number of elements in the second array: ");
    scanf("%d", &m);

    arr2 = (double*) malloc(m * sizeof(double));
    for (j = 0; j < m; j++) {
        printf("Enter element %d of the second array: ", j + 1);
        scanf("%lf", &arr2[j]);
    }

    printf("Enter the number of elements in the third array: ");
    scanf("%d", &k);

    arr3 = (double*) malloc(k * sizeof(double));
    for (i = 0; i < k; i++) {
        printf("Enter element %d of the third array: ", i + 1);
        scanf("%lf", &arr3[i]);
    }

    // Multiply the arrays element-wise
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            for (k = 0; k < k; k++) {
                x = arr1[i] * arr2[j] * arr3[k];
                y = arr1[i] * arr3[k] * arr2[j];
                z = arr2[j] * arr3[k] * arr1[i];
                w = arr1[i] * arr2[j] * arr3[k] + arr2[j] * arr3[k] * arr1[i];

                arr3[k] = x + y + z + w;
            }
        }
    }

    // Print the results
    for (i = 0; i < k; i++) {
        printf("%.2lf ", arr3[i]);
    }
    printf("\n");

    return 0;
}