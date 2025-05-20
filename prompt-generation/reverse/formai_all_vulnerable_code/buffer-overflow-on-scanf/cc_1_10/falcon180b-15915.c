//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 200
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* name, char* number) {
    if (num_entries == MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }

    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].number, number);
    num_entries++;
}

void search_entry(char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }
    printf("Entry not found.\n");
}

void delete_entry(char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            memset(phonebook[i].name, 0, MAX_NAME_LENGTH);
            memset(phonebook[i].number, 0, MAX_NUMBER_LENGTH);
            num_entries--;
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];

    do {
        printf("Phone Book\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter number: ");
            scanf("%s", number);
            add_entry(name, number);
            break;

        case 2:
            printf("Enter name to search: ");
            scanf("%s", name);
            search_entry(name);
            break;

        case 3:
            printf("Enter name to delete: ");
            scanf("%s", name);
            delete_entry(name);
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