//Code Llama-13B DATASET v1.0 Category: Metadata Extractor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store metadata for a file
typedef struct {
    char name[50];
    char type[50];
    int size;
    char path[100];
} metadata_t;

// Function to extract metadata for a file
void extract_metadata(const char *filepath, metadata_t *metadata) {
    // Open the file for reading
    FILE *fp = fopen(filepath, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    // Get the file name and type
    strcpy(metadata->name, filepath);
    char *filename = strrchr(metadata->name, '/');
    if (filename != NULL) {
        filename++;
    } else {
        filename = metadata->name;
    }
    strcpy(metadata->type, filename);
    char *dot = strrchr(metadata->type, '.');
    if (dot != NULL) {
        *dot = '\0';
    }

    // Get the file size
    fseek(fp, 0, SEEK_END);
    metadata->size = ftell(fp);
    rewind(fp);

    // Get the file path
    strcpy(metadata->path, filepath);

    // Close the file
    fclose(fp);
}

// Function to print the metadata
void print_metadata(const metadata_t *metadata) {
    printf("File name: %s\n", metadata->name);
    printf("File type: %s\n", metadata->type);
    printf("File size: %d bytes\n", metadata->size);
    printf("File path: %s\n", metadata->path);
}

int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filepath>\n", argv[0]);
        exit(1);
    }

    // Extract metadata for the file
    metadata_t metadata;
    extract_metadata(argv[1], &metadata);

    // Print the metadata
    print_metadata(&metadata);

    return 0;
}