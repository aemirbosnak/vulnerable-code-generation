//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define MAX_EMAIL_LENGTH 50
#define MAX_NAME_LENGTH 30

typedef struct subscriber {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

void addSubscriber(Subscriber subscribers[], int numSubscribers) {
    printf("Enter name: ");
    scanf("%s", subscribers[numSubscribers].name);
    printf("Enter email: ");
    scanf("%s", subscribers[numSubscribers].email);
    numSubscribers++;
}

void sendEmail(Subscriber subscriber, char* subject, char* body) {
    printf("Sending email to %s (%s)\n", subscriber.name, subscriber.email);
}

void sendEmails(Subscriber subscribers[], int numSubscribers, char* subject, char* body) {
    for (int i = 0; i < numSubscribers; i++) {
        sendEmail(subscribers[i], subject, body);
    }
}

int main() {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int numSubscribers = 0;

    printf("Welcome to the mailing list manager!\n");

    while (1) {
        printf("\n1. Add subscriber\n2. Send email\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numSubscribers >= MAX_SUBSCRIBERS) {
                    printf("Sorry, maximum number of subscribers reached.\n");
                } else {
                    addSubscriber(subscribers, numSubscribers);
                }
                break;
            case 2:
                if (numSubscribers == 0) {
                    printf("No subscribers to send email to.\n");
                } else {
                    char subject[100];
                    char body[1000];

                    printf("Enter subject: ");
                    scanf("%s", subject);

                    printf("Enter body:\n");
                    fgets(body, sizeof(body), stdin);

                    sendEmails(subscribers, numSubscribers, subject, body);
                }
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}