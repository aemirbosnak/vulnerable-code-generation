//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for error types
#define FILE_ERROR 1
#define MEMORY_ERROR 2
#define PARSE_ERROR 3

// Function to handle errors
void handle_error(int error_code) {
    switch(error_code) {
        case FILE_ERROR:
            fprintf(stderr, "Error: Unable to open the file.\n");
            break;
        case MEMORY_ERROR:
            fprintf(stderr, "Error: Memory allocation failed.\n");
            break;
        case PARSE_ERROR:
            fprintf(stderr, "Error: Parsing the data failed.\n");
            break;
        default:
            fprintf(stderr, "Unknown error occurred.\n");
    }
    exit(error_code);
}

// Function to read numbers from a file
int* read_numbers_from_file(const char* filename, int* size) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        handle_error(FILE_ERROR);
    }

    // Dynamically allocate memory for integers
    int* numbers = malloc(100 * sizeof(int)); // Starting with space for 100 integers
    if (!numbers) {
        fclose(file);
        handle_error(MEMORY_ERROR);
    }

    int count = 0, number;
    while (fscanf(file, "%d", &number) == 1) {
        if (count >= 100) {
            // Resize if more than 100 numbers
            numbers = realloc(numbers, (count + 1) * sizeof(int));
            if (!numbers) {
                fclose(file);
                handle_error(MEMORY_ERROR);
            }
        }
        numbers[count++] = number;
    }

    fclose(file);
    *size = count;
    return numbers;
}

// Function to parse and process numbers
void process_numbers(int* numbers, int size) {
    if (size <= 0) {
        fprintf(stderr, "No numbers to process.\n");
        return;
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    printf("Sum of all numbers: %d\n", sum);
}

// Main function
int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int size = 0;
    int* numbers = read_numbers_from_file(argv[1], &size);
    process_numbers(numbers, size);
    
    // Free allocated memory
    free(numbers);
    
    return EXIT_SUCCESS;
}