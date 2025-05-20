//FormAI DATASET v1.0 Category: Phone Book ; Style: energetic
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[30];
    char phone[15];
    char email[30];
};

int main() {
    printf("Welcome to the Unique C Phone Book!\n");

    struct Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;

    char choice;

    do {
        printf("\nSelect an option:\n");
        printf("1. Add a Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Search Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf(" %c", &choice); // space before %c to clear input buffer

        switch (choice) {
            case '1':
                if (num_contacts == MAX_CONTACTS) {
                    printf("Error: Phone Book is full\n");
                } else {
                    struct Contact newContact;

                    printf("\nEnter the following details:\n");
                    printf("Name: ");
                    scanf("%s", newContact.name);
                    printf("Phone number: ");
                    scanf("%s", newContact.phone); // assuming phone number is a string of digits
                    printf("Email: ");
                    scanf("%s", newContact.email);

                    contacts[num_contacts] = newContact;
                    num_contacts++;

                    printf("\nContact added successfully!\n");
                }
                break;

            case '2':
                if (num_contacts == 0) {
                    printf("\nNo contacts to display.\n");
                } else {
                    printf("\nAll Contacts:\n\n");
                    for (int i = 0; i < num_contacts; i++) {
                        printf("Name: %s\n", contacts[i].name);
                        printf("Phone: %s\n", contacts[i].phone);
                        printf("Email: %s\n", contacts[i].email);
                        printf("\n");
                    }
                }
                break;

            case '3':
                if (num_contacts == 0) {
                    printf("\nNo contacts to search.\n");
                    break;
                }
                char searchName[30];
                printf("\nEnter name to search: ");
                scanf("%s", searchName);

                int found = 0;
                for (int i = 0; i < num_contacts; i++) {
                    if (strcmp(searchName, contacts[i].name) == 0) {
                        printf("\nContact found:\n");
                        printf("Name: %s\n", contacts[i].name);
                        printf("Phone: %s\n", contacts[i].phone);
                        printf("Email: %s\n", contacts[i].email);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("\nNo contact found with name '%s'\n", searchName);
                }
                break;

            case '4':
                printf("\nThanks for using Unique C Phone Book!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != '4');


    return 0;
}