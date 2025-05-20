//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

#define MAX 10

void create_matrix(int mat[MAX][MAX], int n);
void print_matrix(int mat[MAX][MAX], int n);
void add_matrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int n);
void subtract_matrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int n);
void multiply_matrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int n);

int main() {
    int n, choice;
    printf("Enter the size of the matrices: ");
    scanf("%d", &n);

    int mat1[MAX][MAX], mat2[MAX][MAX], res[MAX][MAX];

    printf("Enter the elements of the first matrix:\n");
    create_matrix(mat1, n);

    printf("Enter the elements of the second matrix:\n");
    create_matrix(mat2, n);

    printf("Enter your choice:\n");
    printf("1. Add matrices\n");
    printf("2. Subtract matrices\n");
    printf("3. Multiply matrices\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            add_matrices(mat1, mat2, res, n);
            printf("The sum of matrices is:\n");
            print_matrix(res, n);
            break;

        case 2:
            subtract_matrices(mat1, mat2, res, n);
            printf("The difference of matrices is:\n");
            print_matrix(res, n);
            break;

        case 3:
            multiply_matrices(mat1, mat2, res, n);
            printf("The product of matrices is:\n");
            print_matrix(res, n);
            break;

        default:
            printf("Invalid choice!");
            break;
    }

    return 0;
}

void create_matrix(int mat[MAX][MAX], int n) {
    printf("Enter the elements of the matrix:\n");

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void print_matrix(int mat[MAX][MAX], int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtract_matrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            res[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiply_matrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            res[i][j] = 0;
            for(int k=0; k<n; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}