//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 30
#define MAX_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);

    printf("Enter number: ");
    scanf("%s", phonebook[num_entries].number);

    num_entries++;
    printf("Entry added.\n");
}

void search_entry() {
    printf("Enter name to search: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(name, phonebook[i].name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

void delete_entry() {
    printf("Enter name to delete: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(name, phonebook[i].name) == 0) {
            memset(&phonebook[i], 0, sizeof(entry_t));
            printf("Entry deleted.\n");
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);

    printf("Welcome to the phone book!\n");

    while (1) {
        printf("\n1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry();
            break;
        case 2:
            search_entry();
            break;
        case 3:
            delete_entry();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}