//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of the metadata
typedef struct {
    char *filename;
    int filesize;
    char *author;
    char *title;
    char *description;
    char *keywords;
} Metadata;

// Function to extract the metadata from the file
Metadata extract_metadata(FILE *file) {
    Metadata metadata;

    // Read the filename
    char filename[100];
    fseek(file, 0, SEEK_SET);
    fread(filename, 1, 100, file);
    metadata.filename = strdup(filename);

    // Read the file size
    int filesize;
    fread(&filesize, 4, 1, file);
    metadata.filesize = filesize;

    // Read the author
    char author[100];
    fread(author, 1, 100, file);
    metadata.author = strdup(author);

    // Read the title
    char title[100];
    fread(title, 1, 100, file);
    metadata.title = strdup(title);

    // Read the description
    char description[1000];
    fread(description, 1, 1000, file);
    metadata.description = strdup(description);

    // Read the keywords
    char keywords[100];
    fread(keywords, 1, 100, file);
    metadata.keywords = strdup(keywords);

    return metadata;
}

// Function to print the metadata
void print_metadata(Metadata metadata) {
    printf("Filename: %s\n", metadata.filename);
    printf("File Size: %d bytes\n", metadata.filesize);
    printf("Author: %s\n", metadata.author);
    printf("Title: %s\n", metadata.title);
    printf("Description: %s\n", metadata.description);
    printf("Keywords: %s\n", metadata.keywords);
}

// Main function
int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    Metadata metadata = extract_metadata(file);
    print_metadata(metadata);

    fclose(file);

    return 0;
}