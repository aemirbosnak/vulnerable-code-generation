//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define MAX_EMAIL_LENGTH 50
#define SUBJECT_LENGTH 100
#define BODY_LENGTH 1000

typedef struct subscriber {
    char name[MAX_EMAIL_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers;

void add_subscriber() {
    printf("Enter name: ");
    scanf("%s", subscribers[num_subscribers].name);
    printf("Enter email: ");
    scanf("%s", subscribers[num_subscribers].email);
    num_subscribers++;
}

void send_email(Subscriber* subscriber, char* subject, char* body) {
    printf("Sending email to %s (%s)\n", subscriber->name, subscriber->email);
}

void send_emails() {
    for (int i = 0; i < num_subscribers; i++) {
        send_email(&subscribers[i], "Test Subject", "Test Body");
    }
}

int main() {
    num_subscribers = 0;

    while (num_subscribers < MAX_SUBSCRIBERS) {
        printf("1. Add Subscriber\n2. Send Emails\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_subscriber();
                break;
            case 2:
                send_emails();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}