//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024*1024*10)
#define MAX_PATH_LENGTH 1024

typedef struct {
    char *filename;
    char *metadata;
} FileMetadata;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    char *buffer = malloc(MAX_FILE_SIZE);
    if (buffer == NULL) {
        printf("Out of memory\n");
        return 1;
    }

    size_t bytes_read = fread(buffer, 1, MAX_FILE_SIZE, file);
    if (bytes_read == 0) {
        printf("Error reading file: %s\n", filename);
        free(buffer);
        return 1;
    }

    fclose(file);

    char *metadata_start = strstr(buffer, "<!-- METADATA -->");
    if (metadata_start == NULL) {
        printf("No metadata found in file: %s\n", filename);
        free(buffer);
        return 0;
    }

    char *metadata_end = strstr(metadata_start, "<!-- /METADATA -->");
    if (metadata_end == NULL) {
        printf("Invalid metadata format in file: %s\n", filename);
        free(buffer);
        return 1;
    }

    *metadata_end = '\0';
    char *metadata = metadata_start + strlen("<!-- METADATA -->");

    FileMetadata file_metadata = {
       .filename = filename,
       .metadata = metadata
    };

    printf("Filename: %s\n", file_metadata.filename);
    printf("Metadata:\n%s\n", file_metadata.metadata);

    free(buffer);
    return 0;
}