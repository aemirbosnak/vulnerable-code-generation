//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold metadata information
typedef struct {
    char *filename;
    char *author;
    char *title;
    char *date;
} Metadata;

// Function to extract metadata from a file
void extract_metadata(const char *filename, Metadata *meta) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    // Read the author from the file
    char author_buf[100];
    fseek(file, 0, SEEK_SET);
    fgets(author_buf, sizeof(author_buf), file);
    meta->author = strdup(strtok(author_buf, "\n"));

    // Read the title from the file
    fseek(file, 0, SEEK_SET);
    fgets(author_buf, sizeof(author_buf), file);
    meta->title = strdup(strtok(author_buf, "\n"));

    // Read the date from the file
    fseek(file, 0, SEEK_SET);
    fgets(author_buf, sizeof(author_buf), file);
    meta->date = strdup(strtok(author_buf, "\n"));

    fclose(file);
}

// Function to print the metadata
void print_metadata(const Metadata *meta) {
    printf("Filename: %s\n", meta->filename);
    printf("Author: %s\n", meta->author);
    printf("Title: %s\n", meta->title);
    printf("Date: %s\n", meta->date);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    Metadata meta;
    meta.filename = strdup(argv[1]);
    extract_metadata(meta.filename, &meta);
    print_metadata(&meta);

    free(meta.filename);
    free(meta.author);
    free(meta.title);
    free(meta.date);

    return 0;
}