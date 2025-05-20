//FormAI DATASET v1.0 Category: Mailing list manager ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LEN 50
#define MAX_NAME_LEN 20
#define MAX_LIST_SIZE 10

int main() {
    char names[MAX_LIST_SIZE][MAX_NAME_LEN];
    char emails[MAX_LIST_SIZE][MAX_EMAIL_LEN];
    int numContacts = 0;
    int choice = 0;

    do {
        // Display menu
        printf("\n1. Add contact\n");
        printf("2. Display contacts\n");
        printf("3. Remove contact\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle user choice
        switch (choice) {
            case 1: // Add contact
                if (numContacts >= MAX_LIST_SIZE) {
                    printf("Maximum number of contacts reached!\n");
                    break;
                }

                printf("Enter name: ");
                scanf("%s", names[numContacts]);

                printf("Enter email: ");
                scanf("%s", emails[numContacts]);

                numContacts++;

                printf("Contact added!\n");
                break;

            case 2: // Display contacts
                if (numContacts == 0) {
                    printf("No contacts found!\n");
                    break;
                }

                printf("Contacts:\n");
                for (int i = 0; i < numContacts; i++) {
                    printf("%d. Name: %s, Email: %s\n", i+1, names[i], emails[i]);
                }

                break;

            case 3: // Remove contact
                if (numContacts == 0) {
                    printf("No contacts found!\n");
                    break;
                }

                printf("Enter index of contact to remove: ");
                int indexToRemove;
                scanf("%d", &indexToRemove);

                if (indexToRemove < 1 || indexToRemove > numContacts) {
                    printf("Invalid index!\n");
                    break;
                }

                indexToRemove--;

                // Remove contact by shifting all elements after it to the left
                for (int i = indexToRemove; i < numContacts-1; i++) {
                    strcpy(names[i], names[i+1]);
                    strcpy(emails[i], emails[i+1]);
                }
                numContacts--;

                printf("Contact removed!\n");
                break;

            case 4: // Quit
                printf("Exiting program...\n");
                break;

            default: // Invalid choice
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}