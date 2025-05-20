//FormAI DATASET v1.0 Category: Memory management ; Style: real-life
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr1, *ptr2, *ptr3;
    int n1, n2, n3, i;

    printf("Enter the size of the first array: ");
    scanf("%d",&n1);
    ptr1 = (int*)malloc(n1*sizeof(int));
    printf("Enter the elements of the first array: ");
    for(i=0;i<n1;i++)
    {
        scanf("%d",ptr1+i);
    }

    printf("Enter the size of the second array: ");
    scanf("%d",&n2);
    ptr2 = (int*)malloc(n2*sizeof(int));
    printf("Enter the elements of the second array: ");
    for(i=0;i<n2;i++)
    {
        scanf("%d",ptr2+i);
    }

    printf("Enter the size of the third array: ");
    scanf("%d",&n3);
    ptr3 = (int*)calloc(n3,sizeof(int));
    printf("The elements of the third array after calloc are: ");
    for(i=0;i<n3;i++)
    {
        printf("%d ",*(ptr3+i));
    }

    ptr3 = realloc(ptr3,n1*sizeof(int));
    printf("\nThe elements of the third array after realloc are: ");
    for(i=0;i<n1;i++)
    {
        printf("%d ",*(ptr3+i));
    }

    printf("\nThe elements of the first array are: ");
    for(i=0;i<n1;i++)
    {
        printf("%d ",*(ptr1+i));
    }

    printf("\nThe elements of the second array are: ");
    for(i=0;i<n2;i++)
    {
        printf("%d ",*(ptr2+i));
    }

    free(ptr1);
    free(ptr2);
    free(ptr3);

    return 0;
}