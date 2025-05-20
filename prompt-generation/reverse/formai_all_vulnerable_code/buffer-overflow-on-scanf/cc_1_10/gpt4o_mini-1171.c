//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MESSAGES 100
#define MESSAGE_LENGTH 256
#define SPAM_KEYWORDS 5

// A structure to represent an email message
typedef struct {
    char subject[MESSAGE_LENGTH];
    char body[MESSAGE_LENGTH];
} Email;

// Function prototypes
void addEmail(Email emails[], int *count);
void displayEmails(Email emails[], int count);
void checkSpam(Email email);
void displaySpamMessages(Email emails[], int count);

const char *spamKeywords[SPAM_KEYWORDS] = {
    "Win",
    "Free",
    "Urgent",
    "Click",
    "Congratulations"
};

int main() {
    Email emails[MAX_MESSAGES];
    int count = 0;
    int choice;

    while(1) {
        printf("\n=== Email Inbox ===\n");
        printf("1. Add Email\n");
        printf("2. Display Emails\n");
        printf("3. Check for Spam\n");
        printf("4. Display Spam Messages\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline from stdin

        switch(choice) {
            case 1:
                addEmail(emails, &count);
                break;
            case 2:
                displayEmails(emails, count);
                break;
            case 3:
                if (count == 0) {
                    printf("No emails to check.\n");
                } else {
                    for (int i = 0; i < count; i++) {
                        checkSpam(emails[i]);
                    }
                }
                break;
            case 4:
                displaySpamMessages(emails, count);
                break;
            case 5:
                printf("Exiting the Email Inbox. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void addEmail(Email emails[], int *count) {
    if (*count >= MAX_MESSAGES) {
        printf("Inbox is full. Can't add more emails.\n");
        return;
    }

    printf("Enter email subject: ");
    fgets(emails[*count].subject, MESSAGE_LENGTH, stdin);
    emails[*count].subject[strcspn(emails[*count].subject, "\n")] = 0;  // Remove newline

    printf("Enter email body: ");
    fgets(emails[*count].body, MESSAGE_LENGTH, stdin);
    emails[*count].body[strcspn(emails[*count].body, "\n")] = 0; // Remove newline

    (*count)++;
    printf("Email added successfully!\n");
}

void displayEmails(Email emails[], int count) {
    if (count == 0) {
        printf("No emails in your inbox.\n");
        return;
    }

    printf("\n=== Your Emails ===\n");
    for (int i = 0; i < count; i++) {
        printf("Email %d\n", i + 1);
        printf("Subject: %s\n", emails[i].subject);
        printf("Body: %s\n\n", emails[i].body);
    }
}

void checkSpam(Email email) {
    for (int i = 0; i < SPAM_KEYWORDS; i++) {
        if (strstr(email.subject, spamKeywords[i]) != NULL || strstr(email.body, spamKeywords[i]) != NULL) {
            printf("Spam Detected!\n");
            printf("Subject: %s\n", email.subject);
            printf("Body: %s\n\n", email.body);
            return; // Exit after finding first match
        }
    }
}

void displaySpamMessages(Email emails[], int count) {
    printf("\n--- Spam Messages ---\n");
    int spamCount = 0;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < SPAM_KEYWORDS; j++) {
            if (strstr(emails[i].subject, spamKeywords[j]) != NULL || strstr(emails[i].body, spamKeywords[j]) != NULL) {
                printf("Spam Email %d\n", i + 1);
                printf("Subject: %s\n", emails[i].subject);
                printf("Body: %s\n\n", emails[i].body);
                spamCount++;
                break; // Stop checking other keywords for this email
            }
        }
    }
    if (spamCount == 0) {
        printf("No spam messages detected.\n");
    }
}