//FormAI DATASET v1.0 Category: Email Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGES 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char sender[50];
    char receiver[50];
    char subject[100];
    char message[MAX_MESSAGE_LENGTH];
} Message;

int menu() {
    int choice;

    printf("\n\n");
    printf("1. Compose a new email\n");
    printf("2. View Inbox\n");
    printf("3. View Sent mail\n");
    printf("4. Exit\n");
    printf("\n\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    return choice;
}

void send_mail(Message *mail, int *mail_count) {
    printf("\nEnter sender's email address: ");
    scanf("%s", mail[*mail_count].sender);

    printf("\nEnter receiver's email address: ");
    scanf("%s", mail[*mail_count].receiver);

    printf("\nEnter email subject: ");
    scanf("%s", mail[*mail_count].subject);

    printf("\nEnter message body: ");
    getchar();
    fgets(mail[*mail_count].message, MAX_MESSAGE_LENGTH, stdin);

    printf("\nMail Sent!");

    (*mail_count)++;
}

void view_inbox(Message *mail, int mail_count) {
    printf("\nInbox:\n");

    for (int i = 0; i < mail_count; i++) {
        if (strcmp(mail[i].receiver, "myemail@gmail.com") == 0) {
            printf("From: %s\n", mail[i].sender);
            printf("Subject: %s\n", mail[i].subject);
            printf("Message: %s\n", mail[i].message);
            printf("----------------------------------------\n");
        }
    }
}

void view_sent_mail(Message *mail, int mail_count) {
    printf("\nSent mail:\n");

    for (int i = 0; i < mail_count; i++) {
        if (strcmp(mail[i].sender, "myemail@gmail.com") == 0) {
            printf("To: %s\n", mail[i].receiver);
            printf("Subject: %s\n", mail[i].subject);
            printf("Message: %s\n", mail[i].message);
            printf("----------------------------------------\n");
        }
    }
}

int main() {
    Message mail[MAX_MESSAGES];
    int mail_count = 0;
    int choice;

    do {
        choice = menu();

        switch (choice) {
            case 1:
                send_mail(mail, &mail_count);
                break;

            case 2:
                view_inbox(mail, mail_count);
                break;

            case 3:
                view_sent_mail(mail, mail_count);
                break;

            case 4:
                printf("\nGoodbye!");
                exit(0);

            default:
                printf("\nInvalid choice! Try again.\n\n");
        }
    } while (choice != 4);

    return 0;
}