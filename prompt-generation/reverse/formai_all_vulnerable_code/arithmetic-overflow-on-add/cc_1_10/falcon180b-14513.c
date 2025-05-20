//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 1000
#define MAX_LINE_LENGTH 1000

// Define a structure to hold the metadata for a file
typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    int file_size;
    int line_count;
    int word_count;
    int character_count;
} FileMetadata;

// Function to extract metadata from a file
void extract_metadata(FileMetadata *metadata, FILE *file) {
    char line[MAX_LINE_LENGTH];
    int line_number = 1;
    int word_number = 1;
    int character_number = 1;

    // Read the file line by line
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        // Count the number of characters in the line
        int line_length = strlen(line);
        metadata->character_count += line_length;

        // Count the number of words in the line
        int word_count = 1;
        char *word = strtok(line, " \t\n\r\f\v");
        while (word!= NULL) {
            word_number++;
            metadata->word_count++;
            word_count++;
            character_number += strlen(word);
            word = strtok(NULL, " \t\n\r\f\v");
        }

        // Count the number of lines in the file
        metadata->line_count++;
    }

    // Set the file size
    metadata->file_size = ftell(file);

    // Copy the file name into the metadata structure
    strcpy(metadata->file_name, "unknown");
}

// Function to print the metadata for a file
void print_metadata(FileMetadata *metadata) {
    printf("File name: %s\n", metadata->file_name);
    printf("File size: %d bytes\n", metadata->file_size);
    printf("Number of lines: %d\n", metadata->line_count);
    printf("Number of words: %d\n", metadata->word_count);
    printf("Number of characters: %d\n", metadata->character_count);
}

// Main function to run the program
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    // Extract the metadata from the file
    FileMetadata metadata;
    extract_metadata(&metadata, file);

    // Print the metadata for the file
    printf("Metadata for file '%s':\n", argv[1]);
    print_metadata(&metadata);

    // Close the file
    fclose(file);

    return 0;
}