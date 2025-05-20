//Code Llama-13B DATASET v1.0 Category: Metadata Extractor ; Style: artistic
// C Metadata Extractor Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Metadata structure
typedef struct {
    char title[100];
    char author[50];
    int year;
    char genre[20];
} Metadata;

// Function to extract metadata from a file
void extract_metadata(Metadata *metadata, char *filename) {
    // Open the file and read its contents
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    // Read the file's contents into a buffer
    char buffer[1000];
    fread(buffer, sizeof(char), 1000, file);

    // Extract the metadata from the buffer
    char *title = strtok(buffer, "\n");
    char *author = strtok(NULL, "\n");
    char *year = strtok(NULL, "\n");
    char *genre = strtok(NULL, "\n");

    // Assign the metadata to the structure
    strcpy(metadata->title, title);
    strcpy(metadata->author, author);
    metadata->year = atoi(year);
    strcpy(metadata->genre, genre);

    // Close the file
    fclose(file);
}

// Main function
int main() {
    // Declare a Metadata structure and initialize it
    Metadata metadata;
    strcpy(metadata.title, "");
    strcpy(metadata.author, "");
    metadata.year = 0;
    strcpy(metadata.genre, "");

    // Extract the metadata from a file
    extract_metadata(&metadata, "example.txt");

    // Print the extracted metadata
    printf("Title: %s\n", metadata.title);
    printf("Author: %s\n", metadata.author);
    printf("Year: %d\n", metadata.year);
    printf("Genre: %s\n", metadata.genre);

    return 0;
}