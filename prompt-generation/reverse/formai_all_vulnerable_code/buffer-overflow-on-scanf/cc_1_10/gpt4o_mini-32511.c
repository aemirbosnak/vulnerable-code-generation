//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_LENGTH 256
#define SUBJECT_LENGTH 100

typedef struct {
    char sender[MAX_LENGTH];
    char receiver[MAX_LENGTH];
    char subject[SUBJECT_LENGTH];
    char body[MAX_LENGTH];
} Email;

Email inbox[MAX_EMAILS];
int email_count = 0;

// Displays a magical menu
void display_menu() {
    printf("\nWelcome to the Owl Post Email Client!\n");
    printf("1. Send an Email\n");
    printf("2. View Inbox\n");
    printf("3. Exit\n");
    printf("Choose an option (1-3): ");
}

// Sends an email
void send_email() {
    if (email_count >= MAX_EMAILS) {
        printf("The Owl Post is currently full. Please wait before sending more owls!\n");
        return;
    }
    
    Email new_email;
    printf("Enter sender's name: ");
    scanf("%s", new_email.sender);
    printf("Enter receiver's name: ");
    scanf("%s", new_email.receiver);
    
    printf("Enter subject: ");
    scanf(" %[^\n]%*c", new_email.subject);
    
    printf("Enter body of the email: ");
    scanf(" %[^\n]%*c", new_email.body);

    inbox[email_count++] = new_email;
    printf("Your email has been sent by an owl!\n");
}

// Views the inbox
void view_inbox() {
    if (email_count == 0) {
        printf("Your inbox is empty! No owls have delivered mail yet.\n");
        return;
    }

    printf("\n--- Owl Post Inbox ---\n");
    for (int i = 0; i < email_count; i++) {
        printf("From: %s\n", inbox[i].sender);
        printf("To: %s\n", inbox[i].receiver);
        printf("Subject: %s\n", inbox[i].subject);
        printf("Body: %s\n", inbox[i].body);
        printf("---------------------\n");
    }
}

// Main function
int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                send_email();
                break;
            case 2:
                view_inbox();
                break;
            case 3:
                printf("Thank you for using the Owl Post Email Client. Safe travels!\n");
                exit(0);
            default:
                printf("Please select a valid option.\n");
                break;
        }
    }

    return 0;
}