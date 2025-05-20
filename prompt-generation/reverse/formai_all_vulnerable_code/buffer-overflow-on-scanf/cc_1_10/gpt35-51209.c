//FormAI DATASET v1.0 Category: Sorting ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

// Define the maximum size of the array that we will sort
#define MAX_SIZE 100

int main(){

    // Declare variables
    int arr[MAX_SIZE], i, j, temp, size;

    // Prompt user for input
    printf("Enter the size of array to be sorted: ");
    scanf("%d", &size);

    // Validate input
    if(size > MAX_SIZE || size <= 0){
        printf("Invalid array size. Please try again!\n");
        return 0;
    }

    // Populate array with random values
    printf("Populating Array with Random Values\n");
    for(i=0; i<size; i++){
        arr[i] = rand() % 100 + 1;
        printf("%d ", arr[i]);
    }

    printf("\n");

    // Sort the array
    printf("Sorting the Array using Bubble Sort Technique\n");
    for(i=0; i<size-1; i++){
        for(j=0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                // Swap the values
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Print the sorted array
    printf("Printing Sorted Array\n");
    for(i=0; i<size; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}