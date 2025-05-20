//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define MAX_EMAIL_LENGTH 50
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

int numSubscribers = 0;
Subscriber subscribers[MAX_SUBSCRIBERS];

void addSubscriber() {
    printf("Enter your name: ");
    scanf("%s", subscribers[numSubscribers].name);

    printf("Enter your email address: ");
    scanf("%s", subscribers[numSubscribers].email);

    numSubscribers++;
}

void removeSubscriber() {
    printf("Enter the name of the subscriber you want to remove: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    int i;
    for (i = 0; i < numSubscribers; i++) {
        if (strcmp(subscribers[i].name, name) == 0) {
            memmove(&subscribers[i], &subscribers[i+1], (numSubscribers - i - 1) * sizeof(Subscriber));
            numSubscribers--;
            break;
        }
    }
}

void sendEmailToAllSubscribers(char* message) {
    printf("Sending email to all %d subscribers...\n", numSubscribers);
    int i;
    for (i = 0; i < numSubscribers; i++) {
        printf("Sending email to %s (%s)...\n", subscribers[i].name, subscribers[i].email);
    }
}

int main() {
    int choice;
    do {
        printf("\nSherlock Holmes' Mailing List Manager\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Send email to all subscribers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSubscriber();
                break;
            case 2:
                removeSubscriber();
                break;
            case 3:
                printf("Enter the message you want to send: ");
                char message[1000];
                scanf("%s", message);
                sendEmailToAllSubscribers(message);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}