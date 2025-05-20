//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define MAX_EMAIL_LENGTH 100

typedef struct subscriber_info {
    char email[MAX_EMAIL_LENGTH];
    int subscribed;
} SubscriberInfo;

SubscriberInfo subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber(SubscriberInfo* subscriber) {
    if (num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Mailing list is full.\n");
        return;
    }
    subscriber->subscribed = 1;
    strcpy(subscriber->email, "new_subscriber@example.com");
    printf("New subscriber added.\n");
    num_subscribers++;
}

void remove_subscriber(int index) {
    if (index < 0 || index >= num_subscribers) {
        printf("Invalid subscriber index.\n");
        return;
    }
    printf("Removing subscriber %d...\n", index);
    memset(&subscribers[index], 0, sizeof(SubscriberInfo));
    num_subscribers--;
}

void display_subscribers() {
    printf("Subscribers:\n");
    for (int i = 0; i < num_subscribers; i++) {
        printf("%d. %s\n", i+1, subscribers[i].email);
    }
}

void main() {
    int choice, subscriber_index;
    SubscriberInfo subscriber;

    printf("Welcome to the Mailing List Manager!\n");
    printf("1. Add subscriber\n");
    printf("2. Remove subscriber\n");
    printf("3. Display subscribers\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter subscriber email: ");
            scanf("%s", subscriber.email);
            add_subscriber(&subscriber);
            break;
        case 2:
            printf("Enter subscriber index: ");
            scanf("%d", &subscriber_index);
            remove_subscriber(subscriber_index - 1);
            break;
        case 3:
            display_subscribers();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
            break;
    }
}