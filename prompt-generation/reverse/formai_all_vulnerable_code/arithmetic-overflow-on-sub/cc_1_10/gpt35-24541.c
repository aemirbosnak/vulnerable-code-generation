//FormAI DATASET v1.0 Category: Searching algorithm ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

int recursive_binary_search(int* arr, int search, int left, int right);

int main(int argc, char** argv)
{
    int num_elements;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &num_elements);

    int* arr = malloc(num_elements * sizeof(int));

    printf("Enter the elements of the array: ");
    for(int i=0; i<num_elements; i++)
    {
        scanf("%d", &arr[i]);
    }

    int search;
    printf("Enter the element to be searched: ");
    scanf("%d", &search);

    int result = recursive_binary_search(arr, search, 0, num_elements-1);

    if(result != -1)
    {
        printf("Element %d found at index %d.", search, result);
    }
    else
    {
        printf("Element not found.");
    }
    
    return 0;
}

int recursive_binary_search(int* arr, int search, int left, int right)
{
    if(left <= right)
    {
        int mid = (left + right)/2;

        if(arr[mid] == search)
        {
            return mid;
        }
        else if(arr[mid] < search)
        {
            return recursive_binary_search(arr, search, mid+1, right);
        }
        else
        {
            return recursive_binary_search(arr, search, left, mid-1);
        }
    }
    else
    {
        return -1;
    }
}