//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry;

int num_entries = 0;
entry phonebook[MAX_ENTRIES];

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phonebook is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);

    printf("Enter number: ");
    scanf("%s", phonebook[num_entries].number);

    num_entries++;
    printf("Entry added.\n");
}

void search_entry() {
    char name[MAX_NAME_LENGTH];

    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("%s: %s\n", name, phonebook[i].number);
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
            printf("%s deleted.\n", name);
        }
    }
}

int main() {
    while (1) {
        printf("\nPhonebook:\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");

        int choice;
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
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}