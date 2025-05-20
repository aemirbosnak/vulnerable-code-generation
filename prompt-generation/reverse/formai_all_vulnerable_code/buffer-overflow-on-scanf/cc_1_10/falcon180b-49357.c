//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: rigorous
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
    int i = 0;
    while (i < num_subscribers) {
        if (strcmp(subscribers[i].email, email) == 0) {
            for (int j = i; j < num_subscribers - 1; j++) {
                strcpy(subscribers[j].email, subscribers[j + 1].email);
                strcpy(subscribers[j].name, subscribers[j + 1].name);
            }
            num_subscribers--;
            break;
        }
        i++;
    }
}

void send_email() {
    printf("Enter subject: ");
    char subject[MAX_EMAIL_LENGTH];
    scanf("%s", subject);
    printf("Enter message: ");
    char message[MAX_EMAIL_LENGTH];
    scanf("%s", message);
    printf("Enter recipient email address: ");
    char recipient[MAX_EMAIL_LENGTH];
    scanf("%s", recipient);
    int i = 0;
    while (i < num_subscribers) {
        if (strcmp(subscribers[i].email, recipient) == 0) {
            printf("Sending email to %s (%s)...\n", subscribers[i].name, subscribers[i].email);
        }
        i++;
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
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);
    return 0;
}