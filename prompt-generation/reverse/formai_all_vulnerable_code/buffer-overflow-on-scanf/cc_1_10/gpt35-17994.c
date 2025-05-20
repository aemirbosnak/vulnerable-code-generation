//FormAI DATASET v1.0 Category: Mailing list manager ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 50

// Struct to hold email addresses and corresponding names
struct email_entry {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

// Function to print the menu and read in menu selection
int get_menu_choice() {
    int choice;
    printf("\nMAILING LIST MANAGER\n");
    printf("1. Add email address\n");
    printf("2. Remove email address\n");
    printf("3. Print all email addresses\n");
    printf("4. Search for email address\n");
    printf("5. Quit\n");
    printf("Enter choice (1-5): ");
    scanf("%d", &choice);
    return choice;
}

// Function to add email address
void add_email(struct email_entry *emails, int *num_emails) {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    printf("\nEnter name: ");
    scanf("%s", name);
    printf("Enter email address: ");
    scanf("%s", email);
    strcpy(emails[*num_emails].name, name);
    strcpy(emails[*num_emails].email, email);
    (*num_emails)++;
    printf("Email address added.\n");
}

// Function to remove email address
void remove_email(struct email_entry *emails, int *num_emails) {
    char email[MAX_EMAIL_LENGTH];
    printf("\nEnter email address to remove: ");
    scanf("%s", email);
    int index = -1;
    for (int i = 0; i < *num_emails; i++) {
        if (strcmp(emails[i].email, email) == 0) {
            index = i;
        }
    }
    if (index < 0) {
        printf("Email address not found.\n");
    } else {
        for (int i = index; i < *num_emails-1; i++) {
            strcpy(emails[i].name, emails[i+1].name);
            strcpy(emails[i].email, emails[i+1].email);
        }
        (*num_emails)--;
        printf("Email address removed.\n");
    }
}

// Function to print all email addresses
void print_emails(struct email_entry *emails, int num_emails) {
    if (num_emails == 0) {
        printf("\nNo email addresses in list.\n");
    } else {
        printf("\nEMAIL ADDRESSES:\n");
        for (int i = 0; i < num_emails; i++) {
            printf("%s: %s\n", emails[i].name, emails[i].email);
        }
    }
}

// Function to search for email address
void search_email(struct email_entry *emails, int num_emails) {
    char email[MAX_EMAIL_LENGTH];
    printf("\nEnter email address to search for: ");
    scanf("%s", email);
    int index = -1;
    for (int i = 0; i < num_emails; i++) {
        if (strcmp(emails[i].email, email) == 0) {
            index = i;
        }
    }
    if (index < 0) {
        printf("Email address not found.\n");
    } else {
        printf("Email address found: %s\n", emails[index].name);
    }
}

int main() {
    struct email_entry emails[MAX_EMAILS];
    int num_emails = 0;

    int choice = get_menu_choice();

    while (choice != 5) {
        switch (choice) {
            case 1:
                add_email(emails, &num_emails); break;
            case 2:
                remove_email(emails, &num_emails); break;
            case 3:
                print_emails(emails, num_emails); break;
            case 4:
                search_email(emails, num_emails); break;
            default:
                printf("\nInvalid choice.\n");
        }
        choice = get_menu_choice();
    }

    return 0;
}