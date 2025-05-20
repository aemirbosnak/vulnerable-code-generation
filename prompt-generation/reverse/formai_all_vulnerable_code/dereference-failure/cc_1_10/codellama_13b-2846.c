//Code Llama-13B DATASET v1.0 Category: Metadata Extractor ; Style: peaceful
/*
 * C Metadata Extractor Example Program
 *
 * This program extracts metadata from a C source file.
 *
 * Usage:
 *   ./extractor <source_file>
 *
 * Output:
 *   Prints the metadata of the source file in a structured format.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_SIZE 1024

/*
 * Metadata structure
 *
 * Contains the metadata of a source file.
 */
struct metadata {
    char file_name[MAX_METADATA_SIZE];
    char author[MAX_METADATA_SIZE];
    char date[MAX_METADATA_SIZE];
};

/*
 * Extract metadata from a source file
 *
 * @param source_file The source file to extract metadata from
 * @return The extracted metadata
 */
struct metadata extract_metadata(const char *source_file) {
    FILE *file = fopen(source_file, "r");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    size_t line_len = 0;

    struct metadata metadata;
    memset(&metadata, 0, sizeof(metadata));

    while (getline(&line, &line_len, file) != -1) {
        // Parse the line for metadata
        if (strstr(line, "file_name") != NULL) {
            strncpy(metadata.file_name, line + 9, MAX_METADATA_SIZE - 1);
        } else if (strstr(line, "author") != NULL) {
            strncpy(metadata.author, line + 6, MAX_METADATA_SIZE - 1);
        } else if (strstr(line, "date") != NULL) {
            strncpy(metadata.date, line + 4, MAX_METADATA_SIZE - 1);
        }
    }

    free(line);
    fclose(file);

    return metadata;
}

/*
 * Print metadata in a structured format
 *
 * @param metadata The metadata to print
 */
void print_metadata(const struct metadata metadata) {
    printf("File name: %s\n", metadata.file_name);
    printf("Author: %s\n", metadata.author);
    printf("Date: %s\n", metadata.date);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <source_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct metadata metadata = extract_metadata(argv[1]);
    print_metadata(metadata);

    return 0;
}