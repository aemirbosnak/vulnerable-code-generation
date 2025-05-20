//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 100
#define MAX_NUM_KEYS 100
#define MAX_NUM_VALUES 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} KeyValuePair;

void createIndex(KeyValuePair* index, int numKeys) {
    for (int i = 0; i < numKeys; i++) {
        char key[MAX_KEY_LENGTH];
        char value[MAX_VALUE_LENGTH];

        printf("Enter key %d: ", i+1);
        scanf("%s", key);

        printf("Enter value for %s: ", key);
        scanf("%s", value);

        strcpy(index[i].key, key);
        strcpy(index[i].value, value);
    }
}

void searchIndex(KeyValuePair* index, int numKeys, char* searchKey) {
    for (int i = 0; i < numKeys; i++) {
        if (strcmp(index[i].key, searchKey) == 0) {
            printf("Value for %s: %s\n", searchKey, index[i].value);
            return;
        }
    }
    printf("No value found for key %s\n", searchKey);
}

int main() {
    int numKeys;

    printf("Enter number of keys: ");
    scanf("%d", &numKeys);

    KeyValuePair index[MAX_NUM_KEYS];
    createIndex(index, numKeys);

    char searchKey[MAX_KEY_LENGTH];

    while (1) {
        printf("Enter key to search: ");
        scanf("%s", searchKey);

        searchIndex(index, numKeys, searchKey);
    }

    return 0;
}