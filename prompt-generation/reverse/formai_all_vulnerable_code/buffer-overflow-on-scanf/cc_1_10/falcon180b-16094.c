//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Define the structure of a subscriber
typedef struct {
    char name[50];
    char email[100];
} Subscriber;

// Function to add a new subscriber
void addSubscriber(Subscriber* subscribers, int numSubscribers) {
    Subscriber newSubscriber;
    printf("Enter the name of the new subscriber: ");
    scanf("%s", newSubscriber.name);
    printf("Enter the email of the new subscriber: ");
    scanf("%s", newSubscriber.email);

    // Check if there is space for a new subscriber
    if(numSubscribers >= MAX_SUBSCRIBERS) {
        printf("Error: Maximum number of subscribers reached\n");
        return;
    }

    // Add the new subscriber to the list
    subscribers[numSubscribers] = newSubscriber;
    numSubscribers++;
}

// Function to remove a subscriber
void removeSubscriber(Subscriber* subscribers, int numSubscribers) {
    char name[50];
    printf("Enter the name of the subscriber to remove: ");
    scanf("%s", name);

    // Search for the subscriber to remove
    int i;
    for(i = 0; i < numSubscribers; i++) {
        if(strcmp(subscribers[i].name, name) == 0) {
            // Remove the subscriber from the list
            int j;
            for(j = i; j < numSubscribers - 1; j++) {
                subscribers[j] = subscribers[j + 1];
            }
            numSubscribers--;
            break;
        }
    }
}

// Function to display the list of subscribers
void displaySubscribers(Subscriber* subscribers, int numSubscribers) {
    printf("List of subscribers:\n");
    printf("-------------------------------------------------\n");
    printf("Name\t\tEmail\n");
    printf("-------------------------------------------------\n");
    int i;
    for(i = 0; i < numSubscribers; i++) {
        printf("%s\t\t%s\n", subscribers[i].name, subscribers[i].email);
    }
}

// Main function
int main() {
    // Initialize the list of subscribers
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int numSubscribers = 0;

    // Add some initial subscribers
    addSubscriber(subscribers, numSubscribers);
    addSubscriber(subscribers, numSubscribers);
    addSubscriber(subscribers, numSubscribers);

    // Display the list of subscribers
    displaySubscribers(subscribers, numSubscribers);

    // Remove a subscriber
    removeSubscriber(subscribers, numSubscribers);

    // Display the updated list of subscribers
    displaySubscribers(subscribers, numSubscribers);

    return 0;
}