//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// define the phone book entry
typedef struct {
    char name[64];
    char number[16];
} phone_book_entry;

// define the phone book
#define PHONE_BOOK_SIZE 100
typedef phone_book_entry phone_book[PHONE_BOOK_SIZE];

// print the phone book
void print_phone_book(phone_book book) {
    for (int i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (book[i].name[0] != '\0') {
            printf("%s: %s\n", book[i].name, book[i].number);
        }
    }
}

// add a new entry to the phone book
void add_entry(phone_book book) {
    char name[64];
    char number[16];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter number: ");
    scanf("%s", number);
    for (int i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (book[i].name[0] == '\0') {
            strcpy(book[i].name, name);
            strcpy(book[i].number, number);
            break;
        }
    }
}

// delete an entry from the phone book
void delete_entry(phone_book book) {
    char name[64];
    printf("Enter name: ");
    scanf("%s", name);
    for (int i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (strcmp(book[i].name, name) == 0) {
            book[i].name[0] = '\0';
            book[i].number[0] = '\0';
            break;
        }
    }
}

// find an entry in the phone book
void find_entry(phone_book book) {
    char name[64];
    printf("Enter name: ");
    scanf("%s", name);
    for (int i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (strcmp(book[i].name, name) == 0) {
            printf("%s: %s\n", book[i].name, book[i].number);
            break;
        }
    }
}

// main function
int main() {
    phone_book book;
    int choice;
    do {
        printf("1. Print phone book\n");
        printf("2. Add entry\n");
        printf("3. Delete entry\n");
        printf("4. Find entry\n");
        printf("5. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                print_phone_book(book);
                break;
            case 2:
                add_entry(book);
                break;
            case 3:
                delete_entry(book);
                break;
            case 4:
                find_entry(book);
                break;
        }
    } while (choice != 5);
    return 0;
}