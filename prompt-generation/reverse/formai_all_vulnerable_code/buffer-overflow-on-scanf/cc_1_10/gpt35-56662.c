//FormAI DATASET v1.0 Category: Mailing list manager ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 5
#define MAX_LENGTH 100

// Function prototypes
void show_menu();
void add_email(char emails[MAX_EMAILS][MAX_LENGTH], int *num_emails);
void remove_email(char emails[MAX_EMAILS][MAX_LENGTH], int *num_emails);
void view_emails(char emails[MAX_EMAILS][MAX_LENGTH], int num_emails);

// Main function
int main() {

    char emails[MAX_EMAILS][MAX_LENGTH];
    int num_emails = 0;
    int choice;

    printf("Welcome to the Mailing List Manager!\n");

    do {
        show_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_email(emails, &num_emails);
                break;
            case 2:
                remove_email(emails, &num_emails);
                break;
            case 3:
                view_emails(emails, num_emails);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }

    } while (choice != 4);

    return 0;
}

// Function definitions

// Displays the program's main menu
void show_menu() {
    printf("\nMENU\n");
    printf("1 - Add email address\n");
    printf("2 - Remove email address\n");
    printf("3 - View all email addresses\n");
    printf("4 - Quit\n");
    printf("Enter your choice: ");
}

// Adds an email address to the mailing list
void add_email(char emails[MAX_EMAILS][MAX_LENGTH], int *num_emails) {
    char email[MAX_LENGTH];

    printf("Enter email address: ");
    scanf("%s", email);

    if (*num_emails == MAX_EMAILS) {
        printf("Unable to add email. Mailing list is full.\n");
    } else {
        strcpy(emails[*num_emails], email);
        (*num_emails)++;
        printf("Email added!\n");
    }
}

// Removes an email address from the mailing list
void remove_email(char emails[MAX_EMAILS][MAX_LENGTH], int *num_emails) {
    int i;
    char email[MAX_LENGTH];

    printf("Enter email address to remove: ");
    scanf("%s", email);

    for (i = 0; i < *num_emails; i++) {
        if (strcmp(emails[i], email) == 0) {
            (*num_emails)--;
            strcpy(emails[i], emails[*num_emails]);
            printf("Email removed!\n");
            return;
        }
    }

    printf("Email not found. Unable to remove.\n");
}

// Displays all email addresses in the mailing list
void view_emails(char emails[MAX_EMAILS][MAX_LENGTH], int num_emails) {
    int i;

    printf("Mailing list:\n");

    if (num_emails == 0) {
        printf("No emails found.\n");
    } else {
        for (i = 0; i < num_emails; i++) {
            printf("%s\n", emails[i]);
        }
    }
}