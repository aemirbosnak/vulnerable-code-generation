//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for metadata
typedef struct {
    char* title;
    char* author;
    char* genre;
    int year;
} Metadata;

// Function prototypes
Metadata* createMetadata(char* title, char* author, char* genre, int year);
void printMetadata(Metadata* metadata);
void freeMetadata(Metadata* metadata);

// Main function
int main() {
    // Create metadata
    Metadata* metadata = createMetadata("The Great Gatsby", "F. Scott Fitzgerald", "Fiction", 1925);

    // Print metadata
    printMetadata(metadata);

    // Free metadata
    freeMetadata(metadata);

    return 0;
}

// Function to create metadata
Metadata* createMetadata(char* title, char* author, char* genre, int year) {
    Metadata* metadata = (Metadata*) malloc(sizeof(Metadata));

    metadata->title = strdup(title);
    metadata->author = strdup(author);
    metadata->genre = strdup(genre);
    metadata->year = year;

    return metadata;
}

// Function to print metadata
void printMetadata(Metadata* metadata) {
    printf("Title: %s\n", metadata->title);
    printf("Author: %s\n", metadata->author);
    printf("Genre: %s\n", metadata->genre);
    printf("Year: %d\n", metadata->year);
}

// Function to free metadata
void freeMetadata(Metadata* metadata) {
    free(metadata->title);
    free(metadata->author);
    free(metadata->genre);
    free(metadata);
}