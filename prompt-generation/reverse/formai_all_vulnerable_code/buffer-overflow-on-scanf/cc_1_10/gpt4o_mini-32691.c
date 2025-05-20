//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_LINE_LENGTH 256

void write_data(FILE *file, int depth);
void read_data(FILE *file, int depth);

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the file name to create or read from: ");
    scanf("%s", filename);
    
    FILE *file = fopen(filename, "a+");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Write data to the file recursively
    printf("Enter depth for writing data (0 for stop): ");
    int depth;
    scanf("%d", &depth);
    write_data(file, depth);

    // Reset the file pointer to the beginning
    rewind(file);

    // Read and display the contents of the file recursively
    printf("File contents:\n");
    read_data(file, 0);

    fclose(file);
    return EXIT_SUCCESS;
}

void write_data(FILE *file, int depth) {
    if (depth <= 0) {
        return; // Base case, stop if depth is 0 or less.
    }
    
    // Prompt for the data to write
    char data[MAX_LINE_LENGTH];
    printf("Enter a line to write (Depth %d): ", depth);
    scanf(" %[^\n]", data);
    
    // Write data to the file
    fprintf(file, "Depth %d: %s\n", depth, data);
    fflush(file); // flush the file to ensure data is written to disk

    // Recursive call
    write_data(file, depth - 1);
}

void read_data(FILE *file, int depth) {
    char line[MAX_LINE_LENGTH];
    
    // Read line by line from the file
    if (fgets(line, sizeof(line), file) != NULL) {
        // Print the current line
        printf("%s", line);
        
        // Recursive call to read the next line
        read_data(file, depth + 1);
    }
}