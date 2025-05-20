//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to read QR code
void readQR(int arr[MAX_SIZE][MAX_SIZE], int row, int col, int size) {
    // Base case
    if (size == 1) {
        printf("QR code is: %d\n", arr[row][col]);
        return;
    }

    // Recursive case
    int newSize = size / 2;
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            int sum = 0;
            for (int k = 0; k < newSize; k++) {
                sum += arr[row + i * newSize][col + j * newSize + k];
            }
            if (sum % 2 == 0) {
                arr[row + i * newSize][col + j * newSize] = 0;
            } else {
                arr[row + i * newSize][col + j * newSize] = 1;
            }
        }
    }
    readQR(arr, row, col, newSize);
}

// Function to initialize QR code
void initQR(int arr[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr[i][j] = -1;
        }
    }
}

// Function to print QR code
void printQR(int arr[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i][j] == 0) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }
}

int main() {
    int size;
    printf("Enter the size of QR code: ");
    scanf("%d", &size);

    int arr[MAX_SIZE][MAX_SIZE];
    initQR(arr, size);

    int row, col;
    printf("Enter the starting position of QR code: ");
    scanf("%d %d", &row, &col);

    readQR(arr, row, col, size);

    printf("\nQR code:\n");
    printQR(arr, size);

    return 0;
}