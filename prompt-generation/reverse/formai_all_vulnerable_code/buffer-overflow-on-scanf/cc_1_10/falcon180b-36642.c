//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_EMAIL_LENGTH 100

typedef struct subscriber {
    char email[MAX_EMAIL_LENGTH];
    char name[MAX_EMAIL_LENGTH];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

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

void remove_subscriber() {
    char email[MAX_EMAIL_LENGTH];

    printf("Enter email address to remove: ");
    scanf("%s", email);

    for (int i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            for (int j = i; j < num_subscribers - 1; j++) {
                strcpy(subscribers[j].email, subscribers[j + 1].email);
                strcpy(subscribers[j].name, subscribers[j + 1].name);
            }
            num_subscribers--;
            break;
        }
    }
}

void send_email() {
    char subject[MAX_EMAIL_LENGTH];
    char message[MAX_EMAIL_LENGTH];

    printf("Enter subject: ");
    scanf("%s", subject);

    printf("Enter message: ");
    scanf("%s", message);

    for (int i = 0; i < num_subscribers; i++) {
        printf("Sending email to %s (%s)\n", subscribers[i].name, subscribers[i].email);
    }
}

int main() {
    int choice;

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Send email\n");
        printf("4. Exit\n");

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
    } while (1);

    return 0;
}