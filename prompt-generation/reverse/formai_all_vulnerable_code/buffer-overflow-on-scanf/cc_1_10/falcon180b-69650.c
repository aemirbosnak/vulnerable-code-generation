//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry;

entry phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter phone number: ");
    scanf("%s", number);

    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].number, number);

    num_entries++;
}

void search_entry() {
    char name[MAX_NAME_LENGTH];

    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].number);
        }
    }
}

void delete_entry() {
    char name[MAX_NAME_LENGTH];

    printf("Enter name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            strcpy(phonebook[i].name, "");
            strcpy(phonebook[i].number, "");
            printf("Entry deleted.\n");
        }
    }
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
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}