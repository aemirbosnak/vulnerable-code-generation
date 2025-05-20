//FormAI DATASET v1.0 Category: Email Client ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LEN 100
#define MAX_EMAIL_LEN 1000

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_EMAIL_LEN];
    char sender[MAX_EMAIL_LEN];
    char receiver[MAX_EMAIL_LEN];
} Email;

Email inbox[MAX_EMAILS];
int num_emails = 0;

void print_menu() {
    printf("Welcome to C Email Client\n");
    printf("-----------------------------\n");
    printf("1. Compose Email\n");
    printf("2. Check Inbox\n");
    printf("3. Exit\n");
    printf("-----------------------------\n");
}

void compose_email() {
    Email new_email;

    printf("Enter subject:\n");
    fgets(new_email.subject, MAX_SUBJECT_LEN, stdin);
    printf("Enter body:\n");
    fgets(new_email.body, MAX_EMAIL_LEN, stdin);
    printf("Enter sender:\n");
    fgets(new_email.sender, MAX_EMAIL_LEN, stdin);
    printf("Enter receiver:\n");
    fgets(new_email.receiver, MAX_EMAIL_LEN, stdin);

    inbox[num_emails] = new_email;
    num_emails++;

    printf("Email sent successfully!\n");
}

void check_inbox() {
    printf("Inbox:\n");

    if (num_emails == 0) {
        printf("No emails in inbox\n");
        return;
    }

    for (int i = 0; i < num_emails; i++) {
        printf("Subject: %s", inbox[i].subject);
        printf("From: %s", inbox[i].sender);
        printf("To: %s", inbox[i].receiver);
        printf("Body: %s\n", inbox[i].body);
    }
}

int main() {
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                compose_email();
                break;
            case 2:
                check_inbox();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

    } while (choice != 3);

    return 0;
}