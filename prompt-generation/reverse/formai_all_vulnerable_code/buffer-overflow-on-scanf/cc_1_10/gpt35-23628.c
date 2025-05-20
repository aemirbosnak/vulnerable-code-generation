//FormAI DATASET v1.0 Category: Mailing list manager ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000

// Function prototypes
void add_email(char email[]);
void remove_email(char email[]);
void print_list();
int check_duplicate(char email[]);

// Global variables
char email_list[MAX_EMAILS][50];
int num_emails = 0;

int main() {
    char command[10], email[50];

    printf("Welcome to the mailing list manager. Type 'help' for a list of commands.\n");

    while (1) {
        printf("\n> ");

        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%s", email);
            add_email(email);
        } 
        else if (strcmp(command, "remove") == 0) {
            scanf("%s", email);
            remove_email(email);
        } 
        else if (strcmp(command, "list") == 0) {
            print_list();
        } 
        else if (strcmp(command, "help") == 0) {
            printf("Available commands: add, remove, list, help\n");
        } 
        else if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        } 
        else {
            printf("Invalid command. Type 'help' for a list of commands.\n");
        }
    }

    return 0;
}

// Function to add an email to the list
void add_email(char email[]) {
    // Check for duplicate
    if (check_duplicate(email)) {
        printf("Error: email already exists in list.\n");
        return;
    }

    // Check for maximum list size
    if (num_emails >= MAX_EMAILS) {
        printf("Error: maximum list size reached.\n");
        return;
    }

    strcpy(email_list[num_emails], email);
    num_emails++;

    printf("Email added to list.\n");
}

// Function to remove an email from the list
void remove_email(char email[]) {
    int i, j;

    // Find the email in the list
    for (i = 0; i < num_emails; i++) {
        if (strcmp(email_list[i], email) == 0) {
            // Shift all elements after the found email back by one position
            for (j = i; j < num_emails - 1; j++) {
                strcpy(email_list[j], email_list[j+1]);
            }

            num_emails--;
            printf("Email removed from list.\n");
            return;
        }
    }

    printf("Error: email not found in list.\n");
}

// Function to print the list of emails
void print_list() {
    int i;

    if (num_emails == 0) {
        printf("List is empty.\n");
        return;
    }

    printf("LIST OF EMAILS:\n");

    for (i = 0; i < num_emails; i++) {
        printf("%d. %s\n", i+1, email_list[i]);
    }
}

// Function to check if an email is already in the list
int check_duplicate(char email[]) {
    int i;

    for (i = 0; i < num_emails; i++) {
        if (strcmp(email_list[i], email) == 0) {
            return 1;
        }
    }

    return 0;
}