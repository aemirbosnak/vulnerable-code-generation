//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_SENDER_LENGTH 100
#define EMAIL_FILE "emails.txt"

typedef struct {
    char sender[MAX_SENDER_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

Email inbox[MAX_EMAILS];
int email_count = 0;

// Function to compose an email
void compose_email() {
    if (email_count >= MAX_EMAILS) {
        printf("Inbox is full! Cannot send more emails.\n");
        return;
    }

    Email new_email;
    printf("Compose Email:\n");
    printf("Enter sender's name: ");
    fgets(new_email.sender, MAX_SENDER_LENGTH, stdin);
    new_email.sender[strcspn(new_email.sender, "\n")] = 0;  // Remove newline character

    printf("Enter email subject: ");
    fgets(new_email.subject, MAX_SUBJECT_LENGTH, stdin);
    new_email.subject[strcspn(new_email.subject, "\n")] = 0;

    printf("Enter email body: \n");
    fgets(new_email.body, MAX_BODY_LENGTH, stdin);
    new_email.body[strcspn(new_email.body, "\n")] = 0;

    inbox[email_count++] = new_email;
    printf("Email sent successfully!\n");
}

// Function to read emails from a file (from a previous session)
void read_emails_from_file() {
    FILE *file = fopen(EMAIL_FILE, "r");
    if (file == NULL) {
        printf("No previous emails to load.\n");
        return;
    }

    while (fscanf(file, "%s\n%[^\n]\n%[^\n]\n", inbox[email_count].sender, inbox[email_count].subject, inbox[email_count].body) != EOF) {
        email_count++;
    }
    fclose(file);
    printf("Loaded %d emails from the email file.\n", email_count);
}

// Function to print all emails in the inbox
void print_inbox() {
    if (email_count == 0) {
        printf("Inbox is empty.\n");
        return;
    }

    printf("Inbox:\n");
    for (int i = 0; i < email_count; i++) {
        printf("Email #%d\n", i + 1);
        printf("From: %s\n", inbox[i].sender);
        printf("Subject: %s\n", inbox[i].subject);
        printf("Body: %s\n", inbox[i].body);
        printf("-----------------\n");
    }
}

// Function to save emails to a file
void save_emails_to_file() {
    FILE *file = fopen(EMAIL_FILE, "w");
    if (file == NULL) {
        printf("Failed to save emails.\n");
        return;
    }

    for (int i = 0; i < email_count; i++) {
        fprintf(file, "%s\n%s\n%s\n", inbox[i].sender, inbox[i].subject, inbox[i].body);
    }
    fclose(file);
    printf("Emails saved to the file successfully!\n");
}

// Main function
int main() {
    int choice;
    read_emails_from_file();

    do {
        printf("\n*** Simple Email Client ***\n");
        printf("1. Compose Email\n");
        printf("2. View Inbox\n");
        printf("3. Save Emails\n");
        printf("4. Exit\n");
        printf("---------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline character from input buffer

        switch (choice) {
            case 1:
                compose_email();
                break;
            case 2:
                print_inbox();
                break;
            case 3:
                save_emails_to_file();
                break;
            case 4:
                printf("Exiting... Thank you for using the Email Client!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}