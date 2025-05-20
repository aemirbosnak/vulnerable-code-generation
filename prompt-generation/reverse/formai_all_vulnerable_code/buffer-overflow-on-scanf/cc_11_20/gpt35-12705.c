//FormAI DATASET v1.0 Category: Phone Book ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 15
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phoneNumber[MAX_PHONE_NUMBER_LENGTH];
} Contact;

int main() {
    Contact phoneBook[MAX_CONTACTS];
    int numContacts = 0;

    printf("Welcome to the C Phone Book!\n\n");

    while (1) {
        printf("1. Add a contact\n");
        printf("2. Find a contact\n");
        printf("3. Show all contacts\n");
        printf("4. Exit\n");

        int choice;
        printf("\nEnter a choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("\nAdding a contact...\n");

                if (numContacts == MAX_CONTACTS) {
                    printf("Sorry, the phone book is full.\n\n");
                    break;
                }

                printf("Enter the name: ");
                char name[MAX_NAME_LENGTH];
                scanf("%s", name);

                printf("Enter the phone number: ");
                char phoneNumber[MAX_PHONE_NUMBER_LENGTH];
                scanf("%s", phoneNumber);

                Contact newContact;
                strcpy(newContact.name, name);
                strcpy(newContact.phoneNumber, phoneNumber);

                phoneBook[numContacts++] = newContact;

                printf("Contact added!\n\n");
                break;
            }
            case 2: {
                printf("\nFinding a contact...\n");

                if (numContacts == 0) {
                    printf("Sorry, there are no contacts to find.\n\n");
                    break;
                }

                printf("Enter the name: ");
                char name[MAX_NAME_LENGTH];
                scanf("%s", name);

                int foundContact = 0;

                for (int i = 0; i < numContacts; i++) {
                    if (strcmp(name, phoneBook[i].name) == 0) {
                        printf("Name: %s\nPhone Number: %s\n\n", phoneBook[i].name, phoneBook[i].phoneNumber);
                        foundContact = 1;
                        break;
                    }
                }

                if (!foundContact) {
                    printf("Sorry, contact not found.\n\n");
                }

                break;
            }
            case 3: {
                printf("\nAll contacts:\n");

                if (numContacts == 0) {
                    printf("Sorry, there are no contacts to show.\n\n");
                    break;
                }

                for (int i = 0; i < numContacts; i++) {
                    printf("Name: %s\nPhone Number: %s\n\n", phoneBook[i].name, phoneBook[i].phoneNumber);
                }

                break;
            }
            case 4: {
                printf("\nThank you for using the C Phone Book!\n");
                return 0;
            }
            default: {
                printf("\nInvalid choice, please try again.\n\n");
                break;
            }
        }
    }
}