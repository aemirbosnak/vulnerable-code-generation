//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for each mailing list subscriber
typedef struct {
    char name[50];
    char email[100];
} Subscriber;

// Function to add a new subscriber to the mailing list
void addSubscriber(Subscriber *subscriberList, int *numSubscribers) {
    printf("Enter the name of the subscriber: ");
    scanf("%s", subscriberList[*numSubscribers].name);

    printf("Enter the email address of the subscriber: ");
    scanf("%s", subscriberList[*numSubscribers].email);

    (*numSubscribers)++;
}

// Function to remove a subscriber from the mailing list
void removeSubscriber(Subscriber *subscriberList, int *numSubscribers) {
    printf("Enter the name of the subscriber to remove: ");
    char nameToRemove[50];
    scanf("%s", nameToRemove);

    int i;
    for (i = 0; i < *numSubscribers; i++) {
        if (strcmp(subscriberList[i].name, nameToRemove) == 0) {
            // Shift all subscribers after the one being removed over by one
            memmove(&subscriberList[i], &subscriberList[i + 1], (*numSubscribers - i - 1) * sizeof(Subscriber));
            (*numSubscribers)--;
            break;
        }
    }
}

// Function to display the entire mailing list
void displayMailingList(Subscriber *subscriberList, int numSubscribers) {
    printf("Name\tEmail\n");
    printf("------------------------------------------------\n");

    int i;
    for (i = 0; i < numSubscribers; i++) {
        printf("%s\t%s\n", subscriberList[i].name, subscriberList[i].email);
    }
}

int main() {
    int numSubscribers = 0;
    Subscriber *subscriberList = (Subscriber *)malloc(numSubscribers * sizeof(Subscriber));

    // Initialize the mailing list with some subscribers
    addSubscriber(subscriberList, &numSubscribers);
    addSubscriber(subscriberList, &numSubscribers);
    addSubscriber(subscriberList, &numSubscribers);

    // Display the entire mailing list
    displayMailingList(subscriberList, numSubscribers);

    // Remove a subscriber from the mailing list
    removeSubscriber(subscriberList, &numSubscribers);

    // Display the updated mailing list
    displayMailingList(subscriberList, numSubscribers);

    return 0;
}