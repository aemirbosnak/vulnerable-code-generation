//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 1000
#define SUBSCRIBER_NAME_LENGTH 50

typedef struct {
    char name[SUBSCRIBER_NAME_LENGTH];
    int is_subscribed;
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber(char *name) {
    if (num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Mailing list is full.\n");
        return;
    }

    strcpy(subscribers[num_subscribers].name, name);
    subscribers[num_subscribers].is_subscribed = 1;
    num_subscribers++;
}

void remove_subscriber(char *name) {
    int i;

    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].name, name) == 0) {
            subscribers[i].is_subscribed = 0;
            num_subscribers--;
            i--; // adjust for array size
        }
    }
}

void print_subscribers() {
    int i;

    printf("Subscribers:\n");

    for (i = 0; i < num_subscribers; i++) {
        if (subscribers[i].is_subscribed) {
            printf("%s\n", subscribers[i].name);
        }
    }
}

int main() {
    char command[20], name[SUBSCRIBER_NAME_LENGTH];
    int choice;

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Print subscribers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%s", command);

        if (strcmp(command, "1") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            add_subscriber(name);
        } else if (strcmp(command, "2") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            remove_subscriber(name);
        } else if (strcmp(command, "3") == 0) {
            print_subscribers();
        } else if (strcmp(command, "4") == 0) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}