//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBERS 100
#define MAX_LINE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int number[MAX_NUMBERS];
    int numberCount;
} Contact;

void printContact(Contact contact) {
    printf("Name: %s\n", contact.name);
    printf("Phone Numbers:\n");
    for (int i = 0; i < contact.numberCount; i++) {
        printf("%d.\t%d\n", i + 1, contact.number[i]);
    }
}

void addNumber(Contact* contact, int number) {
    contact->number[contact->numberCount] = number;
    contact->numberCount++;
}

void removeNumber(Contact* contact, int index) {
    for (int i = index; i < contact->numberCount; i++) {
        contact->number[i] = contact->number[i + 1];
    }
    contact->numberCount--;
}

void searchContact(Contact contact, char* name) {
    int found = 0;
    for (int i = 0; i < contact.numberCount && !found; i++) {
        if (strcmp(contact.name, name) == 0) {
            found = 1;
            printContact(contact);
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void printMenu() {
    printf("\n---The Curious C Casebook---\n");
    printf("1. Add a contact\n");
    printf("2. Remove a contact\n");
    printf("3. Search for a contact\n");
    printf("4. Display all contacts\n");
    printf("5. Quit\n");
}

int main() {
    Contact suspects[10];
    char choice[MAX_LINE_LENGTH];
    int index = 0;

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%s", choice);

        switch (choice[0]) {
            case '1':
                if (index < 10) {
                    printf("Enter name: ");
                    scanf("%s", suspects[index].name);
                    printf("Enter phone number: ");
                    scanf("%d", &suspects[index].number[0]);
                    addNumber(&suspects[index], suspects[index].number[0]);
                    index++;
                } else {
                    printf("Phonebook is full.\n");
                }
                break;

            case '2':
                if (index > 0) {
                    printf("Enter contact index to remove: ");
                    int indexToRemove;
                    scanf("%d", &indexToRemove);
                    removeNumber(&suspects[index - 1], indexToRemove);
                    index--;
                } else {
                    printf("Phonebook is empty.\n");
                }
                break;

            case '3':
                printf("Enter contact name to search for: ");
                scanf("%s", choice);
                searchContact(suspects[index - 1], choice);
                break;

            case '4':
                for (int i = 0; i < index; i++) {
                    printContact(suspects[i]);
                    printf("\n");
                }
                break;

            case '5':
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}