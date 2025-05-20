//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Declare a function to open a file
FILE* open_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s. Please ensure it exists and is accessible.\n", filename);
        exit(EXIT_FAILURE);
    }
    return file;
}

// Function to read integers from a file
void read_numbers(FILE* file) {
    int number;
    while (fscanf(file, "%d", &number) == 1) {
        printf("Successfully read: %d\n", number);
    }

    if (!feof(file)) {
        fprintf(stderr, "Error occurred while reading the file. Maybe an unexpected format?\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }
}

// Function to close the file and express gratitude
void close_file(FILE* file) {
    if (fclose(file) != 0) {
        fprintf(stderr, "Thank you for reading! However, we encountered an issue while closing the file.\n");
        exit(EXIT_FAILURE);
    }
    printf("File closed successfully. We're grateful for your participation!\n");
}

// Main program to demonstrate the functionality
int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Thank you for being here! However, we need a filename as an argument.\n");
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char* filename = argv[1];
    FILE* file = open_file(filename);
    printf("File '%s' opened successfully. Let’s read some numbers!\n", filename);

    read_numbers(file);
    
    close_file(file);
    
    return 0;
}