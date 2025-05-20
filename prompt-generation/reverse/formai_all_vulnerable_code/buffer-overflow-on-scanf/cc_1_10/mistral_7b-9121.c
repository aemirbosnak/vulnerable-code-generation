//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: immersive
/*
 * Subscription Manager: A C Mailing List Manager
 *
 * This program allows users to subscribe, unsubscribe, and view the current list of subscribers for a mailing list.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SUBSCRIBERS 100

typedef struct Subscriber {
    char name[50];
    char email[100];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber(Subscriber new_subscriber) {
    if (num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Error: Mailing list is full.\n");
        return;
    }
    strcpy(subscribers[num_subscribers].name, new_subscriber.name);
    strcpy(subscribers[num_subscribers].email, new_subscriber.email);
    num_subscribers++;
}

void remove_subscriber(int index) {
    if (index < 0 || index >= num_subscribers) {
        printf("Error: Invalid index.\n");
        return;
    }
    memmove(&subscribers[index], &subscribers[index + 1], sizeof(Subscriber) * (num_subscribers - index - 1));
    num_subscribers--;
}

void view_subscribers() {
    if (num_subscribers == 0) {
        printf("Error: Mailing list is empty.\n");
        return;
    }
    for (int i = 0; i < num_subscribers; i++) {
        printf("%s (%s)\n", subscribers[i].name, subscribers[i].email);
    }
}

int main() {
    int choice;
    Subscriber new_subscriber;
    char name[50], email[100];

    while (true) {
        printf("\nSubscription Manager\n");
        printf("1. Subscribe\n");
        printf("2. Unsubscribe\n");
        printf("3. View Subscribers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your name: ");
                scanf("%s", name);
                printf("Enter your email: ");
                scanf("%s", email);
                new_subscriber = (Subscriber) { .name = name, .email = email };
                add_subscriber(new_subscriber);
                printf("You have been subscribed to the mailing list.\n");
                break;
            case 2:
                printf("Enter the index of the subscriber to unsubscribe: ");
                int index;
                scanf("%d", &index);
                remove_subscriber(index);
                printf("The subscriber has been unsubscribed.\n");
                break;
            case 3:
                view_subscribers();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}