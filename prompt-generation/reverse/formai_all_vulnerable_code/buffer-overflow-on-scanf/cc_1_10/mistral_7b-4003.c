//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_METADATA_LENGTH 200

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char author[MAX_METADATA_LENGTH];
    char title[MAX_METADATA_LENGTH];
} Metadata;

void extract_metadata(char *filepath, Metadata *metadata) {
    FILE *file = fopen(filepath, "r");
    char line[MAX_METADATA_LENGTH];
    char *token;
    char *line_start = NULL;

    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file %s\n", filepath);
        metadata->author[0] = '\0';
        metadata->title[0] = '\0';
        return;
    }

    // Read the first line to find the title
    fgets(line, MAX_METADATA_LENGTH, file);
    line_start = strchr(line, ':') + 1;
    strncpy(metadata->title, line_start, MAX_METADATA_LENGTH);
    metadata->title[MAX_METADATA_LENGTH - 1] = '\0';

    // Read the second line to find the author
    fgets(line, MAX_METADATA_LENGTH, file);
    line_start = strchr(line, ':') + 1;
    strncpy(metadata->author, line_start, MAX_METADATA_LENGTH);
    metadata->author[MAX_METADATA_LENGTH - 1] = '\0';

    fclose(file);

    // Set the filename based on the input filepath
    strcpy(metadata->filename, filepath);
}

int main() {
    char input_filepath[MAX_FILENAME_LENGTH];
    Metadata metadata;

    printf("Enter the filepath: ");
    scanf("%s", input_filepath);

    extract_metadata(input_filepath, &metadata);

    printf("\nMetadata extracted from %s:\n", metadata.filename);
    printf("Title: %s\n", metadata.title);
    printf("Author: %s\n", metadata.author);

    return 0;
}