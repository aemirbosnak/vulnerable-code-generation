//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
} Contact;

void printMenu() {
    printf("\n*********************************\n");
    printf("* Romeo's and Juliet's Phone Book *\n");
    printf("*********************************\n");
    printf("* 1. Add Contact                 *\n");
    printf("* 2. Search Contact              *\n");
    printf("* 3. Display All Contacts        *\n");
    printf("* 4. Delete Contact              *\n");
    printf("* 5. Exit                       *\n");
    printf("*********************************\n");
}

void addContact(Contact contacts[], int *numContacts) {
    if (*numContacts >= MAX_CONTACTS) {
        printf("Phone book is full.\n");
        return;
    }
    printf("Enter contact name: ");
    scanf("%s", contacts[*numContacts].name);
    printf("Enter contact phone number: ");
    scanf("%s", contacts[*numContacts].phone);
    (*numContacts)++;
}

int searchContact(Contact contacts[], int numContacts, char name[]) {
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("\nName: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            return 1;
        }
    }
    printf("Contact not found.\n");
    return 0;
}

void displayContacts(Contact contacts[], int numContacts) {
    printf("\n---------------------------------------------------------\n");
    printf("| Name           | Phone                             |\n");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < numContacts; i++) {
        printf("| %-15s | %-15s |\n", contacts[i].name, contacts[i].phone);
    }
    printf("---------------------------------------------------------\n");
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    int choice;
    char name[50];

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                printf("Enter contact name: ");
                scanf("%s", name);
                searchContact(contacts, numContacts, name);
                break;
            case 3:
                displayContacts(contacts, numContacts);
                break;
            case 4:
                printf("Enter contact name to delete: ");
                scanf("%s", name);
                for (int i = 0; i < numContacts; i++) {
                    if (strcmp(contacts[i].name, name) == 0) {
                        for (int j = i; j < numContacts - 1; j++) {
                            contacts[j] = contacts[j + 1];
                        }
                        numContacts--;
                        break;
                    }
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (choice != 5);

    return 0;
}