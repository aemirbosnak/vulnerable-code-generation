//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char email[MAX_EMAIL_LENGTH];
    char name[MAX_EMAIL_LENGTH];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers;

void add_subscriber() {
    if (num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Sorry, the list is full.\n");
        return;
    }

    printf("Enter email address: ");
    scanf("%s", subscribers[num_subscribers].email);

    printf("Enter name: ");
    scanf("%s", subscribers[num_subscribers].name);

    num_subscribers++;
}

void send_email() {
    printf("Enter email subject: ");
    char subject[MAX_EMAIL_LENGTH];
    scanf("%s", subject);

    printf("Enter email body: ");
    char body[MAX_EMAIL_LENGTH];
    scanf("%s", body);

    printf("Enter recipient email address: ");
    char recipient[MAX_EMAIL_LENGTH];
    scanf("%s", recipient);

    for (int i = 0; i < num_subscribers; i++) {
        if (strcmp(recipient, subscribers[i].email) == 0) {
            printf("Sending email to %s (%s)\n", subscribers[i].name, subscribers[i].email);
        }
    }
}

void view_subscribers() {
    printf("Name\tEmail\n");
    for (int i = 0; i < num_subscribers; i++) {
        printf("%s\t%s\n", subscribers[i].name, subscribers[i].email);
    }
}

int main() {
    printf("Welcome to the mailing list manager!\n");

    while (1) {
        printf("\n");
        printf("1. Add subscriber\n");
        printf("2. Send email\n");
        printf("3. View subscribers\n");
        printf("0. Exit\n");

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
                view_subscribers();
                break;
            case 0:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}