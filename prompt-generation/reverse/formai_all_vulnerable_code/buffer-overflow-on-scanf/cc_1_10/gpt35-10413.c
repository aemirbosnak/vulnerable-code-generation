//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_METADATA_LENGTH 1024

char* extract_metadata(char* filename) {
    char metadata[MAX_METADATA_LENGTH];
    memset(metadata, 0, sizeof(metadata));

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found. Please try again.");
        exit(1);
    }

    bool found_metadata = false;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, file)) != -1) {
        if (strstr(line, "METADATA") != NULL) {
            found_metadata = true;
        } else if (found_metadata) {
            strcat(metadata, line);
        }
    }

    fclose(file);
    if (line) {
        free(line);
    }

    char* extracted = (char*)malloc(strlen(metadata) + 1);
    strcpy(extracted, metadata);

    return extracted;
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the filename: ");
    scanf("%s", filename);

    char* metadata = extract_metadata(filename);
    printf("Metadata:\n%s", metadata);
    free(metadata);

    return 0;
}