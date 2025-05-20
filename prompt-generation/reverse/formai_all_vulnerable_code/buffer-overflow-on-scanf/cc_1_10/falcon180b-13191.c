//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: funny
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define MAX 20

int main()
{
    int i,j,k,l,n,m;
    char ch;

    printf("Enter the number of matrices to be added: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter the number of rows and columns of matrix %d:\n",i+1);
        scanf("%d%d",&m,&l);

        int **a = (int **)malloc(m*sizeof(int *));
        for(j=0;j<m;j++)
        {
            a[j] = (int *)malloc(l*sizeof(int));
        }

        printf("Enter the elements of matrix %d:\n",i+1);

        for(j=0;j<m;j++)
        {
            for(k=0;k<l;k++)
            {
                scanf("%d",&a[j][k]);
            }
        }

        printf("Matrix %d:\n",i+1);

        for(j=0;j<m;j++)
        {
            for(k=0;k<l;k++)
            {
                printf("%d\t",a[j][k]);
            }
            printf("\n");
        }

        free(a[0]);
        free(a);
    }

    return 0;
}