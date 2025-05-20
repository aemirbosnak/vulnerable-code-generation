//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 256
#define FILENAME "data.txt"

// Function to handle file operations and errors
void handle_file_operation(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file '%s': %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_BUFFER_SIZE];
    size_t line_count = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        line_count++;
        printf("Line %zu: %s", line_count, buffer);
    }

    if (ferror(file)) {
        fprintf(stderr, "Error reading from file '%s': %s\n", filename, strerror(errno));
    }

    if (fclose(file) != 0) {
        fprintf(stderr, "Error closing file '%s': %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Finished reading from '%s'. Total lines read: %zu\n", filename, line_count);
}

// Function to demonstrate memory allocation and error handling
void handle_memory_allocation(size_t size) {
    int *array = malloc(size * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed for size %zu: %s\n", size, strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Initialize and use the allocated memory
    for (size_t i = 0; i < size; i++) {
        array[i] = (int)i * 2; // Example processing
    }

    printf("Memory allocation successful for %zu integers.\n", size);

    // Simulate an error by accessing out of bounds
    if (size > 0) {
        printf("Last element: %d\n", array[size - 1]); // Accessing one element within bounds
        printf("Attempting to access out of bounds...\n");
        // Uncommenting the following line will lead to undefined behavior,
        // demonstrating the need for careful error handling
        // printf("Out of bounds element: %d\n", array[size]);
    }

    free(array);
    printf("Memory deallocated successfully.\n");
}

// Main function to coordinate operations and handle errors
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_integers>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *endptr;
    long num_integers = strtol(argv[1], &endptr, 10);

    if (*endptr != '\0' || num_integers <= 0) {
        fprintf(stderr, "Invalid number of integers: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Perform file operations and handle errors
    handle_file_operation(FILENAME);

    // Handle memory allocation with the specified size
    handle_memory_allocation(num_integers);

    printf("Program executed successfully.\n");
    return EXIT_SUCCESS;
}