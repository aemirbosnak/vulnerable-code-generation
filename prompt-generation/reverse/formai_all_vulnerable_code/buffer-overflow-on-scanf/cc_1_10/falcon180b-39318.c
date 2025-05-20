//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber() {
    if (num_subscribers == MAX_SUBSCRIBERS) {
        printf("Sorry, the mailing list is full.\n");
        return;
    }

    printf("Enter your name: ");
    scanf("%s", subscribers[num_subscribers].name);

    printf("Enter your email address: ");
    scanf("%s", subscribers[num_subscribers].email);

    num_subscribers++;
    printf("Thank you for subscribing!\n");
}

void remove_subscriber() {
    int i;

    printf("Enter the index of the subscriber you want to remove: ");
    scanf("%d", &i);

    if (i < 0 || i >= num_subscribers) {
        printf("Invalid index.\n");
        return;
    }

    num_subscribers--;
    printf("Subscriber removed.\n");
}

void send_email() {
    int i;

    printf("Enter the subject of the email: ");
    scanf("%s", subscribers[0].name);

    printf("Enter the body of the email: ");
    scanf("%s", subscribers[0].email);

    for (i = 1; i < num_subscribers; i++) {
        strcat(subscribers[0].name, ", ");
        strcat(subscribers[0].name, subscribers[i].name);
    }

    printf("Email sent to %s.\n", subscribers[0].name);
}

int main() {
    int choice;

    do {
        printf("Mailing List Manager\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Send email\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
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
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}