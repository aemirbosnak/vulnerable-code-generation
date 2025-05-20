//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000
#define MAX_NUM_KEYS 100
#define MAX_NUM_VALUES 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} KeyValuePair;

int main() {
    int numKeys, numValues;
    char input[MAX_VALUE_LENGTH];
    KeyValuePair *keyValuePairs = NULL;

    printf("Enter the number of key-value pairs: ");
    scanf("%d", &numKeys);

    keyValuePairs = (KeyValuePair *)malloc(numKeys * sizeof(KeyValuePair));

    printf("Enter the key-value pairs:\n");
    for (int i = 0; i < numKeys; i++) {
        printf("Key %d: ", i + 1);
        scanf("%s", keyValuePairs[i].key);
        printf("Value %d: ", i + 1);
        scanf("%s", input);
        strncpy(keyValuePairs[i].value, input, MAX_VALUE_LENGTH);
    }

    printf("Enter the number of search keys: ");
    scanf("%d", &numValues);

    char *searchKeys = (char *)malloc(numValues * MAX_KEY_LENGTH);

    printf("Enter the search keys:\n");
    for (int i = 0; i < numValues; i++) {
        printf("Search key %d: ", i + 1);
        scanf("%s", searchKeys + i * MAX_KEY_LENGTH);
    }

    char *results = (char *)malloc(MAX_VALUE_LENGTH * numValues);
    int numResults = 0;

    for (int i = 0; i < numValues; i++) {
        int j;
        for (j = 0; j < numKeys; j++) {
            if (strcmp(keyValuePairs[j].key, searchKeys + i * MAX_KEY_LENGTH) == 0) {
                strncpy(results + numResults * MAX_VALUE_LENGTH, keyValuePairs[j].value, MAX_VALUE_LENGTH);
                numResults++;
                break;
            }
        }
    }

    printf("Search results:\n");
    for (int i = 0; i < numResults; i++) {
        printf("Result %d: %s\n", i + 1, results + i * MAX_VALUE_LENGTH);
    }

    free(keyValuePairs);
    free(searchKeys);
    free(results);

    return 0;
}