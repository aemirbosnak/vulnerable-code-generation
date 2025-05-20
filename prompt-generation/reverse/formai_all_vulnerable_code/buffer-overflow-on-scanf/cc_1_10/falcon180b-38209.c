//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_EMAIL_LENGTH 100

struct Subscriber {
    char email[MAX_EMAIL_LENGTH];
    char name[MAX_EMAIL_LENGTH];
};

int num_subscribers = 0;
struct Subscriber subscribers[MAX_SUBSCRIBERS];

void add_subscriber() {
    char email[MAX_EMAIL_LENGTH];
    char name[MAX_EMAIL_LENGTH];

    printf("Enter email address: ");
    scanf("%s", email);

    printf("Enter name: ");
    scanf("%s", name);

    strcpy(subscribers[num_subscribers].email, email);
    strcpy(subscribers[num_subscribers].name, name);

    num_subscribers++;
}

void send_email() {
    char subject[MAX_EMAIL_LENGTH];
    char message[MAX_EMAIL_LENGTH];

    printf("Enter subject: ");
    scanf("%s", subject);

    printf("Enter message: ");
    scanf("%s", message);

    for (int i = 0; i < num_subscribers; i++) {
        printf("Sending email to %s (%s)...\n", subscribers[i].name, subscribers[i].email);
    }
}

int main() {
    int choice;

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add subscriber\n");
        printf("2. Send email\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
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
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}