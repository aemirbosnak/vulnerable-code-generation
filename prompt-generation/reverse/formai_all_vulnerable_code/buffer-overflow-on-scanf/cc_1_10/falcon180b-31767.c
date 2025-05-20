//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_EMAIL_LENGTH 100

// Subscriber structure
typedef struct {
    char name[MAX_EMAIL_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

// Function to add a subscriber
void addSubscriber(Subscriber *subscribers, int *numSubscribers) {
    printf("Enter name: ");
    scanf("%s", subscribers[*numSubscribers].name);
    printf("Enter email: ");
    scanf("%s", subscribers[*numSubscribers].email);

    (*numSubscribers)++;
}

// Function to delete a subscriber
void deleteSubscriber(Subscriber *subscribers, int *numSubscribers) {
    printf("Enter email to delete: ");
    char email[MAX_EMAIL_LENGTH];
    scanf("%s", email);

    for (int i = 0; i < *numSubscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            for (int j = i; j < *numSubscribers - 1; j++) {
                strcpy(subscribers[j].name, subscribers[j + 1].name);
                strcpy(subscribers[j].email, subscribers[j + 1].email);
            }
            (*numSubscribers)--;
            break;
        }
    }
}

// Function to send email to all subscribers
void sendEmail(Subscriber *subscribers, int numSubscribers) {
    printf("Enter email subject: ");
    char subject[MAX_EMAIL_LENGTH];
    scanf("%s", subject);

    printf("Enter email body: ");
    char body[MAX_EMAIL_LENGTH];
    scanf("%s", body);

    for (int i = 0; i < numSubscribers; i++) {
        printf("Sending email to %s (%s)...\n", subscribers[i].name, subscribers[i].email);
    }
}

// Main function
int main() {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int numSubscribers = 0;

    while (1) {
        printf("\n1. Add subscriber\n2. Delete subscriber\n3. Send email\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSubscriber(subscribers, &numSubscribers);
                break;
            case 2:
                deleteSubscriber(subscribers, &numSubscribers);
                break;
            case 3:
                sendEmail(subscribers, numSubscribers);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}