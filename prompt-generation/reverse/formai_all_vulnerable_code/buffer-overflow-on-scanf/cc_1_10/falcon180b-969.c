//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 30
#define MAX_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry;

int num_entries = 0;
entry phonebook[MAX_ENTRIES];

void add_entry() {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter number: ");
    scanf("%s", number);

    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].number, number);

    num_entries++;
}

void delete_entry() {
    int index;

    printf("Enter index of entry to delete: ");
    scanf("%d", &index);

    if (index >= 0 && index < num_entries) {
        memset(&phonebook[index], 0, sizeof(entry));
        num_entries--;
        printf("Entry deleted successfully.\n");
    } else {
        printf("Invalid index.\n");
    }
}

void search_entry() {
    char name[MAX_NAME_LENGTH];

    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

void print_all_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
    }
}

int main() {
    int choice;

    do {
        printf("1. Add entry\n2. Delete entry\n3. Search entry\n4. Print all entries\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry();
            break;
        case 2:
            delete_entry();
            break;
        case 3:
            search_entry();
            break;
        case 4:
            print_all_entries();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}