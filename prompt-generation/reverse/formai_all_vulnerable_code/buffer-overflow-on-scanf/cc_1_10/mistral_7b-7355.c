//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[50];
    char phone[15];
} Contact;

void addContact(Contact contacts[], int *numContacts);
void printContacts(Contact contacts[], int numContacts);
void searchContact(Contact contacts[], int numContacts);

int main() {
    Contact contacts[MAX_SIZE];
    int numContacts = 0;

    while (1) {
        printf("\n1. Add Contact\n2. Print Contacts\n3. Search Contact\n4. Quit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                printContacts(contacts, numContacts);
                break;
            case 3:
                searchContact(contacts, numContacts);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addContact(Contact contacts[], int *numContacts) {
    if (*numContacts == MAX_SIZE) {
        printf("Phone book is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", contacts[*numContacts].name);

    printf("Enter phone number: ");
    scanf("%s", contacts[*numContacts].phone);

    (*numContacts)++;
}

void printContacts(Contact contacts[], int numContacts) {
    printf("\nContacts:\n");

    for (int i = 0; i < numContacts; i++) {
        printf("\nName: %s\nPhone: %s", contacts[i].name, contacts[i].phone);
    }
}

void searchContact(Contact contacts[], int numContacts) {
    char searchName[50];
    int found = 0;

    printf("Enter name to search for: ");
    scanf("%s", searchName);

    for (int i = 0; i < numContacts && !found; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("\nName: %s\nPhone: %s", contacts[i].name, contacts[i].phone);
            found = 1;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}