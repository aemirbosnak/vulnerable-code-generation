//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_KEY_LEN 50
#define MAX_VALUE_LEN 200

typedef struct entry {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} Entry;

int compare(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void createIndex(Entry entries[], int numEntries) {
    qsort(entries, numEntries, sizeof(Entry), compare);
}

int main() {
    FILE *fp;
    char line[MAX_VALUE_LEN];
    int numEntries = 0;
    Entry entries[MAX_ENTRIES];

    fp = fopen("database.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open database file.\n");
        exit(1);
    }

    while (fgets(line, MAX_VALUE_LEN, fp)!= NULL) {
        if (numEntries >= MAX_ENTRIES) {
            printf("Error: Maximum number of entries reached.\n");
            exit(1);
        }

        char *key = strtok(line, ":");
        char *value = strtok(NULL, ":");

        strcpy(entries[numEntries].key, key);
        strcpy(entries[numEntries].value, value);

        numEntries++;
    }

    fclose(fp);

    createIndex(entries, numEntries);

    printf("Database Index Created\n");

    return 0;
}