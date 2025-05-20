//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Define structure for subscriber information
typedef struct {
    char name[50];
    char email[100];
} Subscriber;

// Function to add a new subscriber
void addSubscriber(Subscriber* subscribers, int numSubscribers) {
    printf("Enter name: ");
    scanf("%s", subscribers[numSubscribers].name);

    printf("Enter email: ");
    scanf("%s", subscribers[numSubscribers].email);

    numSubscribers++;
}

// Function to remove a subscriber by email
void removeSubscriber(Subscriber* subscribers, int numSubscribers, char* email) {
    int i;
    for (i = 0; i < numSubscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            memmove(&subscribers[i], &subscribers[i+1], sizeof(Subscriber) * (numSubscribers - i - 1));
            numSubscribers--;
            break;
        }
    }
}

// Function to send message to all subscribers
void sendMessage(Subscriber* subscribers, int numSubscribers, char* message) {
    printf("Sending message...\n");
    int i;
    for (i = 0; i < numSubscribers; i++) {
        printf("Sending to %s (%s)...\n", subscribers[i].name, subscribers[i].email);
    }
}

// Main function
int main() {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int numSubscribers = 0;

    // Initialize subscribers
    strcpy(subscribers[numSubscribers].name, "Sherlock Holmes");
    strcpy(subscribers[numSubscribers].email, "sherlock@holmes.com");
    numSubscribers++;

    strcpy(subscribers[numSubscribers].name, "Dr. John Watson");
    strcpy(subscribers[numSubscribers].email, "john@watson.com");
    numSubscribers++;

    // Add new subscriber
    addSubscriber(subscribers, numSubscribers);

    // Remove subscriber by email
    removeSubscriber(subscribers, numSubscribers, "sherlock@holmes.com");

    // Send message to all subscribers
    sendMessage(subscribers, numSubscribers, "The game is afoot!");

    return 0;
}