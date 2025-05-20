//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("The phone book is full.\n");
        return;
    }

    printf("Enter name: ");
    fgets(phonebook[num_entries].name, MAX_NAME_LENGTH, stdin);
    phonebook[num_entries].name[strcspn(phonebook[num_entries].name, "\n")] = '\0';

    printf("Enter number: ");
    fgets(phonebook[num_entries].number, MAX_NUMBER_LENGTH, stdin);
    phonebook[num_entries].number[strcspn(phonebook[num_entries].number, "\n")] = '\0';

    num_entries++;
    printf("Entry added.\n");
}

void search_entry() {
    char search_name[MAX_NAME_LENGTH];

    printf("Enter name to search: ");
    fgets(search_name, MAX_NAME_LENGTH, stdin);
    search_name[strcspn(search_name, "\n")] = '\0';

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

void delete_entry() {
    char delete_name[MAX_NAME_LENGTH];

    printf("Enter name to delete: ");
    fgets(delete_name, MAX_NAME_LENGTH, stdin);
    delete_name[strcspn(delete_name, "\n")] = '\0';

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, delete_name) == 0) {
            memmove(&phonebook[i], &phonebook[i+1], sizeof(entry_t) * (num_entries - i - 1));
            num_entries--;
            printf("Entry deleted.\n");
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    printf("Welcome to the C Phone Book!\n");

    while (1) {
        printf("\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");
        printf("\n");

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
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}