//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_EMAIL_LEN 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Subscriber;

int num_subscribers = 0;
Subscriber *subscribers = NULL;

void add_subscriber(Subscriber *new_subscriber) {
    subscribers = realloc(subscribers, sizeof(Subscriber) * (num_subscribers + 1));
    memcpy(&subscribers[num_subscribers], new_subscriber, sizeof(Subscriber));
    num_subscribers++;
}

void print_subscribers() {
    for (int i = 0; i < num_subscribers; i++) {
        printf("%s (%s)\n", subscribers[i].name, subscribers[i].email);
    }
}

void send_email(char *subject, char *body, Subscriber *recipient) {
    printf("Sending email to %s (%s)\nSubject: %s\nBody:\n%s\n", recipient->name, recipient->email, subject, body);
}

int main() {
    char input[MAX_EMAIL_LEN];
    Subscriber new_subscriber;

    while (1) {
        printf("Enter an email address to subscribe (or type 'list' to view subscribers):\n");
        scanf("%s", input);

        if (strcmp(input, "list") == 0) {
            print_subscribers();
        } else {
            strcpy(new_subscriber.email, input);
            printf("Enter your name:\n");
            scanf("%s", new_subscriber.name);
            add_subscriber(&new_subscriber);
            printf("Welcome to the mailing list, %s!\n", new_subscriber.name);
        }
    }

    return 0;
}