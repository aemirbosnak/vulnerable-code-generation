//FormAI DATASET v1.0 Category: Educational ; Style: expert-level
#include <stdio.h>

// Function to multiply two matrices
void matrixMultiplication(int a[10][10], int b[10][10], int c[10][10], int m, int n, int p) {
    // Loop through rows of matrix A
    for(int i=0; i<m; i++) {
        // Loop through columns of matrix B
        for(int j=0; j<p; j++) {
            // Initialize the value of the current element in C to 0
            c[i][j] = 0;
      
            // Loop through rows and columns of A and B respectively
            for(int k=0; k<n; k++) {
                // Add the product of corresponding elements of A and B to the current element of C
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Function to print a matrix
void printMatrix(int mat[10][10], int m, int n) {
    printf("Matrix:\n");
  
    // Loop through rows of the matrix
    for(int i=0; i<m; i++) {
        // Loop through columns of the matrix
        for(int j=0; j<n; j++) {
            printf("%d\t", mat[i][j]); // Print the current element of the matrix
        }
        printf("\n"); // Move to the next row
    }
}

// Main function
int main() {
    int m, n, p;
    
    printf("Enter the number of rows of matrix A: ");
    scanf("%d", &m);
  
    printf("Enter the number of columns of matrix A: ");
    scanf("%d", &n);
  
    int a[10][10];
  
    printf("Enter the elements of matrix A:\n");
  
    // Loop through rows of matrix A
    for(int i=0; i<m; i++) {
        // Loop through columns of matrix A
        for(int j=0; j<n; j++) {
            scanf("%d", &a[i][j]); // Read the value of the current element
        }
    }
  
    printf("Enter the number of columns of matrix B: ");
    scanf("%d", &p);
    
    int b[10][10];
  
    printf("Enter the elements of matrix B:\n");
  
    // Loop through rows of matrix B
    for(int i=0; i<n; i++) {
        // Loop through columns of matrix B
        for(int j=0; j<p; j++) {
            scanf("%d", &b[i][j]); // Read the value of the current element
        }
    }
  
    int c[10][10];
    
    matrixMultiplication(a, b, c, m, n, p); // Call the function to perform matrix multiplication
  
    printMatrix(a, m, n); // Print the matrix A
    printMatrix(b, n, p); // Print the matrix B
    printMatrix(c, m, p); // Print the result of multiplication
    
    return 0;
}