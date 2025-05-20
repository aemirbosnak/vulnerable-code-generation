//Falcon-180B DATASET v1.0 Category: Recursive ; Style: visionary
#include <stdio.h>

#define N 5

// Function to print the matrix
void printMatrix(int arr[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Function to fill the matrix with random numbers
void fillMatrix(int arr[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            arr[i][j] = rand() % 100;
        }
    }
}

// Function to find the sum of all elements in the matrix
int sumMatrix(int arr[N][N]) {
    int i, j, sum = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

// Recursive function to calculate the determinant of a matrix
int determinant(int arr[N][N], int n) {
    if (n == 1) {
        return arr[0][0];
    } else if (n == 2) {
        return arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
    } else {
        int det = 0;
        for (int i = 0; i < n; i++) {
            det += arr[0][i] * determinant(arr, n - 1);
        }
        return det;
    }
}

int main() {
    int arr[N][N];
    fillMatrix(arr);
    printf("Matrix:\n");
    printMatrix(arr);
    printf("Sum of all elements: %d\n", sumMatrix(arr));
    printf("Determinant: %d\n", determinant(arr, N));
    return 0;
}