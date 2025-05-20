//FormAI DATASET v1.0 Category: Phone Book ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 15
#define MAX_CONTACTS 20

// Define contact struct
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phoneNumber[MAX_PHONE_NUMBER_LENGTH];
} Contact;

// Define phone book struct
typedef struct {
    Contact contacts[MAX_CONTACTS];
    int numContacts;
} PhoneBook;

// Add a contact to the phone book
void addContact(PhoneBook *pb, Contact c) {
    if (pb->numContacts < MAX_CONTACTS) {
        pb->contacts[pb->numContacts++] = c;
        printf("Contact added to phone book.\n");
    } else {
        printf("Phone book is full. Contact not added.\n");
    }
}

// Remove a contact from the phone book
void removeContact(PhoneBook *pb, char *name) {
    int i, j;

    for (i = 0; i < pb->numContacts; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            // Shift all remaining contacts one spot to the left
            for (j = i; j < pb->numContacts - 1; j++) {
                pb->contacts[j] = pb->contacts[j+1];
            }
            pb->numContacts--;
            printf("Contact removed from phone book.\n");
            return;
        }
    }

    printf("Contact not found in phone book.\n");
}

// Find a contact in the phone book
void findContact(PhoneBook *pb, char *name) {
    int i;

    for (i = 0; i < pb->numContacts; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("Name: %s \nPhone number: %s\n", pb->contacts[i].name, pb->contacts[i].phoneNumber);
            return;
        }
    }

    printf("Contact not found in phone book.\n");
}

// Print all contacts in the phone book
void printContacts(PhoneBook *pb) {
    int i;

    for (i = 0; i < pb->numContacts; i++) {
        printf("Name: %s \nPhone number: %s\n", pb->contacts[i].name, pb->contacts[i].phoneNumber);
    }

    if (pb->numContacts == 0) {
        printf("Phone book is empty.\n");
    }
}

int main() {
    PhoneBook pb;
    pb.numContacts = 0;

    int choice = -1;
    char name[MAX_NAME_LENGTH];
    char phoneNumber[MAX_PHONE_NUMBER_LENGTH];

    while (choice != 0) {
        printf("\nSelect an option from the menu:\n");
        printf("1. Add a contact\n");
        printf("2. Remove a contact\n");
        printf("3. Find a contact\n");
        printf("4. Print all contacts\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phoneNumber);

                Contact c;
                strcpy(c.name, name);
                strcpy(c.phoneNumber, phoneNumber);

                addContact(&pb, c);
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);

                removeContact(&pb, name);
                break;
            case 3:
                printf("Enter name: ");
                scanf("%s", name);

                findContact(&pb, name);
                break;
            case 4:
                printContacts(&pb);
                break;
            case 0:
                printf("Exiting phone book.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}