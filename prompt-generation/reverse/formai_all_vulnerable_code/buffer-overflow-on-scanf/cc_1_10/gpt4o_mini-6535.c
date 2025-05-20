//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 256
#define MAX_SUBJECT_LENGTH 128
#define MAX_MESSAGE_LENGTH 1024

void clear_buffer() {
    while (getchar() != '\n'); // Drain the input buffer to handle leftover inputs
}

void send_email(const char *recipient, const char *subject, const char *message) {
    // Here we simply simulate sending an email by printing the content to the console
    printf("\nSending the following email...\n");
    printf("To: %s\n", recipient);
    printf("Subject: %s\n", subject);
    printf("Message: %s\n", message);
    printf("Email sent successfully! (At least, we hope so...)\n");
}

void get_email_input() {
    char recipient[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    
    printf("--------------------------------------------------\n");
    printf("Welcome to the Curious C Email Client!\n");
    printf("--------------------------------------------------\n");

    // Get recipient email address
    printf("Please enter the recipient's email address: ");
    fgets(recipient, MAX_EMAIL_LENGTH, stdin);
    recipient[strcspn(recipient, "\n")] = 0; // Remove trailing newline
    
    // Get subject
    printf("What's the subject of your email? ");
    fgets(subject, MAX_SUBJECT_LENGTH, stdin);
    subject[strcspn(subject, "\n")] = 0; // Remove trailing newline

    // Get message body
    printf("Now, express yourself! Write your message:\n");
    printf("(When you're done, press Enter to finish)\n");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strcspn(message, "\n")] = 0; // Remove trailing newline

    // Sending the email
    send_email(recipient, subject, message);
}

void menu() {
    int choice;
    do {
        printf("\n--------------------------------------------------\n");
        printf("1. Send an Email\n");
        printf("2. Exit\n");
        printf("--------------------------------------------------\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_buffer(); // Clears the input buffer after reading the integer

        switch (choice) {
            case 1:
                get_email_input();
                break;
            case 2:
                printf("Exiting the Curious C Email Client. Goodbye!\n");
                break;
            default:
                printf("Hmm... That option doesn't exist. Try again!\n");
        }
    } while (choice != 2);
}

int main() {
    menu();
    return 0;
}