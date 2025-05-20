//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char email[MAX_EMAIL_LENGTH];
    char name[MAX_EMAIL_LENGTH];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber(Subscriber* subscriber) {
    if (num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Error: Maximum number of subscribers reached.\n");
        return;
    }

    strcpy(subscribers[num_subscribers].email, subscriber->email);
    strcpy(subscribers[num_subscribers].name, subscriber->name);

    num_subscribers++;
}

void remove_subscriber(char* email) {
    int i;

    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            num_subscribers--;

            memmove(&subscribers[i], &subscribers[i+1], (num_subscribers - i - 1) * sizeof(Subscriber));

            break;
        }
    }
}

void send_email(char* email, char* subject, char* message) {
    printf("Sending email to %s...\n", email);
}

void send_emails(char* subject, char* message) {
    int i;

    for (i = 0; i < num_subscribers; i++) {
        send_email(subscribers[i].email, subject, message);
    }
}

int main() {
    Subscriber new_subscriber;

    printf("Enter email address: ");
    scanf("%s", new_subscriber.email);

    printf("Enter name: ");
    scanf("%s", new_subscriber.name);

    add_subscriber(&new_subscriber);

    send_emails("Welcome to the mailing list!", "Thank you for subscribing!");

    remove_subscriber(new_subscriber.email);

    send_emails("Goodbye!", "You have been removed from the mailing list.");

    return 0;
}