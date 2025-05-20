//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
    time_t timestamp;
} Entry;

void add_entry(Entry* entries, int num_entries, char* name, char* value) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Database is full!\n");
        return;
    }

    strcpy(entries[num_entries].name, name);
    strcpy(entries[num_entries].value, value);
    entries[num_entries].timestamp = time(NULL);

    num_entries++;
}

void print_entry(Entry entry) {
    printf("Name: %s\nValue: %s\nTimestamp: %s", entry.name, entry.value, ctime(&entry.timestamp));
}

void search_entry(Entry* entries, int num_entries, char* name) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            print_entry(entries[i]);
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];

    srand(time(NULL));

    while (num_entries < MAX_ENTRIES) {
        printf("Enter a name (max %d characters): ", MAX_NAME_LENGTH - 1);
        scanf("%s", name);

        printf("Enter a value (max %d characters): ", MAX_VALUE_LENGTH - 1);
        scanf("%s", value);

        add_entry(entries, num_entries, name, value);
    }

    while (1) {
        printf("Enter a name to search for (max %d characters): ", MAX_NAME_LENGTH - 1);
        scanf("%s", name);

        search_entry(entries, num_entries, name);
    }

    return 0;
}