//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_EMAILS 1000
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_EMAIL_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers;

void add_subscriber() {
    if (num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Error: Maximum number of subscribers reached.\n");
        return;
    }

    printf("Enter subscriber name: ");
    scanf("%s", subscribers[num_subscribers].name);

    printf("Enter subscriber email: ");
    scanf("%s", subscribers[num_subscribers].email);

    num_subscribers++;
}

void send_email() {
    char subject[MAX_EMAIL_LENGTH];
    char message[MAX_EMAIL_LENGTH];

    printf("Enter email subject: ");
    scanf("%s", subject);

    printf("Enter email message: ");
    scanf("%s", message);

    for (int i = 0; i < num_subscribers; i++) {
        sprintf(message, "Dear %s,\n\n%s\n\nBest regards,\nYour mailing list manager", subscribers[i].name, message);
        printf("Sending email to %s...\n", subscribers[i].email);
    }
}

int main() {
    num_subscribers = 0;

    while (1) {
        printf("\nMailing list manager\n");
        printf("1. Add subscriber\n2. Send email\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_subscriber();
                break;
            case 2:
                send_email();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}