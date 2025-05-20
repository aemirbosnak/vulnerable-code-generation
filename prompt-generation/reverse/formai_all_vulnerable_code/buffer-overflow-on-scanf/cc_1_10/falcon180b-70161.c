//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers;

void add_subscriber() {
    printf("Enter subscriber name: ");
    scanf("%s", subscribers[num_subscribers].name);

    printf("Enter subscriber email: ");
    scanf("%s", subscribers[num_subscribers].email);

    num_subscribers++;
}

void remove_subscriber() {
    printf("Enter subscriber email to remove: ");
    char email[MAX_EMAIL_LENGTH];
    scanf("%s", email);

    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            num_subscribers--;
            memmove(&subscribers[i], &subscribers[i+1], (num_subscribers - i - 1) * sizeof(Subscriber));
            break;
        }
    }
}

void send_email() {
    printf("Enter email subject: ");
    char subject[MAX_EMAIL_LENGTH];
    scanf("%s", subject);

    printf("Enter email message: ");
    char message[MAX_EMAIL_LENGTH];
    scanf("%s", message);

    printf("Enter recipient email: ");
    char recipient_email[MAX_EMAIL_LENGTH];
    scanf("%s", recipient_email);

    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].email, recipient_email) == 0) {
            printf("Email sent to %s (%s)\n", subscribers[i].name, subscribers[i].email);
        }
    }
}

int main() {
    num_subscribers = 0;

    while (1) {
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Send email\n");
        printf("4. Exit\n");

        int choice;
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
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}