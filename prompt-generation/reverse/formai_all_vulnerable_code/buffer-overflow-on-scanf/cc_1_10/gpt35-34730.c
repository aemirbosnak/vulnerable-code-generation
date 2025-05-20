//FormAI DATASET v1.0 Category: Mailing list manager ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

void printContacts(Contact *contacts, int numContacts) {
    printf("Current Contacts:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%s - %s\n", contacts[i].name, contacts[i].email);
    }
    printf("\n");
}

int main() {
    int MAX_CONTACTS;
    printf("Enter the maximum number of contacts that you want to manage: ");
    scanf("%d", &MAX_CONTACTS);

    Contact *contacts = (Contact*) malloc(sizeof(Contact)*MAX_CONTACTS);
    int numContacts = 0;

    printf("Welcome to the mailing list manager!\n");

    while (1) {
        printf("Select an option:\n  1. Add a contact\n  2. Remove a contact\n  3. Print all contacts\n  4. Quit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                if (numContacts == MAX_CONTACTS) {
                    printf("Mailing list is full!\n");
                    break;
                }

                Contact newContact;
                printf("Enter the contact's name: ");
                scanf("%s", newContact.name);
                printf("Enter the contact's email: ");
                scanf("%s", newContact.email);

                contacts[numContacts++] = newContact;

                printf("Contact added successfully.\n\n");
                break;
            }
            case 2: {
                if (numContacts == 0) {
                    printf("Mailing list is empty!\n");
                    break;
                }

                int indexToRemove;
                printf("Enter the index of the contact to remove: ");
                scanf("%d", &indexToRemove);

                if (indexToRemove >= numContacts) {
                    printf("Invalid index!\n");
                    break;
                }

                numContacts--;

                for (int i = indexToRemove; i < numContacts; i++) {
                    contacts[i] = contacts[i+1];
                }

                printf("Contact removed successfully.\n\n");
                break;
            }
            case 3: {
                printContacts(contacts, numContacts);
                break;
            }
            case 4: {
                printf("Goodbye!\n");
                free(contacts);
                return 0;
            }
            default:
                printf("Invalid choice\n");
        }
    }
}