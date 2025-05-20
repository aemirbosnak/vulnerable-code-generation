//FormAI DATASET v1.0 Category: Memory management ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr1, *ptr2, *ptr3;
    int size1 = 10, size2 = 20, size3 = 30;
    
    // Allocate memory for ptr1
    ptr1 = (int*) malloc(size1 * sizeof(int));
    if (ptr1 == NULL) {
        printf("Memory allocation failed for ptr1.\n");
        exit(1);
    } else {
        printf("Memory allocation successful for ptr1.\n");
    }
    
    // Allocate memory for ptr2
    ptr2 = (int*) malloc(size2 * sizeof(int));
    if (ptr2 == NULL) {
        printf("Memory allocation failed for ptr2.\n");
        exit(1);
    } else {
        printf("Memory allocation successful for ptr2.\n");
    }
    
    // Allocate memory for ptr3
    ptr3 = (int*) malloc(size3 * sizeof(int));
    if (ptr3 == NULL) {
        printf("Memory allocation failed for ptr3.\n");
        exit(1);
    } else {
        printf("Memory allocation successful for ptr3.\n");
    }
    
    // Fill ptr1 with values
    for (int i = 0; i < size1; i++) {
        ptr1[i] = i * 2;
    }
    
    // Fill ptr2 with values
    for (int i = 0; i < size2; i++) {
        ptr2[i] = i * 3;
    }
    
    // Fill ptr3 with values
    for (int i = 0; i < size3; i++) {
        ptr3[i] = i * 4;
    }
    
    // Print ptr1 values
    printf("\nValues in ptr1:\n");
    for (int i = 0; i < size1; i++) {
        printf("%d ", ptr1[i]);
    }
    
    // Print ptr2 values
    printf("\n\nValues in ptr2:\n");
    for (int i = 0; i < size2; i++) {
        printf("%d ", ptr2[i]);
    }
    
    // Reallocate memory for ptr1
    size1 = size1 * 2;
    ptr1 = (int*) realloc(ptr1, size1 * sizeof(int));
    if (ptr1 == NULL) {
        printf("\nMemory reallocation failed for ptr1.\n");
        exit(1);
    } else {
        printf("\nMemory reallocation successful for ptr1.\n");
        printf("New size of ptr1: %d\n", size1);
    }
    
    // Fill new space in ptr1 with values
    for (int i = size1/2; i < size1; i++) {
        ptr1[i] = i * 2;
    }
    
    // Print ptr1 values again
    printf("\nValues in ptr1 after reallocation:\n");
    for (int i = 0; i < size1; i++) {
        printf("%d ", ptr1[i]);
    }
    
    // Free allocated memory
    free(ptr1);
    free(ptr2);
    free(ptr3);
    ptr1 = NULL;
    ptr2 = NULL;
    ptr3 = NULL;
    
    return 0;
}