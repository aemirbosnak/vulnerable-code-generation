//FormAI DATASET v1.0 Category: Phone Book ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 100

struct phonebook_entry {
    char name[50];
    char phone_number[20];
};

int num_entries = 0;
struct phonebook_entry phonebook[MAX_ENTRIES];

void add_entry(char* name, char* phone_number) {
    // make sure we don't exceed the maximum number of entries
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full. Cannot add entry.\n");
        return;
    }

    // create a new entry and add it to the phone book
    struct phonebook_entry new_entry;
    strncpy(new_entry.name, name, 50);
    strncpy(new_entry.phone_number, phone_number, 20);
    phonebook[num_entries++] = new_entry;
    printf("Added entry for %s.\n", name);
}

void search_entries(char* name) {
    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("%s's phone number is %s.\n", name, phonebook[i].phone_number);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Entry not found for %s.\n", name);
    }
}

void print_all_entries() {
    printf("Phone Book:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", phonebook[i].name, phonebook[i].phone_number);
    }
}

int main() {
    int choice = 0;

    printf("Welcome to Ken's Phone Book!\n");

    while (choice != 4) {
        printf("Select an operation:\n");
        printf("1. Add an entry\n");
        printf("2. Search for an entry\n");
        printf("3. Print all entries\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                char name[50];
                scanf("%s", name);
                printf("Enter phone number: ");
                char phone_number[20];
                scanf("%s", phone_number);
                add_entry(name, phone_number);
                break;
            case 2:
                printf("Enter name: ");
                char search_name[50];
                scanf("%s", search_name);
                search_entries(search_name);
                break;
            case 3:
                print_all_entries();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}