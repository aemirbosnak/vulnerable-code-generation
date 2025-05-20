//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PHONE_BOOK_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} PhoneBookEntry;

void print_menu() {
    printf("Phone Book\n");
    printf("---------\n");
    printf("1. Add new entry\n");
    printf("2. Lookup entry\n");
    printf("3. Delete entry\n");
    printf("4. List all entries\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

void add_entry(PhoneBookEntry *phone_book) {
    int i;
    for (i = 0; i < MAX_PHONE_BOOK_ENTRIES; i++) {
        if (phone_book[i].name[0] == '\0') {
            printf("Enter name: ");
            fgets(phone_book[i].name, MAX_NAME_LENGTH, stdin);
            printf("Enter number: ");
            fgets(phone_book[i].number, MAX_NUMBER_LENGTH, stdin);
            break;
        }
    }
    if (i == MAX_PHONE_BOOK_ENTRIES) {
        printf("Phone book is full.\n");
    }
}

void lookup_entry(PhoneBookEntry *phone_book) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name to lookup: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    int i;
    for (i = 0; i < MAX_PHONE_BOOK_ENTRIES; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            printf("Name: %s\n", phone_book[i].name);
            printf("Number: %s\n", phone_book[i].number);
            break;
        }
    }
    if (i == MAX_PHONE_BOOK_ENTRIES) {
        printf("Name not found.\n");
    }
}

void delete_entry(PhoneBookEntry *phone_book) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name to delete: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    int i;
    for (i = 0; i < MAX_PHONE_BOOK_ENTRIES; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            phone_book[i].name[0] = '\0';
            phone_book[i].number[0] = '\0';
            break;
        }
    }
    if (i == MAX_PHONE_BOOK_ENTRIES) {
        printf("Name not found.\n");
    }
}

void list_all_entries(PhoneBookEntry *phone_book) {
    int i;
    for (i = 0; i < MAX_PHONE_BOOK_ENTRIES; i++) {
        if (phone_book[i].name[0] != '\0') {
            printf("Name: %s\n", phone_book[i].name);
            printf("Number: %s\n", phone_book[i].number);
        }
    }
}

int main() {
    PhoneBookEntry phone_book[MAX_PHONE_BOOK_ENTRIES];
    int option;
    do {
        print_menu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                add_entry(phone_book);
                break;
            case 2:
                lookup_entry(phone_book);
                break;
            case 3:
                delete_entry(phone_book);
                break;
            case 4:
                list_all_entries(phone_book);
                break;
            case 5:
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (option != 5);
    return 0;
}