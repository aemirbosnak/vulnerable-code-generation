//FormAI DATASET v1.0 Category: Mailing list manager ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_PHONE_LEN 20
#define MAX_CONTACTS 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char phone[MAX_PHONE_LEN];
} Contact;

int main() {
    Contact mailingList[MAX_CONTACTS];
    int numContacts = 0;

    // Main menu
    while (1) {
        printf("\nMailing List Manager\n");
        printf("--------------------\n");
        printf("1. Add Contact\n");
        printf("2. Remove Contact\n");
        printf("3. Edit Contact\n");
        printf("4. View Contacts\n");
        printf("5. Exit\n");
        printf("Enter choice (1-5): ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add Contact
                printf("Name: ");
                fgets(mailingList[numContacts].name, MAX_NAME_LEN, stdin); // Consume the newline from previous input
                fgets(mailingList[numContacts].name, MAX_NAME_LEN, stdin);
                strtok(mailingList[numContacts].name, "\n"); // Remove the newline character from name

                printf("Email: ");
                fgets(mailingList[numContacts].email, MAX_EMAIL_LEN, stdin);
                strtok(mailingList[numContacts].email, "\n"); // Remove the newline character from email

                printf("Phone: ");
                fgets(mailingList[numContacts].phone, MAX_PHONE_LEN, stdin);
                strtok(mailingList[numContacts].phone, "\n"); // Remove the newline character from phone

                numContacts++;

                printf("Contact added successfully!\n");
                break;

            case 2: // Remove Contact
                if (numContacts == 0) {
                    printf("No contacts to remove.\n");
                } else {
                    printf("Enter name of contact to remove: ");
                    char nameToRemove[MAX_NAME_LEN];
                    fgets(nameToRemove, MAX_NAME_LEN, stdin); // Consume the newline from previous input
                    fgets(nameToRemove, MAX_NAME_LEN, stdin);
                    strtok(nameToRemove, "\n"); // Remove the newline character from name

                    // Find the index of the contact with the specified name
                    int indexToRemove = -1;
                    for (int i = 0; i < numContacts; i++) {
                        if (strcmp(mailingList[i].name, nameToRemove) == 0) {
                            indexToRemove = i;
                            break;
                        }
                    }

                    if (indexToRemove == -1) {
                        printf("Contact not found.\n");
                    } else {
                        // Remove the contact by shifting all the contacts after it to the left by one
                        for (int i = indexToRemove; i < numContacts - 1; i++) {
                            mailingList[i] = mailingList[i + 1];
                        }

                        numContacts--;

                        printf("Contact removed successfully!\n");
                    }
                }
                break;

            case 3: // Edit Contact
                if (numContacts == 0) {
                    printf("No contacts to edit.\n");
                } else {
                    printf("Enter name of contact to edit: ");
                    char nameToEdit[MAX_NAME_LEN];
                    fgets(nameToEdit, MAX_NAME_LEN, stdin); // Consume the newline from previous input
                    fgets(nameToEdit, MAX_NAME_LEN, stdin);
                    strtok(nameToEdit, "\n"); // Remove the newline character from name

                    // Find the index of the contact with the specified name
                    int indexToEdit = -1;
                    for (int i = 0; i < numContacts; i++) {
                        if (strcmp(mailingList[i].name, nameToEdit) == 0) {
                            indexToEdit = i;
                            break;
                        }
                    }

                    if (indexToEdit == -1) {
                        printf("Contact not found.\n");
                    } else {
                        // Prompt the user for the new values and update the contact struct
                        printf("New name (press enter to keep current name): ");
                        char newName[MAX_NAME_LEN];
                        fgets(newName, MAX_NAME_LEN, stdin);
                        strtok(newName, "\n"); // Remove the newline character from name

                        printf("New email (press enter to keep current email): ");
                        char newEmail[MAX_EMAIL_LEN];
                        fgets(newEmail, MAX_EMAIL_LEN, stdin);
                        strtok(newEmail, "\n"); // Remove the newline character from email

                        printf("New phone (press enter to keep current phone): ");
                        char newPhone[MAX_PHONE_LEN];
                        fgets(newPhone, MAX_PHONE_LEN, stdin);
                        strtok(newPhone, "\n"); // Remove the newline character from phone

                        if (strlen(newName) > 0) {
                            strcpy(mailingList[indexToEdit].name, newName);
                        }

                        if (strlen(newEmail) > 0) {
                            strcpy(mailingList[indexToEdit].email, newEmail);
                        }

                        if (strlen(newPhone) > 0) {
                            strcpy(mailingList[indexToEdit].phone, newPhone);
                        }

                        printf("Contact edited successfully!\n");
                    }
                }
                break;

            case 4: // View Contacts
                if (numContacts == 0) {
                    printf("No contacts to view.\n");
                } else {
                    printf("%-20s %-30s %-15s\n", "Name", "Email", "Phone");
                    printf("-------------------- ------------------------------ ---------------\n");
                    for (int i = 0; i < numContacts; i++) {
                        printf("%-20s %-30s %-15s\n", mailingList[i].name, mailingList[i].email, mailingList[i].phone);
                    }
                }
                break;

            case 5: // Exit
                printf("Exiting...\n");
                exit(0);

            default: // Invalid choice
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}