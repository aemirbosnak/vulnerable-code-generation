//FormAI DATASET v1.0 Category: Email Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 500
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

struct Email {
    char sender[MAX_EMAIL_LENGTH];
    char recipient[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
};

int main() {
    bool loggedIn = false;
    char username[20];
    char password[20];
    
    while (!loggedIn) {
        printf("Welcome to Unique Email Client 1.0!\n");
        printf("Please enter your username: ");
        scanf("%s", username);
        printf("Please enter your password: ");
        scanf("%s", password);
        
        if (strcmp(username, "uniqueuser") == 0 && strcmp(password, "password123") == 0) {
            printf("Welcome, %s!\n", username);
            loggedIn = true;
        } else {
            printf("Invalid login credentials. Please try again.\n");
        }
    }
    
    char choice;
    struct Email inbox[10];
    int inboxSize = 0;
    
    do {
        printf("What would you like to do?\n");
        printf("a) Compose a new email\n");
        printf("b) View your inbox\n");
        printf("c) Logout\n");
        scanf(" %c", &choice);
        
        switch (choice) {
            case 'a':
                printf("New Email\n");
                struct Email newEmail;
                printf("From: %s\n", username);
                printf("To: ");
                scanf("%s", newEmail.recipient);
                printf("Subject: ");
                scanf("%s", newEmail.subject);
                printf("Body: ");
                scanf("%s", newEmail.body);
                inbox[inboxSize] = newEmail;
                inboxSize++;
                printf("Email sent to %s\n", newEmail.recipient);
                break;
            case 'b':
                printf("Inbox\n");
                for (int i = 0; i < inboxSize; i++) {
                    printf("From: %s\n", inbox[i].sender);
                    printf("Subject: %s\n", inbox[i].subject);
                    printf("Body: %s\n\n", inbox[i].body);
                }
                break;
            case 'c':
                printf("Logging out...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 'c');
    
    return 0;
}