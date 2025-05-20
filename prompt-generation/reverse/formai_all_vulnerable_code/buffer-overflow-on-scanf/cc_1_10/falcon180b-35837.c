//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* name, char* number) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }

    strncpy(entries[num_entries].name, name, MAX_NAME_LENGTH);
    strncpy(entries[num_entries].number, number, MAX_NUMBER_LENGTH);

    num_entries++;
}

void display_entries() {
    printf("Phone book entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%d. %s - %s\n", i+1, entries[i].name, entries[i].number);
    }
}

void search_entry(char* search_name) {
    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            printf("%s: %s\n", search_name, entries[i].number);
            found = 1;
        }
    }
    if (!found) {
        printf("Entry not found.\n");
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];

    while (1) {
        printf("1. Add entry\n2. Display entries\n3. Search entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter number: ");
            scanf("%s", number);
            add_entry(name, number);
            break;
        case 2:
            display_entries();
            break;
        case 3:
            printf("Enter name to search: ");
            scanf("%s", name);
            search_entry(name);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}