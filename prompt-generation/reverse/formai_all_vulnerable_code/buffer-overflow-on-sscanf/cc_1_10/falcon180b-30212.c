//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 100

typedef struct {
    char name[MAX_ENTRY_LENGTH];
    int age;
    char city[MAX_ENTRY_LENGTH];
} Entry;

void init_entry(Entry* entry) {
    strcpy(entry->name, "");
    entry->age = 0;
    strcpy(entry->city, "");
}

int compare_entries(const void* a, const void* b) {
    const Entry* entryA = (const Entry*)a;
    const Entry* entryB = (const Entry*)b;

    int result = strcmp(entryA->name, entryB->name);
    if (result == 0) {
        result = entryA->age - entryB->age;
    }

    return result;
}

void print_entry(const Entry* entry) {
    printf("Name: %s\n", entry->name);
    printf("Age: %d\n", entry->age);
    printf("City: %s\n", entry->city);
}

int main() {
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    FILE* file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[MAX_ENTRY_LENGTH];
    while (fgets(line, sizeof(line), file)!= NULL) {
        Entry entry;
        init_entry(&entry);

        sscanf(line, "%s %d %s", entry.name, &entry.age, entry.city);
        entries[num_entries++] = entry;
    }

    fclose(file);

    qsort(entries, num_entries, sizeof(Entry), compare_entries);

    printf("Sorted entries:\n");
    for (int i = 0; i < num_entries; i++) {
        print_entry(&entries[i]);
    }

    return 0;
}