//FormAI DATASET v1.0 Category: Matrix operations ; Style: excited
#include <stdio.h>

int main() {
    printf("Welcome to the Matrix Operations program!\n");
    printf("This is the ultimate tool to perform any matrix operation in the world!\n");
    
    int row, col;
    printf("Please enter the number of rows in your matrix: ");
    scanf("%d", &row);
    printf("Please enter the number of columns in your matrix: ");
    scanf("%d", &col);

    int matrix[row][col];
    printf("Great! Let's start by populating your matrix.\n");
    printf("Please enter %d elements, row by row, separated by a space:\n", row*col);
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int choice;
    printf("\nWhat operation would you like to perform on your matrix?\n");
    printf("1. Transpose\n");
    printf("2. Determinant\n");
    printf("3. Inverse\n");
    printf("4. Scalar multiplication\n");
    printf("5. Addition\n");
    printf("6. Subtraction\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nYou chose transpose! Here's your matrix:\n");
            for(int i=0; i<col; i++) {
                for(int j=0; j<row; j++) {
                    printf("%d ", matrix[j][i]);
                }
                printf("\n");
            }
            break;
        
        case 2:
            if(row==col) {
                printf("\nYou chose determinant! Here's your matrix:\n");
                for(int i=0; i<row; i++) {
                    for(int j=0; j<col; j++) {
                        printf("%d ", matrix[i][j]);
                    }
                    printf("\n");
                }
                printf("Determinant: %d", determinant(matrix, row));
            } else {
                printf("\nError! Determinant can only be calculated for square matrices.\n");
            }
            break;

        case 3:
            if(row==col) {
                printf("\nYou chose inverse! Here's your matrix:\n");
                for(int i=0; i<row; i++) {
                    for(int j=0; j<col; j++) {
                        printf("%d ", matrix[i][j]);
                    }
                    printf("\n");
                }
                float inverse[row][col];
                if(inverseMatrix(matrix, row, inverse)) {
                    printf("Inverse:\n");
                    for(int i=0; i<row; i++) {
                        for(int j=0; j<col; j++) {
                            printf("%.2f ", inverse[i][j]);
                        }
                        printf("\n");
                    }
                } else {
                    printf("The matrix is singular and cannot be inverted.\n");
                }
            } else {
                printf("\nError! Inverse can only be calculated for square matrices.\n");
            }
            break;
        
        case 4:
            printf("\nYou chose scalar multiplication! Enter a scalar value: ");
            int scalar;
            scanf("%d", &scalar);
            printf("Here's your original matrix:\n");
            for(int i=0; i<row; i++) {
                for(int j=0; j<col; j++) {
                    printf("%d ", matrix[i][j]);
                }
                printf("\n");
            }
            printf("And here's your new matrix after multiplication:\n");
            for(int i=0; i<row; i++) {
                for(int j=0; j<col; j++) {
                    printf("%d ", scalar*matrix[i][j]);
                }
                printf("\n");
            }
            break;

        case 5:
            {
            printf("\nYou chose addition! Please enter the second matrix:\n");
            int matrix2[row][col];
            for(int i=0; i<row; i++) {
                for(int j=0; j<col; j++) {
                    scanf("%d", &matrix2[i][j]);
                }
            }
            printf("Here's your first matrix:\n");
            for(int i=0; i<row; i++) {
                for(int j=0; j<col; j++) {
                    printf("%d ", matrix[i][j]);
                }
                printf("\n");
            }
            printf("Here's your second matrix:\n");
            for(int i=0; i<row; i++) {
                for(int j=0; j<col; j++) {
                    printf("%d ", matrix2[i][j]);
                }
                printf("\n");
            }
            printf("And here's the sum of the two matrices:\n");
            for(int i=0; i<row; i++) {
                for(int j=0; j<col; j++) {
                    printf("%d ", matrix[i][j] + matrix2[i][j]);
                }
                printf("\n");
            }
            }
            break;

        case 6:
            {
            printf("\nYou chose subtraction! Please enter the second matrix:\n");
            int matrix2[row][col];
            for(int i=0; i<row; i++) {
                for(int j=0; j<col; j++) {
                    scanf("%d", &matrix2[i][j]);
                }
            }
            printf("Here's your first matrix:\n");
            for(int i=0; i<row; i++) {
                for(int j=0; j<col; j++) {
                    printf("%d ", matrix[i][j]);
                }
                printf("\n");
            }
            printf("Here's your second matrix:\n");
            for(int i=0; i<row; i++) {
                for(int j=0; j<col; j++) {
                    printf("%d ", matrix2[i][j]);
                }
                printf("\n");
            }
            printf("And here's the difference between the two matrices:\n");
            for(int i=0; i<row; i++) {
                for(int j=0; j<col; j++) {
                    printf("%d ", matrix[i][j] - matrix2[i][j]);
                }
                printf("\n");
            }
            }
            break;

        default:
            printf("\nError! Invalid choice.\n");
    }

    printf("Thanks for using the Matrix Operations program! Hope to see you soon!\n");

    return 0;
}

int determinant(int matrix[][100], int n) {
    int det=0;
    int subMatrix[100][100];
    if(n==1) {
        return matrix[0][0];
    } else if(n==2) {
        return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
    } else {
        for(int x=0; x<n; x++) {
            int subMatrix_i=0, subMatrix_j=0;
            for(int i=1; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(j==x) {
                        continue;
                    } else {
                        subMatrix[subMatrix_i][subMatrix_j] = matrix[i][j];
                        subMatrix_j++;
                        if(subMatrix_j == n-1) {
                            subMatrix_j = 0;
                            subMatrix_i++;
                        }
                    }
                }
            }
            det = det + (matrix[0][x] * pow(-1, x) * determinant(subMatrix, n-1));
        }
    }
    return det;
}

int inverseMatrix(int matrix[][100], int n, float inverse[][100]) {
    int subMatrix[100][100];
    int subMatrix_i, subMatrix_j;
    int subMatrixSize = n-1;
    float det = determinant(matrix, n);
    if(det==0) {
        return 0;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            subMatrix_i = 0;
            subMatrix_j = 0;
            for(int r=0; r<n; r++) {
                for(int c=0; c<n; c++) {
                    if(r==i || c==j) {
                        continue;
                    } else {
                        subMatrix[subMatrix_i][subMatrix_j] = matrix[r][c];
                        subMatrix_j++;
                        if(subMatrix_j == subMatrixSize) {
                            subMatrix_j = 0;
                            subMatrix_i++;
                        }
                    }
                }
            }
            inverse[i][j] = pow(-1, i+j) * determinant(subMatrix, subMatrixSize) / det;
        }
    }
    return 1;
}