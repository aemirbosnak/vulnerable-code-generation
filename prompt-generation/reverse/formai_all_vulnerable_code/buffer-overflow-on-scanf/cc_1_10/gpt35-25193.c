//FormAI DATASET v1.0 Category: Email Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 5 // Maximum number of emails a player can have
#define MAX_SUBJECT_LENGTH 50 // Maximum length of email subject line

// Struct to hold email information
typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[1000]; // Maximum length of email body
} Email;

// Struct to hold player information
typedef struct {
    char name[20];
    Email emails[MAX_EMAILS];
    int num_emails;
} Player;

// Function to send email to another player
void send_email(Player *sender, Player *receiver) {
    if (sender->num_emails >= MAX_EMAILS) {
        printf("%s's inbox is full!\n", sender->name);
        return;
    }

    // Get email subject and body from sender
    char subject[MAX_SUBJECT_LENGTH];
    char body[1000];
    printf("Enter email subject: ");
    scanf("%s", subject);
    printf("Enter email body: ");
    scanf("%s", body);

    // Add email to sender's inbox
    Email email;
    strcpy(email.subject, subject);
    strcpy(email.body, body);
    sender->emails[sender->num_emails] = email;
    sender->num_emails++;

    // Notify receiver of new email
    printf("New email from %s: %s\n", sender->name, subject);
}

int main() {
    // Initialize players
    Player player1 = {"Player 1", {}, 0};
    Player player2 = {"Player 2", {}, 0};

    // Allow players to send emails back and forth
    while (1) {
        int choice;
        printf("1. %s send email to %s\n", player1.name, player2.name);
        printf("2. %s send email to %s\n", player2.name, player1.name);
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                send_email(&player1, &player2);
                break;
            case 2:
                send_email(&player2, &player1);
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}