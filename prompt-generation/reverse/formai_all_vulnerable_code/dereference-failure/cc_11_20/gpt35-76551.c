//FormAI DATASET v1.0 Category: Memory management ; Style: complete
#include <stdio.h> 
#include <stdlib.h> 
  
int main() 
{ 
    int* ptr1 = NULL; 
    int* ptr2 = NULL; 
    int* ptr3 = NULL; 
  
    ptr1 = (int*)malloc(5 * sizeof(int)); // allocate memory of size 5 integers
    ptr2 = (int*)calloc(3, sizeof(int)); // allocate memory of size 3 integers and initialize them to 0
    ptr3 = (int*)calloc(10, sizeof(int)); // allocate memory of size 10 integers and initialize them to 0
  
    if (ptr1 == NULL || ptr2 == NULL || ptr3 == NULL) { // Check if allocation was successful
        printf("Memory Allocation Failed\n");
        exit(0); 
    } 
  
    // Initialize the allocated memory with values
    for (int i = 0; i < 5; i++) {
        *(ptr1 + i) = i + 1; 
    }
    *(ptr2 + 0) = 10;
    *(ptr2 + 1) = 20;
    *(ptr2 + 2) = 30;
    
    printf("Contents of ptr1: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr1 + i));
    }
    printf("\n");

    printf("Contents of ptr2: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", *(ptr2 + i));
    }
    printf("\n");

    printf("Contents of ptr3: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(ptr3 + i));
    }
    printf("\n");
  
    // Reallocate memory for ptr1 to size 10 integers
    ptr1 = (int*)realloc(ptr1, 10 * sizeof(int));
    if (ptr1 == NULL) { // Check if allocation was successful
        printf("Memory Allocation Failed\n");
        exit(0); 
    } 
  
    // Initialize the newly allocated memory with new values
    for (int i = 5; i < 10; i++) {
        *(ptr1 + i) = i + 1; 
    }

    printf("New contents of ptr1 after reallocation: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(ptr1 + i));
    }
    printf("\n");

    // Deallocate the memory
    free(ptr1);
    free(ptr2);
    free(ptr3);

    return 0;
}