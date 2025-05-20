//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: happy
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
int num_entries = 0;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);
    printf("Enter number: ");
    scanf("%s", phonebook[num_entries].number);
    num_entries++;
    printf("Entry added successfully!\n");
}

void delete_entry() {
    printf("Enter name to delete: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(name, phonebook[i].name) == 0) {
            memset(phonebook[i].name, 0, MAX_NAME_LENGTH);
            memset(phonebook[i].number, 0, MAX_NUMBER_LENGTH);
            num_entries--;
            printf("Entry deleted successfully!\n");
            return;
        }
    }
    printf("Entry not found.\n");
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

int main() {
    printf("Welcome to the Happy Phone Book!\n");
    int choice;
    do {
        printf("\n1. Add entry\n2. Delete entry\n3. Search entry\n4. Exit\n");
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
                printf("Goodbye! Have a happy day!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);
    return 0;
}