//FormAI DATASET v1.0 Category: Email Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100

typedef struct {
    char sender[50];
    char recipient[50];
    char subject[100];
    char body[1000];
    int is_read;
} Email;

int num_unread_emails = 0;
Email inbox[MAX_EMAILS];

void display_menu() {
    printf("\nWelcome to your Email Client!\n");
    printf("1. Compose Email\n");
    printf("2. View Inbox (%d unread)\n", num_unread_emails);
    printf("3. Exit\n");
}

void compose_email() {
    Email new_email;
    printf("Enter recipient email address: ");
    scanf("%s", new_email.recipient);
    printf("Enter subject: ");
    scanf("%s", new_email.subject);
    printf("Enter message: ");
    scanf("%s", new_email.body);
    strcpy(new_email.sender, "me@myself.com");
    new_email.is_read = 0;
    inbox[num_unread_emails++] = new_email;
    printf("Email sent!\n");
}

void view_inbox() {
    if (num_unread_emails == 0) {
        printf("Your inbox is empty!\n");
        return;
    }
    printf("Unread Emails:\n");
    for (int i = 0; i < num_unread_emails; i++) {
        if (!inbox[i].is_read) {
            printf("\nFrom: %s\nSubject: %s\nMessage: %s\n",
                   inbox[i].sender, inbox[i].subject, inbox[i].body);
            inbox[i].is_read = 1;
        }
    }
}

int main() {
    int option = 0;
    while (option != 3) {
        display_menu();
        printf("Select an option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                compose_email();
                break;
            case 2:
                view_inbox();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option :(\n");
                break;
        }
    }
    return 0;
}