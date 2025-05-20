//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
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

void send_message() {
    char message[MAX_MESSAGE_LENGTH];
    printf("Enter your message: ");
    scanf("%[^\n]", message);

    for (int i = 0; i < num_subscribers; i++) {
        sprintf(message, "To: %s\nFrom: Mailing List Manager\nSubject: New Message\n\n%s", subscribers[i].email, message);
        system(message);
    }
}

int main() {
    while (1) {
        printf("1. Add subscriber\n2. Send message\n3. Exit\n");
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
                printf("Invalid choice.\n");
        }
    }

    return 0;
}