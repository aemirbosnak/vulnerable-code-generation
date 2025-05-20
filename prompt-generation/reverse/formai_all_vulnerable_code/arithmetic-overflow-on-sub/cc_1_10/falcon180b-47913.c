//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of the metadata
typedef struct {
    char* name;
    int size;
    char* date_created;
    char* date_modified;
    char* author;
} metadata_t;

// Function to extract metadata from a file
metadata_t extract_metadata(FILE* file) {
    metadata_t metadata;
    
    // Read the name of the file
    char filename[100];
    fseek(file, 0, SEEK_SET);
    fread(filename, sizeof(char), 100, file);
    filename[strcspn(filename, "\r")] = '\0'; // Remove newline character
    
    // Read the size of the file
    fseek(file, 0, SEEK_END);
    metadata.size = ftell(file);
    rewind(file);
    
    // Read the date created and modified
    char date_created[100];
    char date_modified[100];
    fseek(file, 0, SEEK_SET);
    fread(date_created, sizeof(char), 100, file);
    date_created[strcspn(date_created, "\r")] = '\0';
    fseek(file, metadata.size - 100, SEEK_SET);
    fread(date_modified, sizeof(char), 100, file);
    date_modified[strcspn(date_modified, "\r")] = '\0';
    
    // Read the author
    char author[100];
    fseek(file, 0, SEEK_SET);
    fread(author, sizeof(char), 100, file);
    author[strcspn(author, "\r")] = '\0';
    
    metadata.name = filename;
    metadata.date_created = date_created;
    metadata.date_modified = date_modified;
    metadata.author = author;
    
    return metadata;
}

// Function to print metadata
void print_metadata(metadata_t metadata) {
    printf("Name: %s\n", metadata.name);
    printf("Size: %d bytes\n", metadata.size);
    printf("Date created: %s\n", metadata.date_created);
    printf("Date modified: %s\n", metadata.date_modified);
    printf("Author: %s\n", metadata.author);
}

// Main function
int main() {
    FILE* file;
    metadata_t metadata;
    
    // Open the file
    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    
    // Extract metadata
    metadata = extract_metadata(file);
    
    // Print metadata
    printf("Metadata for file 'example.txt':\n");
    print_metadata(metadata);
    
    // Close the file
    fclose(file);
    
    return 0;
}