//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries;

void add_entry(char* name, char* value) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Database is full\n");
        return;
    }

    strncpy(entries[num_entries].name, name, MAX_NAME_LENGTH);
    strncpy(entries[num_entries].value, value, MAX_VALUE_LENGTH);

    num_entries++;
}

void remove_entry(char* name) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            memset(&entries[i], 0, sizeof(Entry));
            num_entries--;
            return;
        }
    }

    printf("Error: Entry not found\n");
}

void search_entry(char* name) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nValue: %s\n", entries[i].name, entries[i].value);
            return;
        }
    }

    printf("Error: Entry not found\n");
}

int main() {
    int choice;

    do {
        printf("\nDatabase Menu:\n");
        printf("1. Add entry\n2. Remove entry\n3. Search entry\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", entries[num_entries].name);
            printf("Enter value: ");
            scanf("%s", entries[num_entries].value);
            break;

        case 2:
            printf("Enter name of entry to remove: ");
            scanf("%s", entries[num_entries].name);
            remove_entry(entries[num_entries].name);
            break;

        case 3:
            printf("Enter name of entry to search: ");
            scanf("%s", entries[num_entries].name);
            search_entry(entries[num_entries].name);
            break;

        case 4:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    } while (choice!= 4);

    return 0;
}