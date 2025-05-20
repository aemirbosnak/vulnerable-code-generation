//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: irregular
#include<stdio.h>

int main()
{
    int i,j,n;
    int a[100];
    int b[100];
    
    printf("Enter the size of the matrix: ");
    scanf("%d",&n);
    printf("Enter the elements of the matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i]);
        }
    }
    
    for(i=0;i<n;i++)
    {
        b[i]=a[i];
    }
    
    printf("Original Matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[j]);
        }
        printf("\n");
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(b[j]==a[j])
            {
                printf("Same\n");
            }
            else
            {
                printf("Different\n");
            }
        }
    }
    
    return 0;
}