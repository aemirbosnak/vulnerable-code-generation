//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_EMAIL_LENGTH 64
#define MAX_NAME_LENGTH 64

typedef struct subscriber {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers;

void add_subscriber(char* name, char* email) {
    if (num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Error: Maximum number of subscribers reached.\n");
        return;
    }

    strcpy(subscribers[num_subscribers].name, name);
    strcpy(subscribers[num_subscribers].email, email);
    num_subscribers++;
}

void remove_subscriber(char* email) {
    int i;

    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            memmove(&subscribers[i], &subscribers[i+1], sizeof(Subscriber) * (num_subscribers - i - 1));
            num_subscribers--;
            return;
        }
    }

    printf("Error: Subscriber not found.\n");
}

void send_email(char* name, char* email, char* message) {
    printf("Sending email to %s (%s)...\n", name, email);
}

void send_emails(char* message) {
    int i;

    for (i = 0; i < num_subscribers; i++) {
        send_email(subscribers[i].name, subscribers[i].email, message);
    }
}

int main() {
    char command[64];

    while (1) {
        printf("Enter command (add/remove/send): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char name[MAX_NAME_LENGTH];
            char email[MAX_EMAIL_LENGTH];

            printf("Enter name: ");
            scanf("%s", name);

            printf("Enter email: ");
            scanf("%s", email);

            add_subscriber(name, email);
        }
        else if (strcmp(command, "remove") == 0) {
            char email[MAX_EMAIL_LENGTH];

            printf("Enter email: ");
            scanf("%s", email);

            remove_subscriber(email);
        }
        else if (strcmp(command, "send") == 0) {
            char message[1024];

            printf("Enter message: ");
            fgets(message, 1024, stdin);

            send_emails(message);
        }
        else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}