//FormAI DATASET v1.0 Category: Email Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_EMAIL_SIZE 1024
#define MAX_EMAILS 100

struct email {
    char sender[50];
    char receiver[50];
    char subject[100];
    char message[MAX_EMAIL_SIZE];
    bool is_read;
};

struct inbox {
    struct email *emails[MAX_EMAILS];
    int num_emails;
};

void send_email(struct inbox *user_inbox) {
    char sender[50];
    char receiver[50];
    char subject[100];
    char message[MAX_EMAIL_SIZE];

    printf("Enter sender name: ");
    scanf("%s", sender);
    printf("Enter receiver name: ");
    scanf("%s", receiver);
    printf("Enter subject: ");
    scanf("%s", subject);
    printf("Enter message: \n");
    getchar();
    fgets(message, MAX_EMAIL_SIZE, stdin);

    struct email *new_email = malloc(sizeof(struct email));
    strcpy(new_email->sender, sender);
    strcpy(new_email->receiver, receiver);
    strcpy(new_email->subject, subject);
    strcpy(new_email->message, message);
    new_email->is_read = false;

    user_inbox->emails[user_inbox->num_emails] = new_email;
    user_inbox->num_emails++;
}

void view_inbox(struct inbox *user_inbox) {
    printf("\nInbox:\n");
    for (int i = 0; i < user_inbox->num_emails; i++) {
        printf("From: %s\n", user_inbox->emails[i]->sender);
        printf("Subject: %s\n", user_inbox->emails[i]->subject);
        if (user_inbox->emails[i]->is_read) {
            printf("Status: Read\n");
        } else {
            printf("Status: Unread\n");
        }
        printf("-----------------------------\n");
    }
}

void view_email(struct inbox *user_inbox) {
    int email_index;
    printf("Enter email index: ");
    scanf("%d", &email_index);
    email_index--;

    printf("\nFrom: %s\n", user_inbox->emails[email_index]->sender);
    printf("To: %s\n", user_inbox->emails[email_index]->receiver);
    printf("Subject: %s\n", user_inbox->emails[email_index]->subject);
    printf("Message:\n%s\n", user_inbox->emails[email_index]->message);
    user_inbox->emails[email_index]->is_read = true;
}

void delete_email(struct inbox *user_inbox) {
    int email_index;
    printf("Enter email index: ");
    scanf("%d", &email_index);
    email_index--;

    free(user_inbox->emails[email_index]);
    for (int i = email_index; i < user_inbox->num_emails - 1; i++) {
        user_inbox->emails[i] = user_inbox->emails[i + 1];
    }
    user_inbox->num_emails--;
}

int main() {
    char user_name[50];
    int user_choice;
    struct inbox *user_inbox = malloc(sizeof(struct inbox));
    user_inbox->num_emails = 0;

    printf("Welcome to Unique C Email Client!\n");
    printf("Please enter your user name: ");
    scanf("%s", user_name);

    while (true) {
        printf("\nHello, %s!\n", user_name);
        printf("Enter 1 to send email\n");
        printf("Enter 2 to view inbox\n");
        printf("Enter 3 to view email\n");
        printf("Enter 4 to delete email\n");
        printf("Enter 5 to exit\n");

        scanf("%d", &user_choice);

        switch (user_choice) {
            case 1:
                send_email(user_inbox);
                break;
            case 2:
                view_inbox(user_inbox);
                break;
            case 3:
                view_email(user_inbox);
                break;
            case 4:
                delete_email(user_inbox);
                break;
            case 5:
                printf("Exiting Unique C Email Client. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}