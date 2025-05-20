//FormAI DATASET v1.0 Category: Matrix operations ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>

#define MAX_ROW 50
#define MAX_COL 50

void read_matrix(int a[][MAX_COL], int r, int c){
    int i,j;
    printf("Enter the matrix elements:\n");
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            scanf("%d",&a[i][j]);
        }
    }
}

void display_matrix(int a[][MAX_COL], int r, int c){
    int i,j;
    printf("The matrix is:\n");
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(int a[][MAX_COL], int b[][MAX_COL], int c[][MAX_COL], int r, int c2){
    int i,j;
    for(i=0; i<r; i++){
        for(j=0; j<c2; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiply_matrices(int a[][MAX_COL], int b[][MAX_COL], int c[][MAX_COL], int r1, int c1, int c2){
    int i,j,k;
    for(i=0; i<r1; i++){
        for(j=0; j<c2; j++){
            c[i][j] = 0;
            for(k=0; k<c1; k++){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
}

int main(){
    int a[MAX_ROW][MAX_COL], b[MAX_ROW][MAX_COL], c[MAX_ROW][MAX_COL];
    int r1,r2,c1,c2;
    printf("Enter the number of rows and columns of first matrix:\n");
    scanf("%d %d",&r1,&c1);
    printf("Enter the number of rows and columns of second matrix:\n");
    scanf("%d %d",&r2,&c2);
    if(c1 != r2){
        printf("Matrix multiplication is not possible.\n");
        exit(0);
    }
    read_matrix(a, r1, c1);
    read_matrix(b, r2, c2);
    display_matrix(a, r1, c1);
    display_matrix(b, r2, c2);
    add_matrices(a, b, c, r1, c1);
    printf("The sum of matrices is:\n");
    display_matrix(c, r1, c1);
    multiply_matrices(a, b, c, r1, c1, c2);
    printf("The product of matrices is:\n");
    display_matrix(c, r1, c2);
    return 0;
}