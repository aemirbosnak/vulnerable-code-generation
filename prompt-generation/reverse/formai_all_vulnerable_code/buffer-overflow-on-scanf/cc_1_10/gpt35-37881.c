//FormAI DATASET v1.0 Category: Mailing list manager ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LEN 50
#define MAX_NAME_LEN 20
#define MAX_LIST_SIZE 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

typedef struct {
    Contact contactList[MAX_LIST_SIZE];
    int listSize;
} MailingList;

void printMenu() {
    printf("\nWelcome to Mailing List Manager!\n");
    printf("1. Add contact to list\n");
    printf("2. Remove contact from list\n");
    printf("3. Display list\n");
    printf("4. Search for contact by name\n");
    printf("5. Exit\n\n");
}

void addContact(MailingList *list) {
    if (list->listSize >= MAX_LIST_SIZE) {
        printf("Error: Mailing list is full.\n");
        return;
    }

    Contact newContact;

    printf("\nEnter name: ");
    fgets(newContact.name, MAX_NAME_LEN, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0';  // remove trailing newline character

    printf("Enter email: ");
    fgets(newContact.email, MAX_EMAIL_LEN, stdin);
    newContact.email[strcspn(newContact.email, "\n")] = '\0';  // remove trailing newline character
    
    list->contactList[list->listSize++] = newContact;

    printf("%s was successfully added to the mailing list!\n", newContact.name);
}

void removeContact(MailingList *list) {
    char name[MAX_NAME_LEN];
    int matchFound = 0;

    printf("\nEnter name of contact to remove: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0';  // remove trailing newline character

    for (int i = 0; i < list->listSize; i++) {
        if (strcmp(name, list->contactList[i].name) == 0) {
            matchFound = 1;

            // shift all subsequent contacts back one index to overwrite removed contact
            for (int j = i; j < list->listSize; j++) {
                list->contactList[j] = list->contactList[j+1];
            }

            list->listSize--;
            printf("%s was successfully removed from the mailing list.\n", name);
            break;
        }
    }

    if (!matchFound) {
        printf("Error: %s was not found in the mailing list.\n", name);
    }
}

void displayList(MailingList *list) {
    printf("\nMailing list:\n");

    if (list->listSize == 0) {
        printf("Empty.\n");
        return;
    }

    for (int i = 0; i < list->listSize; i++) {
        printf("%s - %s\n", list->contactList[i].name, list->contactList[i].email);
    }
}

void searchByName(MailingList *list) {
    char name[MAX_NAME_LEN];
    int matchFound = 0;

    printf("\nEnter name to search for: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0';  // remove trailing newline character

    for (int i = 0; i < list->listSize; i++) {
        if (strcmp(name, list->contactList[i].name) == 0) {
            matchFound = 1;
            printf("%s - %s\n", list->contactList[i].name, list->contactList[i].email);
        }
    }

    if (!matchFound) {
        printf("%s was not found in the mailing list.\n", name);
    }
}

int main() {
    MailingList list = {0};
    int choice;

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // remove trailing newline character from input buffer

        switch (choice) {
            case 1:
                addContact(&list);
                break;
            case 2:
                removeContact(&list);
                break;
            case 3:
                displayList(&list);
                break;
            case 4:
                searchByName(&list);
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nError: Invalid choice.\n");
                break;
        }

    } while (choice != 5);

    return 0;
}