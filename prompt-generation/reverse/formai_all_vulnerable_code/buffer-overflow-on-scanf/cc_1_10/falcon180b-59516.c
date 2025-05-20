//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define MAX_EMAIL_LENGTH 50
#define MAX_NAME_LENGTH 30

// Subscriber data structure
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

// Function prototypes
void addSubscriber(Subscriber* subscribers, int numSubscribers);
void deleteSubscriber(Subscriber* subscribers, int numSubscribers);
void sendEmail(Subscriber* subscribers, int numSubscribers);

int main() {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int numSubscribers = 0;

    // Initialize with some subscribers
    strcpy(subscribers[0].name, "John Doe");
    strcpy(subscribers[0].email, "johndoe@example.com");
    numSubscribers++;

    strcpy(subscribers[1].name, "Jane Smith");
    strcpy(subscribers[1].email, "janesmith@example.com");
    numSubscribers++;

    // Add a new subscriber
    addSubscriber(subscribers, numSubscribers);

    // Delete a subscriber
    deleteSubscriber(subscribers, numSubscribers);

    // Send an email to all subscribers
    sendEmail(subscribers, numSubscribers);

    return 0;
}

void addSubscriber(Subscriber* subscribers, int numSubscribers) {
    printf("Enter the name of the new subscriber: ");
    scanf("%s", subscribers[numSubscribers].name);

    printf("Enter the email of the new subscriber: ");
    scanf("%s", subscribers[numSubscribers].email);

    numSubscribers++;
}

void deleteSubscriber(Subscriber* subscribers, int numSubscribers) {
    printf("Enter the name of the subscriber to delete: ");
    scanf("%s", subscribers[numSubscribers - 1].name);

    numSubscribers--;
}

void sendEmail(Subscriber* subscribers, int numSubscribers) {
    printf("Sending email to %d subscribers...\n", numSubscribers);
    for (int i = 0; i < numSubscribers; i++) {
        printf("Sending email to %s (%s)\n", subscribers[i].name, subscribers[i].email);
    }
}