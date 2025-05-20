//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 256
#define MAX_SUBJECT_LENGTH 128
#define MAX_BODY_LENGTH 512

typedef struct {
    char sender[MAX_EMAIL_LENGTH];
    char recipient[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

Email inbox[MAX_EMAILS];
int inbox_count = 0;

void sendEmail(const char *sender, const char *recipient, const char *subject, const char *body) {
    if (inbox_count >= MAX_EMAILS) {
        printf("Inbox is full!\n");
        return;
    }
    
    Email new_email;
    strncpy(new_email.sender, sender, MAX_EMAIL_LENGTH);
    strncpy(new_email.recipient, recipient, MAX_EMAIL_LENGTH);
    strncpy(new_email.subject, subject, MAX_SUBJECT_LENGTH);
    strncpy(new_email.body, body, MAX_BODY_LENGTH);

    inbox[inbox_count++] = new_email;
    printf("Email sent from %s to %s: %s\n", sender, recipient, subject);
}

void listEmails() {
    printf("\n--- Inbox: %d Emails ---\n", inbox_count);
    for (int i = 0; i < inbox_count; i++) {
        printf("Email #%d:\n", i + 1);
        printf("From: %s\n", inbox[i].sender);
        printf("To: %s\n", inbox[i].recipient);
        printf("Subject: %s\n", inbox[i].subject);
        printf("Body: %s\n", inbox[i].body);
        printf("-------------------------\n");
    }
}

void loadEmail(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file: %s\n", filename);
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char *sender = strtok(line, ",");
        char *recipient = strtok(NULL, ",");
        char *subject = strtok(NULL, ",");
        char *body = strtok(NULL, "\n");

        sendEmail(sender, recipient, subject, body);
    }
    fclose(file);
}

void clearInbox() {
    inbox_count = 0;
    printf("Inbox cleared!\n");
}

void displayMenu() {
    printf("\n--- C Email Client ---\n");
    printf("1. Send Email\n");
    printf("2. List Emails\n");
    printf("3. Load Emails from File\n");
    printf("4. Clear Inbox\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    char sender[MAX_EMAIL_LENGTH];
    char recipient[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char filename[MAX_EMAIL_LENGTH];
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter Sender: ");
                scanf("%s", sender);
                printf("Enter Recipient: ");
                scanf("%s", recipient);
                printf("Enter Subject: ");
                scanf(" %[^\n]", subject);
                printf("Enter Body: ");
                scanf(" %[^\n]", body);
                sendEmail(sender, recipient, subject, body);
                break;
            case 2:
                listEmails();
                break;
            case 3:
                printf("Enter filename to load emails: ");
                scanf("%s", filename);
                loadEmail(filename);
                break;
            case 4:
                clearInbox();
                break;
            case 5:
                printf("Exiting Email Client. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }
    return 0;
}