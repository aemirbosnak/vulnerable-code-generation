//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 50

typedef struct subscriber {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber() {
    printf("Enter your name: ");
    scanf("%s", subscribers[num_subscribers].name);
    printf("Enter your email: ");
    scanf("%s", subscribers[num_subscribers].email);
    num_subscribers++;
}

void send_email(char* subject, char* body) {
    printf("Sending email to %d subscribers...\n", num_subscribers);
    for (int i = 0; i < num_subscribers; i++) {
        printf("Sending email to %s <%s>\n", subscribers[i].name, subscribers[i].email);
    }
}

void main() {
    printf("Welcome to the mailing list manager!\n");
    while (1) {
        printf("\nOptions:\n");
        printf("1. Add subscriber\n");
        printf("2. Send email\n");
        printf("3. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_subscriber();
                break;
            case 2:
                printf("Enter email subject: ");
                char subject[MAX_EMAIL_LENGTH];
                scanf("%s", subject);
                printf("Enter email body: ");
                char body[MAX_EMAIL_LENGTH];
                scanf("%s", body);
                send_email(subject, body);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}