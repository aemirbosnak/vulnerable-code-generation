//FormAI DATASET v1.0 Category: Email Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_SIZE 1024
#define MAX_SUBJECT_SIZE 128
#define MAX_EMAILS_COUNT 100

struct Email {
    char sender[MAX_MSG_SIZE];
    char receiver[MAX_MSG_SIZE];
    char subject[MAX_SUBJECT_SIZE];
    char message[MAX_MSG_SIZE];
};

struct Inbox {
    struct Email emails[MAX_EMAILS_COUNT];
    int count;
} inbox;

struct Sent {
    struct Email emails[MAX_EMAILS_COUNT];
    int count;
} sent;

void display_menu() {
    printf("\nMenu\n");
    printf("===================\n");
    printf("1. Compose Email\n");
    printf("2. View Inbox\n");
    printf("3. View Sent Emails\n");
    printf("4. Exit\n");
}

void display_inbox() {
    printf("-------------------\n");
    printf("Inbox (%d)\n", inbox.count);
    printf("-------------------\n");

    for(int i=0; i<inbox.count; i++) {
        printf("From: %s\n", inbox.emails[i].sender);
        printf("Subject: %s\n", inbox.emails[i].subject);
        printf("-------------------\n");
        printf("%s\n", inbox.emails[i].message);
        printf("-------------------\n");
    }
}

void display_sent() {
    printf("-------------------\n");
    printf("Sent Emails (%d)\n", sent.count);
    printf("-------------------\n");
    
    for(int i=0; i<sent.count; i++) {
        printf("To: %s\n", sent.emails[i].receiver);
        printf("Subject: %s\n", sent.emails[i].subject);
        printf("-------------------\n");
        printf("%s\n", sent.emails[i].message);
        printf("-------------------\n");
    }
}

void read_string(char *message, int size) {
    fgets(message, size, stdin);
    strtok(message, "\n");
}

void compose_email() {
    printf("To: ");
    char to[MAX_MSG_SIZE];
    read_string(to, MAX_MSG_SIZE);

    printf("Subject: ");
    char subject[MAX_SUBJECT_SIZE];
    read_string(subject, MAX_SUBJECT_SIZE);

    printf("Message: ");
    char message[MAX_MSG_SIZE];
    read_string(message, MAX_MSG_SIZE);

    struct Email email;
    strcpy(email.sender, "youremail@domain.com");
    strcpy(email.receiver, to);
    strcpy(email.subject, subject);
    strcpy(email.message, message);

    sent.emails[sent.count] = email;
    sent.count++;
}

int main() {
    inbox.count = 0;
    sent.count = 0;
    int choice;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                compose_email();
                break;
            case 2:
                display_inbox();
                break;
            case 3:
                display_sent();
                break;
            case 4:
                printf("Exiting Program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(choice != 4);

    return 0;
}