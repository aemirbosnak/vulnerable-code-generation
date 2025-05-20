//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct subscriber {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber() {
    printf("Enter name: ");
    scanf("%s", subscribers[num_subscribers].name);
    printf("Enter email: ");
    scanf("%s", subscribers[num_subscribers].email);
    num_subscribers++;
}

void send_message() {
    printf("Enter message: ");
    char message[MAX_MESSAGE_LENGTH];
    scanf("%s", message);
    for (int i = 0; i < num_subscribers; i++) {
        printf("Sending message to %s...\n", subscribers[i].name);
    }
}

int main() {
    printf("Welcome to the Mailing List Manager!\n");
    while (1) {
        printf("1. Add subscriber\n2. Send message\n3. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_subscriber();
                printf("Subscriber added!\n");
                break;
            case 2:
                send_message();
                printf("Message sent!\n");
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}