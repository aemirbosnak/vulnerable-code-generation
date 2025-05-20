//Falcon-180B DATASET v1.0 Category: Memory management ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    char *memory[MAX_SIZE];
    int size = 0;
    int i = 0;

    // Initialize all pointers to NULL
    for (i = 0; i < MAX_SIZE; i++) {
        memory[i] = NULL;
    }

    // Allocate memory for a string
    memory[size] = (char *) malloc(10);
    if (memory[size] == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    // Copy a string into the allocated memory
    strcpy(memory[size], "Hello, world!");

    // Print the string
    printf("%s\n", memory[size]);

    // Free the memory
    free(memory[size]);
    memory[size] = NULL;

    // Allocate memory for an integer array
    memory[++size] = (int *) malloc(5 * sizeof(int));
    if (memory[size] == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    // Initialize the integer array
    for (i = 0; i < 5; i++) {
        *(memory[size] + i) = i;
    }

    // Print the integer array
    for (i = 0; i < 5; i++) {
        printf("%d ", *(memory[size] + i));
    }
    printf("\n");

    // Free the memory
    free(memory[size]);
    memory[size] = NULL;

    // Allocate memory for a float array
    memory[++size] = (float *) malloc(3 * sizeof(float));
    if (memory[size] == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    // Initialize the float array
    for (i = 0; i < 3; i++) {
        *(memory[size] + i) = (float) i;
    }

    // Print the float array
    for (i = 0; i < 3; i++) {
        printf("%f ", *(memory[size] + i));
    }
    printf("\n");

    // Free the memory
    free(memory[size]);
    memory[size] = NULL;

    return 0;
}