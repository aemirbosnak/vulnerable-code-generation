//FormAI DATASET v1.0 Category: Mailing list manager ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
/* Maximum number of subscribers */
#define MAX_SUBSCRIBERS 10

/* Subscriber structure */
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
} Subscriber;

/* Function prototypes */
int addSubscriber(Subscriber* subscribers, int* numSubscribers);
int removeSubscriber(Subscriber* subscribers, int* numSubscribers);
void printSubscribers(Subscriber* subscribers, int numSubscribers);

int main() {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int numSubscribers = 0;
    int choice = -1;

    // Main menu
    while (choice != 0) {
        printf("\nMain Menu:\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. Print Subscribers\n");
        printf("0. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSubscriber(subscribers, &numSubscribers);
                break;
            case 2:
                removeSubscriber(subscribers, &numSubscribers);
                break;
            case 3:
                printSubscribers(subscribers, numSubscribers);
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

/* Add a new subscriber */
int addSubscriber(Subscriber* subscribers, int* numSubscribers) {
    if (*numSubscribers == MAX_SUBSCRIBERS) {
        printf("Error: Maximum number of subscribers reached.\n");
        return -1;
    }

    Subscriber newSubscriber;

    printf("\nEnter subscriber name: ");
    scanf("%s", newSubscriber.name);
    printf("Enter subscriber email: ");
    scanf("%s", newSubscriber.email);

    subscribers[*numSubscribers] = newSubscriber;
    (*numSubscribers)++;

    printf("Subscriber added successfully.\n");

    return 0;
}

/* Remove a subscriber */
int removeSubscriber(Subscriber* subscribers, int* numSubscribers) {
    if (*numSubscribers == 0) {
        printf("Error: No subscribers to remove.\n");
        return -1;
    }

    int indexToRemove = -1;
    char nameToRemove[MAX_NAME_LENGTH];

    printf("\nEnter subscriber name to remove: ");
    scanf("%s", nameToRemove);

    // Find the index of the subscriber with the given name
    for (int i = 0; i < *numSubscribers; i++) {
        if (strcmp(nameToRemove, subscribers[i].name) == 0) {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove == -1) {
        printf("Error: Subscriber not found.\n");
        return -1;
    }

    // Remove the subscriber by shifting the remaining subscribers to fill the gap
    for (int i = indexToRemove; i < *numSubscribers - 1; i++) {
        subscribers[i] = subscribers[i+1];
    }

    (*numSubscribers)--;

    printf("Subscriber removed successfully.\n");

    return 0;
}

/* Print all subscribers */
void printSubscribers(Subscriber* subscribers, int numSubscribers) {
    printf("\nSubscribers:\n");
    for (int i = 0; i < numSubscribers; i++) {
        printf("%s <%s>\n", subscribers[i].name, subscribers[i].email);
    }
}