//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n, i, j, k, count = 0;
    float a[100][100], sum = 0, det = 0;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d",&n,&n);

    printf("\nEnter the elements of the matrix:\n");

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    printf("\nThe matrix entered is:\n");

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%f\t", a[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i!= j)
            {
                for(k=0; k<n; k++)
                {
                    a[i][j] += a[i][k]*a[k][j];
                }
            }
        }
    }

    printf("\nThe determinant of the matrix is: %f\n", det);

    return 0;
}