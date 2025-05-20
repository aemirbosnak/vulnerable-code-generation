//FormAI DATASET v1.0 Category: Email Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_EMAILS 10
#define MAX_SUBJECT_LENGTH 50
#define MAX_MESSAGE_LENGTH 200

struct Email {
    char sender[50];
    char recipient[50];
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    bool isRead;
};

// Function to send an email
void sendEmail(struct Email *emails, int *emailCount) {
    if (*emailCount == MAX_EMAILS) {
        printf("Error: Inbox is full. Please delete some emails to make space for new ones.\n");
        return;
    }

    struct Email newEmail;

    printf("Enter sender: ");
    scanf("%s", newEmail.sender);
    printf("Enter recipient: ");
    scanf("%s", newEmail.recipient);
    printf("Enter subject (maximum %d characters): ", MAX_SUBJECT_LENGTH);
    getchar();
    fgets(newEmail.subject, MAX_SUBJECT_LENGTH, stdin);
    printf("Enter message (maximum %d characters): ", MAX_MESSAGE_LENGTH);
    fgets(newEmail.message, MAX_MESSAGE_LENGTH, stdin);

    newEmail.isRead = false;

    emails[*emailCount] = newEmail;

    printf("Email sent successfully!\n");

    (*emailCount)++;
}

// Function to display all emails in the inbox
void displayInbox(struct Email *emails, int emailCount) {
    if (emailCount == 0) {
        printf("Inbox is empty.\n");
        return;
    }

    printf("Inbox:\n");

    for (int i = 0; i < emailCount; i++) {
        printf("Email #%d:\n", i + 1);
        printf("Sender: %s\n", emails[i].sender);
        printf("Recipient: %s\n", emails[i].recipient);
        printf("Subject: %s", emails[i].subject);
        printf("Message: %s", emails[i].message);
        printf("Status: %s\n", emails[i].isRead ? "Read" : "Unread");
        printf("\n");
    }
}

// Function to display only unread emails
void displayUnread(struct Email *emails, int emailCount) {
    if (emailCount == 0) {
        printf("Inbox is empty.\n");
        return;
    }

    printf("Unread emails:\n");

    for (int i = 0; i < emailCount; i++) {
        if (!emails[i].isRead) {
            printf("Email #%d:\n", i + 1);
            printf("Sender: %s\n", emails[i].sender);
            printf("Recipient: %s\n", emails[i].recipient);
            printf("Subject: %s", emails[i].subject);
            printf("Message: %s", emails[i].message);
            printf("\n");
        }
    }
}

// Function to mark an email as read
void markRead(struct Email *emails, int emailCount) {
    if (emailCount == 0) {
        printf("Inbox is empty.\n");
        return;
    }

    printf("Enter email number to mark as read: ");
    int emailNumber;
    scanf("%d", &emailNumber);
    emailNumber--;

    if (emailNumber < 0 || emailNumber >= emailCount) {
        printf("Invalid email number.\n");
        return;
    }

    emails[emailNumber].isRead = true;

    printf("Email #%d marked as read.\n", emailNumber + 1);
}

// Function to delete an email from the inbox
void deleteEmail(struct Email *emails, int *emailCount) {
    if (*emailCount == 0) {
        printf("Inbox is empty.\n");
        return;
    }

    printf("Enter email number to delete: ");
    int emailNumber;
    scanf("%d", &emailNumber);
    emailNumber--;

    if (emailNumber < 0 || emailNumber >= *emailCount) {
        printf("Invalid email number.\n");
        return;
    }

    for (int i = emailNumber; i < *emailCount - 1; i++) {
        emails[i] = emails[i + 1];
    }

    (*emailCount)--;

    printf("Email #%d successfully deleted.\n", emailNumber + 1);
}

int main() {
    struct Email emails[MAX_EMAILS];
    int emailCount = 0;

    int choice;
    do {
        printf("Email Client Main Menu:\n");
        printf("1. Send email\n");
        printf("2. Display inbox\n");
        printf("3. Display unread emails\n");
        printf("4. Mark email as read\n");
        printf("5. Delete email\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sendEmail(emails, &emailCount);
                break;
            case 2:
                displayInbox(emails, emailCount);
                break;
            case 3:
                displayUnread(emails, emailCount);
                break;
            case 4:
                markRead(emails, emailCount);
                break;
            case 5:
                deleteEmail(emails, &emailCount);
                break;
            case 6:
                printf("Exiting Email Client...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}