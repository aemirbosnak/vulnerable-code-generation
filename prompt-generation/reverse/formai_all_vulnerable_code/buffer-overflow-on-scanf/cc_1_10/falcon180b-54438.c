//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_EMAIL_LEN 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    int subscribed;
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber(char* name, char* email) {
    if (num_subscribers >= MAX_SUBSCRIBERS) {
        printf("ERROR: Maximum number of subscribers reached.\n");
        return;
    }

    strcpy(subscribers[num_subscribers].name, name);
    strcpy(subscribers[num_subscribers].email, email);
    subscribers[num_subscribers].subscribed = 1;
    num_subscribers++;
}

void remove_subscriber(char* email) {
    int i;

    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            subscribers[i].subscribed = 0;
            break;
        }
    }
}

void send_email(char* subject, char* message) {
    int i;

    for (i = 0; i < num_subscribers; i++) {
        if (subscribers[i].subscribed) {
            printf("Sending email to %s (%s)\n", subscribers[i].name, subscribers[i].email);
        }
    }
}

int main() {
    char input[100];
    int choice;

    printf("Welcome to the Mailing List Manager!\n");
    printf("Please choose an option:\n");
    printf("1. Add subscriber\n");
    printf("2. Remove subscriber\n");
    printf("3. Send email\n");
    printf("4. Exit\n");

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", input);
                printf("Enter email: ");
                scanf("%s", input);
                add_subscriber(input, input);
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", input);
                remove_subscriber(input);
                break;
            case 3:
                printf("Enter subject: ");
                scanf("%s", input);
                printf("Enter message: ");
                scanf("%s", input);
                send_email(input, input);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}