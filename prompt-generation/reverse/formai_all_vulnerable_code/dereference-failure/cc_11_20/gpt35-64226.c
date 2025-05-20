//FormAI DATASET v1.0 Category: Memory management ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize memory allocation and pointer
    int* first_chunk = (int*) malloc(5 * sizeof(int));
    int* second_chunk = (int*) malloc(10 * sizeof(int));
    
    // Error handling for memory allocation
    if (first_chunk == NULL || second_chunk == NULL) {
        printf("Error: Memory allocation failed.\n");
        return -1;
    }
    
    // Setting the values for the first chunk
    for (int i = 0; i < 5; i++) {
        *(first_chunk + i) = i + 1;
    }
    
    // Setting the values for the second chunk
    for (int i = 0; i < 10; i++) {
        *(second_chunk + i) = i + 6;
    }
    
    // Printing out the values of the first chunk
    printf("First chunk values:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(first_chunk + i));
    }
    printf("\n");
    
    // Printing out the values of the second chunk
    printf("Second chunk values:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(second_chunk + i));
    }
    printf("\n");
    
    // Re-allocating the memory for the first chunk
    int* new_first_chunk = (int*) realloc(first_chunk, 10 * sizeof(int));
    
    // Error handling for re-allocation
    if (new_first_chunk == NULL) {
        printf("Error: Failed to re-allocate memory.\n");
        return -1;
    }
    
    // Setting the new values for the first chunk
    for (int i = 5; i < 10; i++) {
        *(new_first_chunk + i) = i + 1;
    }
    
    // Printing out the values of the new first chunk
    printf("New first chunk values:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(new_first_chunk + i));
    }
    printf("\n");
    
    // Freeing up the memory for the second chunk
    free(second_chunk);
    
    // Printing out the values of the new first chunk again after freeing the second chunk
    printf("New first chunk values after freeing second chunk:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(new_first_chunk + i));
    }
    printf("\n");
    
    // Freeing up the memory for the new first chunk
    free(new_first_chunk);
    
    return 0;
}