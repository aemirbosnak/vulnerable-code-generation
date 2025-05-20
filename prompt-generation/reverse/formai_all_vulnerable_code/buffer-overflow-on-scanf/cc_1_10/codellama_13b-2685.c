//Code Llama-13B DATASET v1.0 Category: Email Client ; Style: protected
/*
 * Email Client Example Program
 *
 * This program demonstrates how to create a simple email client in C.
 * It allows the user to send and receive emails using a command-line interface.
 *
 * Usage:
 *  - To send an email, type "send <recipient> <message>"
 *  - To receive an email, type "receive"
 *  - To quit, type "quit"
 *
 * Note: This is a basic example and does not handle errors or security.
 *
 * Author:
 *  - [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for an email
typedef struct {
    char* recipient;
    char* message;
} email_t;

// Define the structure for the email client
typedef struct {
    email_t* emails;
    int num_emails;
} email_client_t;

// Function to send an email
void send_email(email_client_t* client, email_t* email) {
    // Check if the email is valid
    if (email->recipient == NULL || email->message == NULL) {
        printf("Invalid email\n");
        return;
    }

    // Add the email to the client's list of emails
    client->emails[client->num_emails++] = *email;

    printf("Email sent successfully\n");
}

// Function to receive an email
void receive_email(email_client_t* client, int index) {
    // Check if the index is valid
    if (index < 0 || index >= client->num_emails) {
        printf("Invalid index\n");
        return;
    }

    // Print the email
    printf("From: %s\n", client->emails[index].recipient);
    printf("Message: %s\n", client->emails[index].message);
}

// Main function
int main() {
    // Create a new email client
    email_client_t client = {NULL, 0};

    // Loop until the user quits
    while (1) {
        // Get the user's input
        char command[256];
        printf("> ");
        scanf("%s", command);

        // Check if the command is "send"
        if (strcmp(command, "send") == 0) {
            // Get the recipient and message
            char recipient[256];
            char message[256];
            scanf("%s %s", recipient, message);

            // Create a new email
            email_t email = {recipient, message};

            // Send the email
            send_email(&client, &email);
        }

        // Check if the command is "receive"
        else if (strcmp(command, "receive") == 0) {
            // Get the index of the email to receive
            int index;
            scanf("%d", &index);

            // Receive the email
            receive_email(&client, index);
        }

        // Check if the command is "quit"
        else if (strcmp(command, "quit") == 0) {
            // Quit the program
            break;
        }

        // Print an error message if the command is invalid
        else {
            printf("Invalid command\n");
        }
    }

    // Free the memory allocated for the email client
    free(client.emails);

    return 0;
}