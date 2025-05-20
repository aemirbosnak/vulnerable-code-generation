//FormAI DATASET v1.0 Category: Phone Book ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_ENTRIES 100

#define ADD_ENTRY 1
#define DELETE_ENTRY 2
#define SEARCH_ENTRY 3
#define PRINT_ALL_ENTRIES 4
#define EXIT 5

struct phonebook_entry {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_LENGTH];
};

void add_entry(struct phonebook_entry* entries, int* num_entries) {
    if (*num_entries < MAX_ENTRIES) {
        printf("Enter name: ");
        scanf(" %[^\n]", entries[*num_entries].name);
        printf("Enter phone number: ");
        scanf(" %[^\n]", entries[*num_entries].phone_number);
        (*num_entries)++;
    } else {
        printf("Phone book is full!\n");
    }
}

void delete_entry(struct phonebook_entry* entries, int* num_entries) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < *num_entries; i++) {
        if (strcmp(name, entries[i].name) == 0) {
            for (int j = i; j < *num_entries - 1; j++) {
                strcpy(entries[j].name, entries[j+1].name);
                strcpy(entries[j].phone_number, entries[j+1].phone_number);
            }
            (*num_entries)--;
            printf("Entry deleted successfully!\n");
            return;
        }
    }
    printf("Entry not found!\n");
}

void search_entry(struct phonebook_entry* entries, int num_entries) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(name, entries[i].name) == 0) {
            printf("Phone number: %s\n", entries[i].phone_number);
            return;
        }
    }
    printf("Entry not found!\n");
}

void print_all_entries(struct phonebook_entry* entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("Name: %s\n", entries[i].name);
        printf("Phone number: %s\n", entries[i].phone_number);
        printf("\n");
    }
}

int menu() {
    int choice;
    printf("Phone book\n");
    printf("1. Add entry\n");
    printf("2. Delete entry\n");
    printf("3. Search entry\n");
    printf("4. Print all entries\n");
    printf("5. Exit\n");
    printf("\nEnter choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    struct phonebook_entry entries[MAX_ENTRIES];
    int num_entries = 0;
    int choice;

    do {
        choice = menu();
        switch (choice) {
            case ADD_ENTRY:
                add_entry(entries, &num_entries);
                break;
            case DELETE_ENTRY:
                delete_entry(entries, &num_entries);
                break;
            case SEARCH_ENTRY:
                search_entry(entries, num_entries);
                break;
            case PRINT_ALL_ENTRIES:
                print_all_entries(entries, num_entries);
                break;
            case EXIT:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != EXIT);

    return 0;
}