//FormAI DATASET v1.0 Category: Matrix operations ; Style: grateful
#include <stdio.h>

int main() {
    printf("Hello there! I'm so grateful you're trying out my C Matrix Operations program.\n");

    // Initializing the matrices
    int matrix1[3][3];
    int matrix2[3][3];

    // Reading the values for matrix 1
    printf("Please enter the values for Matrix 1.\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Reading the values for matrix 2
    printf("Please enter the values for Matrix 2.\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Add the two matrices
    printf("Matrix 1 + Matrix 2 =\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", matrix1[i][j] + matrix2[i][j]);
        }
        printf("\n");
    }

    // Subtract the two matrices
    printf("Matrix 1 - Matrix 2 =\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", matrix1[i][j] - matrix2[i][j]);
        }
        printf("\n");
    }

    // Multiply the two matrices
    printf("Matrix 1 * Matrix 2 =\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            int sum = 0;
            for(int k = 0; k < 3; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            printf("%d ", sum);
        }
        printf("\n");
    }

    printf("Thank you for using my program! Have a great day.\n");

    return 0;
}