//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME 50
#define MAX_VALUE 100

typedef struct {
    char name[MAX_NAME];
    char value[MAX_VALUE];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

int compare_entries(const void *a, const void *b) {
    entry_t *e1 = (entry_t *)a;
    entry_t *e2 = (entry_t *)b;
    return strcmp(e1->name, e2->name);
}

void add_entry(char *name, char *value) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Too many entries.\n");
        return;
    }
    strncpy(entries[num_entries].name, name, MAX_NAME);
    strncpy(entries[num_entries].value, value, MAX_VALUE);
    num_entries++;
}

void search_entries(char *name) {
    qsort(entries, num_entries, sizeof(entry_t), compare_entries);
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Found entry: %s = %s\n", entries[i].name, entries[i].value);
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    char name[MAX_NAME];
    char value[MAX_VALUE];
    int choice;
    do {
        printf("1. Add entry\n2. Search entry\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter value: ");
            scanf("%s", value);
            add_entry(name, value);
            break;
        case 2:
            printf("Enter name to search: ");
            scanf("%s", name);
            search_entries(name);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (1);
    return 0;
}