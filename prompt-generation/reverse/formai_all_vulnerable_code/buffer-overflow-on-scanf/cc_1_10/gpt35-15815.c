//FormAI DATASET v1.0 Category: Memory management ; Style: bold
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    // allocate memory for an array of integers
    int *arr = (int*) malloc(MAX_SIZE * sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    printf("Enter %d integers:\n", MAX_SIZE);
    
    // read integers from user input and store in array
    for (int i = 0; i < MAX_SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("You entered:\n");
    
    // print contents of array
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // reallocate memory for a larger array of integers
    int *larger_arr = (int*) realloc(arr, MAX_SIZE * 2 * sizeof(int));
    
    if (larger_arr == NULL) {
        printf("Memory reallocation failed!\n");
        free(arr); // free original memory allocation
        return 1;
    }
    
    arr = larger_arr; // assign new memory allocation to original pointer
    
    printf("Successfully reallocated memory for %d integers.\n", MAX_SIZE * 2);
    
    // read additional integers from user input and store in larger array
    for (int i = MAX_SIZE; i < MAX_SIZE * 2; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("You entered:\n");
    
    // print contents of larger array
    for (int i = 0; i < MAX_SIZE * 2; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr); // free memory allocation
    
    return 0;
}