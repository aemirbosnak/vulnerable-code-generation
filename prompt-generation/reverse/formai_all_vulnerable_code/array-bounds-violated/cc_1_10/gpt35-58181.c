//FormAI DATASET v1.0 Category: Mailing list manager ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of allowed subscribers
#define MAX_SUBSCRIBERS 100

// Subscriber struct
typedef struct {
    char name[50];
    char email[100];
} Subscriber;

// Global array to store subscribers
Subscriber subscriberList[MAX_SUBSCRIBERS];
int totalSubscribers = 0;

// Add new subscriber to the list
void subscribe() {
    Subscriber newSubscriber;

    printf("\nWelcome to our newsletter mailing list! Please enter your details below:\n");
    printf("Name: ");
    fgets(newSubscriber.name, sizeof(newSubscriber.name), stdin);
    printf("Email: ");
    fgets(newSubscriber.email, sizeof(newSubscriber.email), stdin);

    // Remove newline character from input
    strtok(newSubscriber.name, "\n");
    strtok(newSubscriber.email, "\n");

    subscriberList[totalSubscribers] = newSubscriber;
    totalSubscribers++;

    printf("\nThank you for subscribing!\n");
}

// Remove a subscriber from the list
void unsubscribe() {
    int subscriberIndex;

    printf("\nEnter the email address of the subscriber you wish to unsubscribe:\n");
    char email[100];
    fgets(email, sizeof(email), stdin);
    strtok(email, "\n");

    for (int i = 0; i < totalSubscribers; i++) {
        if (strcmp(subscriberList[i].email, email) == 0) {
            subscriberIndex = i;
            break;
        }
    }

    // Shift elements in the subscriber list to remove unsubscribed subscriber
    for (int i = subscriberIndex; i < totalSubscribers - 1; i++) {
        subscriberList[i] = subscriberList[i + 1];
    }

    totalSubscribers--;

    printf("\n%s has been unsubscribed from the mailing list.\n", email);
}

// Print all subscribers in the list
void printSubscribers() {
    printf("\nCurrent subscribers:\n\n");

    for (int i = 0; i < totalSubscribers; i++) {
        printf("Name: %s \tEmail: %s \n", subscriberList[i].name, subscriberList[i].email);
    }
}

int main() {
    int choice;

    printf("Welcome to our mailing list manager!\n");

    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Subscribe to the mailing list\n");
        printf("2. Unsubscribe from the mailing list\n");
        printf("3. View current subscribers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                subscribe();
                break;
            case 2:
                unsubscribe();
                break;
            case 3:
                printSubscribers();
                break;
            case 4:
                printf("\nThank you for using our mailing list manager. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}