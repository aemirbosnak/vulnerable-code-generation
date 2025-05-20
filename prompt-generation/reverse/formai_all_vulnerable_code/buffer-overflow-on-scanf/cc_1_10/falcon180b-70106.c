//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the metadata structure
typedef struct {
    char *filename; // Name of the file
    int filesize; // Size of the file in bytes
} Metadata;

// Function to extract metadata from a file
Metadata *extract_metadata(char *filename) {
    FILE *file = fopen(filename, "rb"); // Open the file in binary mode
    if (file == NULL) { // Check if the file was opened successfully
        printf("Error: Could not open file '%s'.\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END); // Move the file pointer to the end of the file
    int filesize = ftell(file); // Get the size of the file
    rewind(file); // Move the file pointer back to the beginning of the file

    Metadata *metadata = malloc(sizeof(Metadata)); // Allocate memory for the metadata structure
    if (metadata == NULL) { // Check if the memory allocation was successful
        printf("Error: Could not allocate memory for metadata.\n");
        exit(1);
    }

    metadata->filename = strdup(filename); // Copy the filename to the metadata structure
    metadata->filesize = filesize; // Set the filesize in the metadata structure

    fclose(file); // Close the file
    return metadata; // Return the metadata structure
}

// Function to print metadata
void print_metadata(Metadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("Filesize: %d bytes\n", metadata->filesize);
}

// Main function
int main() {
    char filename[100]; // Declare a character array to store the filename
    printf("Enter the filename: ");
    scanf("%s", filename); // Read the filename from the user

    Metadata *metadata = extract_metadata(filename); // Extract the metadata from the file
    if (metadata!= NULL) { // Check if the metadata was extracted successfully
        print_metadata(metadata); // Print the metadata
        free(metadata->filename); // Free the memory allocated for the filename
        free(metadata); // Free the memory allocated for the metadata structure
    }

    return 0; // Exit the program
}