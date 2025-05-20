//FormAI DATASET v1.0 Category: Phone Book ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

struct PhoneBookEntry {
    char firstName[20];
    char lastName[20];
    char phoneNumber[15];
};

struct PhoneBook {
    struct PhoneBookEntry entries[MAX_ENTRIES];
    int count;
};

void addEntry(struct PhoneBook* book) {
    if (book->count == MAX_ENTRIES) {
        printf("Phone book is full\n");
        return;
    }
    
    struct PhoneBookEntry entry;
    printf("Enter first name: ");
    scanf("%s", entry.firstName);
    printf("Enter last name: ");
    scanf("%s", entry.lastName);
    printf("Enter phone number: ");
    scanf("%s", entry.phoneNumber);
    
    book->entries[book->count] = entry;
    book->count++;
    printf("Entry added successfully\n");
}

void searchEntries(struct PhoneBook* book) {
    char query[20];
    int count = 0;
    
    printf("Enter search query: ");
    scanf("%s", query);
    
    for (int i = 0; i < book->count; i++) {
        if (strstr(book->entries[i].firstName, query) != NULL || strstr(book->entries[i].lastName, query) != NULL) {
            printf("%s %s - %s\n", book->entries[i].firstName, book->entries[i].lastName, book->entries[i].phoneNumber);
            count++;
        }
    }
    
    if (count == 0) {
        printf("No results found\n");
    }
}

int main() {
    struct PhoneBook book;
    book.count = 0;
    int choice;
    
    do {
        printf("\n\nPhone Book Menu\n");
        printf("1. Add new entry\n");
        printf("2. Search entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEntry(&book);
                break;
            case 2:
                searchEntries(&book);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);
    
    return 0;
}