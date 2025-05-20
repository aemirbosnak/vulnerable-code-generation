//FormAI DATASET v1.0 Category: Matrix operations ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void matrix_addition(int a[][MAX], int b[][MAX], int c[][MAX], int n, int m){
    int i, j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void matrix_subtraction(int a[][MAX], int b[][MAX], int c[][MAX], int n, int m){
    int i, j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

void matrix_multiplication(int a[][MAX], int b[][MAX], int c[][MAX], int n, int m, int p){
    int i, j, k;
    for(i=0;i<n;i++){
        for(j=0;j<p;j++){
            c[i][j] = 0;
            for(k=0;k<m;k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void display_matrix(int mat[][MAX], int n, int m){
    int i, j;
    printf("\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n1, m1, n2, m2, i, j;
    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];

    printf("Enter the number of rows and columns of matrix A: ");
    scanf("%d %d",&n1, &m1);

    printf("Enter the elements of matrix A: \n");
    for(i=0;i<n1;i++){
        for(j=0;j<m1;j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter the number of rows and columns of matrix B: ");
    scanf("%d %d",&n2, &m2);

    printf("Enter the elements of matrix B: \n");
    for(i=0;i<n2;i++){
        for(j=0;j<m2;j++){
            scanf("%d",&b[i][j]);
        }
    }

    if(n1!=n2 || m1!=m2){
        printf("\nERROR: The matrices cannot be added/subtracted\n");
    }
    else{
        printf("Matrix A + Matrix B: \n");
        matrix_addition(a, b, c, n1, m1);
        display_matrix(c, n1, m1);

        printf("Matrix A - Matrix B: \n");
        matrix_subtraction(a, b, c, n1, m1);
        display_matrix(c, n1, m1);
    }

    if(m1!=n2){
        printf("\nERROR: The matrices cannot be multiplied\n");
    }
    else{
        printf("Matrix A x Matrix B: \n");
        matrix_multiplication(a, b, c, n1, m1, m2);
        display_matrix(c, n1, m2);
    }

    return 0;
}