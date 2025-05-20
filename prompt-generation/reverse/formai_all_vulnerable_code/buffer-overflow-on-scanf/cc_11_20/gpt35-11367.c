//FormAI DATASET v1.0 Category: Matrix operations ; Style: scientific
#include<stdio.h>

int main(){

int arr1[100][100], arr2[100][100], result[100][100];
int rows1,columns1,rows2,columns2;

printf("Enter the number of rows for matrix1: ");
scanf("%d",&rows1);
printf("Enter the number of columns for matrix1: ");
scanf("%d",&columns1);

printf("\nEnter the elements of first matrix:\n");

for(int i=0;i<rows1;i++){
    for(int j=0;j<columns1;j++){
        scanf("%d",&arr1[i][j]);
    }
}

printf("\nEnter the number of rows for matrix2: ");
scanf("%d",&rows2);
printf("Enter the number of columns for matrix2: ");
scanf("%d",&columns2);

if(columns1!=rows2) printf("\nMatrix multiplication not possible!\n");
else{

    printf("\nEnter the elements of second matrix:\n");

    for(int i=0;i<rows2;i++){
        for(int j=0;j<columns2;j++){
            scanf("%d",&arr2[i][j]);
        }
    }

    for(int i=0;i<rows1;i++){
        for(int j=0;j<columns2;j++){
            result[i][j]=0;
            for(int k=0;k<columns1;k++){
                result[i][j]=result[i][j]+arr1[i][k]*arr2[k][j];
            }
        }
    }

    printf("\nThe resultant matrix is:\n");

    for(int i=0;i<rows1;i++){
        for(int j=0;j<columns2;j++){
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }

}

return 0;
}