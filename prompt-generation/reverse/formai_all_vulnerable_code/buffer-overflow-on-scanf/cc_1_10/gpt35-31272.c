//FormAI DATASET v1.0 Category: Mailing list manager ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of email addresses
#define MAX_EMAILS 100

// Maximum length of email address
#define MAX_EMAIL_LENGTH 50

// Function to add email to the list
void add_email(char email_list[MAX_EMAILS][MAX_EMAIL_LENGTH], int *email_count) {
    // Check if email list is full
    if (*email_count >= MAX_EMAILS) {
        printf("Email list is full, cannot add more emails.\n");
        return;
    }
    // Get email address from user
    char email[MAX_EMAIL_LENGTH];
    printf("Enter email address: ");
    scanf("%s", email);
    // Check if email already exists in list
    for (int i=0; i<*email_count; i++) {
        if (strcmp(email, email_list[i]) == 0) {
            printf("Email already exists in the list.\n");
            return;
        }
    }
    // Add email to list
    strcpy(email_list[*email_count], email);
    (*email_count)++;
    printf("Email added to list.\n");
}

// Function to remove email from the list
void remove_email(char email_list[MAX_EMAILS][MAX_EMAIL_LENGTH], int *email_count) {
    // Get email address from user
    char email[MAX_EMAIL_LENGTH];
    printf("Enter email address to remove: ");
    scanf("%s", email);
    // Find index of email in list
    int index = -1;
    for (int i=0; i<*email_count; i++) {
        if (strcmp(email, email_list[i]) == 0) {
            index = i;
            break;
        }
    }
    // Check if email exists in list
    if (index == -1) {
        printf("Email does not exist in the list.\n");
        return;
    }
    // Remove email from list by shifting all emails to left
    for (int i=index; i<*email_count-1; i++) {
        strcpy(email_list[i], email_list[i+1]);
    }
    (*email_count)--;
    printf("Email removed from list.\n");
}

// Function to display all emails in the list
void display_emails(char email_list[MAX_EMAILS][MAX_EMAIL_LENGTH], int email_count) {
    printf("Current email list:\n");
    for (int i=0; i<email_count; i++) {
        printf("%d. %s\n", i+1, email_list[i]);
    }
}

// Main function
int main() {
    // Initialize email list
    char email_list[MAX_EMAILS][MAX_EMAIL_LENGTH];
    int email_count = 0;
    // Show menu and get user input
    int choice;
    do {
       printf("Email List Manager\n");
       printf("==================\n");
       printf("1. Add email to list\n");
       printf("2. Remove email from list\n");
       printf("3. Display all emails in the list\n");
       printf("4. Exit\n");
       printf("Enter your choice: ");
       scanf("%d", &choice);
       switch (choice) {
           case 1:
               add_email(email_list, &email_count);
               break;
           case 2:
               remove_email(email_list, &email_count);
               break;
           case 3:
               display_emails(email_list, email_count);
               break;
           case 4:
               printf("Exiting...\n");
               break;
           default:
               printf("Invalid choice, please enter a number between 1 and 4.\n");
               break;
       }
    } while (choice != 4);
    return 0;
}