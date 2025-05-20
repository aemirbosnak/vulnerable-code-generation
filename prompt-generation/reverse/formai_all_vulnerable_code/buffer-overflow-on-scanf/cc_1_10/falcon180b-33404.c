//Falcon-180B DATASET v1.0 Category: Memory management ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr;
    int size,i;

    printf("Enter the size of array: ");
    scanf("%d",&size);

    ptr = (int*)malloc(size*sizeof(int));

    if(ptr == NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }

    printf("Enter the elements of array: ");

    for(i=0;i<size;i++)
    {
        scanf("%d",ptr+i);
    }

    printf("Original array: ");

    for(i=0;i<size;i++)
    {
        printf("%d ",*(ptr+i));
    }

    printf("\n");

    free(ptr);

    ptr = (int*)malloc(size*sizeof(int));

    if(ptr == NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }

    printf("Enter the elements of array: ");

    for(i=0;i<size;i++)
    {
        scanf("%d",ptr+i);
    }

    printf("Updated array: ");

    for(i=0;i<size;i++)
    {
        printf("%d ",*(ptr+i));
    }

    printf("\n");

    return 0;
}