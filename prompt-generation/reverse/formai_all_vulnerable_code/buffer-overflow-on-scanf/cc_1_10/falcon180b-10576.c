//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 30
#define MAX_NUMBER_LEN 15

struct entry {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
};

struct entry phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);
    printf("Enter phone number: ");
    scanf("%s", phonebook[num_entries].number);
    num_entries++;
}

void search_entry() {
    char name[MAX_NAME_LEN];
    printf("Enter name to search: ");
    scanf("%s", name);
    int i = 0;
    while (i < num_entries) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
        i++;
    }
    printf("Entry not found.\n");
}

void delete_entry() {
    char name[MAX_NAME_LEN];
    printf("Enter name to delete: ");
    scanf("%s", name);
    int i = 0;
    while (i < num_entries) {
        if (strcmp(phonebook[i].name, name) == 0) {
            memmove(&phonebook[i], &phonebook[i+1], sizeof(struct entry) * (num_entries - i - 1));
            num_entries--;
            printf("Entry deleted.\n");
            return;
        }
        i++;
    }
    printf("Entry not found.\n");
}

void print_entries() {
    int i = 0;
    while (i < num_entries) {
        printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].number);
        i++;
    }
}

int main() {
    int choice;
    do {
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Print all entries\n5. Exit\n");
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