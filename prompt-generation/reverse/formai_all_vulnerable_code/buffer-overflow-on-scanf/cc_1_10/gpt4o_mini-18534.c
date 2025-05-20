//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

Email emails[MAX_EMAILS];
int email_count = 0;

void send_email() {
    if (email_count >= MAX_EMAILS) {
        printf("Email limit reached. Cannot send more emails.\n");
        return;
    }

    printf("Enter email subject: ");
    fgets(emails[email_count].subject, MAX_SUBJECT_LENGTH, stdin);
    strtok(emails[email_count].subject, "\n"); // Remove newline character

    printf("Enter email body:\n");
    fgets(emails[email_count].body, MAX_BODY_LENGTH, stdin);
    strtok(emails[email_count].body, "\n"); // Remove newline character

    email_count++;
    printf("Email sent!\n");
}

void view_emails() {
    if (email_count == 0) {
        printf("No emails to display.\n");
        return;
    }

    for (int i = 0; i < email_count; i++) {
        printf("Email %d:\n", i + 1);
        printf("Subject: %s\n", emails[i].subject);
        printf("Body: %s\n\n", emails[i].body);
    }
}

void save_emails() {
    FILE *file = fopen("emails.txt", "w");
    if (file == NULL) {
        printf("Error opening file for saving emails.\n");
        return;
    }

    for (int i = 0; i < email_count; i++) {
        fprintf(file, "Subject: %s\n", emails[i].subject);
        fprintf(file, "Body: %s\n\n", emails[i].body);
    }

    fclose(file);
    printf("Emails saved to emails.txt.\n");
}

void load_emails() {
    FILE *file = fopen("emails.txt", "r");
    if (file == NULL) {
        printf("No previous emails found.\n");
        return;
    }

    while (fscanf(file, "Subject: %[^\n]\n", emails[email_count].subject) != EOF) {
        fgets(emails[email_count].body, MAX_BODY_LENGTH, file);
        email_count++;
    }

    fclose(file);
    printf("Emails loaded from emails.txt.\n");
}

void show_menu() {
    printf("Email Client Menu:\n");
    printf("1. Send Email\n");
    printf("2. View Emails\n");
    printf("3. Save Emails\n");
    printf("4. Load Emails\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    load_emails();

    while (1) {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character left by scanf

        switch (choice) {
            case 1:
                send_email();
                break;
            case 2:
                view_emails();
                break;
            case 3:
                save_emails();
                break;
            case 4:
                load_emails();
                break;
            case 5:
                save_emails(); // Save emails before exiting
                printf("Exiting email client.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}