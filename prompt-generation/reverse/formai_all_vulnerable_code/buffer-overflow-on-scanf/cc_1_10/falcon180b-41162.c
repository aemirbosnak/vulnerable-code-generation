//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[50];
    char number[15];
} phonebook_entry;

phonebook_entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    char name[50], number[15];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter phone number: ");
    scanf("%s", number);

    strcpy(entries[num_entries].name, name);
    strcpy(entries[num_entries].number, number);

    num_entries++;
}

void delete_entry() {
    int index;
    printf("Enter index of entry to delete: ");
    scanf("%d", &index);

    if (index >= 0 && index < num_entries) {
        num_entries--;
    } else {
        printf("Invalid index.\n");
    }
}

void search_entry() {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nPhone number: %s\n", entries[i].name, entries[i].number);
        }
    }
}

void print_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("Name: %s\nPhone number: %s\n", entries[i].name, entries[i].number);
    }
}

int main() {
    char choice;

    do {
        printf("1. Add entry\n2. Delete entry\n3. Search entry\n4. Print entries\n5. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                add_entry();
                break;
            case '2':
                delete_entry();
                break;
            case '3':
                search_entry();
                break;
            case '4':
                print_entries();
                break;
            case '5':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '5');

    return 0;
}