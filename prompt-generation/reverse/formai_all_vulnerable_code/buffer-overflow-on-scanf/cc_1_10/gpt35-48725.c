//FormAI DATASET v1.0 Category: Matrix operations ; Style: creative
#include <stdio.h>

//function to display the matrix
void displayMatrix(int a[][5], int r, int c){
    printf("\nMatrix:\n");
    for(int i=0; i<r;i++){
        for(int j=0; j<c;j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

//function to add matrices
void addMatrix(int a[][5], int b[][5], int r, int c){
    int sum[5][5];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            sum[i][j]=a[i][j]+b[i][j];
        }
    }
    displayMatrix(sum,r,c);
}

//function to subtract matrices
void subtractMatrix(int a[][5], int b[][5], int r, int c){
    int diff[5][5];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            diff[i][j]=a[i][j]-b[i][j];
        }
    }
    displayMatrix(diff,r,c);
}

//function to multiply matrices
void multiplyMatrix(int a[][5], int b[][5], int r1, int c1, int c2){
    int prod[5][5];
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            prod[i][j]=0;
            for(int k=0;k<c1;k++){
                prod[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    displayMatrix(prod,r1,c2);
}

int main(){
    int a[5][5], b[5][5], r1, c1, r2, c2;
    
    printf("Enter the number of rows and columns for Matrix1: ");
    scanf("%d%d",&r1, &c1);
    
    printf("\nEnter the elements of Matrix1:\n");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            scanf("%d",&a[i][j]);
        }
    }
    displayMatrix(a,r1,c1);
    
    printf("\nEnter the number of rows and columns for Matrix2: ");
    scanf("%d%d",&r2, &c2);
    
    printf("\nEnter the elements of Matrix2:\n");
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            scanf("%d",&b[i][j]);
        }
    }
    displayMatrix(b,r2,c2);
    
    //check if matrices are compatible for adding or subtracting
    if(r1==r2 && c1==c2){
        printf("\nSum of the matrices: ");
        addMatrix(a,b,r1,c1);
        printf("\nDifference of the matrices: ");
        subtractMatrix(a,b,r1,c1);
    }
    else{
        printf("\nMatrices cannot be added or subtracted.\n");
    }
    
    //check if matrices are compatible for multiplying
    if(c1==r2){
        printf("\nProduct of the matrices: ");
        multiplyMatrix(a,b,r1,c1,c2);
    }
    else{
        printf("\nMatrices cannot be multiplied.\n");
    }
    
    return 0;
}