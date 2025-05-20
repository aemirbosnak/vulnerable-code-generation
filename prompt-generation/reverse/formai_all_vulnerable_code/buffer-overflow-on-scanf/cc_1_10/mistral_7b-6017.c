//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SUBSCRIBERS 1000
#define SUBSCRIBER_NAME_LENGTH 50
#define SUBSCRIBER_EMAIL_LENGTH 100

typedef struct Subscriber {
    char name[SUBSCRIBER_NAME_LENGTH];
    char email[SUBSCRIBER_EMAIL_LENGTH];
    struct Subscriber *next;
} Subscriber;

Subscriber *subscribers = NULL;
Subscriber *current = NULL;

void add_subscriber(char *name, char *email) {
    Subscriber *new_subscriber = (Subscriber *)malloc(sizeof(Subscriber));

    strcpy(new_subscriber->name, name);
    strcpy(new_subscriber->email, email);
    new_subscriber->next = NULL;

    if (subscribers == NULL) {
        subscribers = new_subscriber;
        current = subscribers;
    } else {
        current->next = new_subscriber;
        current = new_subscriber;
    }
}

void remove_subscriber(char *email) {
    Subscriber *previous = NULL;
    Subscriber *current = subscribers;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL) {
                subscribers = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Subscriber not found.\n");
}

void display_subscribers() {
    Subscriber *current = subscribers;

    printf("Subscribers:\n");
    while (current != NULL) {
        printf("%s (%s)\n", current->name, current->email);
        current = current->next;
    }
}

int main() {
    char name[SUBSCRIBER_NAME_LENGTH];
    char email[SUBSCRIBER_EMAIL_LENGTH];
    char command[10];

    while (true) {
        printf("\nmailman> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Name: ");
            scanf("%s", name);
            printf("Email: ");
            scanf("%s", email);
            add_subscriber(name, email);
        } else if (strcmp(command, "remove") == 0) {
            printf("Email: ");
            scanf("%s", email);
            remove_subscriber(email);
        } else if (strcmp(command, "display") == 0) {
            display_subscribers();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}