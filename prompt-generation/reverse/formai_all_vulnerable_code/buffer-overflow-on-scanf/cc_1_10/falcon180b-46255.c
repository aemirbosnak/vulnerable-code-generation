//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int numSubscribers = 0;

void addSubscriber() {
    if (numSubscribers >= MAX_SUBSCRIBERS) {
        printf("Sorry, the mailing list is full.\n");
        return;
    }

    printf("Enter your name:\n");
    scanf("%s", subscribers[numSubscribers].name);

    printf("Enter your email:\n");
    scanf("%s", subscribers[numSubscribers].email);

    numSubscribers++;

    printf("You have been added to the mailing list.\n");
}

void removeSubscriber() {
    int index;
    char email[MAX_EMAIL_LENGTH];

    printf("Enter the email address of the subscriber you want to remove:\n");
    scanf("%s", email);

    for (index = 0; index < numSubscribers; index++) {
        if (strcmp(subscribers[index].email, email) == 0) {
            memset(&subscribers[index], 0, sizeof(Subscriber));
            numSubscribers--;
            printf("The subscriber has been removed from the mailing list.\n");
            return;
        }
    }

    printf("The subscriber was not found on the mailing list.\n");
}

void sendEmail() {
    int index;
    char subject[MAX_EMAIL_LENGTH];
    char message[MAX_EMAIL_LENGTH];

    printf("Enter the subject of the email:\n");
    scanf("%s", subject);

    printf("Enter the message of the email:\n");
    scanf("%s", message);

    for (index = 0; index < numSubscribers; index++) {
        sprintf(message, "Dear %s,\n\n%s\n\nBest regards,\nThe Mailing List Manager", subscribers[index].name, message);
        system(sprintf("echo \"%s\" | mail -s \"%s\" %s", message, subject, subscribers[index].email));
    }

    printf("The email has been sent to all subscribers.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nCyberpunk Mailing List Manager\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Send email\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addSubscriber();
            break;
        case 2:
            removeSubscriber();
            break;
        case 3:
            sendEmail();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}