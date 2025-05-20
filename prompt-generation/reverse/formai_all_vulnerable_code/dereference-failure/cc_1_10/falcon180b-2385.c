//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEYS 100
#define MAX_VALUES 1000
#define MAX_LINE_LENGTH 500

typedef struct {
    char *key;
    char *value;
} KeyValuePair;

int main(int argc, char *argv[]) {
    FILE *inputFile;
    char line[MAX_LINE_LENGTH];
    char *currentKey = NULL;
    char *currentValue = NULL;
    int currentKeyLength = 0;
    int currentValueLength = 0;
    int numKeys = 0;
    KeyValuePair keys[MAX_KEYS];

    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, inputFile)!= NULL) {
        char *token = strtok(line, ":");
        if (token == NULL) {
            continue;
        }

        if (numKeys >= MAX_KEYS) {
            printf("Error: too many keys.\n");
            exit(1);
        }

        if (currentKey!= NULL) {
            keys[numKeys - 1].key = strdup(currentKey);
            keys[numKeys - 1].value = strdup(currentValue);
        }

        currentKey = strdup(token);
        currentKeyLength = strlen(currentKey);
        currentValue = NULL;
        currentValueLength = 0;
        numKeys++;
    }

    if (currentKey!= NULL) {
        keys[numKeys - 1].key = strdup(currentKey);
        keys[numKeys - 1].value = strdup(currentValue);
    }

    fclose(inputFile);

    printf("Number of keys: %d\n", numKeys);
    for (int i = 0; i < numKeys; i++) {
        printf("Key %d: %s\n", i, keys[i].key);
        printf("Value %d: %s\n", i, keys[i].value);
    }

    for (int i = 0; i < numKeys; i++) {
        free(keys[i].key);
        free(keys[i].value);
    }

    return 0;
}