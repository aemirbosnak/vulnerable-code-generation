//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[51];
    char number[16];
} entry;

entry phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    char name[51];
    char number[16];

    printf("Enter name: ");
    fgets(name, 51, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter phone number: ");
    fgets(number, 16, stdin);
    number[strcspn(number, "\n")] = '\0';

    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].number, number);
    num_entries++;

    printf("Entry added successfully.\n");
}

void search_entry() {
    char search_name[51];

    printf("Enter name to search: ");
    fgets(search_name, 51, stdin);
    search_name[strcspn(search_name, "\n")] = '\0';

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            printf("Name: %s\n", phonebook[i].name);
            printf("Number: %s\n", phonebook[i].number);
        }
    }
}

void delete_entry() {
    char delete_name[51];

    printf("Enter name to delete: ");
    fgets(delete_name, 51, stdin);
    delete_name[strcspn(delete_name, "\n")] = '\0';

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, delete_name) == 0) {
            strcpy(phonebook[i].name, "");
            strcpy(phonebook[i].number, "");
            printf("Entry deleted successfully.\n");
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    int choice;

    do {
        printf("\nPhone Book\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
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
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}