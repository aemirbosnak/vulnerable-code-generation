//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char email[MAX_EMAIL_LENGTH];
    int subscribed;
} Subscriber;

Subscriber subscribers[MAX_EMAILS];
int num_subscribers = 0;

void add_subscriber(char* email) {
    if (num_subscribers >= MAX_EMAILS) {
        printf("Error: Too many subscribers\n");
        return;
    }

    strcpy(subscribers[num_subscribers].email, email);
    subscribers[num_subscribers].subscribed = 1;
    num_subscribers++;
}

void remove_subscriber(char* email) {
    int i;

    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            subscribers[i].subscribed = 0;
            return;
        }
    }

    printf("Error: Subscriber not found\n");
}

void send_email(char* email, char* message) {
    int i;

    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0 && subscribers[i].subscribed) {
            printf("Sending email to %s...\n", email);
        }
    }
}

int main() {
    char email[MAX_EMAIL_LENGTH];
    char message[MAX_EMAIL_LENGTH];

    while (1) {
        printf("Enter email address: ");
        scanf("%s", email);

        if (strcmp(email, "add") == 0) {
            printf("Enter email address to add: ");
            scanf("%s", email);
            add_subscriber(email);
        } else if (strcmp(email, "remove") == 0) {
            printf("Enter email address to remove: ");
            scanf("%s", email);
            remove_subscriber(email);
        } else if (strcmp(email, "send") == 0) {
            printf("Enter message: ");
            scanf("%s", message);
            send_email(email, message);
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}