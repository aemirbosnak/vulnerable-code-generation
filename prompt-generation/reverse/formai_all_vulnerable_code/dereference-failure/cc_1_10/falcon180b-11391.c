//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_METADATA 100

typedef struct {
    char *key;
    char *value;
} Metadata;

int main() {
    char *filename = "example.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int num_metadata = 0;
    Metadata *metadata = NULL;

    // Read in metadata from file
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (line[0] == '#') {
            char *delimiter = strchr(line, ':');
            if (delimiter == NULL) {
                printf("Error: invalid metadata format in line %d\n", num_metadata + 1);
                return 1;
            }
            *delimiter = '\0';
            char *key = strdup(line + 1);
            char *value = strdup(delimiter + 1);

            if (num_metadata == MAX_NUM_METADATA) {
                printf("Error: too many metadata items\n");
                return 1;
            }

            metadata = realloc(metadata, sizeof(Metadata) * (num_metadata + 1));
            metadata[num_metadata].key = key;
            metadata[num_metadata].value = value;
            num_metadata++;
        }
    }

    // Print out metadata
    printf("Metadata:\n");
    for (int i = 0; i < num_metadata; i++) {
        printf("%s: %s\n", metadata[i].key, metadata[i].value);
    }

    // Free memory
    for (int i = 0; i < num_metadata; i++) {
        free(metadata[i].key);
        free(metadata[i].value);
    }
    free(metadata);

    fclose(file);

    return 0;
}