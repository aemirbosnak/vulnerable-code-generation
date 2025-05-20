//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for metadata
typedef struct {
    char *filename;
    int filesize;
    char *mimetype;
    int width;
    int height;
} Metadata;

// Function to extract metadata from a file
Metadata *extractMetadata(char *filename) {
    FILE *fp;
    Metadata *metadata = malloc(sizeof(Metadata));
    metadata->filename = strdup(filename);
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    metadata->filesize = ftell(fp);
    rewind(fp);
    char buffer[3];
    fread(buffer, 1, 3, fp);
    if (strcmp(buffer, "GIF") == 0) {
        metadata->mimetype = strdup("image/gif");
    } else if (strcmp(buffer, "JFIF") == 0) {
        metadata->mimetype = strdup("image/jpeg");
    } else if (strcmp(buffer, "II*") == 0) {
        metadata->mimetype = strdup("image/tiff");
    } else {
        metadata->mimetype = strdup("application/octet-stream");
    }
    fclose(fp);
    return metadata;
}

// Function to print metadata
void printMetadata(Metadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("Filesize: %d bytes\n", metadata->filesize);
    printf("MIME Type: %s\n", metadata->mimetype);
}

// Main function
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    Metadata *metadata = extractMetadata(argv[1]);
    printMetadata(metadata);
    free(metadata->filename);
    free(metadata->mimetype);
    free(metadata);
    return 0;
}