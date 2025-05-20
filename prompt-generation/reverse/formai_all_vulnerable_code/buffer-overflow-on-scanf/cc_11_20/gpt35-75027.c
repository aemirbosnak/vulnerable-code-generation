//FormAI DATASET v1.0 Category: Phone Book ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct contact {
    char name[30];
    char phone[15];
} Contact;

int main() {
    Contact phoneBook[MAX_CONTACTS];
    int numContacts = 0;

    printf("Welcome to the Phone Book!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a contact\n");
        printf("2. View all contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Delete a contact\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name: ");
                scanf("%s", phoneBook[numContacts].name);
                printf("Enter the phone number: ");
                scanf("%s", phoneBook[numContacts].phone);
                printf("Contact added successfully!\n");
                numContacts++;
                break;
            case 2:
                if (numContacts == 0) {
                    printf("No contacts found!\n");
                } else {
                    printf("List of Contacts:\n");
                    for (int i = 0; i < numContacts; i++) {
                        printf("%s - %s\n", phoneBook[i].name, phoneBook[i].phone);
                    }
                }
                break;
            case 3:
                printf("Enter the name to search for: ");
                char searchName[30];
                scanf("%s", searchName);
                int match = 0;
                for (int i = 0; i < numContacts; i++) {
                    if (strcmp(phoneBook[i].name, searchName) == 0) {
                        printf("%s - %s\n", phoneBook[i].name, phoneBook[i].phone);
                        match = 1;
                        break;
                    }
                }
                if (!match) {
                    printf("Contact not found!\n");
                }
                break;
            case 4:
                printf("Enter the index of the contact to delete: ");
                int deleteIndex;
                scanf("%d", &deleteIndex);
                if (deleteIndex >= numContacts || deleteIndex < 0) {
                    printf("Invalid index!\n");
                } else {
                    for (int i = deleteIndex; i < numContacts - 1; i++) {
                        strcpy(phoneBook[i].name, phoneBook[i + 1].name);
                        strcpy(phoneBook[i].phone, phoneBook[i + 1].phone);
                    }
                    printf("Contact deleted successfully!\n");
                    numContacts--;
                }
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}