//FormAI DATASET v1.0 Category: Educational ; Style: futuristic
#include<stdio.h>

//Function to perform matrix multiplication
void multiplyMatrix(int A[][3], int B[][3], int C[][3], int m, int n, int p)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<p; j++)
        {
            C[i][j] = 0;
            for(int k=0; k<n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main()
{
    int m=3, n=3, p=3;
    int A[m][n], B[n][p], C[m][p];
    
    //Take input for matrix A
    printf("Enter the %d elements of matrix A:\n", m*n);
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    
    //Take input for matrix B
    printf("\nEnter the %d elements of matrix B:\n", n*p);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<p; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }
    
    //Perform matrix multiplication and store in C
    multiplyMatrix(A, B, C, m, n, p);
    
    //Print the result
    printf("\nResultant matrix C:\n");
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<p; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}