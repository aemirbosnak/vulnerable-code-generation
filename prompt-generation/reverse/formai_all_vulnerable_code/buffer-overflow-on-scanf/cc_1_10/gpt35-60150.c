//FormAI DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100   // maximum number of entries in the phonebook
#define MAX_NAME 50       // maximum name length
#define MAX_PHONE 20      // maximum phone number length

struct phonebook_entry {  // structure to hold a single phonebook entry
    char name[MAX_NAME];
    char phone[MAX_PHONE];
};

struct phonebook {        // structure to hold the entire phonebook
    int num_entries;      // current number of entries in phonebook
    struct phonebook_entry entries[MAX_ENTRIES];  // array of phonebook entries
};

void add_entry(struct phonebook *book) {
    char name[MAX_NAME];
    char phone[MAX_PHONE];
    
    printf("Enter the name: ");
    fgets(name, MAX_NAME, stdin);
    name[strcspn(name, "\n")] = '\0';  // remove newline character
    
    printf("Enter the phone number: ");
    fgets(phone, MAX_PHONE, stdin);
    phone[strcspn(phone, "\n")] = '\0';
    
    // add the new entry to the phonebook
    strcpy(book->entries[book->num_entries].name, name);
    strcpy(book->entries[book->num_entries].phone, phone);
    book->num_entries++;
    
    printf("Entry added successfully!\n");
}

void search_entry(struct phonebook *book) {
    char name[MAX_NAME];
    int found = 0;
    
    printf("Enter the name to search for: ");
    fgets(name, MAX_NAME, stdin);
    name[strcspn(name, "\n")] = '\0';
    
    // search for the entry in the phonebook
    for (int i=0; i<book->num_entries; i++) {
        if (strcmp(book->entries[i].name, name) == 0) {
            printf("Phone number for %s: %s\n", name, book->entries[i].phone);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Entry not found!\n");
    }
}

void list_entries(struct phonebook *book) {
    printf("Entries in phonebook:\n");
    for (int i=0; i<book->num_entries; i++) {
        printf("%s -- %s\n", book->entries[i].name, book->entries[i].phone);
    }
}

int main() {
    struct phonebook book = {0};   // initialize phonebook with no entries
    int choice;
    
    while (1) {
        printf("1. Add an entry\n");
        printf("2. Search for an entry\n");
        printf("3. List all entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // consume newline character left in input stream
        
        switch (choice) {
            case 1:
                add_entry(&book);
                break;
            case 2:
                search_entry(&book);
                break;
            case 3:
                list_entries(&book);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    
    return 0;
}