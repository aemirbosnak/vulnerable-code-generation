//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_SIZE 100

typedef struct {
    char name[MAX_ENTRY_SIZE];
    int age;
} Entry;

int main() {
    int num_entries = 0;
    Entry entries[MAX_ENTRIES];

    // Load data from file
    FILE* file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    char line[MAX_ENTRY_SIZE];
    while (fgets(line, MAX_ENTRY_SIZE, file)!= NULL) {
        Entry entry;
        sscanf(line, "%s %d", entry.name, &entry.age);
        memcpy(&entries[num_entries], &entry, sizeof(Entry));
        num_entries++;
    }

    fclose(file);

    // Create index
    int index_size = num_entries * 4;
    char* index = malloc(index_size);
    memset(index, 0, index_size);

    for (int i = 0; i < num_entries; i++) {
        Entry entry = entries[i];
        int index_offset = i * 4;
        memcpy(&index[index_offset], entry.name, strlen(entry.name));
        memcpy(&index[index_offset + strlen(entry.name)], &entry.age, sizeof(int));
    }

    // Sort index
    for (int i = 0; i < index_size; i += 4) {
        int entry_index = 0;
        while (entry_index < num_entries && strcmp(&index[i], entries[entry_index].name) > 0) {
            entry_index++;
        }

        if (entry_index!= i / 4) {
            memcpy(&index[i], &index[entry_index * 4], 4);
            memcpy(&index[entry_index * 4], &index[i], 4);
        }
    }

    // Search index
    char search_name[MAX_ENTRY_SIZE];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    int search_index = 0;
    while (search_index < num_entries && strcmp(search_name, entries[search_index].name) > 0) {
        search_index++;
    }

    if (search_index == num_entries) {
        printf("Name not found\n");
    } else {
        printf("Age: %d\n", entries[search_index].age);
    }

    return 0;
}