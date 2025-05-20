//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define MAX_MESSAGE_LENGTH 1024

typedef struct {
    char name[64];
    char email[128];
    int subscribed;
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber(char *name, char *email) {
    if (num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Error: too many subscribers.\n");
        return;
    }

    strcpy(subscribers[num_subscribers].name, name);
    strcpy(subscribers[num_subscribers].email, email);
    subscribers[num_subscribers].subscribed = 1;
    num_subscribers++;
}

void remove_subscriber(char *email) {
    int i;

    for (i = 0; i < num_subscribers; i++) {
        if (!strcmp(subscribers[i].email, email)) {
            subscribers[i].subscribed = 0;
            break;
        }
    }
}

void send_message(char *subject, char *message) {
    int i;

    for (i = 0; i < num_subscribers; i++) {
        if (subscribers[i].subscribed) {
            sprintf(message, "To: %s\r\nSubject: %s\r\n\r\n%s", subscribers[i].email, subject, message);
            system(message);
        }
    }
}

int main() {
    int choice;
    char name[64];
    char email[128];
    char message[MAX_MESSAGE_LENGTH];

    printf("Cyberpunk Mailing List Manager\n");
    printf("---------------------------------\n");

    while (1) {
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Send message\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter email: ");
            scanf("%s", email);
            add_subscriber(name, email);
            break;

        case 2:
            printf("Enter email: ");
            scanf("%s", email);
            remove_subscriber(email);
            break;

        case 3:
            printf("Enter subject: ");
            scanf("%s", message);
            printf("Enter message: ");
            scanf("%s", message + strlen(message));
            send_message(message, message + strlen(message));
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}