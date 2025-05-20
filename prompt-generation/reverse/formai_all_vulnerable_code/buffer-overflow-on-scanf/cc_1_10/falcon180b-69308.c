//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_EMAIL_LENGTH 100
#define SUBJECT_LENGTH 100

typedef struct {
    char name[MAX_EMAIL_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber() {
    if (num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Sorry, the mailing list is full.\n");
        return;
    }

    printf("Enter the subscriber's name: ");
    scanf("%s", subscribers[num_subscribers].name);

    printf("Enter the subscriber's email address: ");
    scanf("%s", subscribers[num_subscribers].email);

    num_subscribers++;
    printf("Subscriber added.\n");
}

void send_email() {
    char subject[SUBJECT_LENGTH];
    printf("Enter the email subject: ");
    scanf("%s", subject);

    char message[1000];
    printf("Enter the email message: ");
    scanf("%s", message);

    printf("Sending email to %d subscribers...\n", num_subscribers);
    for (int i = 0; i < num_subscribers; i++) {
        printf("Sending email to %s (%s)...\n", subscribers[i].name, subscribers[i].email);
    }
}

void main() {
    printf("Welcome to the Mailing List Manager!\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add subscriber\n");
        printf("2. Send email\n");
        printf("3. Exit\n");

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
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid option.\n");
        }
    }
}