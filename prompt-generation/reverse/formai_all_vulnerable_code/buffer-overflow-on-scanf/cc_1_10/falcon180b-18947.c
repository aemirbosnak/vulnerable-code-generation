//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAILS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
} Contact;

int main() {
    int choice, numContacts;
    char input[100];
    Contact contacts[MAX_EMAILS];
    int i;

    // Initialize variables
    numContacts = 0;

    // Main loop
    while (1) {
        // Print menu
        printf("Mailing List Manager\n");
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. View contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Exit program if user chooses to quit
        if (choice == 4) {
            break;
        }

        // Add contact
        if (choice == 1) {
            printf("Enter name: ");
            scanf("%s", input);
            strcpy(contacts[numContacts].name, input);

            printf("Enter email: ");
            scanf("%s", input);
            strcpy(contacts[numContacts].email, input);

            numContacts++;
            printf("Contact added successfully.\n");
        }

        // Remove contact
        else if (choice == 2) {
            printf("Enter name to remove: ");
            scanf("%s", input);

            for (i = 0; i < numContacts; i++) {
                if (strcmp(contacts[i].name, input) == 0) {
                    memmove(&contacts[i], &contacts[i+1], (numContacts-i-1)*sizeof(Contact));
                    numContacts--;
                    printf("Contact removed successfully.\n");
                    break;
                }
            }
        }

        // View contacts
        else if (choice == 3) {
            printf("Contacts:\n");
            for (i = 0; i < numContacts; i++) {
                printf("Name: %s\nEmail: %s\n", contacts[i].name, contacts[i].email);
            }
        }

        // Invalid choice
        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}