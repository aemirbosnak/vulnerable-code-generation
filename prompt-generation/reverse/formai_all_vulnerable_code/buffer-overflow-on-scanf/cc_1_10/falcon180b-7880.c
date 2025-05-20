//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);

    printf("Enter phone number: ");
    scanf("%s", phonebook[num_entries].number);

    num_entries++;
}

void delete_entry() {
    int idx;
    printf("Enter index of entry to delete: ");
    scanf("%d", &idx);

    if (idx >= 0 && idx < num_entries) {
        num_entries--;
        for (int i = idx; i < num_entries; i++) {
            strcpy(phonebook[i].name, phonebook[i+1].name);
            strcpy(phonebook[i].number, phonebook[i+1].number);
        }
        printf("Entry deleted.\n");
    } else {
        printf("Invalid index.\n");
    }
}

void search_entry() {
    char name[MAX_NAME_LEN];
    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("Name: %s\nPhone number: %s\n\n", phonebook[i].name, phonebook[i].number);
    }
}

int main() {
    int choice;

    do {
        printf("1. Add entry\n2. Delete entry\n3. Search entry\n4. Print entries\n5. Exit\n");
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
                print_entries();
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