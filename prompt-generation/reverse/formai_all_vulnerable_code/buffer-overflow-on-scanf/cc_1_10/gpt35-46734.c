//FormAI DATASET v1.0 Category: Matrix operations ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 3

void matrix_input(int mat[N][N]) {
    printf("Enter the elements of matrix(%d x %d):", N, N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &mat[i][j]);
}

void matrix_display(int mat[N][N]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void matrix_add(int mat1[N][N], int mat2[N][N], int result[N][N]) {
    printf("Adding two matrices...\n");
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            result[i][j] = mat1[i][j] + mat2[i][j];
}

void matrix_subtract(int mat1[N][N], int mat2[N][N], int result[N][N]) {
    printf("Subtracting two matrices...\n");
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            result[i][j] = mat1[i][j] - mat2[i][j];
}

void matrix_multiply(int mat1[N][N], int mat2[N][N], int result[N][N]) {
    printf("Multiplying two matrices...\n");
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++) {
            result[i][j] = 0;
            for(int k=0; k<N; k++)
                result[i][j] += mat1[i][k] * mat2[k][j];
        }
}

void matrix_transpose(int mat[N][N], int result[N][N]) {
    printf("Finding transpose of matrix...\n");
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            result[i][j] = mat[j][i];
}

int main() {
    int mat1[N][N], mat2[N][N], result[N][N];
    int choice, flag=1;
    
    srand(time(NULL));
    printf("\n*** Welcome to Matrix Operations Program! ***\n\n");
    
    printf("Enter the elements of first matrix:\n");
    matrix_input(mat1);
    
    printf("\nEnter the elements of second matrix:\n");
    matrix_input(mat2);
    
    while(flag) {
        printf("\nPlease select an option:\n");
        printf("1. Display matrices\n");
        printf("2. Add two matrices\n");
        printf("3. Subtract two matrices\n");
        printf("4. Multiply two matrices\n");
        printf("5. Transpose of a matrix\n");
        printf("6. Exit\n");
        printf("> ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("First matrix: \n");
                matrix_display(mat1);
                printf("Second matrix: \n");
                matrix_display(mat2);
                break;
            case 2:
                matrix_add(mat1, mat2, result);
                printf("Resultant matrix: \n");
                matrix_display(result);
                break;
            case 3:
                matrix_subtract(mat1, mat2, result);
                printf("Resultant matrix: \n");
                matrix_display(result);
                break;
            case 4:
                matrix_multiply(mat1, mat2, result);
                printf("Resultant matrix: \n");
                matrix_display(result);
                break;
            case 5:
                matrix_transpose(mat1, result);
                printf("Transpose of first matrix: \n");
                matrix_display(result);
                matrix_transpose(mat2, result);
                printf("Transpose of second matrix: \n");
                matrix_display(result);
                break;
            case 6:
                printf("\nThank you for using Matrix Operations Program! Exiting...\n");
                flag = 0;
                break;
            default:
                printf("\nInvalid option selected! Please try again.\n");
        }
    }
    return 0;
}