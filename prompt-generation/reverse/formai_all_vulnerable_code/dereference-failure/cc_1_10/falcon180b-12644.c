//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Metadata struct
typedef struct {
    char *filename;
    int filesize;
    char *mimetype;
    char *creationdate;
} Metadata;

// Function to extract metadata from a file
Metadata extract_metadata(const char *filename) {
    FILE *fp;
    Metadata metadata = {0};

    // Open the file
    fp = fopen(filename, "rb");
    if (!fp) {
        metadata.filename = strdup("Error opening file");
        return metadata;
    }

    // Get the file size
    fseek(fp, 0, SEEK_END);
    metadata.filesize = ftell(fp);
    rewind(fp);

    // Get the MIME type
    char buffer[1024];
    fgets(buffer, sizeof(buffer), fp);
    metadata.mimetype = strdup(buffer);

    // Get the creation date
    char *creation_date_ptr = strstr(metadata.mimetype, "creation-date:");
    if (creation_date_ptr) {
        creation_date_ptr += strlen("creation-date:");
        metadata.creationdate = strdup(creation_date_ptr);
    } else {
        metadata.creationdate = strdup("");
    }

    // Close the file
    fclose(fp);

    metadata.filename = strdup(filename);

    return metadata;
}

// Function to print metadata
void print_metadata(const Metadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("File size: %d bytes\n", metadata->filesize);
    printf("MIME type: %s\n", metadata->mimetype);
    printf("Creation date: %s\n", metadata->creationdate);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Metadata metadata = extract_metadata(argv[1]);
    print_metadata(&metadata);

    // Free memory
    free(metadata.filename);
    free(metadata.mimetype);
    free(metadata.creationdate);

    return 0;
}