//FormAI DATASET v1.0 Category: Email Client ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 500

struct email {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char recipient[50];
    char sender[50];
};

struct email inbox[MAX_EMAILS];
int num_emails = 0;

void readEmail(struct email *e) {
    printf("Subject: ");
    scanf("%s", e->subject);
    printf("Body: ");
    scanf("%s", e->body);
    printf("Recipient: ");
    scanf("%s", e->recipient);
    printf("Sender: ");
    scanf("%s", e->sender);
}

void sendEmail() {
    printf("Compose a new email: \n");
    struct email e;
    readEmail(&e);
    inbox[num_emails] = e;
    printf("Email sent!\n");
    num_emails++;
}

void viewInbox() {
    printf("Inbox: \n");
    for(int i = 0; i < num_emails; i++) {
        printf("Subject: %s\n", inbox[i].subject);
        printf("From: %s\n", inbox[i].sender);
        printf("Body: %s\n", inbox[i].body);
    }
}

int main() {
    printf("Welcome to CyberMail!\n");
    int menu_choice;
    do {
        printf("1. Compose an email\n");
        printf("2. View inbox\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &menu_choice);
        switch(menu_choice) {
            case 1:
                sendEmail();
                break;
            case 2:
                viewInbox();
                break;
            case 3:
                printf("Thank you for using CyberMail!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while(menu_choice != 3);

    return 0;
}