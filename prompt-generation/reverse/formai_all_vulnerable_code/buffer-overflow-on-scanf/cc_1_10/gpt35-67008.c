//FormAI DATASET v1.0 Category: Sudoku solver ; Style: introspective
#include<stdio.h>

int findEmpty(int **matrix,int *x,int *y,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                *x=i;
                *y=j;
                return 1;
            }
        }
    }
    return 0;
}

int isSafe(int **matrix,int num,int row,int col,int n){
    for(int i=0;i<n;i++){
        if(matrix[row][i]==num||matrix[i][col]==num){
            return 0;
        }
    }
    int a=row-row%3,b=col-col%3;
    for(int i=a;i<a+3;i++){
        for(int j=b;j<b+3;j++){
            if(matrix[i][j]==num){
               return 0; 
            }
        }
    }
    return 1;
}

int sudokuSolver(int **matrix,int n){
    int row,column;
    if(!findEmpty(matrix,&row,&column,n)){
        return 1;
    }
    for(int i=1;i<=n;i++){
        if(isSafe(matrix,i,row,column,n)){
            matrix[row][column]=i;
            if(sudokuSolver(matrix,n)){
                return 1;
            }
            matrix[row][column]=0;
        }
    }
    return 0;
}

int main(){
    int n;
    printf("Enter the value of n:");
    scanf("%d",&n);
    int **matrix=(int**)calloc(n,sizeof(int*));
    for(int i=0;i<n;i++){
        matrix[i]=(int*)calloc(n,sizeof(int));
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    if(sudokuSolver(matrix,n)){
        printf("Solution Exists\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%d ",matrix[i][j]);
            }
            printf("\n");
        }
    }
    else{
        printf("Solution doesn't exist\n");
    }
}