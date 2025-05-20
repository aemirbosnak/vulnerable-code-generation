//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_EMAIL_LENGTH 50
#define MAX_NAME_LENGTH 30

// Subscriber struct
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

// Function prototypes
void addSubscriber(Subscriber* subscribers, int numSubscribers);
void removeSubscriber(Subscriber* subscribers, int numSubscribers);
void sendEmail(Subscriber* subscribers, int numSubscribers, char* subject, char* message);

int main() {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int numSubscribers = 0;

    // Initialize with default values
    strcpy(subscribers[0].name, "John Doe");
    strcpy(subscribers[0].email, "johndoe@example.com");
    numSubscribers++;

    // Add more subscribers
    addSubscriber(subscribers, numSubscribers);
    addSubscriber(subscribers, numSubscribers);

    // Remove a subscriber
    removeSubscriber(subscribers, numSubscribers);

    // Send an email
    sendEmail(subscribers, numSubscribers, "Test Email", "Hello, world!");

    return 0;
}

// Add a subscriber
void addSubscriber(Subscriber* subscribers, int numSubscribers) {
    printf("Enter name: ");
    scanf("%s", subscribers[numSubscribers].name);

    printf("Enter email: ");
    scanf("%s", subscribers[numSubscribers].email);

    numSubscribers++;
}

// Remove a subscriber
void removeSubscriber(Subscriber* subscribers, int numSubscribers) {
    printf("Enter email to remove: ");
    scanf("%s", subscribers[0].email);

    for (int i = 1; i < numSubscribers; i++) {
        if (strcmp(subscribers[i].email, subscribers[0].email) == 0) {
            strcpy(subscribers[i - 1].email, subscribers[i].email);
            strcpy(subscribers[i - 1].name, subscribers[i].name);
        }
    }

    numSubscribers--;
}

// Send an email to all subscribers
void sendEmail(Subscriber* subscribers, int numSubscribers, char* subject, char* message) {
    printf("Sending email to %d subscribers:\n", numSubscribers);

    for (int i = 0; i < numSubscribers; i++) {
        printf("Name: %s\nEmail: %s\n", subscribers[i].name, subscribers[i].email);
    }
}