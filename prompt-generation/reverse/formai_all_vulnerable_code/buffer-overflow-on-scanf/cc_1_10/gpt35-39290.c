//FormAI DATASET v1.0 Category: Mailing list manager ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the email list
#define MAX_EMAILS 100

// Define the maximum length of an email address
#define EMAIL_LENGTH 50

// Define the email struct
typedef struct {
    char email[EMAIL_LENGTH];
} Email;

// Function to print the current list of emails
void print_emails(Email* emails, int num_emails) {
    for(int i = 0; i < num_emails; i++) {
        printf("%d. %s\n", i+1, (emails+i)->email);
    }
}

int main() {
    Email emails[MAX_EMAILS]; // Create an array of emails
    int num_emails = 0; // Initialize the number of emails to 0

    printf("Welcome to the mailing list manager!\n");

    while(1) { // Loop indefinitely
        printf("\nWhat would you like to do?\n");
        printf("1. Add an email to the list\n");
        printf("2. Remove an email from the list\n");
        printf("3. View the current list of emails\n");
        printf("4. Exit\n");
        printf("Your choice: ");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Add an email
                if(num_emails == MAX_EMAILS) { // Check if the list is already full
                    printf("The mailing list is full. Cannot add more emails.\n");
                } else {
                    char new_email[EMAIL_LENGTH];
                    printf("Enter the new email: ");
                    scanf("%s", new_email);
                    strcpy((emails+num_emails)->email, new_email);
                    num_emails++;

                    printf("Email has been added to the list.\n");
                }
                break;

            case 2: // Remove an email
                if(num_emails == 0) { // Check if the list is already empty
                    printf("The mailing list is empty. Cannot remove any emails.\n");
                } else {
                    int index;
                    printf("Enter the index of the email to be removed: ");
                    scanf("%d", &index);

                    if(index < 1 || index > num_emails) { // Check if the index is within range
                        printf("Invalid index. Please try again.\n");
                    } else {
                        for(int i = index-1; i < num_emails-1; i++) { // Shift the emails to fill the gap
                            strcpy((emails+i)->email, (emails+i+1)->email);
                        }
                        num_emails--;

                        printf("Email has been removed from the list.\n");
                    }
                }
                break;

            case 3: // View the current list of emails
                if(num_emails == 0) { // Check if the list is empty
                    printf("The mailing list is empty.\n");
                } else {
                    printf("Current list of emails:\n");
                    print_emails(emails, num_emails);
                }
                break;

            case 4: // Exit
                printf("Thank you for using the mailing list manager!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}