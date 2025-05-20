//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char from[50];
    char to[50];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

Email emailDatabase[MAX_EMAILS];
int emailCount = 0;

void viewEmails() {
    printf("\n=== Attempting to discern the various missives in our possession... ===\n");
    for (int i = 0; i < emailCount; i++) {
        printf("\nEmail #%d:\n", i + 1);
        printf("  From: %s\n", emailDatabase[i].from);
        printf("  To: %s\n", emailDatabase[i].to);
        printf("  Subject: %s\n", emailDatabase[i].subject);
        printf("  Body: %s\n", emailDatabase[i].body);
    }
}

void composeEmail() {
    if (emailCount >= MAX_EMAILS) {
        printf("Oh dear! The inbox can hold no more. Please delete an email before composing a new one.\n");
        return;
    }

    printf("\n=== A new email awaits to be crafted... ===\n");

    printf("Enter the sender's address: ");
    scanf("%s", emailDatabase[emailCount].from);
    printf("Enter the recipient's address: ");
    scanf("%s", emailDatabase[emailCount].to);
    printf("Enter the subject: ");
    getchar(); // To consume the newline character left by previous scanf
    fgets(emailDatabase[emailCount].subject, MAX_SUBJECT_LENGTH, stdin);
    emailDatabase[emailCount].subject[strcspn(emailDatabase[emailCount].subject, "\n")] = 0; // Remove newline

    printf("Enter the message body:\n");
    fgets(emailDatabase[emailCount].body, MAX_BODY_LENGTH, stdin);
    emailDatabase[emailCount].body[strcspn(emailDatabase[emailCount].body, "\n")] = 0; // Remove newline

    emailCount++;
    printf("The email has been composed and awaits dispatch!\n");
}

void deleteEmail() {
    if (emailCount == 0) {
        printf("Alas! There are no emails to eliminate.\n");
        return;
    }

    viewEmails();
    printf("Which email would you like to delete? (1-%d): ", emailCount);
    int emailNumber;
    scanf("%d", &emailNumber);

    if (emailNumber < 1 || emailNumber > emailCount) {
        printf("A most perplexing choice! Exiting without changes.\n");
        return;
    }

    for (int i = emailNumber - 1; i < emailCount - 1; i++) {
        emailDatabase[i] = emailDatabase[i + 1];
    }
    emailCount--;
    printf("The email hath been vanquished! We are closer to a cleaner slate.\n");
}

void showMenu() {
    printf("\n== Welcome to the Baker Street Email Client ==\n");
    printf("1. View Emails\n");
    printf("2. Compose Email\n");
    printf("3. Delete Email\n");
    printf("4. Exit\n");
    printf("=======================================\n");
}

int main() {
    int choice;

    while (1) {
        showMenu();
        printf("Enter your selection: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewEmails();
                break;
            case 2:
                composeEmail();
                break;
            case 3:
                deleteEmail();
                break;
            case 4:
                printf("Exiting the Baker Street Email Client. Until next time!\n");
                exit(0);
            default:
                printf("An enigma! Please choose a valid option from the list.\n");
                break;
        }
    }

    return 0;
}