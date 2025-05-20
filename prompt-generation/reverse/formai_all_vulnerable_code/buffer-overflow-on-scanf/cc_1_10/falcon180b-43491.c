//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_EMAIL_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber() {
    printf("Enter your name: ");
    scanf("%s", subscribers[num_subscribers].name);

    printf("Enter your email: ");
    scanf("%s", subscribers[num_subscribers].email);

    num_subscribers++;
}

void remove_subscriber() {
    printf("Enter the email of the subscriber you want to remove: ");
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
    printf("Enter the subject of the email: ");
    char subject[MAX_EMAIL_LENGTH];
    scanf("%s", subject);

    printf("Enter the content of the email: ");
    char content[MAX_EMAIL_LENGTH];
    scanf("%s", content);

    int i;
    for (i = 0; i < num_subscribers; i++) {
        printf("Sending email to %s (%s)...\n", subscribers[i].name, subscribers[i].email);
    }
}

int main() {
    int choice;

    do {
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}