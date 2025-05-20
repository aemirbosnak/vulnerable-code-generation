//FormAI DATASET v1.0 Category: Mailing list manager ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 50
#define MAX_LEN 50

typedef struct {
    char name[MAX_LEN];
    char email[MAX_LEN];
} Contact;

int numContacts = 0;
Contact contacts[MAX_EMAILS];

void addContact(char name[], char email[]) {
    if (numContacts >= MAX_EMAILS) {
        printf("Maximum number of contacts reached.\n");
    } else {
        strcpy(contacts[numContacts].name, name);
        strcpy(contacts[numContacts].email, email);
        numContacts++;
        printf("Contact added successfully!\n");
    }
}

void removeContact(char email[]) {
    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].email, email) == 0) {
            found = 1;
            for (int j = i; j < numContacts - 1; j++) {
                strcpy(contacts[j].name, contacts[j+1].name);
                strcpy(contacts[j].email, contacts[j+1].email);
            }
            numContacts--;
            printf("Contact removed successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Contact with email '%s' not found.\n", email);
    }
}

void printContacts() {
    if (numContacts == 0) {
        printf("No contacts found.\n");
    } else {
        printf("Name\t\tEmail\n");
        for (int i = 0; i < numContacts; i++) {
            printf("%s\t\t%s\n", contacts[i].name, contacts[i].email);
        }
    }
}

int main() {
    char name[MAX_LEN];
    char email[MAX_LEN];
    char input[MAX_LEN];

    while (1) {
        printf("Enter command (add, remove, print, or quit):\n");
        scanf("%s", input);
        if (strcmp(input, "add") == 0) {
            printf("Enter name:\n");
            scanf("%s", name);
            printf("Enter email:\n");
            scanf("%s", email);
            addContact(name, email);
        } else if (strcmp(input, "remove") == 0) {
            printf("Enter email:\n");
            scanf("%s", email);
            removeContact(email);
        } else if (strcmp(input, "print") == 0) {
            printContacts();
        } else if (strcmp(input, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}