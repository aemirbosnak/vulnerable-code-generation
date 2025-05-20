//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define NUMBER_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char number[NUMBER_LENGTH];
} Entry;

typedef struct {
    Entry entries[MAX_ENTRIES];
    int count;
} PhoneBook;

void add_entry(PhoneBook* book) {
    if (book->count >= MAX_ENTRIES) {
        printf("Alas! The phone book is full, thou canst not add more entries.\n");
        return;
    }
    
    printf("Enter the name of the noble:\n");
    scanf(" %[^\n]%*c", book->entries[book->count].name);
    
    printf("Enter the mystical number of the noble:\n");
    scanf(" %[^\n]%*c", book->entries[book->count].number);
    
    book->count++;
    printf("A new entry for %s has been inscribed!\n", book->entries[book->count - 1].name);
}

void display_entries(const PhoneBook* book) {
    if (book->count == 0) {
        printf("Verily, the phone book is empty, no entries to display!\n");
        return;
    }
    
    printf("\nBehold the entries in the noble's phone book:\n");
    for (int i = 0; i < book->count; ++i) {
        printf("Entry %d:\n", i + 1);
        printf("Name: %s\n", book->entries[i].name);
        printf("Number: %s\n\n", book->entries[i].number);
    }
}

void search_entry(const PhoneBook* book) {
    char name[NAME_LENGTH];
    printf("Whom dost thou seek? Enter the name:\n");
    scanf(" %[^\n]%*c", name);
    
    for (int i = 0; i < book->count; ++i) {
        if (strcmp(book->entries[i].name, name) == 0) {
            printf("Aha! Found %s's number: %s\n", book->entries[i].name, book->entries[i].number);
            return;
        }
    }
    printf("Alas! No entry found for the noble %s.\n", name);
}

void delete_entry(PhoneBook* book) {
    char name[NAME_LENGTH];
    printf("Which noble's entry dost thou wish to delete?\n");
    scanf(" %[^\n]%*c", name);
    
    for (int i = 0; i < book->count; ++i) {
        if (strcmp(book->entries[i].name, name) == 0) {
            for (int j = i; j < book->count - 1; ++j) {
                book->entries[j] = book->entries[j + 1];
            }
            book->count--;
            printf("The entry for %s has been cast into oblivion!\n", name);
            return;
        }
    }
    printf("Alas! No entry found for the noble %s to delete.\n", name);
}

void menu() {
    printf("\nWelcome to the Grand Phone Book of the Kingdom!\n");
    printf("1. Add Entry\n");
    printf("2. Display Entries\n");
    printf("3. Search Entry\n");
    printf("4. Delete Entry\n");
    printf("5. Exit\n");
    printf("Choose thy path: ");
}

int main() {
    PhoneBook book;
    book.count = 0;
    int choice;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(&book);
                break;
            case 2:
                display_entries(&book);
                break;
            case 3:
                search_entry(&book);
                break;
            case 4:
                delete_entry(&book);
                break;
            case 5:
                printf("Farewell, noble traveler! Until we meet again!\n");
                return 0;
            default:
                printf("Methinks that is not a valid choice. Choose wisely!\n");
        }
    }

    return 0;
}