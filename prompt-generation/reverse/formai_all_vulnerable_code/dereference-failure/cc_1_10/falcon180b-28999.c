//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_KEYS 100
#define MAX_KEY_LENGTH 256
#define MAX_VALUE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} KeyValuePair;

int main(int argc, char *argv[]) {
    FILE *inputFile;
    char line[MAX_LINE_LENGTH];
    char *token;
    int numKeys = 0;
    KeyValuePair *keyValuePairs = NULL;
    char *key = NULL;
    char *value = NULL;
    int keyLength = 0;
    int valueLength = 0;

    // Open input file
    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Read input file line by line
    while (fgets(line, MAX_LINE_LENGTH, inputFile)!= NULL) {
        // Extract key-value pairs from each line
        token = strtok(line, "=");
        while (token!= NULL) {
            // Check if we have reached the maximum number of keys
            if (numKeys >= MAX_NUM_KEYS) {
                printf("Error: Maximum number of keys exceeded!\n");
                exit(1);
            }

            // Allocate memory for key and value
            key = malloc(MAX_KEY_LENGTH);
            value = malloc(MAX_VALUE_LENGTH);

            // Copy key and value from line
            strncpy(key, token, MAX_KEY_LENGTH);
            keyLength = strlen(key);
            strncpy(value, strchr(line, '=') + 1, MAX_VALUE_LENGTH);
            valueLength = strlen(value);

            // Add key-value pair to array
            keyValuePairs = realloc(keyValuePairs, (numKeys + 1) * sizeof(KeyValuePair));
            keyValuePairs[numKeys].key = key;
            keyValuePairs[numKeys].value = value;
            numKeys++;

            // Move to next token
            token = strtok(NULL, "=");
        }
    }

    // Close input file
    fclose(inputFile);

    // Print key-value pairs
    printf("Key-Value Pairs:\n");
    for (int i = 0; i < numKeys; i++) {
        printf("Key: %s\nValue: %s\n", keyValuePairs[i].key, keyValuePairs[i].value);
    }

    // Free memory
    for (int i = 0; i < numKeys; i++) {
        free(keyValuePairs[i].key);
        free(keyValuePairs[i].value);
    }
    free(keyValuePairs);

    return 0;
}