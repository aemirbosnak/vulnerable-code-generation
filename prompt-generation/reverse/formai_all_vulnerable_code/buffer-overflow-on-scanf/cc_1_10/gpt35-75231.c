//FormAI DATASET v1.0 Category: Mailing list manager ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1000

// Define struct to hold email addresses
struct Email {
    char name[50];
    char email[50];
};

// Declare function to add email addresses to mailing list
void add_email(struct Email*, int*);

int main() {

    // Declare array to hold email addresses
    struct Email mailing_list[MAX_SIZE];

    // Declare variable to keep track of number of email addresses in mailing list
    int num_emails = 0;

    // Welcome user to Mailing List Manager Program
    printf("Welcome to the Mailing List Manager Program!\n");

    // Run program until user chooses to exit
    while (1) {

        // Display menu options to user
        printf("\nEnter a number:\n");
        printf("1. Add an email address\n");
        printf("2. List email addresses\n");
        printf("3. Exit\n");

        // Declare variable to hold user's menu selection
        int menu_choice;
        scanf("%d", &menu_choice);

        // Check user's menu selection and perform appropriate action
        switch (menu_choice) {

            case 1:
                // Call add_email function to add email to mailing list
                add_email(mailing_list, &num_emails);
                break;

            case 2:
                // List all current email addresses in mailing list
                printf("\nMailing List:\n");
                for (int i = 0; i < num_emails; i++) {
                    printf("%s: %s\n", mailing_list[i].name, mailing_list[i].email);
                }
                break;

            case 3:
                // Exit program
                printf("\nThank you for using the Mailing List Manager Program!\n");
                exit(0);

            default:
                // Display error message and ask user to try again if invalid menu option selected
                printf("\nThat is not a valid menu option. Please try again.\n");
                break;
        }
    }

    return 0;
}

// Define function to add email addresses to mailing list
void add_email(struct Email* mailing_list, int* num_emails) {
    // Declare variables to hold user's name and email address
    char name[50];
    char email[50];

    // Prompt user for name and email address
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter email: ");
    scanf("%s", email);

    // Create new Email struct to hold name and email
    struct Email new_email;
    strcpy(new_email.name, name);
    strcpy(new_email.email, email);

    // Add new Email struct to mailing list array
    mailing_list[*num_emails] = new_email;
    (*num_emails)++;

    // Display success message to user
    printf("\nEmail address added to mailing list!\n");
}