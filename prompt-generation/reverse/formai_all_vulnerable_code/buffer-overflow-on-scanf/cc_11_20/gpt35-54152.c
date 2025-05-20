//FormAI DATASET v1.0 Category: Matrix operations ; Style: energetic
#include<stdio.h>

int main(){
    int n,m,t,i,j,k;
    printf("#MATRIX OPERATIONS IN C#\n");
    printf("Enter the value of n: ");
    scanf("%d",&n);
    printf("Enter the value of m: ");
    scanf("%d",&m);

    int matrix1[n][m], matrix2[n][m], result[n][m];

    printf("Enter values for matrix 1\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("Enter value for matrix1[%d][%d]: ",i,j);
            scanf("%d",&matrix1[i][j]);
        }
    }

    printf("\nEnter values for matrix 2\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("Enter value for matrix2[%d][%d]: ",i,j);
            scanf("%d",&matrix2[i][j]);
        }
    }

    printf("\nMATRIX 1\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d ",matrix1[i][j]);
        }
        printf("\n");
    }

    printf("\nMATRIX 2\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d ",matrix2[i][j]);
        }
        printf("\n");
    }

    //Addition of matrices
    printf("\nADDING MATRIX 1 AND MATRIX 2\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }

    //Multiplication of matrices
    printf("\nMULTIPLYING MATRIX 1 AND MATRIX 2\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            result[i][j] = 0;
            for(k=0;k<m;k++){
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
    return 0;
}