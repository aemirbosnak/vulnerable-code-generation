//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[50];
    char email[100];
} Subscriber;

int num_subscribers = 0;
Subscriber subscribers[MAX_SUBSCRIBERS];

void add_subscriber() {
    if (num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Sorry, the mailing list is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", subscribers[num_subscribers].name);

    printf("Enter email: ");
    scanf("%s", subscribers[num_subscribers].email);

    num_subscribers++;
}

void remove_subscriber() {
    printf("Enter email to remove: ");
    char email[100];
    scanf("%s", email);

    for (int i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            strcpy(subscribers[i].name, "");
            strcpy(subscribers[i].email, "");
            num_subscribers--;
            printf("Subscriber removed.\n");
            return;
        }
    }

    printf("Subscriber not found.\n");
}

void send_message() {
    char message[MAX_MESSAGE_LENGTH];

    printf("Enter message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    for (int i = 0; i < num_subscribers; i++) {
        if (subscribers[i].name[0]!= '\0' && subscribers[i].email[0]!= '\0') {
            printf("Sending message to %s (%s)...\n", subscribers[i].name, subscribers[i].email);
        }
    }
}

int main() {
    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Send message\n");
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
                send_message();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}