//FormAI DATASET v1.0 Category: Matrix operations ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

/* Function to read matrix elements */
void readMatrix(int M[][100], int row, int col) {
    int i,j;
    
    for(i=0;i<row;i++) {
        for(j=0;j<col;j++) {
            printf("Enter element [%d][%d]: ",i,j);
            scanf("%d",&M[i][j]);
        }
    }
    
    printf("\nMatrix read successfully!\n");
}

/* Function to display matrix elements */
void displayMatrix(int M[][100], int row, int col) {
    int i,j;
    
    for(i=0;i<row;i++) {
        for(j=0;j<col;j++) {
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }
}

/* Function to add two matrices */
void addMatrices(int M1[][100], int M2[][100], int M3[][100], int row, int col) {
    int i,j;
    
    for(i=0;i<row;i++) {
        for(j=0;j<col;j++) {
            M3[i][j] = M1[i][j] + M2[i][j];
        }
    }
}

/* Function to find transpose of a matrix */
void transposeMatrix(int M1[][100], int M2[][100], int row, int col) {
    int i,j;
    
    for(i=0;i<row;i++) {
        for(j=0;j<col;j++) {
            M2[j][i] = M1[i][j];
        }
    }
}

int main() {
    int M1[100][100], M2[100][100], M3[100][100];
    int row, col, choice;
    
    printf("Enter number of rows and columns of matrices: ");
    scanf("%d %d", &row, &col);
    
    printf("\nSelect an operation to perform:\n");
    printf("1. Read matrices\n");
    printf("2. Display matrices\n");
    printf("3. Add matrices\n");
    printf("4. Find transpose of a matrix\n");
    printf("0. Exit\n\n");
    
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: // Read matrices
                printf("\nEnter elements of first matrix:\n");
                readMatrix(M1, row, col);
                printf("\nEnter elements of second matrix:\n");
                readMatrix(M2, row, col);
                break;
            case 2: // Display matrices
                printf("\nFirst matrix:\n");
                displayMatrix(M1, row, col);
                printf("\nSecond matrix:\n");
                displayMatrix(M2, row, col);
                break;
            case 3: // Add matrices
                addMatrices(M1, M2, M3, row, col);
                printf("\nResultant matrix:\n");
                displayMatrix(M3, row, col);
                break;
            case 4: // Find transpose of a matrix
                printf("\nEnter elements of the matrix:\n");
                readMatrix(M1, row, col);
                transposeMatrix(M1, M2, row, col);
                printf("\nTranspose of the matrix:\n");
                displayMatrix(M2, col, row);
                break;
            case 0:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n\n");
                break;
        }
        
    } while(choice != 0);
    
    return 0;
}