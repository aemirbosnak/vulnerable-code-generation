//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char email[MAX_EMAIL_LENGTH];
    char name[MAX_EMAIL_LENGTH];
} subscriber;

int num_subscribers = 0;
subscriber subscribers[MAX_SUBSCRIBERS];

void add_subscriber(char* email, char* name) {
    if (num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Error: Maximum number of subscribers reached.\n");
        return;
    }

    strcpy(subscribers[num_subscribers].email, email);
    strcpy(subscribers[num_subscribers].name, name);

    num_subscribers++;
}

void remove_subscriber(char* email) {
    int i;

    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            num_subscribers--;
            break;
        }
    }
}

void send_email(char* subject, char* body, char* from) {
    int i;

    printf("Sending email to %d subscribers...\n", num_subscribers);

    for (i = 0; i < num_subscribers; i++) {
        printf("Sending email to %s (%s)...\n", subscribers[i].name, subscribers[i].email);
    }
}

int main() {
    char command[MAX_EMAIL_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char name[MAX_EMAIL_LENGTH];
    char subject[MAX_EMAIL_LENGTH];
    char body[MAX_EMAIL_LENGTH];
    char from[MAX_EMAIL_LENGTH];

    while (1) {
        printf("Enter command (add, remove, send): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter email: ");
            scanf("%s", email);

            printf("Enter name: ");
            scanf("%s", name);

            add_subscriber(email, name);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter email: ");
            scanf("%s", email);

            remove_subscriber(email);
        } else if (strcmp(command, "send") == 0) {
            printf("Enter subject: ");
            scanf("%s", subject);

            printf("Enter body: ");
            scanf("%s", body);

            printf("Enter from: ");
            scanf("%s", from);

            send_email(subject, body, from);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}