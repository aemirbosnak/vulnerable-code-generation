//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main()
{
    int i,j,n,m,k,l,count=0,flag,sum=0;
    int arr[10][10],temp[10][10];
    char ch;

    printf("\nEnter the number of rows and columns of the matrix: ");
    scanf("%d%d",&n,&m);

    printf("\nEnter the elements of the matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    printf("\nThe original matrix is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }

    while(1)
    {
        count++;
        flag=0;
        for(i=0;i<n-1;i++)
        {
            for(j=0;j<m-1;j++)
            {
                if(arr[i][j]>arr[i][j+1])
                {
                    temp[i][j]=arr[i][j];
                    arr[i][j]=arr[i][j+1];
                    arr[i][j+1]=temp[i][j];
                    flag=1;
                }
            }
        }

        if(flag==0)
        {
            break;
        }

        printf("\n\nAfter %d iterations, the matrix is:\n",count);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                printf("%d\t",arr[i][j]);
            }
            printf("\n");
        }

    }

    return 0;
}