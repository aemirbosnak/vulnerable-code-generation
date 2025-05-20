//FormAI DATASET v1.0 Category: Memory management ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int *arr = (int*)malloc(n * sizeof(int)); // allocate memory for array
    
    if (arr == NULL) { // check if allocation was successful
        printf("Memory allocation failed.");
        return 1;
    }
    
    printf("Enter %d integers:\n", n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("The integers you entered are: ");
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\nEnter the new size of the array: ");
    scanf("%d", &n);
    
    arr = (int*)realloc(arr, n * sizeof(int)); // re-allocate memory for array
    
    if (arr == NULL) { // check if reallocation was successful
        printf("Memory reallocation failed.");
        return 1;
    }
    
    printf("Enter %d more integers:\n", n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("The integers you entered are: ");
    
    for (int i = 0; i < (2 * n); i++) {
        printf("%d ", arr[i]);
    }
    
    free(arr); // free memory
    
    return 0;
}