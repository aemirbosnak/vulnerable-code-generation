//FormAI DATASET v1.0 Category: Phone Book ; Style: medieval
#include <stdio.h>
#include <string.h>

/* Define a structure for contact details */
struct contact {
    char name[50];
    char phone_number[20];
    char email[50];
};

int main() {
    /* Declare an array to hold up to 100 contacts */
    struct contact contacts[100];

    /* Initialize the number of contacts to 0 */
    int num_contacts = 0;

    /* Display the program greeting */
    printf("Welcome to the Medieval Phone Book Program!\n\n");

    /* Loop until the user chooses to exit */
    while (1) {
        /* Display the menu */
        printf("Please choose an option:\n");
        printf("1. Add a contact\n");
        printf("2. Display all contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Exit\n\n");

        /* Get the user's choice */
        printf("Your choice: ");
        int choice;
        scanf("%d", &choice);

        /* Handle the user's choice */
        switch (choice) {
            case 1: /* Add a contact */
                printf("\nPlease enter the contact's name: ");
                scanf("%s", contacts[num_contacts].name);

                printf("Please enter the contact's phone number: ");
                scanf("%s", contacts[num_contacts].phone_number);

                printf("Please enter the contact's email address: ");
                scanf("%s", contacts[num_contacts].email);

                printf("\n%s has been added to the phone book.\n\n", contacts[num_contacts].name);

                /* Increment the number of contacts */
                num_contacts++;

                break;

            case 2: /* Display all contacts */
                if (num_contacts == 0) {
                    printf("\nThe phone book is currently empty.\n\n");
                } else {
                    printf("\nPHONE BOOK\n");
                    printf("==========\n");

                    for (int i = 0; i < num_contacts; i++) {
                        printf("%s\t%s\t%s\n", contacts[i].name, contacts[i].phone_number, contacts[i].email);
                    }

                    printf("\n");
                }

                break;

            case 3: /* Search for a contact */
                printf("\nPlease enter the name of the contact you are searching for: ");
                char search_name[50];
                scanf("%s", search_name);

                /* Loop through all contacts to find a match */
                int found = 0;
                for (int i = 0; i < num_contacts; i++) {
                    if (strcmp(search_name, contacts[i].name) == 0) {
                        printf("\n%s\t%s\t%s\n\n", contacts[i].name, contacts[i].phone_number, contacts[i].email);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("\n%s was not found in the phone book.\n\n", search_name);
                }

                break;

            case 4: /* Exit */
                printf("\nThank you for using the Medieval Phone Book Program!\n\n");
                return 0;

            default: /* Invalid choice */
                printf("\nInvalid choice. Please choose a number from the menu.\n\n");
                break;
        }
    }
}