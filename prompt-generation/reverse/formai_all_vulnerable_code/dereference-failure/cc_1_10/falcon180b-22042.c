//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_VALUE_PAIRS 100

typedef struct {
    char* key;
    char* value;
} KeyValuePair;

KeyValuePair* extractMetadata(char* metadata, int* numPairs) {
    KeyValuePair* pairs = malloc(MAX_KEY_VALUE_PAIRS * sizeof(KeyValuePair));
    int count = 0;

    // Extract key-value pairs from metadata
    char* line = strtok(metadata, "\n");
    while (line!= NULL && count < MAX_KEY_VALUE_PAIRS) {
        // Split line into key-value pair
        char* keyEnd = strchr(line, ':');
        if (keyEnd!= NULL) {
            *keyEnd = '\0';
            char* key = line;
            char* value = keyEnd + 1;

            // Add key-value pair to array
            pairs[count] = (KeyValuePair) {.key = strdup(key),.value = strdup(value) };
            count++;
        }

        line = strtok(NULL, "\n");
    }

    *numPairs = count;
    return pairs;
}

void printMetadata(KeyValuePair* pairs, int numPairs) {
    for (int i = 0; i < numPairs; i++) {
        printf("%s: %s\n", pairs[i].key, pairs[i].value);
    }
}

int main() {
    char metadata[MAX_LINE_LENGTH];
    printf("Enter metadata:\n");
    fgets(metadata, MAX_LINE_LENGTH, stdin);

    int numPairs;
    KeyValuePair* pairs = extractMetadata(metadata, &numPairs);
    printMetadata(pairs, numPairs);

    for (int i = 0; i < numPairs; i++) {
        free(pairs[i].key);
        free(pairs[i].value);
    }
    free(pairs);

    return 0;
}