//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

struct subscriber {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

struct message {
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
};

void add_subscriber(struct subscriber *subscribers, int num_subscribers, char *name, char *email) {
    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].name, name) == 0) {
            strcpy(subscribers[i].email, email);
            return;
        }
    }
    strcpy(subscribers[num_subscribers].name, name);
    strcpy(subscribers[num_subscribers].email, email);
    num_subscribers++;
}

void send_message(struct subscriber *subscribers, int num_subscribers, char *subject, char *message) {
    int i;
    for (i = 0; i < num_subscribers; i++) {
        printf("Sending message to %s (%s)\n", subscribers[i].name, subscribers[i].email);
    }
}

int main() {
    struct subscriber subscribers[100];
    int num_subscribers = 0;
    char input[100];

    while (true) {
        printf("Enter command (add/send/exit): ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            printf("Enter name: ");
            scanf("%s", input);
            printf("Enter email: ");
            scanf("%s", input);
            add_subscriber(subscribers, num_subscribers, input, input);
        } else if (strcmp(input, "send") == 0) {
            printf("Enter subject: ");
            scanf("%s", input);
            printf("Enter message: ");
            scanf("%s", input);
            send_message(subscribers, num_subscribers, input, input);
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}