//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_VALUE_PAIRS 100

typedef struct {
    char key[MAX_LINE_LENGTH];
    char value[MAX_LINE_LENGTH];
} KeyValuePair;

int main(int argc, char **argv) {
    FILE *inputFile;
    char line[MAX_LINE_LENGTH];
    int numKeyValuePairs = 0;
    KeyValuePair *keyValuePairs = (KeyValuePair *) malloc(sizeof(KeyValuePair) * MAX_KEY_VALUE_PAIRS);

    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }

    inputFile = fopen(argv[1], "r");

    if (inputFile == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        exit(2);
    }

    while (fgets(line, MAX_LINE_LENGTH, inputFile)!= NULL) {
        int keyLen = strlen(line);
        char *equalSign = strchr(line, '=');
        if (equalSign == NULL) {
            printf("Error: malformed line '%s'\n", line);
            exit(3);
        }
        int valueLen = strlen(equalSign + 1);
        if (keyLen + valueLen + 2 > MAX_LINE_LENGTH) {
            printf("Error: line too long '%s'\n", line);
            exit(4);
        }
        strncpy(keyValuePairs[numKeyValuePairs].key, line, keyLen);
        strncpy(keyValuePairs[numKeyValuePairs].value, equalSign + 1, valueLen);
        numKeyValuePairs++;
        if (numKeyValuePairs == MAX_KEY_VALUE_PAIRS) {
            printf("Error: too many key-value pairs found\n");
            exit(5);
        }
    }

    fclose(inputFile);

    printf("Found %d key-value pairs:\n", numKeyValuePairs);
    for (int i = 0; i < numKeyValuePairs; i++) {
        printf("Key: %s\nValue: %s\n", keyValuePairs[i].key, keyValuePairs[i].value);
    }

    free(keyValuePairs);
    return 0;
}