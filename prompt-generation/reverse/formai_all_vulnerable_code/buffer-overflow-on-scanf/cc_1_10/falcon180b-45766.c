//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char email[MAX_EMAIL_LENGTH];
    char name[MAX_EMAIL_LENGTH];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber() {
    printf("Enter email address: ");
    scanf("%s", subscribers[num_subscribers].email);

    printf("Enter name: ");
    scanf("%s", subscribers[num_subscribers].name);

    num_subscribers++;
}

void remove_subscriber() {
    printf("Enter email address to remove: ");
    char email[MAX_EMAIL_LENGTH];
    scanf("%s", email);

    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            num_subscribers--;
            break;
        }
    }
}

void send_email() {
    printf("Enter email subject: ");
    char subject[MAX_EMAIL_LENGTH];
    scanf("%s", subject);

    printf("Enter email body: ");
    char body[MAX_EMAIL_LENGTH];
    scanf("%s", body);

    printf("Enter recipients (comma-separated): ");
    char recipients[MAX_EMAIL_LENGTH];
    scanf("%s", recipients);

    int num_recipients = 0;
    char *token = strtok(recipients, ",");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_subscribers; i++) {
            if (strcmp(subscribers[i].email, token) == 0) {
                printf("Sending email to %s (%s)\n", subscribers[i].name, subscribers[i].email);
            }
        }
        num_recipients++;
        token = strtok(NULL, ",");
    }

    printf("Email sent to %d recipients.\n", num_recipients);
}

int main() {
    int choice;

    do {
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Send email\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_subscriber();
                break;
            case 2:
                remove_subscriber();
                break;
            case 3:
                send_email();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}