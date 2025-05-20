//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for metadata
typedef struct {
    char *key;
    char *value;
} Metadata;

// Function to extract metadata from a file
int extractMetadata(const char *filename, Metadata *metadata) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *key = strchr(line, ':');
        if (key!= NULL) {
            *key = '\0';
            key++;
            while (isspace(*key)) {
                key++;
            }

            char *value = strchr(key, ':');
            if (value!= NULL) {
                *value = '\0';
                value++;
                while (isspace(*value)) {
                    value++;
                }

                metadata->key = strdup(key);
                metadata->value = strdup(value);

                return 0;
            }
        }
    }

    fclose(file);
    return 1;
}

// Function to print metadata
void printMetadata(Metadata *metadata) {
    if (metadata->key!= NULL && metadata->value!= NULL) {
        printf("%s: %s\n", metadata->key, metadata->value);
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Metadata metadata;

    int result = extractMetadata(argv[1], &metadata);
    if (result == 0) {
        printMetadata(&metadata);
    }

    if (metadata.key!= NULL) {
        free(metadata.key);
    }

    if (metadata.value!= NULL) {
        free(metadata.value);
    }

    return 0;
}