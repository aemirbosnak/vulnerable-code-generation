//FormAI DATASET v1.0 Category: Searching algorithm ; Style: multivariable
#include<stdio.h>

// multi-variable searching algorithm example program

int main()
{
    int arr[100], size, i, key;

    //taking input from user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter %d elements in the array:\n", size);
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    printf("\nSearching in the array...\n\n");

    int isFound = 0; // boolean type variable to check if the key is found or not
    int position; // variable to store the index of key if found

    // multi-variable searching algorithm
    for(i=0; i<size; i++)
    {
        if(arr[i] == key)
        {
            isFound = 1;
            position = i+1;
            break;
        }
        else if(i+1 < size && arr[i+1] == key)
        {
            isFound = 1;
            position = i+2;
            break;
        }
        else if(i+2 < size && arr[i+2] == key)
        {
            isFound = 1;
            position = i+3;
            break;
        }
    }

    // printing the result
    if(isFound)
    {
        printf("Key found at index %d\n", position-1);
    }
    else
    {
        printf("Key not found in the array\n");
    }

    return 0;
}