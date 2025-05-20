//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_EMAILS 1000
#define MAX_NAME 100

typedef struct subscriber {
    char name[MAX_NAME];
    char email[MAX_EMAILS];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

// Function to add a new subscriber
void add_subscriber() {
    if (num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Error: Maximum number of subscribers reached.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", subscribers[num_subscribers].name);

    printf("Enter email: ");
    scanf("%s", subscribers[num_subscribers].email);

    num_subscribers++;

    printf("Subscriber added successfully.\n");
}

// Function to send an email to all subscribers
void send_email() {
    if (num_subscribers == 0) {
        printf("Error: No subscribers found.\n");
        return;
    }

    printf("Enter subject: ");
    char subject[MAX_EMAILS];
    scanf("%s", subject);

    printf("Enter message: ");
    char message[MAX_EMAILS];
    scanf("%s", message);

    for (int i = 0; i < num_subscribers; i++) {
        sprintf(message, "Dear %s,\n\n%s\n\nSincerely,\nThe Peaceful Programmer", subscribers[i].name, message);
        printf("Sending email to %s...\n", subscribers[i].email);
    }
}

int main() {
    int choice;

    do {
        printf("\nPeaceful Mailing List Manager\n");
        printf("1. Add subscriber\n");
        printf("2. Send email\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_subscriber();
                break;
            case 2:
                send_email();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}