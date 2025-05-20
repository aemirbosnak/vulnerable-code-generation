//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_PHONE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char phone[MAX_PHONE_LEN];
} Contact;

int main() {
    int numContacts = 0;
    Contact *contacts = NULL;

    // Print menu
    printf("Mailing List Manager:\n");
    printf("1. Add a contact\n");
    printf("2. Remove a contact\n");
    printf("3. Print the current list\n");
    printf("4. Quit\n");

    int choice;
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: // Add a contact
                numContacts++;
                contacts = realloc(contacts, numContacts * sizeof(Contact));
                printf("\nEnter contact name: ");
                scanf("%s", contacts[numContacts-1].name);
                printf("Enter contact email: ");
                scanf("%s", contacts[numContacts-1].email);
                printf("Enter contact phone number: ");
                scanf("%s", contacts[numContacts-1].phone);
                break;
            case 2: // Remove a contact
                if (numContacts == 0) {
                    printf("\nNo contacts to remove.\n");
                } else {
                    printf("\nEnter the index of the contact to remove (1-%d): ", numContacts);
                    int indexToRemove;
                    scanf("%d", &indexToRemove);
                    if (indexToRemove < 1 || indexToRemove > numContacts) {
                        printf("\nInvalid index.\n");
                    } else {
                        for (int i = indexToRemove-1; i < numContacts-1; i++) {
                            contacts[i] = contacts[i+1];
                        }
                        numContacts--;
                        contacts = realloc(contacts, numContacts * sizeof(Contact));
                        printf("\nContact removed.\n");
                    }
                }
                break;
            case 3: // Print the current list
                printf("\nCurrent Mailing List:\n");
                for (int i = 0; i < numContacts; i++) {
                    printf("%d. Name: %s\n   Email: %s\n   Phone: %s\n", i+1, contacts[i].name, contacts[i].email, contacts[i].phone);
                }
                break;
            case 4: // Quit
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    } while (choice != 4);

    free(contacts);
    printf("\nGoodbye!\n");

    return 0;
}