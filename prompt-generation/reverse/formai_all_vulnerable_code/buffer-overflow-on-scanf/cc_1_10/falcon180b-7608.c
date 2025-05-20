//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);
    printf("Enter number: ");
    scanf("%s", phonebook[num_entries].number);
    num_entries++;
}

void delete_entry() {
    printf("Enter name to delete: ");
    scanf("%s", phonebook[num_entries - 1].name);
    num_entries--;
}

void search_entry() {
    printf("Enter name to search: ");
    scanf("%s", phonebook[num_entries - 1].name);
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, phonebook[num_entries - 1].name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }
    printf("Entry not found.\n");
}

void print_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
    }
}

int main() {
    num_entries = 0;
    printf("Welcome to the Phone Book!\n");
    while (1) {
        printf("\nOptions:\n1. Add entry\n2. Delete entry\n3. Search entry\n4. Print all entries\n5. Exit\n");
        int choice;
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
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}