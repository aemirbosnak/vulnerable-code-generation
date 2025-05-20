//FormAI DATASET v1.0 Category: Mailing list manager ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_NAME_LENGTH 30
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

int main() {
    Contact mailingList[MAX_EMAILS];
    int numContacts = 0;

    printf("---Mailing List Manager---\n\n");

    while (1) {
        // Display options to user
        printf("1. Add contact\n");
        printf("2. View all contacts\n");
        printf("3. Search for contact\n");
        printf("4. Remove contact\n");
        printf("5. Quit\n");
        
        // Get user input
        printf("\nEnter the number of the action you wish to perform: ");
        int choice;
        scanf("%d", &choice);
        getchar(); // consume the '\n' character left over from scanf

        // Handle user input
        switch (choice) {
            case 1: // Add contact
                printf("\n---Add Contact---\n");
                if (numContacts >= MAX_EMAILS) {
                    printf("Error: Maximum number of contacts reached.\n");
                    break;
                }
                printf("Enter name: ");
                fgets(mailingList[numContacts].name, MAX_NAME_LENGTH, stdin);
                mailingList[numContacts].name[strlen(mailingList[numContacts].name) - 1] = '\0'; // remove the '\n' at the end of the string
                printf("Enter email address: ");
                fgets(mailingList[numContacts].email, MAX_EMAIL_LENGTH, stdin);
                mailingList[numContacts].email[strlen(mailingList[numContacts].email) - 1] = '\0'; // remove the '\n' at the end of the string
                numContacts++;
                printf("Contact added.\n");
                break;

            case 2: // View all contacts
                printf("\n---View Contacts---\n");
                if (numContacts == 0) {
                    printf("No contacts to display.\n");
                    break;
                }
                printf("Name\t\t\tEmail\n");
                printf("------------------------------------\n");
                for (int i = 0; i < numContacts; i++) {
                    printf("%-30s%-50s\n", mailingList[i].name, mailingList[i].email);
                }
                break;

            case 3: // Search for contact
                printf("\n---Search Contacts---\n");
                if (numContacts == 0) {
                    printf("No contacts to search.\n");
                    break;
                }
                printf("Enter name or email address to search: ");
                char searchStr[MAX_EMAIL_LENGTH];
                fgets(searchStr, MAX_EMAIL_LENGTH, stdin);
                searchStr[strlen(searchStr) - 1] = '\0'; // remove the '\n' at the end of the string
                printf("Search results:\n");
                printf("Name\t\t\tEmail\n");
                printf("------------------------------------\n");
                for (int i = 0; i < numContacts; i++) {
                    if (strstr(mailingList[i].name, searchStr) != NULL || strstr(mailingList[i].email, searchStr) != NULL) {
                        printf("%-30s%-50s\n", mailingList[i].name, mailingList[i].email);
                    }
                }
                break;

            case 4: // Remove contact
                printf("\n---Remove Contact---\n");
                if (numContacts == 0) {
                    printf("No contacts to remove.\n");
                    break;
                }
                printf("Enter name or email address of contact to remove: ");
                char removeStr[MAX_EMAIL_LENGTH];
                fgets(removeStr, MAX_EMAIL_LENGTH, stdin);
                removeStr[strlen(removeStr) - 1] = '\0'; // remove the '\n' at the end of the string
                for (int i = 0; i < numContacts; i++) {
                    if (strcmp(mailingList[i].name, removeStr) == 0 || strcmp(mailingList[i].email, removeStr) == 0) {
                        for (int j = i; j < numContacts - 1; j++) {
                            strcpy(mailingList[j].name, mailingList[j + 1].name);
                            strcpy(mailingList[j].email, mailingList[j + 1].email);
                        }
                        strcpy(mailingList[numContacts - 1].name, "");
                        strcpy(mailingList[numContacts - 1].email, "");
                        numContacts--;
                        printf("Contact removed.\n");
                        break;
                    }
                }
                break;

            case 5: // Quit
                printf("\n---Goodbye!---\n");
                exit(0); // exit the program

            default:
                printf("Error: Invalid input. Please enter a valid number.\n");
                break;
        }
        printf("\n");
    }
    return 0;
}