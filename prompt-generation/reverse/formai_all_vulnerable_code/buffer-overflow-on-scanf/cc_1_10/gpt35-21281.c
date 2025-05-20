//FormAI DATASET v1.0 Category: Phone Book ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone_number[20];
} PhoneBookEntry;

void addNewContact(PhoneBookEntry *phoneBook, int *numContacts);
void searchContact(PhoneBookEntry *phoneBook, int numContacts);
void displayAllContacts(PhoneBookEntry *phoneBook, int numContacts);
void deleteContact(PhoneBookEntry *phoneBook, int *numContacts);

int main() {
    PhoneBookEntry phoneBook[MAX_CONTACTS];
    int numContacts = 0;
    int choice;

    while (1) {
        printf("\nMENU\n");
        printf("1. Add New Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display All Contacts\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNewContact(phoneBook, &numContacts);
                break;
            case 2:
                searchContact(phoneBook, numContacts);
                break;
            case 3:
                displayAllContacts(phoneBook, numContacts);
                break;
            case 4:
                deleteContact(phoneBook, &numContacts);
                break;
            case 5:
                printf("Exiting Phone Book. Bye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void addNewContact(PhoneBookEntry *phoneBook, int *numContacts) {
    if (*numContacts == MAX_CONTACTS) {
        printf("Phone Book is full. Cannot add new contact.\n");
        return;
    }

    printf("Enter Name: ");
    scanf("%s", (phoneBook + *numContacts)->name);

    printf("Enter Phone Number: ");
    scanf("%s", (phoneBook + *numContacts)->phone_number);

    printf("Contact added successfully.\n");
    (*numContacts)++;
}

void searchContact(PhoneBookEntry *phoneBook, int numContacts) {
    if (numContacts == 0) {
        printf("Phone Book is empty. Cannot search for contact.\n");
        return;
    }

    char name[50];
    printf("Enter Name to Search: ");
    scanf("%s", name);

    for (int i=0; i<numContacts; i++) {
        if (strcmp((phoneBook + i)->name, name) == 0) {
            printf("Contact Found:\n");
            printf("Name: %s, Phone Number: %s\n", (phoneBook + i)->name, (phoneBook + i)->phone_number);
            return;
        }
    }

    printf("Contact not found for %s\n", name);
}

void displayAllContacts(PhoneBookEntry *phoneBook, int numContacts) {
    if (numContacts == 0) {
        printf("Phone Book is empty. No contacts to display.\n");
        return;
    }

    printf("List of all Contacts:\n");
    for (int i=0; i<numContacts; i++) {
        printf("Name: %s, Phone Number: %s\n", (phoneBook + i)->name, (phoneBook + i)->phone_number);
    }
}

void deleteContact(PhoneBookEntry *phoneBook, int *numContacts) {
    if (*numContacts == 0) {
        printf("Phone Book is empty. Cannot delete contact.\n");
        return;
    }

    char name[50];
    printf("Enter Name to Delete: ");
    scanf("%s", name);

    for (int i=0; i<*numContacts; i++) {
        if (strcmp((phoneBook + i)->name, name) == 0) {
            for (int j=i; j<(*numContacts)-1; j++) {
                strcpy((phoneBook + j)->name, (phoneBook + j + 1)->name);
                strcpy((phoneBook + j)->phone_number, (phoneBook + j + 1)->phone_number);
            }
            printf("Contact deleted successfully.\n");
            (*numContacts)--;
            return;
        }
    }

    printf("Contact not found for %s\n", name);
}