//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Define a custom structure for storing metadata
typedef struct {
    char *filename;
    int filesize;
    char *mimetype;
} metadata_t;

// Function for extracting metadata from a file
metadata_t *extract_metadata(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *buffer = malloc(filesize + 1);
    fread(buffer, filesize, 1, fp);
    fclose(fp);
    char *mimetype = strrchr(filename, '.');
    if (mimetype == NULL) {
        mimetype = "unknown";
    }
    metadata_t *metadata = malloc(sizeof(metadata_t));
    metadata->filename = strdup(filename);
    metadata->filesize = filesize;
    metadata->mimetype = strdup(mimetype);
    return metadata;
}

// Function for printing metadata
void print_metadata(const metadata_t *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("File Size: %d bytes\n", metadata->filesize);
    printf("MIME Type: %s\n", metadata->mimetype);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    metadata_t *metadata = extract_metadata(argv[1]);
    print_metadata(metadata);
    free(metadata->filename);
    free(metadata->mimetype);
    free(metadata);
    return 0;
}