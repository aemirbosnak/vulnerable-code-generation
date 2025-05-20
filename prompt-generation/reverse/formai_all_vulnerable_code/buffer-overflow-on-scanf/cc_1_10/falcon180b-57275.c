//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
    int id;
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

int find_entry_id(char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            return entries[i].id;
        }
    }
    return -1;
}

int add_entry(char* name, char* value) {
    int i;
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (entries[i].id == -1) {
            strcpy(entries[i].name, name);
            strcpy(entries[i].value, value);
            entries[i].id = num_entries;
            num_entries++;
            return i;
        }
    }
    return -1;
}

void print_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%d: %s = %s\n", i, entries[i].name, entries[i].value);
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Add entry\n2. Print entries\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", entries[add_entry("", "")].name);
                printf("Enter value: ");
                scanf("%s", entries[add_entry("", "")].value);
                break;
            case 2:
                print_entries();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}