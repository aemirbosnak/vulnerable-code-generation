//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* name, char* value) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Database is full!\n");
        return;
    }

    strcpy(entries[num_entries].name, name);
    strcpy(entries[num_entries].value, value);
    num_entries++;
}

void remove_entry(char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            memset(&entries[i], 0, sizeof(entry_t));
            num_entries--;
            return;
        }
    }
    printf("Error: Entry not found!\n");
}

void display_entries() {
    if (num_entries == 0) {
        printf("Database is empty!\n");
        return;
    }

    printf("Name\t\tValue\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\n", entries[i].name, entries[i].value);
    }
}

void main() {
    int choice;

    do {
        system("clear");
        printf("Welcome to the Happy Database!\n");
        printf("1. Add entry\n2. Remove entry\n3. Display entries\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                char name[MAX_NAME_LENGTH];
                scanf("%s", name);

                printf("Enter value: ");
                char value[MAX_VALUE_LENGTH];
                scanf("%s", value);

                add_entry(name, value);
                break;

            case 2:
                printf("Enter name: ");
                char name_remove[MAX_NAME_LENGTH];
                scanf("%s", name_remove);

                remove_entry(name_remove);
                break;

            case 3:
                display_entries();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice!= 4);
}