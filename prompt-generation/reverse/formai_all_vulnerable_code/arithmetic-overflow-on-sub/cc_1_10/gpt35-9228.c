//FormAI DATASET v1.0 Category: Searching algorithm ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// function to search for element in array
int search(int *arr, int n, int x){
    // initialize variables
    int i = 0, j = n - 1, mid;
    // loop until i is less or equal to j
    while(i <= j){
        // calculate mid index
        mid = i + (j - i) / 2;

        // if element is found at mid index, return mid
        if(arr[mid] == x)
            return mid;
        // if element is greater than mid element, search in right half
        else if(arr[mid] < x)
            i = mid + 1;
        // else search in left half
        else
            j = mid - 1;
    }
    // if element is not found, return -1
    return -1;
}

// main function
int main(){
    int n, *arr, x, index;

    // take input from user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // dynamically allocate array
    arr = (int*)malloc(n * sizeof(int));

    // take input array from user
    printf("Enter the elements in sorted order:\n");
    for(int i=0; i<n; i++)
        scanf("%d", arr+i);

    // take element to search from user
    printf("Enter the element to search: ");
    scanf("%d", &x);

    // call search function to find index of element
    index = search(arr, n, x);

    // print result
    if(index == -1)
        printf("Element not found in the array.\n");
    else
        printf("Element found at index %d in the array.\n", index);

    // free dynamically allocated memory
    free(arr);

    return 0;
}