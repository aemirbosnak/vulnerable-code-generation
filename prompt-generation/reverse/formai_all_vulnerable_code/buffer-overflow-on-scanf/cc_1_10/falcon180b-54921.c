//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct entry {
    char name[50];
    char number[15];
};

struct entry phonebook[MAX_ENTRIES];
int entry_count = 0;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", phonebook[entry_count].name);

    printf("Enter phone number: ");
    scanf("%s", phonebook[entry_count].number);

    entry_count++;
}

void search_entry() {
    char search_name[50];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    int i;
    for (i = 0; i < entry_count; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            printf("Name: %s\nPhone Number: %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

void delete_entry() {
    char delete_name[50];
    printf("Enter name to delete: ");
    scanf("%s", delete_name);

    int i;
    for (i = 0; i < entry_count; i++) {
        if (strcmp(phonebook[i].name, delete_name) == 0) {
            memmove(&phonebook[i], &phonebook[i+1], sizeof(struct entry) * (entry_count - i - 1));
            entry_count--;
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    int choice;

    do {
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}