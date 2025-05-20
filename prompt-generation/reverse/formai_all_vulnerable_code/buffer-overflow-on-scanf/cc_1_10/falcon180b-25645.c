//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000
#define MAX_NUM_KEYS 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} KeyValuePair;

int main() {
    FILE *indexFile;
    KeyValuePair *keyValuePairs;
    int numKeyValuePairs;

    // Open index file for reading
    indexFile = fopen("index.txt", "r");
    if (indexFile == NULL) {
        printf("Error: Could not open index file.\n");
        exit(1);
    }

    // Read number of key-value pairs from index file
    fscanf(indexFile, "%d", &numKeyValuePairs);

    // Allocate memory for key-value pairs
    keyValuePairs = (KeyValuePair *)malloc(numKeyValuePairs * sizeof(KeyValuePair));

    // Read key-value pairs from index file
    for (int i = 0; i < numKeyValuePairs; i++) {
        fscanf(indexFile, "%s %s", keyValuePairs[i].key, keyValuePairs[i].value);
    }

    // Close index file
    fclose(indexFile);

    // Prompt user for search key
    char searchKey[MAX_KEY_LENGTH];
    printf("Enter search key: ");
    scanf("%s", searchKey);

    // Search for key in key-value pairs
    int keyFound = 0;
    for (int i = 0; i < numKeyValuePairs; i++) {
        if (strcmp(keyValuePairs[i].key, searchKey) == 0) {
            printf("Value for key '%s': %s\n", searchKey, keyValuePairs[i].value);
            keyFound = 1;
            break;
        }
    }

    // Free memory for key-value pairs
    free(keyValuePairs);

    return 0;
}