//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store metadata information
typedef struct {
    char *filename;
    int filesize;
    char *filetype;
    char *author;
    char *date;
} Metadata;

// Function to extract metadata from a file
void extractMetadata(char *filename, Metadata *metadata) {
    // Open the file for reading
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    // Get the file size
    fseek(fp, 0, SEEK_END);
    metadata->filesize = ftell(fp);
    rewind(fp);

    // Read the file type
    char magic[4];
    fread(magic, 1, 4, fp);
    metadata->filetype = strdup(magic);

    // Read the author and date
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp)!= NULL) {
        char *p = strstr(buffer, "Author:");
        if (p!= NULL) {
            p += strlen("Author:");
            char *author = strdup(p);
            metadata->author = author;
        }
        p = strstr(buffer, "Date:");
        if (p!= NULL) {
            p += strlen("Date:");
            char *date = strdup(p);
            metadata->date = date;
        }
    }

    // Close the file
    fclose(fp);
}

// Function to print metadata information
void printMetadata(Metadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("File size: %d bytes\n", metadata->filesize);
    printf("File type: %s\n", metadata->filetype);
    if (metadata->author!= NULL)
        printf("Author: %s\n", metadata->author);
    if (metadata->date!= NULL)
        printf("Date: %s\n", metadata->date);
}

// Main function to run the program
int main(int argc, char *argv[]) {
    // Check if the correct number of arguments were provided
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Allocate memory for the metadata structure
    Metadata metadata;
    metadata.filename = argv[1];

    // Extract metadata from the file
    extractMetadata(metadata.filename, &metadata);

    // Print the metadata information
    printMetadata(&metadata);

    // Free the allocated memory
    free(metadata.author);
    free(metadata.date);
    free(metadata.filetype);
    free(metadata.filename);

    return 0;
}