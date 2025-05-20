//Code Llama-13B DATASET v1.0 Category: Metadata Extractor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct {
    char *name;
    char *value;
} Metadata;

Metadata *extract_metadata(const char *input, int *count) {
    char *buffer = NULL;
    char *token = NULL;
    char *saveptr = NULL;
    int i = 0;
    Metadata *metadata = NULL;

    // allocate memory for the metadata array
    metadata = (Metadata *)malloc(sizeof(Metadata) * *count);

    // loop through each line of the input string
    while (fgets(buffer, MAX_BUFFER_SIZE, input)) {
        // tokenize each line using the colon delimiter
        token = strtok_r(buffer, ":", &saveptr);
        // skip the first token (name) and use the second token (value)
        token = strtok_r(NULL, ":", &saveptr);
        // allocate memory for the name and value
        metadata[i].name = (char *)malloc(strlen(token) + 1);
        metadata[i].value = (char *)malloc(strlen(token) + 1);
        // copy the name and value to the metadata structure
        strcpy(metadata[i].name, token);
        strcpy(metadata[i].value, token);
        i++;
    }

    return metadata;
}

int main() {
    int count = 0;
    Metadata *metadata = NULL;

    // input string
    char input[] = "name:value\nname2:value2\nname3:value3";

    // extract the metadata from the input string
    metadata = extract_metadata(input, &count);

    // print the metadata
    for (int i = 0; i < count; i++) {
        printf("Name: %s\nValue: %s\n", metadata[i].name, metadata[i].value);
    }

    // free the memory allocated for the metadata
    for (int i = 0; i < count; i++) {
        free(metadata[i].name);
        free(metadata[i].value);
    }
    free(metadata);

    return 0;
}