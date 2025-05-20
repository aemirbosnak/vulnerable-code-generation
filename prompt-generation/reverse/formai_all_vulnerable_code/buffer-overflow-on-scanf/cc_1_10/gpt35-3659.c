//FormAI DATASET v1.0 Category: Mailing list manager ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBSCRIBERS 1000

typedef struct subscriber {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void addSubscriber() {
    if (num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Maximum number of subscribers reached.\n");
        return;
    }
    Subscriber new_subscriber;
    printf("Enter name: ");
    fgets(new_subscriber.name, MAX_NAME_LENGTH, stdin);
    printf("Enter email: ");
    fgets(new_subscriber.email, MAX_EMAIL_LENGTH, stdin);
    subscribers[num_subscribers] = new_subscriber;
    num_subscribers++;
}

void displaySubscribers() {
    printf("Subscribers:\n");
    for (int i = 0; i < num_subscribers; i++) {
        printf("%d. Name: %sEmail: %s\n", i + 1, subscribers[i].name, subscribers[i].email);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nMenu\n");
        printf("1. Add subscriber\n2. Display subscribers\n3. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline
        switch (choice) {
            case 1:
                addSubscriber();
                break;
            case 2:
                displaySubscribers();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}