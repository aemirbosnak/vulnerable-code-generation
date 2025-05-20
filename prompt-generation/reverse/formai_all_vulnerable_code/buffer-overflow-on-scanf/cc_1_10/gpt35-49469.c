//FormAI DATASET v1.0 Category: Matrix operations ; Style: surprised
#include<stdio.h>

// Define the size of the Matrix
#define SIZE 3

// Function to print the Matrix
void printMatrix(int matrix[SIZE][SIZE]) {
    printf("The Matrix is:\n");
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[SIZE][SIZE];
    
    // Get input from user to fill the Matrix
    printf("Please enter %d elements for the Matrix:\n", SIZE*SIZE);
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Print the Matrix
    printMatrix(matrix);
    
    // Compute the sum of all elements in the Matrix
    int sum=0;
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            sum += matrix[i][j];
        }
    }
    printf("\nThe sum of all elements in the Matrix is %d\n", sum);
    
    // Compute the product of the diagonal elements in the Matrix
    int product=1;
    for(int i=0; i<SIZE; i++) {
        product *= matrix[i][i];
    }
    printf("\nThe product of the diagonal elements in the Matrix is %d\n", product);
    
    // Compute the transpose of the Matrix
    int transpose[SIZE][SIZE];
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
    printf("\nThe transpose of the Matrix is:\n");
    printMatrix(transpose);
    
    // Compute the inverse of the Matrix
    int determinant=0;
    for (int i = 0; i < SIZE; i++)
        determinant = determinant + (matrix[0][i] * (matrix[1][(i+1)%SIZE] * matrix[2][(i+2)%SIZE] - matrix[1][(i+2)%SIZE] * matrix[2][(i+1)%SIZE]));
    printf("\nThe determinant of the Matrix is %d\n", determinant);
    
    // Check if the Matrix is invertible
    if(determinant == 0) {
        printf("\nThe Matrix is not invertible\n");
    }
    else {
        printf("\nThe inverse of the Matrix is:\n");
        float inverse[SIZE][SIZE];
        for(int i=0; i<SIZE; i++) {
            for(int j=0; j<SIZE; j++) {
                inverse[i][j] = ((matrix[(j+1)%SIZE][(i+1)%SIZE] * matrix[(j+2)%SIZE][(i+2)%SIZE]) - (matrix[(j+1)%SIZE][(i+2)%SIZE] * matrix[(j+2)%SIZE][(i+1)%SIZE])) / determinant;
                printf("%.2f ", inverse[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}