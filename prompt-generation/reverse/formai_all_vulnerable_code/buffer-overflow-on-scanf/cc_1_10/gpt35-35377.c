//FormAI DATASET v1.0 Category: Memory management ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

/* This program allocates and deallocates memory dynamically. 
It allows the user to input the length of an array and stores some data in it. */ 

int main(){
    int n;

    // Ask the user for the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Allocate memory for the array
    int *arr = (int*) malloc(n*sizeof(int));

    // Check if the memory was allocated successfully
    if (arr == NULL){
        printf("Memory allocation failed. \n");
        return 1;
    }

    // Fill the array with some data
    for(int i=0; i<n; i++){
        arr[i] = i*2;
    }

    // Print the array
    printf("Array content: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Deallocate memory for the array
    free(arr);

    // Set the pointer to NULL to prevent dangling pointer
    arr = NULL;

    // Check if the memory was deallocated successfully
    if (arr == NULL){
        printf("Memory deallocation successful. \n");
        return 0;
    }
    else {
        printf("Memory deallocation failed. \n");
        return 1;
    }
}