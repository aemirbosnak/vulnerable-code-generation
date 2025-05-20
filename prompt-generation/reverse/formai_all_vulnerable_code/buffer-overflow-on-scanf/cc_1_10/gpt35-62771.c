//FormAI DATASET v1.0 Category: Phone Book ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_NUM_LENGTH 15

typedef struct phonebook_entry {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUM_LENGTH];
    struct phonebook_entry* next;
} phonebook_entry;

void add_entry(phonebook_entry** phonebook, char* name, char* number);
void display_entries(phonebook_entry* phonebook);
void search_entry(phonebook_entry* phonebook, char* name);
void delete_entry(phonebook_entry** phonebook, char* name);

int main() {
    phonebook_entry* phonebook = NULL;
    char choice;
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUM_LENGTH];

    do {
        printf("\n\n\tC Phonebook Application"
               "\n\t======================="
               "\n\t1. Add New Entry"
               "\n\t2. Display All Entries"
               "\n\t3. Search Entry"
               "\n\t4. Delete Entry"
               "\n\t5. Exit"
               "\n\tEnter choice (1-5): ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("\n\tEnter name:");
                scanf("%s", name);
                printf("\tEnter number:");
                scanf("%s", number);
                add_entry(&phonebook, name, number);
                break;

            case '2':
                display_entries(phonebook);
                break;

            case '3':
                printf("\n\tEnter name to search for:");
                scanf("%s", name);
                search_entry(phonebook, name);
                break;

            case '4':
                printf("\n\tEnter name to delete:");
                scanf("%s", name);
                delete_entry(&phonebook, name);
                break;

            case '5':
                printf("\n\tExiting Phonebook Application...\n");
                break;

            default:
                printf("\n\tInvalid choice, please try again.");
                break;
        }

    } while (choice != '5');

    return 0;
}

void add_entry(phonebook_entry** phonebook, char* name, char* number) {
    phonebook_entry* new_entry = malloc(sizeof(phonebook_entry));
    strcpy(new_entry->name, name);
    strcpy(new_entry->number, number);
    new_entry->next = *phonebook;
    *phonebook = new_entry;
    printf("\n\tEntry added successfully!");
}

void display_entries(phonebook_entry* phonebook) {
    if (phonebook == NULL) {
        printf("\n\tNo entries found.\n");
        return;
    }

    printf("\n\tAll Phonebook Entries\n"
           "\t=====================\n");
    while (phonebook != NULL) {
        printf("\tName: %s\n\tPhone Number: %s\n\n", phonebook->name, phonebook->number);
        phonebook = phonebook->next;
    }
}

void search_entry(phonebook_entry* phonebook, char* name) {
    while (phonebook != NULL) {
        if (strcmp(phonebook->name, name) == 0) {
            printf("\n\tName: %s\n\tPhone Number: %s\n", phonebook->name, phonebook->number);
            return;
        }
        phonebook = phonebook->next;
    }

    printf("\n\tEntry not found.\n");
}

void delete_entry(phonebook_entry** phonebook, char* name) {
    phonebook_entry* current_entry = *phonebook;
    phonebook_entry* previous_entry = NULL;

    while (current_entry != NULL) {
        if (strcmp(current_entry->name, name) == 0) {
            if (previous_entry == NULL) {
                *phonebook = current_entry->next;
            } else {
                previous_entry->next = current_entry->next;
            }
            free(current_entry);
            printf("\n\tEntry deleted successfully!");
            return;
        }
        previous_entry = current_entry;
        current_entry = current_entry->next;
    }

    printf("\n\tEntry not found.\n");
}