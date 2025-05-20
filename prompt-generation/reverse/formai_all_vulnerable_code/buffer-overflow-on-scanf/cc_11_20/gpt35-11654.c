//FormAI DATASET v1.0 Category: Matrix operations ; Style: artistic
#include <stdio.h>

/* Artistic C program that performs matrix operations */
int main() {
    int row, col;
    printf("Enter the number of rows and columns for the matrix: ");
    scanf("%d %d", &row, &col);

    int matrix[row][col], transpose[col][row];

    // Populating the matrix
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            matrix[i][j] = i*j + 1;
        }
    }

    printf("\nThe original matrix is:\n");
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Transposing the matrix
    for(int i=0; i<col; i++) {
        for(int j=0; j<row; j++) {
            transpose[i][j] = matrix[j][i];
        }
    }

    printf("\nThe transposed matrix is:\n");
    for(int i=0; i<col; i++) {
        for(int j=0; j<row; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    // Finding the sum of diagonal elements of the original matrix
    int sum = 0;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(i == j) {
                sum += matrix[i][j];
            }
        }
    }

    printf("\nThe sum of diagonal elements of the original matrix is: %d\n", sum);

    // Ending the program in an artistic way
    printf("\n*******************************************\n");
    printf("*                                           *\n");
    printf("*       Matrix operations performed         *\n");
    printf("*                                           *\n");
    printf("*******************************************\n");
    printf("   _____  __  _______    ______              \n");
    printf("  / ___/ / / / / ___/   / ____/  __  __      \n");
    printf("  \\__ \\ / /_/ /\\__ \\   / __/ | |/_/ / /_____\n");
    printf(" ___/ // __  /___/ /  / /____>  <  / / /_/ /\n");
    printf("/____//_/ /_//____/  /_____/_/|_|/_/\\____/ \n");

    return 0;
}