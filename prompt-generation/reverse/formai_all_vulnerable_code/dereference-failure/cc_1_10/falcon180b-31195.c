//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 50
#define MAX_VALUE_LEN 200
#define MAX_INDEX_LEN 100

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
    int index;
} entry;

int compare_entries(const void *a, const void *b) {
    entry *e1 = (entry *) a;
    entry *e2 = (entry *) b;

    return strcmp(e1->key, e2->key);
}

void print_entries(entry *entries, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\n", entries[i].key, entries[i].value);
    }
}

int main() {
    int count = 0;
    entry *entries = NULL;

    printf("Enter number of entries: ");
    scanf("%d", &count);

    entries = (entry *) malloc(count * sizeof(entry));

    for (int i = 0; i < count; i++) {
        printf("Enter key for entry %d: ", i+1);
        scanf("%s", entries[i].key);
        printf("Enter value for entry %d: ", i+1);
        scanf("%s", entries[i].value);
        entries[i].index = i;
    }

    qsort(entries, count, sizeof(entry), compare_entries);

    printf("Sorted entries:\n");
    print_entries(entries, count);

    return 0;
}