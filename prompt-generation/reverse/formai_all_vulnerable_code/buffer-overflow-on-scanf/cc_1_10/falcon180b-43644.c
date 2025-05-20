//Falcon-180B DATASET v1.0 Category: Email Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void cyberpunk_email_client(void);

int main(void) {
    cyberpunk_email_client();
    return 0;
}

void cyberpunk_email_client(void) {
    char username[50], password[50], recipient[50], subject[100], message[500];
    int choice, len;

    // Cyberpunk style ASCII art
    printf("\n");
    printf("   ___ _ _ _ \n");
    printf("  / __| | | | |\n");
    printf(" | (__| | | | |\n");
    printf("  \\__,_|_|_|_|\n");
    printf("\n");
    printf(" Cyberpunk Email Client\n");
    printf("\n");

    // Login screen
    printf("Enter your username: ");
    fgets(username, 50, stdin);
    printf("Enter your password: ");
    fgets(password, 50, stdin);

    // Validate user credentials
    if (strcmp(username, "neo") == 0 && strcmp(password, "theone") == 0) {
        printf("\nLogin successful!\n");
    } else {
        printf("\nInvalid username or password.\n");
        return;
    }

    // Main menu
    do {
        printf("\nMain Menu:\n");
        printf("1. Compose email\n");
        printf("2. Inbox\n");
        printf("3. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Compose email
                printf("\nCompose email:\n");
                printf("To: ");
                fgets(recipient, 50, stdin);
                printf("Subject: ");
                fgets(subject, 100, stdin);
                printf("Message: ");
                fgets(message, 500, stdin);

                // Send email
                printf("\nEmail sent to %s with subject '%s'.\n", recipient, subject);
                break;

            case 2:
                // Inbox
                printf("\nInbox:\n");
                // TODO: Implement inbox functionality
                break;

            case 3:
                // Logout
                printf("\nLogout successful!\n");
                break;

            default:
                printf("\nInvalid choice.\n");
        }

    } while (choice!= 3);
}