//FormAI DATASET v1.0 Category: Email Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#define MAX_EMAILS 10
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 500

typedef struct {
    char sender[50];
    char receiver[50];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

int main() {
    Email inbox[MAX_EMAILS];
    int num_emails = 0;
    char username[50];
    char password[50];
    char menu_choice;

    printf("Welcome to the Future Email Client\n");

    // Get the user's username and password
    printf("Enter your username: ");
    scanf("%s", username);
    struct termios orig_termios;
    tcgetattr(STDIN_FILENO, &orig_termios);
    struct termios new_termios = orig_termios;
    new_termios.c_lflag &= ~(ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &new_termios);
    printf("Enter your password: ");
    scanf("%s", password);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
    printf("\n");

    while (1) {
        printf("Menu:\n");
        printf("1. Compose an email\n");
        printf("2. View Inbox\n");
        printf("3. Exit\n");
        printf("Enter a choice: ");
        scanf(" %c", &menu_choice);
        printf("\n");

        switch (menu_choice) {
            case '1': // Compose new email
                if (num_emails == MAX_EMAILS) {
                    printf("Inbox is full. Please delete some emails to make space.\n\n");
                    break;
                }
                Email email;
                printf("Compose Email:\n");
                printf("To: ");
                scanf("%s", email.receiver);
                printf("Subject: ");
                scanf("%s", email.subject);
                printf("Body: ");
                scanf("%s", email.body);
                strcpy(email.sender, username);
                inbox[num_emails++] = email;
                printf("\nEmail sent successfully!\n\n");
                break;

            case '2': // View Inbox
                if (num_emails == 0) {
                    printf("Your inbox is currently empty.\n\n");
                    break;
                }
                printf("Inbox:\n");
                for (int i = 0; i < num_emails; i++) {
                    Email email = inbox[i];
                    printf("%d. From: %s\n", i+1, email.sender);
                    printf("   Subject: %s\n", email.subject);
                    printf("   Body: %s\n", email.body);
                    printf("\n");
                }
                break;

            case '3': // Exit
                printf("Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }

    return 0;
}