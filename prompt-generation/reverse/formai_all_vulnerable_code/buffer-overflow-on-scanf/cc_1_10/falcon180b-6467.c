//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

int entry_count = 0;
Entry entries[MAX_ENTRIES];

void add_entry() {
    printf("Enter name: ");
    scanf("%s", entries[entry_count].name);
    printf("Enter phone number: ");
    scanf("%s", entries[entry_count].number);
    entry_count++;
}

void remove_entry() {
    if (entry_count == 0) {
        printf("Phonebook is empty.\n");
        return;
    }
    printf("Enter name to remove: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    for (int i = 0; i < entry_count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            memmove(&entries[i], &entries[i + 1], sizeof(Entry) * (entry_count - i - 1));
            entry_count--;
            printf("Entry removed.\n");
            return;
        }
    }
    printf("Entry not found.\n");
}

void search_entry() {
    printf("Enter name to search: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    for (int i = 0; i < entry_count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\n", entries[i].name);
            printf("Number: %s\n", entries[i].number);
        }
    }
}

int main() {
    while (1) {
        printf("1. Add entry\n2. Remove entry\n3. Search entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_entry();
            break;
        case 2:
            remove_entry();
            break;
        case 3:
            search_entry();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}