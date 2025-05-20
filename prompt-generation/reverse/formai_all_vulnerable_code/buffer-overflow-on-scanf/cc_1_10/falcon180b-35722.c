//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define MAX_EMAILS 1000

typedef struct {
    char name[50];
    char email[100];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers;

void add_subscriber() {
    printf("Enter name: ");
    scanf("%s", subscribers[num_subscribers].name);
    printf("Enter email: ");
    scanf("%s", subscribers[num_subscribers].email);
    num_subscribers++;
}

void remove_subscriber() {
    printf("Enter email to remove subscriber: ");
    char email[100];
    scanf("%s", email);
    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(email, subscribers[i].email) == 0) {
            num_subscribers--;
            memmove(&subscribers[i], &subscribers[i+1], (MAX_SUBSCRIBERS - i - 1) * sizeof(Subscriber));
            break;
        }
    }
}

void send_email() {
    printf("Enter subject: ");
    char subject[100];
    scanf("%s", subject);
    printf("Enter message: ");
    char message[1000];
    scanf("%s", message);
    int i;
    for (i = 0; i < num_subscribers; i++) {
        printf("Sending email to %s...\n", subscribers[i].name);
        printf("Subject: %s\n", subject);
        printf("Message:\n%s\n", message);
    }
}

int main() {
    printf("Welcome to the Mailing List Manager!\n");
    while (1) {
        printf("\n1. Add subscriber\n2. Remove subscriber\n3. Send email\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_subscriber();
                printf("\nSubscriber added successfully!\n");
                break;
            case 2:
                remove_subscriber();
                printf("\nSubscriber removed successfully!\n");
                break;
            case 3:
                send_email();
                printf("\nEmail sent successfully!\n");
                break;
            case 4:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}