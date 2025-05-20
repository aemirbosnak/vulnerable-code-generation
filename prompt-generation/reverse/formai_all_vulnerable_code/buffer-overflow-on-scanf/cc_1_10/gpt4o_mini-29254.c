//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_menu();
void compose_email();
void send_email(const char *recipient, const char *subject, const char *body);
void clear_buffer();

int main() {
    printf("🎉 Welcome to the Happy Email Client! 🎉\n");
    
    int choice;
    while (1) {
        display_menu();

        printf("Please enter your choice: ");
        scanf("%d", &choice);
        clear_buffer();

        switch (choice) {
            case 1:
                compose_email();
                break;
            case 2:
                printf("You chose to exit. Have a wonderful day! 😊\n");
                exit(0);
            default:
                printf("Oops! That's not a valid option! Please try again. 😄\n");
        }
    }
    return 0;
}

void display_menu() {
    printf("\n--- Happy Email Client Menu ---\n");
    printf("1. Compose a new email 📧\n");
    printf("2. Exit the program ❌\n");
    printf("-------------------------------\n");
}

void compose_email() {
    char recipient[100];
    char subject[100];
    char body[500];

    printf("✍️  Let's compose an email!\n");

    printf("Enter the recipient's email address: ");
    fgets(recipient, sizeof(recipient), stdin);
    recipient[strcspn(recipient, "\n")] = 0; // Remove newline character

    printf("Enter the subject: ");
    fgets(subject, sizeof(subject), stdin);
    subject[strcspn(subject, "\n")] = 0; // Remove newline character

    printf("Enter the body of the email (end with a blank line):\n");
    char temp[500];
    body[0] = '\0';  // Initialize body

    while (1) {
        fgets(temp, sizeof(temp), stdin);
        if (strcmp(temp, "\n") == 0) {
            break; // Exit on blank line
        }
        strncat(body, temp, sizeof(body) - strlen(body) - 1);
    }

    printf("Sending your email...\n");
    send_email(recipient, subject, body);
}

void send_email(const char *recipient, const char *subject, const char *body) {
    printf("✉️  Sending email to: %s\n", recipient);
    printf("Subject: %s\n", subject);
    printf("Body:\n%s\n", body);
    printf("✨ Success! Your email has been sent! Have a fantastic day! 🌟\n");
}

void clear_buffer() {
    while (getchar() != '\n'); // Clear input buffer
}