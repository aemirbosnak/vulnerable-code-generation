//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_PHONE_NUMBERS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int phoneNumbersCount;
    int phoneNumbers[MAX_PHONE_NUMBERS];
} Contact;

Contact phoneBook[100];
int currentContactIndex = 0;

int findContactIndexByName(const char *name) {
    for (int i = 0; i < currentContactIndex; ++i) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void addContact(const char *name, int phoneNumber) {
    if (currentContactIndex == 100) {
        printf("Phone book is full.\n");
        return;
    }

    int contactIndex = findContactIndexByName(name);
    if (contactIndex != -1) {
        printf("Contact with this name already exists.\n");
        return;
    }

    strcpy(phoneBook[currentContactIndex].name, name);
    phoneBook[currentContactIndex].phoneNumbers[0] = phoneNumber;
    phoneBook[currentContactIndex].phoneNumbersCount = 1;

    currentContactIndex++;
}

void editContactPhoneNumber(const char *name, int newPhoneNumber) {
    int contactIndex = findContactIndexByName(name);
    if (contactIndex == -1) {
        printf("Contact not found.\n");
        return;
    }

    for (int i = 0; i < phoneBook[contactIndex].phoneNumbersCount; ++i) {
        if (phoneBook[contactIndex].phoneNumbers[i] == phoneBook[contactIndex].phoneNumbers[0]) {
            phoneBook[contactIndex].phoneNumbers[i] = newPhoneNumber;
            printf("Phone number updated successfully.\n");
            return;
        }
    }

    printf("Error: Contact has only one phone number.\n");
}

void printContact(const Contact *contact) {
    printf("%s: ", contact->name);
    for (int i = 0; i < contact->phoneNumbersCount; ++i) {
        printf("%d ", contact->phoneNumbers[i]);
    }
    printf("\n");
}

void printPhoneBook() {
    for (int i = 0; i < currentContactIndex; ++i) {
        printContact(&phoneBook[i]);
    }
}

int main() {
    char command[20];
    char name[MAX_NAME_LENGTH];
    int phoneNumber;

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        } else if (strcmp(command, "add") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter phone number: ");
            scanf("%d", &phoneNumber);
            addContact(name, phoneNumber);
        } else if (strcmp(command, "edit") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter new phone number: ");
            scanf("%d", &phoneNumber);
            editContactPhoneNumber(name, phoneNumber);
        } else if (strcmp(command, "list") == 0) {
            printPhoneBook();
        } else {
            printf("Unknown command.\n");
        }
    }

    return 0;
}