//FormAI DATASET v1.0 Category: Matrix operations ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>

int main() {

    int n, m;
    printf("Enter number of rows and columns: ");
    scanf("%d%d", &n, &m);
    int **arr1, **arr2, **add, **transpose; // Declaring pointers for dynamic memory allocation

    // Dynamically allocating memory for 2D arrays
    arr1 = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        arr1[i] = (int *)malloc(m * sizeof(int));
    }

    arr2 = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        arr2[i] = (int *)malloc(m * sizeof(int));
    }

    add = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        add[i] = (int *)malloc(m * sizeof(int));
    }

    transpose = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        transpose[i] = (int *)malloc(n * sizeof(int));
    }

    // Reading values for first matrix
    printf("Enter values for first matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }

    // Reading values for second matrix
    printf("Enter values for second matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }

    // Matrix addition
    printf("Addition of matrices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            add[i][j] = arr1[i][j] + arr2[i][j];
            printf("%d ", add[i][j]);
        }
        printf("\n");
    }

    // Matrix transpose
    printf("Transpose of first matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            transpose[i][j] = arr1[j][i];
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    // Freeing dynamically allocated memory
    for (int i = 0; i < n; i++) {
        free(arr1[i]);
        free(arr2[i]);
        free(add[i]);
    }
    for (int i = 0; i < m; i++) {
        free(transpose[i]);
    }
    free(arr1);
    free(arr2);
    free(add);
    free(transpose);

    return 0;
}