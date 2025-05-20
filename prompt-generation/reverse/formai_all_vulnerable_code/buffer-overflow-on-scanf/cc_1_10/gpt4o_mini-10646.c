//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_EMAIL_LENGTH 100

typedef struct Email {
    char recipient[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

void display_menu() {
    printf("Welcome to Simple Email Client\n");
    printf("---------------------------------------\n");
    printf("1. Compose Email\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

void compose_email(Email *email) {
    printf("Enter recipient's email: ");
    fgets(email->recipient, MAX_EMAIL_LENGTH, stdin);
    email->recipient[strcspn(email->recipient, "\n")] = 0; // Remove newline character

    printf("Enter subject: ");
    fgets(email->subject, MAX_SUBJECT_LENGTH, stdin);
    email->subject[strcspn(email->subject, "\n")] = 0; // Remove newline character

    printf("Enter body (type 'END' on a new line to stop):\n");
    char line[256];
    email->body[0] = '\0'; // Initialize body as empty
    while (1) {
        fgets(line, sizeof(line), stdin);
        if (strncmp(line, "END", 3) == 0) {
            break;
        }
        strcat(email->body, line);
    }
}

void send_email(Email *email) {
    printf("\nEmail Summary:\n");
    printf("To: %s\n", email->recipient);
    printf("Subject: %s\n", email->subject);
    printf("Body: \n%s\n", email->body);
    printf("Email has been sent successfully!\n\n");
}

int main() {
    Email email;
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // Use getchar() to consume the newline character left by scanf

        switch (choice) {
            case 1:
                compose_email(&email);
                send_email(&email);
                break;
            case 2:
                printf("Exiting the email client. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}