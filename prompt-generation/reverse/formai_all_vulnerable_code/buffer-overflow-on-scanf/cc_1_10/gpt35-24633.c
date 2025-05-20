//FormAI DATASET v1.0 Category: Phone Book ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NUM_LEN 20

struct Contact {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
    struct Contact *next;
};

// Inserts a new contact into the phone book
void insertContact(struct Contact **headRef, char *name, char *number) {
    struct Contact *newContact = (struct Contact *)malloc(sizeof(struct Contact));
    if (newContact == NULL) {
        printf("Error: Memory allocation failed!\n");
        return;
    }
    strncpy(newContact->name, name, MAX_NAME_LEN);
    strncpy(newContact->number, number, MAX_NUM_LEN);
    newContact->next = *headRef;
    *headRef = newContact;
}

// Searches for a contact with a given name and returns its phone number
// If the contact is not found, returns NULL
char *searchContact(struct Contact *head, char *name) {
    struct Contact *currContact = head;
    while (currContact != NULL) {
        if (strcmp(currContact->name, name) == 0) {
            return currContact->number;
        }
        currContact = currContact->next;
    }
    return NULL;
}

int main() {
    struct Contact *phoneBook = NULL;
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
    char *phoneNumber;

    printf("Welcome to the C Phone Book!\n");

    while (1) {
        printf("Enter a command (add, search, exit): ");
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter number: ");
            scanf("%s", number);
            insertContact(&phoneBook, name, number);
            printf("%s added to phone book.\n", name);
        }
        else if (strcmp(command, "search") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            phoneNumber = searchContact(phoneBook, name);
            if (phoneNumber == NULL) {
                printf("%s not found in phone book.\n", name);
            }
            else {
                printf("%s's phone number is %s.\n", name, phoneNumber);
            }
        }
        else if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid command.\n");
        }
    }

    // Free memory allocated for the phone book
    struct Contact *currContact = phoneBook;
    while (currContact != NULL) {
        struct Contact *nextContact = currContact->next;
        free(currContact);
        currContact = nextContact;
    }

    return 0;
}