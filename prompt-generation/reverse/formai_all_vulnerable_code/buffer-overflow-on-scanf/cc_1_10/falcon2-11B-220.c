//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: visionary
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone[12];
    char address[100];
} Contact;

Contact contacts[100];
int numContacts = 0;

void addContact(char *name, char *phone, char *address) {
    int i;
    Contact *contact = &contacts[numContacts];

    for (i = 0; i < numContacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            break;
        }
    }

    if (i == numContacts) {
        strcpy(contact->name, name);
        strcpy(contact->phone, phone);
        strcpy(contact->address, address);
        numContacts++;
    }
}

void searchContact(char *name) {
    int i;
    Contact *contact = &contacts[numContacts];

    for (i = 0; i < numContacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Address: %s\n", contacts[i].address);
            return;
        }
    }

    printf("Contact not found\n");
}

void deleteContact(char *name) {
    int i;
    Contact *contact = &contacts[numContacts];

    for (i = 0; i < numContacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            for (int j = i; j < numContacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            numContacts--;
            break;
        }
    }
}

int main() {
    char name[50], phone[12], address[100];
    int choice = 0;

    while (1) {
        printf("1. Add contact\n2. Search contact\n3. Delete contact\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter contact name: ");
                scanf("%s", name);
                printf("Enter contact phone number: ");
                scanf("%s", phone);
                printf("Enter contact address: ");
                scanf("%s", address);
                addContact(name, phone, address);
                break;

            case 2:
                printf("Enter contact name to search: ");
                scanf("%s", name);
                searchContact(name);
                break;

            case 3:
                printf("Enter contact name to delete: ");
                scanf("%s", name);
                deleteContact(name);
                break;
        }
    }

    return 0;
}