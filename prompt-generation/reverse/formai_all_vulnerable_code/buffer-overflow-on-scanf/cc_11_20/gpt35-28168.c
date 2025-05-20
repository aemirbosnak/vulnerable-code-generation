//FormAI DATASET v1.0 Category: Phone Book ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone[15];
};

int main() {
    int choice, numContacts = 0;
    struct Contact contacts[MAX_CONTACTS];
    char searchName[50];

    do {
        printf("Phone Book\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Display all contacts\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (numContacts == MAX_CONTACTS) {
                    printf("Phone book is full!\n");
                } else {
                    printf("Enter name: ");
                    scanf("%s", contacts[numContacts].name);
                    printf("Enter phone number: ");
                    scanf("%s", contacts[numContacts].phone);
                    numContacts++;
                    printf("Contact added successfully!\n");
                }
                break;
            case 2:
                printf("Enter name to search: ");
                scanf("%s", searchName);
                for (int i = 0; i < numContacts; i++) {
                    if (strcmp(searchName, contacts[i].name) == 0) {
                        printf("Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
                        break;
                    } else if (i == numContacts - 1) {
                        printf("Contact not found!\n");
                    }
                }
                break;
            case 3:
                if (numContacts == 0) {
                    printf("Phone book is empty!\n");
                } else {
                    printf("Contacts:\n");
                    for (int i = 0; i < numContacts; i++) {
                        printf("Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
                    }
                }
                break;
            case 4:
                printf("Exiting phone book...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}