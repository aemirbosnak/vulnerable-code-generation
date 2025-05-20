//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of mailing list subscribers
#define MAX_SUBSCRIBERS 100

// Define the structure of a mailing list subscriber
typedef struct Subscriber {
    char name[50];
    char email[50];
    struct Subscriber* next;
} Subscriber;

// Create a function to add a subscriber to the mailing list
void addSubscriber(Subscriber* head) {
    // Allocate memory for a new subscriber
    Subscriber* newSubscriber = (Subscriber*)malloc(sizeof(Subscriber));

    // Get the subscriber's name and email address
    printf("Enter your name: ");
    scanf("%s", newSubscriber->name);

    printf("Enter your email address: ");
    scanf("%s", newSubscriber->email);

    // Add the new subscriber to the list
    if (head == NULL) {
        head = newSubscriber;
    } else {
        head->next = newSubscriber;
    }

    // Print a confirmation message
    printf("Thank you for subscribing to our mailing list, %s!\n", newSubscriber->name);
}

// Create a function to print the subscribers on the mailing list
void printSubscribers(Subscriber* head) {
    // Iterate over the list of subscribers
    Subscriber* currentSubscriber = head;
    while (currentSubscriber) {
        // Print the subscriber's name and email address
        printf("%s (%s)\n", currentSubscriber->name, currentSubscriber->email);
        currentSubscriber = currentSubscriber->next;
    }
}

// Main function
int main() {
    // Create a head of the mailing list
    Subscriber* head = NULL;

    // Add some subscribers to the list
    addSubscriber(head);
    addSubscriber(head);
    addSubscriber(head);

    // Print the subscribers on the list
    printSubscribers(head);

    return 0;
}