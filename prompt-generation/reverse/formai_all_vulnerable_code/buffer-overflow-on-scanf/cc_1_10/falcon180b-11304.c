//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for storing subscriber info
typedef struct {
    char name[50];
    char email[100];
} Subscriber;

// Function for adding a new subscriber
void addSubscriber(Subscriber *subscribers, int *numSubscribers) {
    printf("Enter name: ");
    scanf("%s", subscribers[*numSubscribers].name);

    printf("Enter email: ");
    scanf("%s", subscribers[*numSubscribers].email);

    (*numSubscribers)++;
}

// Function for displaying all subscribers
void displaySubscribers(Subscriber *subscribers, int numSubscribers) {
    printf("Name\tEmail\n");
    for (int i = 0; i < numSubscribers; i++) {
        printf("%s\t%s\n", subscribers[i].name, subscribers[i].email);
    }
}

// Function for sending an email to all subscribers
void sendEmail(Subscriber *subscribers, int numSubscribers, char *subject, char *message) {
    for (int i = 0; i < numSubscribers; i++) {
        printf("Sending email to %s...\n", subscribers[i].email);
        // Code for sending email
    }
}

int main() {
    int numSubscribers = 0;
    Subscriber subscribers[100];

    // Add some subscribers
    addSubscriber(subscribers, &numSubscribers);
    addSubscriber(subscribers, &numSubscribers);
    addSubscriber(subscribers, &numSubscribers);

    // Display all subscribers
    displaySubscribers(subscribers, numSubscribers);

    // Send an email to all subscribers
    char subject[100] = "Test Email";
    char message[500] = "Hello,\n\nThis is a test email sent using the mailing list manager program.\n\nBest regards,\nThe Programmer";
    sendEmail(subscribers, numSubscribers, subject, message);

    return 0;
}