//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_VALUE_SIZE 1000
#define MAX_NUM_KEYS 100

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} KeyValuePair;

int main() {
    int numKeys = 0;
    KeyValuePair keys[MAX_NUM_KEYS];

    FILE *fp = fopen("database.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open database file.\n");
        exit(1);
    }

    // Read in the key-value pairs from the file
    while (fscanf(fp, "%s %s\n", keys[numKeys].key, keys[numKeys].value)!= EOF) {
        numKeys++;
    }
    fclose(fp);

    // Sort the key-value pairs by key
    for (int i = 0; i < numKeys; i++) {
        for (int j = i + 1; j < numKeys; j++) {
            if (strcmp(keys[i].key, keys[j].key) > 0) {
                KeyValuePair temp = keys[i];
                keys[i] = keys[j];
                keys[j] = temp;
            }
        }
    }

    // Print out the sorted key-value pairs
    printf("Sorted key-value pairs:\n");
    for (int i = 0; i < numKeys; i++) {
        printf("%s -> %s\n", keys[i].key, keys[i].value);
    }

    // Search for a specific key and print its value
    char searchKey[MAX_KEY_SIZE];
    printf("\nEnter a key to search for: ");
    scanf("%s", searchKey);

    for (int i = 0; i < numKeys; i++) {
        if (strcmp(keys[i].key, searchKey) == 0) {
            printf("%s\n", keys[i].value);
            break;
        }
    }

    return 0;
}