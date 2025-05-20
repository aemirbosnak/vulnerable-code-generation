//Code Llama-13B DATASET v1.0 Category: Metadata Extractor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_METADATA_LEN 1024

typedef struct {
    char name[MAX_METADATA_LEN];
    char value[MAX_METADATA_LEN];
} Metadata;

Metadata* extract_metadata(char* input, int* num_metadata) {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    Metadata* metadata = NULL;
    int num_lines = 0;

    while ((read = getline(&line, &len, input)) != -1) {
        if (strncmp(line, "---", 3) == 0) {
            // Found a metadata line
            char* name = strtok(line, ":");
            char* value = strtok(NULL, ":");
            if (name && value) {
                Metadata* new_metadata = realloc(metadata, (num_lines + 1) * sizeof(Metadata));
                if (!new_metadata) {
                    perror("realloc");
                    exit(1);
                }
                metadata = new_metadata;
                strncpy(metadata[num_lines].name, name, MAX_METADATA_LEN);
                strncpy(metadata[num_lines].value, value, MAX_METADATA_LEN);
                num_lines++;
            }
        }
    }

    *num_metadata = num_lines;
    return metadata;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }

    FILE* input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("fopen");
        exit(1);
    }

    char* input = NULL;
    size_t len = 0;
    ssize_t read;
    int num_metadata;

    while ((read = getline(&input, &len, input_file)) != -1) {
        Metadata* metadata = extract_metadata(input, &num_metadata);
        for (int i = 0; i < num_metadata; i++) {
            printf("%s: %s\n", metadata[i].name, metadata[i].value);
        }
        free(metadata);
    }

    fclose(input_file);
    free(input);
    return 0;
}