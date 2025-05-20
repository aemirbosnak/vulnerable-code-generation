//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct {
    int row;
    int col;
    int value;
} MatrixElement;

void swap(MatrixElement *a, MatrixElement *b) {
    MatrixElement temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(MatrixElement arr[], int size, int rootIndex) {
    int maxIndex = rootIndex;
    int leftChild = 2 * rootIndex + 1;
    int rightChild = 2 * rootIndex + 2;

    if (leftChild < size && arr[leftChild].value > arr[maxIndex].value) {
        maxIndex = leftChild;
    }

    if (rightChild < size && arr[rightChild].value > arr[maxIndex].value) {
        maxIndex = rightChild;
    }

    if (maxIndex != rootIndex) {
        swap(&arr[rootIndex], &arr[maxIndex]);
        heapify(arr, size, maxIndex);
    }
}

void heapSort(MatrixElement arr[], int size) {
    int i;

    for (i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    for (i = size - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void printMatrix(MatrixElement arr[], int rowSize, int colSize) {
    int i, j;

    for (i = 0; i < rowSize; i++) {
        for (j = 0; j < colSize; j++) {
            printf("%3d ", arr[i * colSize + j].value);
        }
        printf("\n");
    }
}

int main() {
    MatrixElement matrix[MAX_SIZE][MAX_SIZE];
    int rowSize = 3, colSize = 4;
    int i, j;

    printf("Enter elements of the matrix:\n");

    for (i = 0; i < rowSize; i++) {
        for (j = 0; j < colSize; j++) {
            scanf("%d", &matrix[i][j].value);
            matrix[i][j].row = i;
            matrix[i][j].col = j;
        }
    }

    heapSort(matrix, rowSize * colSize);

    printf("\nSorted Matrix:\n");
    printMatrix(matrix, rowSize, colSize);

    return 0;
}