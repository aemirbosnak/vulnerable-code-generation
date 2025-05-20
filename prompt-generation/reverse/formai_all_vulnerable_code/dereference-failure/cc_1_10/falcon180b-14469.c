//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_VALUE_PAIRS 100

typedef struct {
    char* key;
    char* value;
} KeyValuePair;

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <metadata file>\n", argv[0]);
        return 1;
    }

    FILE* metadataFile = fopen(argv[1], "r");
    if (metadataFile == NULL) {
        printf("Error opening metadata file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int numKeyValuePairs = 0;
    KeyValuePair keyValuePairs[MAX_KEY_VALUE_PAIRS];

    while (fgets(line, MAX_LINE_LENGTH, metadataFile)!= NULL) {
        char* key = strtok(line, ":");
        char* value = strtok(NULL, "\n");

        if (key == NULL || value == NULL) {
            printf("Invalid metadata format.\n");
            fclose(metadataFile);
            return 1;
        }

        if (numKeyValuePairs >= MAX_KEY_VALUE_PAIRS) {
            printf("Too many key-value pairs.\n");
            fclose(metadataFile);
            return 1;
        }

        keyValuePairs[numKeyValuePairs].key = strdup(key);
        keyValuePairs[numKeyValuePairs].value = strdup(value);
        numKeyValuePairs++;
    }

    fclose(metadataFile);

    for (int i = 0; i < numKeyValuePairs; i++) {
        printf("%s: %s\n", keyValuePairs[i].key, keyValuePairs[i].value);
    }

    for (int i = 0; i < numKeyValuePairs; i++) {
        free(keyValuePairs[i].key);
        free(keyValuePairs[i].value);
    }

    return 0;
}