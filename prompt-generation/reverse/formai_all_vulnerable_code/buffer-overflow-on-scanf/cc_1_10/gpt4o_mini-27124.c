//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 587
#define BUFFER_SIZE 1024
#define MAX_EMAILS 10

typedef struct {
    char email[100];
    char subject[100];
    char body[512];
} Email;

Email inbox[MAX_EMAILS];
int inboxCount = 0;

// Function Prototypes
void displayMenu();
void sendEmail();
void viewInbox();
void clearBuffer(char *buffer, int size);

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Your choice: ");
        scanf("%d", &choice);
        clearBuffer(stdin, 0); // Clear newline from input buffer
        switch (choice) {
            case 1: sendEmail(); break;
            case 2: viewInbox(); break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n=== Simple C Email Client ===\n");
    printf("1. Send Email\n");
    printf("2. View Inbox\n");
    printf("3. Exit\n");
}

void sendEmail() {
    if (inboxCount >= MAX_EMAILS) {
        printf("Inbox is full, cannot send more emails!\n");
        return;
    }
    Email newEmail;
    
    printf("Enter recipient's email: ");
    fgets(newEmail.email, sizeof(newEmail.email), stdin);
    strtok(newEmail.email, "\n"); // Removing newline character at the end
    
    printf("Enter subject: ");
    fgets(newEmail.subject, sizeof(newEmail.subject), stdin);
    strtok(newEmail.subject, "\n");
    
    printf("Enter message body: ");
    fgets(newEmail.body, sizeof(newEmail.body), stdin);
    strtok(newEmail.body, "\n");

    inbox[inboxCount++] = newEmail;

    printf("Email sent to %s with subject: '%s'\n", newEmail.email, newEmail.subject);
}

void viewInbox() {
    if (inboxCount == 0) {
        printf("Inbox is empty!\n");
        return;
    }
    
    printf("\n=== Your Inbox ===\n");
    for (int i = 0; i < inboxCount; i++) {
        printf("Email %d:\n", i + 1);
        printf("From: %s\n", inbox[i].email);
        printf("Subject: %s\n", inbox[i].subject);
        printf("Body: %s\n", inbox[i].body);
        printf("-------------------\n");
    }
}

void clearBuffer(char *buffer, int size) {
    if (size > 0) memset(buffer, 0, size);
    else while (getchar() != '\n'); // Clear until newline
}