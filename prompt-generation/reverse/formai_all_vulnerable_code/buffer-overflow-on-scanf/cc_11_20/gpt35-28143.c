//FormAI DATASET v1.0 Category: Matrix operations ; Style: cheerful
#include <stdio.h>

int main() {
    // Cheerful Matrix Operations Example Program!

    printf("Welcome to the Matrix Operations Program!\n");
    printf("We will create, populate, and perform operations on matrices.\n");
    printf("Let's get started!\n\n");

    // Create a 3x3 matrix
    int matrix[3][3];

    printf("Please enter values for the matrix:\n");

    // Populate matrix
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Great! Here is the matrix you just created:\n\n");

    // Display matrix
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nNow let's perform some operations on the matrix:\n");

    // Transpose matrix
    printf("\nTransposing the matrix...\n\n");

    int transpose[3][3];

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            transpose[i][j] = matrix[j][i];
        }
    }

    // Display transposed matrix
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    // Add matrix with itself
    printf("\nAdding the matrix with itself...\n\n");

    int added[3][3];

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            added[i][j] = matrix[i][j] + matrix[i][j];
        }
    }

    // Display added matrix
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", added[i][j]);
        }
        printf("\n");
    }

    // Multiply matrix with its transpose
    printf("\nMultiplying the matrix with its transpose...\n\n");

    int multiplied[3][3];

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            multiplied[i][j] = 0;
            for(int k = 0; k < 3; k++) {
                multiplied[i][j] += matrix[i][k] * transpose[k][j];
            }
        }
    }

    // Display multiplied matrix
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", multiplied[i][j]);
        }
        printf("\n");
    }

    printf("\nCongratulations! You have successfully completed the Matrix Operations Program!\n");

    return 0;
}