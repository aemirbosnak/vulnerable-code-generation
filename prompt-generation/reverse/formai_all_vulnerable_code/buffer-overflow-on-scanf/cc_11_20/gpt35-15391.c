//FormAI DATASET v1.0 Category: Mailing list manager ; Style: excited
/* 
 * Welcome to my exciting C Mailing List Manager program!
 * This amazing program allows you to easily manage a mailing list using C!
 * Get ready to be amazed as you send emails to your entire list with just a few clicks!
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 50
#define MAX_NAME_LENGTH 30
#define MAX_LIST_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

int main() {

    Contact mailingList[MAX_LIST_LENGTH];
    int numContacts = 0;

    printf("Welcome to the C Mailing List Manager!\n\n");

    while (1) {
        // Display the main menu
        printf("MAIN MENU\n");
        printf("1. Add a Contact\n");
        printf("2. View Contacts\n");
        printf("3. Send Email\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");

        // Get the user's choice
        int choice;
        scanf("%d", &choice);

        // Perform the corresponding action based on the user's choice
        switch (choice) {
            case 1: // Add a contact
                printf("\nADD A CONTACT\n");

                // Make sure there is space in the mailing list
                if (numContacts == MAX_LIST_LENGTH) {
                    printf("Error: The mailing list is full.\n\n");
                    break;
                }

                // Get the new contact's name and email address
                printf("Enter the contact's name: ");
                scanf("%s", mailingList[numContacts].name);
                printf("Enter the contact's email address: ");
                scanf("%s", mailingList[numContacts].email);

                // Increment the number of contacts in the mailing list
                numContacts++;

                printf("Contact added successfully!\n\n");
                break;

            case 2: // View contacts
                printf("\nVIEW CONTACTS\n");

                // Make sure there are contacts in the mailing list
                if (numContacts == 0) {
                    printf("No contacts on the mailing list.\n\n");
                    break;
                }

                // Display all of the contacts in the mailing list
                for (int i = 0; i < numContacts; i++) {
                    printf("%d. %s <%s>\n", i + 1, mailingList[i].name, mailingList[i].email);
                }

                printf("\n");
                break;

            case 3: // Send email
                printf("\nSEND EMAIL\n");

                // Make sure there are contacts in the mailing list
                if (numContacts == 0) {
                    printf("Error: No contacts on the mailing list.\n\n");
                    break;
                }

                // Get the email message and loop through all contacts to send the message
                char message[100];
                printf("Enter the email message: ");
                scanf("%s", message);

                for (int i = 0; i < numContacts; i++) {
                    printf("Sent to %s <%s>: %s\n", mailingList[i].name, mailingList[i].email, message);
                }

                printf("Email sent successfully!\n\n");
                break;

            case 4: // Exit the program
                printf("\nThank you for using the C Mailing List Manager!\n");
                return 0;

            default: // Invalid choice
                printf("Error: Invalid choice. Please enter a number between 1 and 4.\n\n");
                break;
        }
    }

    return 0;
}