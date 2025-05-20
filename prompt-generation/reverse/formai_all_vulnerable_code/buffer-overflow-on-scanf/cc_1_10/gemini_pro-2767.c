//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *name;
    char *number;
} Entry;

int compareEntries(const void *a, const void *b) {
    Entry *entryA = (Entry *)a;
    Entry *entryB = (Entry *)b;
    return strcmp(entryA->name, entryB->name);
}

int main() {
    int numEntries;
    Entry *entries;

    // Read the number of entries
    printf("Enter the number of entries: ");
    scanf("%d", &numEntries);

    // Allocate memory for the entries
    entries = (Entry *)malloc(sizeof(Entry) * numEntries);

    // Read the entries
    for (int i = 0; i < numEntries; i++) {
        printf("Enter the name of entry %d: ", i + 1);
        char *name = (char *)malloc(sizeof(char) * 100);
        scanf("%s", name);
        entries[i].name = name;

        printf("Enter the number of entry %d: ", i + 1);
        char *number = (char *)malloc(sizeof(char) * 100);
        scanf("%s", number);
        entries[i].number = number;
    }

    // Sort the entries
    qsort(entries, numEntries, sizeof(Entry), compareEntries);

    // Print the entries
    for (int i = 0; i < numEntries; i++) {
        printf("%s: %s\n", entries[i].name, entries[i].number);
    }

    // Free the memory
    for (int i = 0; i < numEntries; i++) {
        free(entries[i].name);
        free(entries[i].number);
    }
    free(entries);

    return 0;
}