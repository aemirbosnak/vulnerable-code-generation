//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int main() {
    int rows, cols;
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
    int i, j, k;
    int choice;
    int flag = 0;

    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter elements of matrix A:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    srand(time(NULL));
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            C[i][j] = rand() % 10;
        }
    }

    printf("Enter the operation you want to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    C[i][j] = A[i][j] + B[i][j];
                }
            }
            break;
        case 2:
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    C[i][j] = A[i][j] - B[i][j];
                }
            }
            break;
        case 3:
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    C[i][j] = A[i][j] * B[i][j];
                }
            }
            break;
        default:
            printf("Invalid choice!\n");
            exit(0);
    }

    printf("Result:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}