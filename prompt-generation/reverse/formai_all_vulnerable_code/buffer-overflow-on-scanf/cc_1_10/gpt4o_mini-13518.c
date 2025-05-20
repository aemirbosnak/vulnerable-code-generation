//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define EMAIL_LENGTH 256
#define SUBJECT_LENGTH 128
#define BODY_LENGTH 512

typedef struct {
    char sender[EMAIL_LENGTH];
    char receiver[EMAIL_LENGTH];
    char subject[SUBJECT_LENGTH];
    char body[BODY_LENGTH];
} Email;

void send_email(Email *email);
void read_email(Email *email);
void display_menu();
void flush_input();

Email email_database[MAX_EMAILS];
int email_count = 0;

int main() {
    int choice;
    Email new_email;

    while (1) {
        display_menu();
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        flush_input();

        switch (choice) {
            case 1: // Send email
                if (email_count < MAX_EMAILS) {
                    printf("Enter sender email: ");
                    fgets(new_email.sender, EMAIL_LENGTH, stdin);
                    new_email.sender[strcspn(new_email.sender, "\n")] = 0; // Remove newline

                    printf("Enter receiver email: ");
                    fgets(new_email.receiver, EMAIL_LENGTH, stdin);
                    new_email.receiver[strcspn(new_email.receiver, "\n")] = 0; // Remove newline

                    printf("Enter subject: ");
                    fgets(new_email.subject, SUBJECT_LENGTH, stdin);
                    new_email.subject[strcspn(new_email.subject, "\n")] = 0; // Remove newline

                    printf("Enter email body: ");
                    fgets(new_email.body, BODY_LENGTH, stdin);
                    new_email.body[strcspn(new_email.body, "\n")] = 0; // Remove newline
                    
                    send_email(&new_email);
                } else {
                    printf("Mail storage full!\n");
                }
                break;

            case 2: // Read email
                if (email_count > 0) {
                    for (int i = 0; i < email_count; i++) {
                        printf("\nEmail %d:\n", i + 1);
                        read_email(&email_database[i]);
                    }
                } else {
                    printf("No emails to display.\n");
                }
                break;

            case 3: // Exit
                printf("Exiting email client.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}

void send_email(Email *email) {
    email_database[email_count++] = *email; // Store email in database
    printf("Email sent successfully!\n");
}

void read_email(Email *email) {
    printf("From: %s\n", email->sender);
    printf("To: %s\n", email->receiver);
    printf("Subject: %s\n", email->subject);
    printf("Body: %s\n", email->body);
}

void display_menu() {
    printf("\n=== Email Client ===\n");
    printf("1. Send Email\n");
    printf("2. Read Emails\n");
    printf("3. Exit\n");
}

void flush_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Clear input buffer
}