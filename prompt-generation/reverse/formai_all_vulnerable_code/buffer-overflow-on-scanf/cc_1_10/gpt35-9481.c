//FormAI DATASET v1.0 Category: Email Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void showMenu();
void login();
void sendMail();
void receiveMail();
void showSentMails();
void showInbox();

// data structure to hold email
typedef struct {
    char to[50];
    char from[50];
    char subject[50];
    char body[MAX];
} Email;

// data structure to hold user mailbox
typedef struct {
    char name[50];
    Email inbox[MAX];
    int inboxCount;
    Email sent[MAX];
    int sentCount;
} Mailbox;

// global mailbox variable
Mailbox mailbox;

int main() {
    // prompt user to login or create new account
    printf("Welcome! Do you have an account? (Y/N) ");
    char response;
    scanf("%c", &response);
    if (response == 'Y' || response == 'y') {
        login();
    } else if (response == 'N' || response == 'n') {
        printf("Please create an account.\n");
        printf("Username: ");
        scanf("%s", mailbox.name);
        printf("Account created successfully. You can now login.\n");
        login();
    } else {
        printf("Invalid response. Please try again.\n");
        main();
    }
    return 0;
}

// display main menu to user
void showMenu() {
    printf("\n1. Send email\n");
    printf("2. View inbox\n");
    printf("3. View sent emails\n");
    printf("4. Log out\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            sendMail();
            break;
        case 2:
            showInbox();
            break;
        case 3:
            showSentMails();
            break;
        case 4:
            printf("Logged out.\n");
            main();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            showMenu();
            break;
    }
}

// login to user's mailbox
void login() {
    printf("Username: ");
    char username[50];
    scanf("%s", username);
    if (strcmp(mailbox.name, username) == 0) {
        printf("Login successful.\n");
        showMenu();
    } else {
        printf("Invalid username. Please try again.\n");
        login();
    }
}

// send an email
void sendMail() {
    Email email;
    printf("To: ");
    scanf("%s", email.to);
    printf("Subject: ");
    scanf("%s", email.subject);
    printf("Body: ");
    scanf("%s", email.body);
    strcpy(email.from, mailbox.name);
    mailbox.sent[mailbox.sentCount++] = email;
    printf("Email sent.\n");
    showMenu();
}

// view user's inbox
void showInbox() {
    printf("Inbox:\n");
    for (int i = 0; i < mailbox.inboxCount; i++) {
        printf("From: %s\nSubject: %s\nBody: %s\n", mailbox.inbox[i].from, mailbox.inbox[i].subject, mailbox.inbox[i].body);
    }
    showMenu();
}

// view user's sent emails
void showSentMails() {
    printf("Sent emails:\n");
    for (int i = 0; i < mailbox.sentCount; i++) {
        printf("To: %s\nSubject: %s\nBody: %s\n", mailbox.sent[i].to, mailbox.sent[i].subject, mailbox.sent[i].body);
    }
    showMenu();
}