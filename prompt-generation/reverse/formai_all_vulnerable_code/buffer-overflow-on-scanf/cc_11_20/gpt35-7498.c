//FormAI DATASET v1.0 Category: Phone Book ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[50];
    char phone[15];
}contacts[50];

int main() {
    printf("----------------- Welcome to the Surrealist Phone Book -----------------\n\n");

    int numContacts = 0;
    int option = 0;

    do {
        printf("\nPlease choose an option:\n");
        printf("1. Add a new contact\n");
        printf("2. Search for a contact by name\n");
        printf("3. Edit an existing contact\n");
        printf("4. Delete a contact\n");
        printf("5. View all contacts\n");
        printf("6. Exit\n");

        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\n-------- Adding a new contact --------\n");

                printf("Enter the contact's name: ");
                scanf("%s", contacts[numContacts].name);

                printf("Enter the contact's phone number: ");
                scanf("%s", contacts[numContacts].phone);

                numContacts++;

                printf("\nContact added successfully!\n");
                break;

            case 2:
                printf("\n-------- Searching for a contact by name --------\n");

                char searchName[50];
                int found = 0;

                printf("Enter the name you are searching for: ");
                scanf("%s", searchName);

                for (int i = 0; i < numContacts; i++) {
                    if (strcmp(searchName, contacts[i].name) == 0) {
                        printf("\nName: %s\nPhone number: %s\n", contacts[i].name, contacts[i].phone);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("\nNo contact found with that name.\n");
                }
                break;

            case 3:
                printf("\n-------- Editing an existing contact --------\n");

                char editName[50];
                int index;
                int found2 = 0;

                printf("Enter the name of the contact you want to edit: ");
                scanf("%s", editName);

                for (int i = 0; i < numContacts; i++) {
                    if (strcmp(editName, contacts[i].name) == 0) {
                        index = i;
                        found2 = 1;
                        break;
                    }
                }

                if (!found2) {
                    printf("\nNo contact found with that name.\n");
                    break;
                }

                printf("Enter the new name (enter '-' to keep the same): ");
                scanf("%s", contacts[index].name);

                printf("Enter the new phone number (enter '-' to keep the same): ");
                scanf("%s", contacts[index].phone);

                printf("\nContact updated successfully!\n");
                break;

            case 4:
                printf("\n-------- Deleting a contact --------\n");

                char deleteName[50];
                int index2;
                int found3 = 0;

                printf("Enter the name of the contact you want to delete: ");
                scanf("%s", deleteName);

                for (int i = 0; i < numContacts; i++) {
                    if (strcmp(deleteName, contacts[i].name) == 0) {
                        index2 = i;
                        found3 = 1;
                        break;
                    }
                }

                if (!found3) {
                    printf("\nNo contact found with that name.\n");
                    break;
                }

                for (int i = index2; i < numContacts - 1; i++) {
                    strcpy(contacts[i].name, contacts[i + 1].name);
                    strcpy(contacts[i].phone, contacts[i + 1].phone);
                }

                numContacts--;

                printf("\nContact deleted successfully!\n");
                break;

            case 5:
                printf("\n-------- Viewing all contacts --------\n");

                if (numContacts == 0) {
                    printf("\nNo contacts to display.\n");
                    break;
                }

                for (int i = 0; i < numContacts; i++) {
                    printf("Name: %s\nPhone number: %s\n\n", contacts[i].name, contacts[i].phone);
                }

                break;

            case 6:
                printf("\nExiting the Surrealist Phone Book. Thank you for using it!\n");
                break;

            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }

    } while (option != 6);

    return 0;
}