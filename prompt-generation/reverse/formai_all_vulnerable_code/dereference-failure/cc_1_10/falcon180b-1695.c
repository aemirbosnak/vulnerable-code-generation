//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the metadata structure
typedef struct {
    char *filename;
    int filesize;
    char *filetype;
    char *author;
    char *datecreated;
} Metadata;

// Function to extract metadata from a file
Metadata extractMetadata(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    Metadata metadata;

    // Get file size
    fseek(file, 0, SEEK_END);
    metadata.filesize = ftell(file);
    rewind(file);

    // Get file type
    char filetype[4];
    fread(filetype, 1, 4, file);
    metadata.filetype = strdup(filetype);

    // Get author
    char author[100];
    fread(author, 1, 100, file);
    author[strcspn(author, "\0")] = '\0';
    metadata.author = strdup(author);

    // Get date created
    char datecreated[20];
    fread(datecreated, 1, 20, file);
    datecreated[strcspn(datecreated, "\0")] = '\0';
    metadata.datecreated = strdup(datecreated);

    fclose(file);
    return metadata;
}

// Function to print metadata
void printMetadata(Metadata metadata) {
    printf("Filename: %s\n", metadata.filename);
    printf("File size: %d bytes\n", metadata.filesize);
    printf("File type: %s\n", metadata.filetype);
    printf("Author: %s\n", metadata.author);
    printf("Date created: %s\n", metadata.datecreated);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    Metadata metadata = extractMetadata(filename);
    printMetadata(metadata);

    return 0;
}