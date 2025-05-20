//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: multivariable
#include <stdio.h>
#define ROWS 5
#define COLS 3

void bubbleSort(int arr[][COLS], int rowSize);
void printArray(int arr[][COLS], int rowSize);

int main() {
    int arr[ROWS][COLS];

    printf("Enter %d rows x %d columns matrix elements:\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    bubbleSort(arr, ROWS);
    printf("\nSorted matrix:\n");
    printArray(arr, ROWS);

    return 0;
}

void bubbleSort(int arr[][COLS], int rowSize) {
    for (int i = 0; i < rowSize - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < rowSize; j++) {
            if (rowSum(arr, i) > rowSum(arr, j)) {
                minIndex = j;
            }
        }

        int temp[COLS];
        for (int k = 0; k < COLS; k++) {
            temp[k] = arr[i][k];
            arr[i][k] = arr[minIndex][k];
            arr[minIndex][k] = temp[k];
        }
    }
}

void printArray(int arr[][COLS], int rowSize) {
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int rowSum(int arr[][COLS], int index) {
    int sum = 0;
    for (int i = 0; i < COLS; i++) {
        sum += arr[index][i];
    }
    return sum;
}