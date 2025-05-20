//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 100
#define MAX_VALUE_LEN 1000
#define MAX_NUM_KEYS 100

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} KeyValuePair;

void loadDatabase(KeyValuePair db[], int numKeys) {
    FILE *fp;
    char line[MAX_VALUE_LEN];
    int i = 0;

    fp = fopen("database.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open database file.\n");
        exit(1);
    }

    while (fgets(line, MAX_VALUE_LEN, fp)!= NULL && i < numKeys) {
        char *token = strtok(line, ":");
        strcpy(db[i].key, token);

        token = strtok(NULL, ":");
        strcpy(db[i].value, token);

        i++;
    }

    fclose(fp);
}

int compareKeys(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void sortDatabase(KeyValuePair db[], int numKeys) {
    qsort(db, numKeys, sizeof(KeyValuePair), compareKeys);
}

void saveDatabase(KeyValuePair db[], int numKeys) {
    FILE *fp;
    int i;

    fp = fopen("database.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not open database file.\n");
        exit(1);
    }

    for (i = 0; i < numKeys; i++) {
        fprintf(fp, "%s:%s\n", db[i].key, db[i].value);
    }

    fclose(fp);
}

void searchDatabase(KeyValuePair db[], int numKeys, char searchKey[]) {
    int i;

    for (i = 0; i < numKeys; i++) {
        if (strcmp(db[i].key, searchKey) == 0) {
            printf("%s: %s\n", db[i].key, db[i].value);
        }
    }
}

int main() {
    KeyValuePair db[MAX_NUM_KEYS];
    int numKeys = 0;

    loadDatabase(db, numKeys);
    sortDatabase(db, numKeys);
    saveDatabase(db, numKeys);

    char searchKey[MAX_KEY_LEN];
    printf("Enter a key to search for: ");
    scanf("%s", searchKey);

    searchDatabase(db, numKeys, searchKey);

    return 0;
}