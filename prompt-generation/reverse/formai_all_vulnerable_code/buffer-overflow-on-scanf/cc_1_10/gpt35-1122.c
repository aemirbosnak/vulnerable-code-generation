//FormAI DATASET v1.0 Category: Mailing list manager ; Style: realistic
// A unique mailing list manager program in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers and the maximum length of each name and email address.
#define MAX_SUBSCRIBERS 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50

// Declare a structure to hold subscriber information.
typedef struct subscriber {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

// Declare a function to add a new subscriber to the list.
void addSubscriber(Subscriber *list, int *numSubscribers) {
    // Check if the list is full.
    if (*numSubscribers >= MAX_SUBSCRIBERS) {
        printf("Error: The mailing list is full.\n");
        return;
    }

    // Get the subscriber's name and email address.
    printf("Enter subscriber's name: ");
    scanf("%s", list[*numSubscribers].name);
    printf("Enter subscriber's email address: ");
    scanf("%s", list[*numSubscribers].email);

    // Increment the number of subscribers.
    (*numSubscribers)++;
}

// Declare a function to remove a subscriber from the list.
void removeSubscriber(Subscriber *list, int *numSubscribers) {
    // Get the subscriber's email address to remove.
    char emailToRemove[MAX_EMAIL_LENGTH];
    printf("Enter email address to remove: ");
    scanf("%s", emailToRemove);

    // Find the subscriber with the matching email address and remove them.
    int i;
    for (i = 0; i < *numSubscribers; i++) {
        if (strcmp(list[i].email, emailToRemove) == 0) {
            // Shift all subscribers after the removed subscriber back by one.
            int j;
            for (j = i; j < *numSubscribers-1; j++) {
                strcpy(list[j].name, list[j+1].name);
                strcpy(list[j].email, list[j+1].email);
            }

            // Decrement the number of subscribers.
            (*numSubscribers)--;
            printf("Subscriber with email address %s removed.\n", emailToRemove);
            return;
        }
    }

    printf("Error: Subscriber with email address %s not found.\n", emailToRemove);
}

// Declare a function to print the list of subscribers.
void printList(Subscriber *list, int numSubscribers) {
    printf("Mailing list:\n");
    int i;
    for (i = 0; i < numSubscribers; i++) {
        printf("%s <%s>\n", list[i].name, list[i].email);
    }
}

int main() {
    Subscriber mailingList[MAX_SUBSCRIBERS];
    int numSubscribers = 0;
    int menuChoice;

    // Print the menu and allow the user to select an option until they choose to exit.
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Print list\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &menuChoice);

        switch (menuChoice) {
            case 1:
                addSubscriber(mailingList, &numSubscribers);
                break;
            case 2:
                removeSubscriber(mailingList, &numSubscribers);
                break;
            case 3:
                printList(mailingList, numSubscribers);
                break;
            case 4:
                printf("Exiting.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}