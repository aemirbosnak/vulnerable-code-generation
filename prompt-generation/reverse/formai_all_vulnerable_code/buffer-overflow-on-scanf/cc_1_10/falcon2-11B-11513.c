//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 20
#define MAX_INDEX_LEN 8

typedef struct {
    char name[MAX_NAME_LEN];
    char index[MAX_INDEX_LEN];
} IndexEntry;

IndexEntry* createIndexEntry(char* name) {
    IndexEntry* entry = (IndexEntry*) malloc(sizeof(IndexEntry));
    if (entry == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    strcpy(entry->name, name);
    entry->index[0] = '\0';
    return entry;
}

IndexEntry* findIndexEntry(IndexEntry* entries, char* name) {
    for (int i = 0; entries[i].index[0]!= '\0'; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            return entries + i;
        }
    }
    return NULL;
}

int main() {
    IndexEntry entries[100];
    int numEntries = 0;

    while (1) {
        printf("Enter name (or 'quit' to exit): ");
        char name[MAX_NAME_LEN];
        scanf("%s", name);
        if (strcmp(name, "quit") == 0) {
            break;
        }
        IndexEntry* entry = createIndexEntry(name);
        if (entry == NULL) {
            continue;
        }
        entries[numEntries++] = *entry;
        printf("%s indexed under %s\n", name, entry->index);
    }

    printf("Enter name to find index: ");
    char findName[MAX_NAME_LEN];
    scanf("%s", findName);
    IndexEntry* foundEntry = findIndexEntry(entries, findName);
    if (foundEntry!= NULL) {
        printf("%s is indexed under %s\n", findName, foundEntry->index);
    } else {
        printf("%s not found in index\n", findName);
    }

    free(entries);
    return 0;
}