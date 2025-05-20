//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 1000

typedef struct {
    char name[50];
    char email[100];
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

    printf("Enter your email: ");
    scanf("%s", subscribers[num_subscribers].email);

    num_subscribers++;

    printf("You have been added to the mailing list.\n");
}

void remove_subscriber() {
    printf("Enter your email: ");
    char email[100];
    scanf("%s", email);

    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            memmove(&subscribers[i], &subscribers[i+1], (num_subscribers - i - 1) * sizeof(Subscriber));
            num_subscribers--;
            printf("You have been removed from the mailing list.\n");
            return;
        }
    }

    printf("You are not on the mailing list.\n");
}

void send_email() {
    printf("Enter the subject of the email: ");
    char subject[100];
    scanf("%s", subject);

    printf("Enter the body of the email: ");
    char body[1000];
    scanf("%s", body);

    printf("Email sent to all subscribers.\n");
}

int main() {
    int choice;

    do {
        printf("\nMailing List Manager\n");
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
                printf("Invalid choice.\n");
        }

    } while (choice!= 4);

    return 0;
}