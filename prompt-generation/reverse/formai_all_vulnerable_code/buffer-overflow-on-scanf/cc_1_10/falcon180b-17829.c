//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a metadata
typedef struct {
    char filename[100];
    int filesize;
    char author[50];
    char creationdate[20];
} metadata;

// Function to read metadata from a file
metadata read_metadata(char *filename) {
    metadata meta;
    FILE *fp;

    // Open the file in read mode
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    // Read the metadata from the file
    fseek(fp, 0, SEEK_SET);
    fread(&meta.filesize, sizeof(int), 1, fp);
    fread(meta.filename, sizeof(char), strlen(filename), fp);
    fread(meta.author, sizeof(char), 50, fp);
    fread(meta.creationdate, sizeof(char), 20, fp);

    // Close the file
    fclose(fp);

    // Return the metadata
    return meta;
}

// Function to write metadata to a file
void write_metadata(char *filename, metadata meta) {
    FILE *fp;

    // Open the file in write mode
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    // Write the metadata to the file
    fwrite(&meta.filesize, sizeof(int), 1, fp);
    fwrite(meta.filename, sizeof(char), strlen(meta.filename), fp);
    fwrite(meta.author, sizeof(char), strlen(meta.author), fp);
    fwrite(meta.creationdate, sizeof(char), strlen(meta.creationdate), fp);

    // Close the file
    fclose(fp);
}

// Function to print metadata
void print_metadata(metadata meta) {
    printf("Filename: %s\n", meta.filename);
    printf("File size: %d bytes\n", meta.filesize);
    printf("Author: %s\n", meta.author);
    printf("Creation date: %s\n", meta.creationdate);
}

int main() {
    char filename[100];
    metadata meta;

    // Read metadata from a file
    printf("Enter the filename: ");
    scanf("%s", filename);
    meta = read_metadata(filename);

    // Print the metadata
    print_metadata(meta);

    // Write the metadata to a file
    char output_filename[100];
    printf("Enter the output filename: ");
    scanf("%s", output_filename);
    write_metadata(output_filename, meta);

    return 0;
}