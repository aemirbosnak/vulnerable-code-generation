//FormAI DATASET v1.0 Category: Phone Book ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20
#define MAX_CONTACTS 100

struct contact {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
};

struct phonebook {
    int count;
    struct contact contacts[MAX_CONTACTS];
};

void add_contact(struct phonebook *book, char *name, char *number) {
    if (book->count >= MAX_CONTACTS) {
        printf("Phonebook is full! Cannot add contact.\n");
        return;
    }
    strcpy(book->contacts[book->count].name, name);
    strcpy(book->contacts[book->count].number, number);
    book->count++;
    printf("Contact added successfully.\n");
}

void delete_contact(struct phonebook *book, char *name) {
    int i, j;
    for (i = 0; i < book->count; i++) {
        if (strcmp(book->contacts[i].name, name) == 0) {
            for (j = i; j < book->count - 1; j++) {
                strcpy(book->contacts[j].name, book->contacts[j+1].name);
                strcpy(book->contacts[j].number, book->contacts[j+1].number);
            }
            book->count--;
            printf("Contact deleted successfully.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

void search_contact(struct phonebook *book, char *name) {
    int i;
    for (i = 0; i < book->count; i++) {
        if (strcmp(book->contacts[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", book->contacts[i].name, book->contacts[i].number);
            return;
        }
    }
    printf("Contact not found.\n");
}

void print_phonebook(struct phonebook *book) {
    int i;
    for (i = 0; i < book->count; i++) {
        printf("Name: %s\nNumber: %s\n\n", book->contacts[i].name, book->contacts[i].number);
    }
}

int main() {
    struct phonebook book = {0};
    int choice;
    char name[MAX_NAME_LENGTH], number[MAX_NUMBER_LENGTH];
    while (1) {
        printf("=========================\n");
        printf("1. Add contact\n");
        printf("2. Delete contact\n");
        printf("3. Search contact\n");
        printf("4. Print phonebook\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter contact name: ");
                scanf("%s", name);
                printf("Enter contact number: ");
                scanf("%s", number);
                add_contact(&book, name, number);
                break;
            case 2:
                printf("Enter contact name: ");
                scanf("%s", name);
                delete_contact(&book, name);
                break;
            case 3:
                printf("Enter contact name: ");
                scanf("%s", name);
                search_contact(&book, name);
                break;
            case 4:
                print_phonebook(&book);
                break;
            case 5:
                printf("Exiting phonebook...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}