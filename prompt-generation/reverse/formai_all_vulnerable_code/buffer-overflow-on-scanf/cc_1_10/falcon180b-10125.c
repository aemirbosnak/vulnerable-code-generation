//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);

    printf("Enter number: ");
    scanf("%s", phonebook[num_entries].number);

    num_entries++;
}

void remove_entry() {
    int index;

    printf("Enter the name of the entry you want to remove: ");
    scanf("%s", phonebook[0].name);

    for (index = 0; index < num_entries; index++) {
        if (strcmp(phonebook[index].name, phonebook[0].name) == 0) {
            break;
        }
    }

    if (index == num_entries) {
        printf("Entry not found.\n");
    } else {
        num_entries--;
        memmove(&phonebook[index], &phonebook[index + 1], sizeof(entry_t) * (num_entries - index));
    }
}

void search_entry() {
    char name[MAX_NAME_LENGTH];

    printf("Enter the name of the entry you want to search: ");
    scanf("%s", name);

    int index;
    for (index = 0; index < num_entries; index++) {
        if (strcmp(phonebook[index].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[index].name, phonebook[index].number);
            break;
        }
    }

    if (index == num_entries) {
        printf("Entry not found.\n");
    }
}

void display_entries() {
    int index;
    for (index = 0; index < num_entries; index++) {
        printf("Name: %s\nNumber: %s\n", phonebook[index].name, phonebook[index].number);
    }
}

int main() {
    int choice;

    do {
        printf("1. Add entry\n2. Remove entry\n3. Search entry\n4. Display entries\n5. Exit\n");
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
            display_entries();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}