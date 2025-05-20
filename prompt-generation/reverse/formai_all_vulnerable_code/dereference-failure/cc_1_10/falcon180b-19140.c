//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 64
#define MAX_VALUE_LENGTH 1024
#define MAX_NUM_KEY_VALUE_PAIRS 1024

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} KeyValuePair;

int numKeyValuePairs = 0;
KeyValuePair keyValuePairs[MAX_NUM_KEY_VALUE_PAIRS];

void addKeyValuePair(char* key, char* value) {
    if (numKeyValuePairs >= MAX_NUM_KEY_VALUE_PAIRS) {
        printf("Error: Maximum number of key-value pairs reached.\n");
        exit(1);
    }
    strcpy(keyValuePairs[numKeyValuePairs].key, key);
    strcpy(keyValuePairs[numKeyValuePairs].value, value);
    numKeyValuePairs++;
}

bool isKeyValuePairLine(char* line) {
    int i;
    for (i = 0; i < strlen(line); i++) {
        if (!isprint(line[i])) {
            return false;
        }
    }
    return true;
}

void extractMetadata() {
    FILE* metadataFile = fopen("metadata.txt", "r");
    if (metadataFile == NULL) {
        printf("Error: Could not open metadata file.\n");
        exit(1);
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, metadataFile)!= NULL) {
        if (isKeyValuePairLine(line)) {
            char* key = line;
            char* value = strchr(line, ':');
            if (value == NULL) {
                printf("Error: Invalid key-value pair format.\n");
                exit(1);
            }
            *value = '\0';
            value++;
            while (isspace(*value)) {
                value++;
            }
            addKeyValuePair(key, value);
        }
    }
    fclose(metadataFile);
}

void printKeyValuePairs() {
    printf("Key-Value Pairs:\n");
    int i;
    for (i = 0; i < numKeyValuePairs; i++) {
        printf("%s: %s\n", keyValuePairs[i].key, keyValuePairs[i].value);
    }
}

int main() {
    extractMetadata();
    printKeyValuePairs();
    return 0;
}