//FormAI DATASET v1.0 Category: Email Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1024

struct Email {
    char* sender;
    char* receiver;
    char* subject;
    char* body;
    time_t timestamp;
};

struct Email *inbox[MAX_LENGTH];
int inbox_size = 0;

void send_email(char* sender, char* receiver, char* subject, char* body) {
    struct Email* email = (struct Email*) malloc(sizeof(struct Email));
    email->sender = strdup(sender);
    email->receiver = strdup(receiver);
    email->subject = strdup(subject);
    email->body = strdup(body);
    email->timestamp = time(NULL);

    printf("\n\n---Email Sent---\n");
    printf("From: %s\n", email->sender);
    printf("To: %s\n", email->receiver);
    printf("Subject: %s\n", email->subject);
    printf("Body: %s\n", email->body);

    inbox[inbox_size++] = email;
}

void list_emails() {
    for (int i = 0; i < inbox_size; i++) {
        struct Email* email = inbox[i];
        printf("\n\n---Email %d---\n", i+1);
        printf("From: %s\n", email->sender);
        printf("To: %s\n", email->receiver);
        printf("Subject: %s\n", email->subject);
        printf("Body: %s\n", email->body);
        printf("Timestamp: %s\n", ctime(&email->timestamp));
    }
}

int main() {
    while(1) {
        printf("\n\nAvailable Options:\n");
        printf("1. Send Email\n");
        printf("2. List Emails\n");
        printf("3. Quit\n");
        printf("Enter Choice: ");
        int choice;
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            char sender[MAX_LENGTH], receiver[MAX_LENGTH], subject[MAX_LENGTH], body[MAX_LENGTH];
            printf("\nEnter Sender: ");
            fgets(sender, MAX_LENGTH, stdin);
            sender[strcspn(sender, "\n")] = 0;
            printf("Enter Receiver: ");
            fgets(receiver, MAX_LENGTH, stdin);
            receiver[strcspn(receiver, "\n")] = 0;
            printf("Enter Subject: ");
            fgets(subject, MAX_LENGTH, stdin);
            subject[strcspn(subject, "\n")] = 0;
            printf("Enter Body: ");
            fgets(body, MAX_LENGTH, stdin);
            body[strcspn(body, "\n")] = 0;

            send_email(sender, receiver, subject, body);
        } else if (choice == 2) {
            list_emails();
        } else {
            break;
        }
    }
    return 0;
}