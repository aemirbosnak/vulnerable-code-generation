//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[40];
    char number[15];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phonebook is full!\n");
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
        printf("Phonebook is empty!\n");
        return;
    }

    printf("Enter name to delete: ");
    char name[40];
    scanf("%s", name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            memmove(&phonebook[i], &phonebook[i+1], (num_entries - i - 1) * sizeof(entry_t));
            num_entries--;
            break;
        }
    }
}

void search_entry() {
    if (num_entries == 0) {
        printf("Phonebook is empty!\n");
        return;
    }

    printf("Enter name to search: ");
    char name[40];
    scanf("%s", name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\n", phonebook[i].name);
            printf("Number: %s\n", phonebook[i].number);
            break;
        }
    }
}

int main() {
    int choice;
    do {
        printf("\nPhonebook\n");
        printf("1. Add entry\n");
        printf("2. Delete entry\n");
        printf("3. Search entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
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
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}