//FormAI DATASET v1.0 Category: Mailing list manager ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_EMAILS 100 // Maximum number of emails that can be stored in the list
#define MAX_LENGTH 50 // Maximum length of email address 

char* emails[MAX_EMAILS]; // Single pointer array to store the email addresses

int count = 0; // Counter variable to keep track of number of emails in the list

// Function to add email addresses to the list
void add_email(char* email) {
    if(count >= MAX_EMAILS) {
        printf("Unable to add email. Maximum limit of %d emails reached.\n", MAX_EMAILS);
        return;
    }

    // Check if email already exists in the list
    for(int i = 0; i < count; i++) {
        if(strcmp(email, emails[i]) == 0) {
            printf("Email address already exists in the list.\n");
            return;
        }
    }

    // Allocate memory for the email address and store in the list
    emails[count] = (char*)malloc(sizeof(char) * MAX_LENGTH);
    strcpy(emails[count], email);
    count++;
    printf("%s added to the list.\n", email);
}

// Function to remove email addresses from the list
void remove_email(char* email) {
    int index = -1;

    // Find the index of the email address
    for(int i = 0; i < count; i++) {
        if(strcmp(email, emails[i]) == 0) {
            index = i;
            break;
        }
    }

    // If email address is not found in the list
    if(index == -1) {
        printf("Email address not found in the list.\n");
        return;
    }

    // Free the memory used for the email address
    free(emails[index]);

    // Shift the remaining email addresses in the list
    for(int i = index; i < count - 1; i++) {
        emails[i] = emails[i + 1];
    }

    count--;
    printf("%s removed from the list.\n", email);
}

// Function to print all the email addresses in the list
void print_emails() {
    printf("Current list of email addresses:\n");

    for(int i = 0; i < count; i++) {
        printf("%d: %s\n", i + 1, emails[i]);
    }
}

int main() {
    printf("Welcome to the Mailing List Manager\n\n");

    while(1) {
        printf("Enter a command (add, remove, print, quit): ");
        char command[10];
        scanf("%s", command);

        if(strcmp(command, "add") == 0) {
            printf("Enter email address: ");
            char email[MAX_LENGTH];
            scanf("%s", email);
            add_email(email);
        } else if(strcmp(command, "remove") == 0) {
            printf("Enter email address: ");
            char email[MAX_LENGTH];
            scanf("%s", email);
            remove_email(email);
        } else if(strcmp(command, "print") == 0) {
            print_emails();
        } else if(strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    printf("\nThank you for using the Mailing List Manager.\n");

    // Free memory used for the email addresses
    for(int i = 0; i < count; i++) {
        free(emails[i]);
    }

    return 0;
}