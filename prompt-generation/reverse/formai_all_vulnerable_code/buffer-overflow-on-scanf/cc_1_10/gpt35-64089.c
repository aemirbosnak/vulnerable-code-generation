//FormAI DATASET v1.0 Category: Memory management ; Style: energetic
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr1, *ptr2, *ptr3; //Declaring Pointers
    int size, i;

    printf("Enter the number of elements: ");
    scanf("%d", &size);


    ptr1 = (int*) malloc(size* sizeof(int));  //Creating ptr1 for size no of elements in Heap memory

    if(ptr1 == NULL) //Checking for allocation failure
    {
        printf("\n Error! Memory Allocation failed.");
        exit(0);
    }


    for(i=0; i<size; i++) //Taking input
    {
        printf("Enter element %d : ", i+1);
        scanf("%d", (ptr1+i));
    }


    printf("\n The elements of the array are: ");
    for(i=0; i<size; i++) //Printing elements of the array
    {
        printf("%d ", *(ptr1+i));
    }

    printf("\n\n The size of the array is %d Bytes. \n", sizeof(ptr1));


    //Reallocating size to the array using ptr2
    ptr2 = realloc(ptr1, (2*size)*sizeof(int)); //Allocating double the size

   if(ptr2 == NULL) //Checking for reallocation failure
    {
        printf("\n Error! Memory Allocation failed.");
        free(ptr1);
        exit(0);
    }
   else
    {
        ptr1 = ptr2;
    }


    //Adding more elements in the array
    printf("\n\n Enter %d more elements: \n", size);
    for(i=size; i<2*size; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", (ptr1+i));
    }


    //Sorting the array in descending order
    printf("\n\n The elements of the array in descending order are: ");
    for(i=0; i<2*size; i++) //Bubble Sort
    {
        for(int j=0; j<2*size-i-1; j++)
        {
            if(*(ptr1+j) < *(ptr1+j+1))
            {
                int temp = *(ptr1+j);
                *(ptr1+j) = *(ptr1+j+1);
                *(ptr1+j+1) = temp;
            }
        }
    }

    //Printing the sorted array
    for(i=0; i<2*size; i++)
    {
        printf("%d ", *(ptr1+i));
    }

    printf("\n\n The size of the array is %d Bytes. \n", sizeof(ptr1));


    //Freeing the allocated memory using ptr3
    ptr3 = ptr1;  //Assigning the address of ptr1 to ptr3
    free(ptr3);   //Freeing the memory
    printf("\n The memory has been freed.");


    return 0;

}