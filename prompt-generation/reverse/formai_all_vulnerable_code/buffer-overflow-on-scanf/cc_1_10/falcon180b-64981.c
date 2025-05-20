//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000
#define MAX_NUM_KEYS 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} KeyValue;

void addKeyValue(KeyValue* kv, char* key, char* value) {
    strncpy(kv->key, key, MAX_KEY_LENGTH);
    strncpy(kv->value, value, MAX_VALUE_LENGTH);
}

int compareKeys(const void* a, const void* b) {
    KeyValue* kvA = (KeyValue*)a;
    KeyValue* kvB = (KeyValue*)b;
    return strcmp(kvA->key, kvB->key);
}

int main() {
    int numKeys = 0;
    KeyValue* kvArray = malloc(MAX_NUM_KEYS * sizeof(KeyValue));
    if (kvArray == NULL) {
        printf("Error: could not allocate memory for key-value array.\n");
        return 1;
    }

    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];

    while (1) {
        printf("Enter a key (or type 'done' to finish): ");
        scanf("%s", key);
        if (strcmp(key, "done") == 0) {
            break;
        }

        printf("Enter a value: ");
        scanf("%s", value);

        addKeyValue(&kvArray[numKeys], key, value);
        numKeys++;
    }

    qsort(kvArray, numKeys, sizeof(KeyValue), compareKeys);

    for (int i = 0; i < numKeys; i++) {
        printf("%s: %s\n", kvArray[i].key, kvArray[i].value);
    }

    free(kvArray);
    return 0;
}