//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20
#define MAX_ENTRIES 100

struct entry {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
};

int num_entries = 0;
struct entry phonebook[MAX_ENTRIES];

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full!\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);
    printf("Enter phone number: ");
    scanf("%s", phonebook[num_entries].number);
    num_entries++;
}

void delete_entry() {
    if (num_entries == 0) {
        printf("Phone book is empty!\n");
        return;
    }
    int i;
    printf("Enter name to delete: ");
    scanf("%s", phonebook[0].name);
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, phonebook[0].name) == 0) {
            memmove(&phonebook[i], &phonebook[i+1], sizeof(struct entry) * (num_entries - i - 1));
            num_entries--;
            printf("Entry deleted!\n");
            return;
        }
    }
}

void search_entry() {
    if (num_entries == 0) {
        printf("Phone book is empty!\n");
        return;
    }
    printf("Enter name to search: ");
    scanf("%s", phonebook[0].name);
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, phonebook[0].name) == 0) {
            printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }
    printf("Entry not found!\n");
}

void display_entries() {
    if (num_entries == 0) {
        printf("Phone book is empty!\n");
        return;
    }
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].number);
    }
}

int main() {
    int choice;
    do {
        printf("1. Add entry\n2. Delete entry\n3. Search entry\n4. Display all entries\n5. Exit\n");
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
                display_entries();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 5);
    return 0;
}