//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

// Function prototypes
void send_email(const char *recipient, const char *subject, const char *body);
void receive_emails();

int main(void) {
    int choice;

    printf("********** Eloquent Email Client **********\n");
    printf("1. Send Email\n");
    printf("2. Receive Emails\n");
    printf("3. Exit\n");
    printf("********************************************\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1: {
                char recipient[100], subject[100], body[BUFFER_SIZE];

                printf("To: ");
                fgets(recipient, sizeof(recipient), stdin);
                strtok(recipient, "\n"); // Remove newline

                printf("Subject: ");
                fgets(subject, sizeof(subject), stdin);
                strtok(subject, "\n");

                printf("Body (End with ^D): \n");
                fgets(body, sizeof(body), stdin);

                send_email(recipient, subject, body);
                break;
            }
            case 2:
                receive_emails();
                break;
            case 3:
                printf("Exiting the Eloquent Email Client. See you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to send an email
void send_email(const char *recipient, const char *subject, const char *body) {
    printf("\n--- Sending Email ---\n");
    printf("To: %s\nSubject: %s\nMessage:\n%s\n", recipient, subject, body);
    
    // Here we would have code to actually send the email via SMTP
    // For this art piece, we'll simulate a successful send
    printf("Email sent successfully to %s!\n", recipient);
}

// Function to receive emails
void receive_emails() {
    printf("\n--- Receiving Emails ---\n");

    // Simulating email reception
    printf("1. Welcome to your inbox!\n");
    printf("   Subject: Hello from C!\n");
    printf("   From: friend@example.com\n");
    printf("   Body: Just wanted to say hi!\n\n");

    printf("2. Project Update\n");
    printf("   Subject: Project Completion\n");
    printf("   From: boss@example.com\n");
    printf("   Body: The project is completed!\n\n");

    // In a real client, you'd interact with a mail server
    printf("You have 2 new emails.\n");
}