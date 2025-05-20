//FormAI DATASET v1.0 Category: Email Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_SIZE 1024

// Define the structures for the email and email client
typedef struct {
    char sender[MAX_EMAIL_SIZE];
    char recipient[MAX_EMAIL_SIZE];
    char subject[MAX_EMAIL_SIZE];
    char body[MAX_EMAIL_SIZE];
} Email;

typedef struct {
    Email inbox[MAX_EMAIL_SIZE];
    int num_emails;
} EmailClient;

// Function to add an email to the inbox
void add_email(EmailClient* client, Email email) {
    if (client->num_emails == MAX_EMAIL_SIZE) {
        printf("Inbox is full!\n");
        return;
    }
    
    client->inbox[client->num_emails++] = email;
}

int main() {
    EmailClient client;
    client.num_emails = 0;
    
    // Initialize variables for user input
    char sender[MAX_EMAIL_SIZE], recipient[MAX_EMAIL_SIZE], subject[MAX_EMAIL_SIZE], body[MAX_EMAIL_SIZE];
    char option;

    // Loop to handle user input
    while (1) {
        printf("Enter 'c' to compose a new email or 'v' to view your inbox: ");
        scanf(" %c", &option);
        
        if (option == 'c') {
            printf("Enter sender: ");
            scanf(" %[^\n]", sender);
            printf("Enter recipient: ");
            scanf(" %[^\n]", recipient);
            printf("Enter subject: ");
            scanf(" %[^\n]", subject);
            printf("Enter body: ");
            scanf(" %[^\n]", body);
            
            // Create a new email and add it to the inbox
            Email email;
            strcpy(email.sender, sender);
            strcpy(email.recipient, recipient);
            strcpy(email.subject, subject);
            strcpy(email.body, body);
            add_email(&client, email);
            
            printf("Email sent!\n");
        } else if (option == 'v') {
            // Loop through the inbox and print out each email
            for (int i = 0; i < client.num_emails; i++) {
                printf("Email %d\n", i+1);
                printf("Sender: %s\n", client.inbox[i].sender);
                printf("Recipient: %s\n", client.inbox[i].recipient);
                printf("Subject: %s\n", client.inbox[i].subject);
                printf("Body: %s\n\n", client.inbox[i].body);
            }
        } else {
            printf("Invalid option!\n");
        }
    }
    
    return 0;
}