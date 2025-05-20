//FormAI DATASET v1.0 Category: Phone Book ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_PHONE_NUM_LEN 20

typedef struct phoneBookEntry {
    char name[MAX_NAME_LEN];
    char phoneNum[MAX_PHONE_NUM_LEN];
    struct phoneBookEntry* nextEntry;
} PhoneBookEntry;

void addEntry(char name[MAX_NAME_LEN], char phoneNum[MAX_PHONE_NUM_LEN], PhoneBookEntry** head) {
    PhoneBookEntry* newEntry = (PhoneBookEntry*) malloc(sizeof(PhoneBookEntry));
    strcpy(newEntry->name, name);
    strcpy(newEntry->phoneNum, phoneNum);
    newEntry->nextEntry = *head;
    *head = newEntry;
}

void printPhoneBook(PhoneBookEntry* head) {
    PhoneBookEntry* currentEntry = head;
    while (currentEntry != NULL) {
        printf("Name: %s\nPhone Number: %s\n\n", currentEntry->name, currentEntry->phoneNum);
        currentEntry = currentEntry->nextEntry;
    }
}

void searchPhoneBook(char name[MAX_NAME_LEN], PhoneBookEntry* head) {
    PhoneBookEntry* currentEntry = head;
    while (currentEntry != NULL) {
        if (strcmp(currentEntry->name, name) == 0) {
            printf("Name: %s\nPhone Number: %s\n\n", currentEntry->name, currentEntry->phoneNum);
            return;
        }
        currentEntry = currentEntry->nextEntry;
    }
    printf("Entry not found\n");
}

void deleteEntry(char name[MAX_NAME_LEN], PhoneBookEntry** head) {
    PhoneBookEntry* currentEntry = *head;
    PhoneBookEntry* previousEntry = NULL;
    while (currentEntry != NULL) {
        if (strcmp(currentEntry->name, name) == 0) {
            if (previousEntry == NULL) {
                *head = currentEntry->nextEntry;
            } else {
                previousEntry->nextEntry = currentEntry->nextEntry;
            }
            free(currentEntry);
            return;
        }
        previousEntry = currentEntry;
        currentEntry = currentEntry->nextEntry;
    }
    printf("Entry not found\n");
}

void freePhoneBook(PhoneBookEntry* head) {
    PhoneBookEntry* currentEntry = head;
    while (currentEntry != NULL) {
        PhoneBookEntry* nextEntry = currentEntry->nextEntry;
        free(currentEntry);
        currentEntry = nextEntry;
    }
}

int main() {
    printf("Welcome to your ephemeral phone book!\n\n");
    PhoneBookEntry* phoneBook = NULL;
    char option;
    do {
        printf("What would you like to do?\n");
        printf("A - Add an entry\n");
        printf("P - Print the phone book\n");
        printf("S - Search for an entry\n");
        printf("D - Delete an entry\n");
        printf("Q - Quit the program\n");

        scanf(" %c", &option);
        printf("\n");

        switch(option) {
            case 'A': {
                char name[MAX_NAME_LEN];
                char phoneNum[MAX_PHONE_NUM_LEN];
                printf("Enter the name: ");
                scanf(" %[^\n]%*c", name);
                printf("Enter the phone number: ");
                scanf(" %s", phoneNum);
                addEntry(name, phoneNum, &phoneBook);
                printf("Entry added\n\n");
            } break;
            case 'P': {
                if (phoneBook == NULL) {
                    printf("Phone book is empty\n\n");
                } else {
                    printf("Printing phone book:\n");
                    printPhoneBook(phoneBook);
                }
            } break;
            case 'S': {
                if (phoneBook == NULL) {
                    printf("Phone book is empty\n\n");
                } else {
                    char name[MAX_NAME_LEN];
                    printf("Enter the name: ");
                    scanf(" %[^\n]%*c", name);
                    searchPhoneBook(name, phoneBook);
                }
            } break;
            case 'D': {
                if (phoneBook == NULL) {
                    printf("Phone book is empty\n\n");
                } else {
                    char name[MAX_NAME_LEN];
                    printf("Enter the name: ");
                    scanf(" %[^\n]%*c", name);
                    deleteEntry(name, &phoneBook);
                    printf("Entry deleted\n\n");
                }
            } break;
            case 'Q': {
                printf("Exiting. Goodbye!\n");
            } break;
            default: {
                printf("Invalid option. Please try again\n\n");
            } break;
        }
    } while (option != 'Q');

    freePhoneBook(phoneBook);
    return 0;
}