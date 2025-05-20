//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define MAX_EMAIL_LENGTH 100

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

    printf("Enter your name: ");
    scanf("%s", subscribers[num_subscribers].name);

    printf("Enter your email address: ");
    scanf("%s", subscribers[num_subscribers].email);

    num_subscribers++;
}

void send_email() {
    printf("Enter the subject of the email: ");
    char subject[MAX_EMAIL_LENGTH];
    scanf("%s", subject);

    printf("Enter the body of the email: ");
    char body[MAX_EMAIL_LENGTH];
    scanf("%[^\n]", body);

    printf("Enter the recipient's email address: ");
    char recipient[MAX_EMAIL_LENGTH];
    scanf("%s", recipient);

    for (int i = 0; i < num_subscribers; i++) {
        if (strcmp(recipient, subscribers[i].email) == 0) {
            printf("Email sent to %s (%s).\n", subscribers[i].name, subscribers[i].email);
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
    while (1) {
        printf("1. Add Subscriber\n2. Send Email\n3. View Subscribers\n4. Exit\n");
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
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}