//FormAI DATASET v1.0 Category: Memory management ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare a pointer to an array of integers
    int *numbers = NULL;
    // Declare an integer variable to store the number of elements
    int numElements = 0;
    
    while (1) {
        // Prompt the user for input
        printf("Enter the number of elements in the array (or 0 to exit): ");
        scanf("%d", &numElements);
        
        if (numElements == 0) {
            // Exit the program
            printf("Goodbye!");
            break;
        }
        
        if (numbers != NULL) {
            // If the pointer is not null, free the previously allocated memory
            free(numbers);
        }
        
        // Allocate memory for the array
        numbers = (int*)malloc(numElements * sizeof(int));
        
        if (numbers == NULL) {
            // Print an error message and exit if memory allocation fails
            printf("Error: unable to allocate memory");
            break;
        }
        
        // Read in the values for the array
        int i;
        for (i = 0; i < numElements; i++) {
            printf("Enter a value for element %d: ", i);
            scanf("%d", &numbers[i]);
        }
        
        // Print out the values in the array
        printf("The values in the array are: ");
        for (i = 0; i < numElements; i++) {
            printf("%d ", numbers[i]);
        }
        printf("\n");
    }
    
    // Free the memory allocated for the array
    if (numbers != NULL) {
        free(numbers);
    }
    
    return 0;
}