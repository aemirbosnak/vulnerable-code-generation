//Falcon-180B DATASET v1.0 Category: Memory management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Function to dynamically allocate memory
void* my_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Out of memory.\n");
        exit(1);
    }
    return ptr;
}

// Function to free memory
void my_free(void* ptr) {
    if (ptr!= NULL) {
        free(ptr);
    }
}

int main() {
    // Dynamically allocate memory for an integer array
    int* arr = (int*)my_malloc(10 * sizeof(int));

    // Initialize the array with some values
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }

    // Print the array
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Dynamically allocate memory for a string
    char* str = (char*)my_malloc(20 * sizeof(char));

    // Set the string value
    strcpy(str, "Hello, world!");

    // Print the string
    printf("%s\n", str);

    // Free the dynamically allocated memory
    my_free(arr);
    my_free(str);

    return 0;
}