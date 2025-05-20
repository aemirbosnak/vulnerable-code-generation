//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold metadata information
typedef struct {
    char *filename;
    int filesize;
    char *filetype;
    char *creationdate;
    char *modificationdate;
} Metadata;

// Function to extract metadata from a file
Metadata *extractMetadata(char *filename) {
    FILE *fp;
    char buff[1024];
    Metadata *metadata = (Metadata *)malloc(sizeof(Metadata));

    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    // Read the file contents into a buffer
    fread(buff, 1, 1024, fp);
    fclose(fp);

    // Extract the metadata information
    metadata->filename = strdup(filename);
    metadata->filesize = strlen(buff);
    metadata->filetype = strrchr(filename, '.') + 1;
    metadata->creationdate = "N/A";
    metadata->modificationdate = "N/A";

    return metadata;
}

// Function to print metadata information
void printMetadata(Metadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("File Size: %d bytes\n", metadata->filesize);
    printf("File Type: %s\n", metadata->filetype);
    printf("Creation Date: %s\n", metadata->creationdate);
    printf("Modification Date: %s\n", metadata->modificationdate);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    Metadata *metadata = extractMetadata(filename);
    printMetadata(metadata);

    free(metadata->filename);
    free(metadata);

    return 0;
}