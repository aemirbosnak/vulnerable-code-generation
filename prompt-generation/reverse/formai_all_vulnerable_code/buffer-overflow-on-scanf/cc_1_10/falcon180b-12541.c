//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Function to generate QR code
void generateQRCode(char* data, int size) {
    // Initialize QR code matrix
    int matrixSize = size * size;
    int** matrix = (int**)malloc(sizeof(int*) * matrixSize);
    for (int i = 0; i < matrixSize; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * matrixSize);
        memset(matrix[i], 0, sizeof(int) * matrixSize);
    }

    // Fill QR code matrix with data
    int dataIndex = 0;
    int matrixIndex = (size - 1) / 2;
    while (dataIndex < strlen(data)) {
        if (data[dataIndex] == '\n') {
            matrixIndex++;
        } else if (isdigit(data[dataIndex])) {
            int value = data[dataIndex] - '0';
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    if ((matrixIndex + i - (size - 1) / 2) % 2 == 0 && (j + matrixIndex - (size - 1) / 2) % 2 == 0) {
                        matrix[i][j] = value;
                    }
                }
            }
            matrixIndex++;
        } else {
            printf("Invalid character found in data: %c\n", data[dataIndex]);
            exit(1);
        }
        dataIndex++;
    }

    // Print QR code matrix
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free QR code matrix memory
    for (int i = 0; i < matrixSize; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Main function
int main() {
    srand(time(NULL));

    // Prompt user for data to be encoded in QR code
    char data[1000];
    printf("Enter data to be encoded in QR code:\n");
    fgets(data, sizeof(data), stdin);

    // Prompt user for QR code size
    int size;
    do {
        printf("Enter QR code size (between 1 and 40):\n");
        scanf("%d", &size);
    } while (size < 1 || size > 40);

    // Generate QR code
    generateQRCode(data, size);

    return 0;
}