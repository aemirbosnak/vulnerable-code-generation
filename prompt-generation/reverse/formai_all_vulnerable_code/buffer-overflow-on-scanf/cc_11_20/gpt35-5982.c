//FormAI DATASET v1.0 Category: Phone Book ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone[15];
    char email[50];
} contact;

int main() {
    int option = 0;
    int numContacts = 0;
    contact* myContacts = NULL;

    while (option != 4) {
        printf("Welcome to your C Phone Book!\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Display all contacts\n");
        printf("4. Quit\n");
        printf("Please enter your option: ");
        scanf("%d", &option);

        if (option == 1) {
            numContacts++;
            contact* temp = realloc(myContacts, numContacts * sizeof(contact));
            if (temp == NULL) {
                printf("Error: Unable to allocate memory.\n");
                return 1;
            }
            myContacts = temp;

            printf("Enter the name of the contact: ");
            scanf("%s", myContacts[numContacts - 1].name);

            printf("Enter the phone number of the contact (format: xxx-xxx-xxxx): ");
            scanf("%s", myContacts[numContacts - 1].phone);

            printf("Enter the email address of the contact: ");
            scanf("%s", myContacts[numContacts - 1].email);

            printf("Contact added successfully!\n");
        }
        else if (option == 2) {
            char searchTerm[50];
            printf("Enter the name of the contact to search for: ");
            scanf("%s", searchTerm);

            int found = 0;
            for (int i = 0; i < numContacts; i++) {
                if (strcmp(myContacts[i].name, searchTerm) == 0) {
                    printf("Name: %s\n", myContacts[i].name);
                    printf("Phone: %s\n", myContacts[i].phone);
                    printf("Email: %s\n", myContacts[i].email);
                    found = 1;
                }
            }

            if (!found) {
                printf("No contacts found.\n");
            }
        }
        else if (option == 3) {
            for (int i = 0; i < numContacts; i++) {
                printf("Name: %s\n", myContacts[i].name);
                printf("Phone: %s\n", myContacts[i].phone);
                printf("Email: %s\n", myContacts[i].email);
                printf("\n");
            }
        }
        else if (option == 4) {
            printf("Goodbye!\n");
        }
        else {
            printf("Invalid option.\n");
        }
    }

    free(myContacts);
    return 0;
}