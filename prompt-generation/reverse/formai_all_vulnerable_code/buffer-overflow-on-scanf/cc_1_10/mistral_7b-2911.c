//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 30
#define PHONE_LENGTH 12

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

Contact phoneBook[MAX_ENTRIES];
int numEntries = 0;

void listContacts() {
    int i;
    printf("\n*** PHONE BOOK ***\n");
    for (i = 0; i < numEntries; i++) {
        printf("%d. %s - %s\n", i+1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void addContact() {
    if (numEntries >= MAX_ENTRIES) {
        printf("\nPhone book is full!\n");
        return;
    }

    printf("\nEnter name: ");
    scanf("%s", phoneBook[numEntries].name);

    printf("Enter phone number: ");
    scanf("%s", phoneBook[numEntries].phone);

    numEntries++;
}

int main() {
    char command[10];
    int choice;

    do {
        printf("\n*** PHONE BOOK MENU ***\n");
        printf("1. Add contact\n");
        printf("2. List contacts\n");
        printf("3. Exit\n");
        printf("> ");
        scanf("%s", command);

        choice = atoi(command);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                listContacts();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid command.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}