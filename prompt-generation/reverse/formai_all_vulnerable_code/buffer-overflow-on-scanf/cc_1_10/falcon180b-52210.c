//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 50
#define MAX_SUBJECT_LENGTH 100

typedef struct {
    char email[MAX_EMAIL_LENGTH];
    char name[MAX_NAME_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
} Subscriber;

Subscriber subscribers[100];
int num_subscribers = 0;

void add_subscriber(Subscriber* new_subscriber) {
    if (num_subscribers >= 100) {
        printf("Error: Maximum number of subscribers reached.\n");
        return;
    }

    strcpy(subscribers[num_subscribers].email, new_subscriber->email);
    strcpy(subscribers[num_subscribers].name, new_subscriber->name);
    strcpy(subscribers[num_subscribers].subject, new_subscriber->subject);

    num_subscribers++;
}

void send_email(Subscriber* subscriber, char* message) {
    printf("Sending email to %s (%s) about %s...\n", subscriber->name, subscriber->email, subscriber->subject);
}

int main() {
    Subscriber new_subscriber;

    while (1) {
        printf("Enter email address: ");
        scanf("%s", new_subscriber.email);

        printf("Enter name: ");
        scanf("%s", new_subscriber.name);

        printf("Enter subject of interest: ");
        scanf("%s", new_subscriber.subject);

        add_subscriber(&new_subscriber);
    }

    return 0;
}