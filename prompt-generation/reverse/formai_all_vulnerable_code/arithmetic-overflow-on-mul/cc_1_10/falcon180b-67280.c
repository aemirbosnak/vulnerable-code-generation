//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main() {
    int size, i, j, k, l, choice;
    int *matrix1, *matrix2, *result;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the size of the matrices: ");
    scanf("%d", &size);

    matrix1 = (int *)malloc(size * size * sizeof(int));
    matrix2 = (int *)malloc(size * size * sizeof(int));
    result = (int *)malloc(size * size * sizeof(int));

    printf("Enter the elements of first matrix:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%d", &matrix1[i * size + j]);
        }
    }

    printf("Enter the elements of second matrix:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%d", &matrix2[i * size + j]);
        }
    }

    start = clock();
    for (k = 0; k < size; k++) {
        for (l = 0; l < size; l++) {
            result[k * size + l] = matrix1[k * size + l] + matrix2[k * size + l];
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nResult:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", result[i * size + j]);
        }
        printf("\n");
    }

    printf("Time taken: %.4lf seconds\n", cpu_time_used);

    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}