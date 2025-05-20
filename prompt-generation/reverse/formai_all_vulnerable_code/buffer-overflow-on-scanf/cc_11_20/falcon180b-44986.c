//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n,i,j,k;
    float a[10][10],b[10][10],c[10][10],sum=0,det=0;

    printf("Enter the number of variables: ");
    scanf("%d",&n);

    printf("\nEnter the coefficients of the variables in the first row:\n");
    for(i=0;i<n;i++)
    {
        scanf("%f",&a[0][i]);
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
                printf("\nEnter the coefficient of %c in terms of %c:\n",(char)(j+65),(char)(i+65));
                scanf("%f",&a[i][j]);
            }
            else
            {
                a[i][j]=1;
            }
        }
    }

    printf("\nThe system of equations is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%fX%c + ",a[i][j],(char)(j+65));
        }
        printf("= %f\n",a[i][n]);
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            b[i][j]=a[i][j];
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                if(i==k)
                {
                    c[i][j] = b[i][j];
                }
                else if(j==k)
                {
                    c[i][j] = 0;
                }
                else
                {
                    c[i][j] = b[i][k] * b[k][j];
                }
            }
        }
    }

    printf("\nThe cofactor matrix is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%f ",c[i][j]);
        }
        printf("\n");
    }

    det = a[0][0] * c[0][0];

    for(i=1;i<n;i++)
    {
        det += a[0][i] * c[0][i];
    }

    printf("\nThe determinant of the matrix is: %f",det);

    return 0;
}