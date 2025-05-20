//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100
#define MAX_MESSAGE_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers;

void add_subscriber() {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];

    printf("Enter subscriber name: ");
    scanf("%s", name);

    printf("Enter subscriber email: ");
    scanf("%s", email);

    strcpy(subscribers[num_subscribers].name, name);
    strcpy(subscribers[num_subscribers].email, email);

    num_subscribers++;
}

void send_message() {
    char message[MAX_MESSAGE_LEN];

    printf("Enter message: ");
    scanf("%[^\n]", message);

    for (int i = 0; i < num_subscribers; i++) {
        printf("Sending message to %s (%s)\n", subscribers[i].name, subscribers[i].email);
    }
}

int main() {
    num_subscribers = 0;

    while (num_subscribers < MAX_SUBSCRIBERS) {
        printf("1. Add subscriber\n");
        printf("2. Send message\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_subscriber();
                break;
            case 2:
                send_message();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}