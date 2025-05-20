//FormAI DATASET v1.0 Category: Mailing list manager ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define max size of email list and max length of emails
#define MAX_LIST_SIZE 100
#define MAX_EMAIL_LENGTH 50

// Struct for email list
typedef struct {
    char emails[MAX_LIST_SIZE][MAX_EMAIL_LENGTH];
    int list_size;
} EmailList;


// Function to display menu of options for user
void display_menu() {
    printf("\n-- Mailing List Manager --\n");
    printf("1. Add email to list\n");
    printf("2. Remove email from list\n");
    printf("3. View email list\n");
    printf("4. Clear email list\n");
    printf("5. Exit program\n");
    printf("Enter your choice (1-5): ");
}

// Function to add email to list
void add_email(EmailList* list) {
    // Check if list is full
    if (list->list_size >= MAX_LIST_SIZE) {
        printf("Sorry, the email list is full.\n");
        return;
    }

    // Prompt user for email
    char new_email[MAX_EMAIL_LENGTH];
    printf("Enter email to add: ");
    scanf("%s", new_email);

    // Check if email already exists in list
    for (int i=0; i<list->list_size; i++) {
        if (strcmp(list->emails[i], new_email) == 0) {
            printf("Email already exists in list.\n");
            return;
        }
    }

    // Add email to list
    strcpy(list->emails[list->list_size], new_email);
    list->list_size++;
    printf("Email added successfully.\n");
}

// Function to remove email from list
void remove_email(EmailList* list) {
    // Prompt user for email
    char email_to_remove[MAX_EMAIL_LENGTH];
    printf("Enter email to remove: ");
    scanf("%s", email_to_remove);

    // Search for email in list
    int index = -1;
    for (int i=0; i<list->list_size; i++) {
        if (strcmp(list->emails[i], email_to_remove) == 0) {
            index = i;
            break;
        }
    }

    // If email not found, display error message
    if (index == -1) {
        printf("Email not found in list.\n");
        return;
    }

    // Shift emails in list to remove email
    for (int i=index; i<list->list_size-1; i++) {
        strcpy(list->emails[i], list->emails[i+1]);
    }

    // Decrement list size
    list->list_size--;
    printf("Email removed successfully.\n");
}

// Function to display email list
void view_list(EmailList* list) {
    printf("\n-- Email List --\n");
    for (int i=0; i<list->list_size; i++) {
        printf("%d. %s\n", i+1, list->emails[i]);
    }
}

// Function to clear email list
void clear_list(EmailList* list) {
    list->list_size = 0;
    printf("Email list cleared successfully.\n");
}

int main() {
    // Initialize email list
    EmailList list;
    list.list_size = 0;

    // Display menu and prompt user for choice
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_email(&list);
                break;
            case 2:
                remove_email(&list);
                break;
            case 3:
                view_list(&list);
                break;
            case 4:
                clear_list(&list);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number from 1-5.\n");
                break;
        }

    } while (choice != 5);

    return 0;
}