//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define NUMBER_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char number[NUMBER_LENGTH];
} PhoneBookEntry;

typedef struct {
    PhoneBookEntry entries[MAX_ENTRIES];
    int count;
} PhoneBook;

void initialize_phone_book(PhoneBook *pb) {
    pb->count = 0;
}

void add_entry(PhoneBook *pb, const char *name, const char *number) {
    if (pb->count >= MAX_ENTRIES) {
        printf("Phone Book is full!\n");
        return;
    }
    
    strcpy(pb->entries[pb->count].name, name);
    strcpy(pb->entries[pb->count].number, number);
    pb->count++;
}

void view_entries(const PhoneBook *pb) {
    if (pb->count == 0) {
        printf("No entries in the Phone Book.\n");
        return;
    }
    
    printf("\n--- Phone Book Entries ---\n");
    for (int i = 0; i < pb->count; i++) {
        printf("Entry %d: Name: %s, Number: %s\n", i + 1, pb->entries[i].name, pb->entries[i].number);
    }
    printf("--------------------------\n\n");
}

void search_entry(const PhoneBook *pb, const char *name) {
    printf("\nSearching for '%s'...\n", name);
    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->entries[i].name, name) == 0) {
            printf("Found: Name: %s, Number: %s\n", pb->entries[i].name, pb->entries[i].number);
            return;
        }
    }
    printf("No entry found for '%s'.\n", name);
}

void menu() {
    printf("\n--- Phone Book Menu ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Search Entry\n");
    printf("4. Exit\n");
    printf("-----------------------\n");
    printf("Choose an option: ");
}

int main() {
    PhoneBook phoneBook;
    initialize_phone_book(&phoneBook);
    int choice;
    char name[NAME_LENGTH], number[NUMBER_LENGTH];

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf(" %[^\n]", name);  // Read string with spaces
                printf("Enter Number: ");
                scanf(" %[^\n]", number); // Read string with spaces
                add_entry(&phoneBook, name, number);
                break;
            case 2:
                view_entries(&phoneBook);
                break;
            case 3:
                printf("Enter Name to Search: ");
                scanf(" %[^\n]", name); // Read string with spaces
                search_entry(&phoneBook, name);
                break;
            case 4:
                printf("Exiting the Phone Book. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}