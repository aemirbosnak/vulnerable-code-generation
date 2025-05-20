//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define MAX_MESSAGE_SIZE 512

typedef struct {
    char name[64];
    char email[128];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber() {
    char name[64];
    char email[128];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your email: ");
    scanf("%s", email);

    strcpy(subscribers[num_subscribers].name, name);
    strcpy(subscribers[num_subscribers].email, email);

    num_subscribers++;
}

void remove_subscriber() {
    char email[128];

    printf("Enter the email address of the subscriber you want to remove: ");
    scanf("%s", email);

    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            memmove(&subscribers[i], &subscribers[i+1], (num_subscribers - i - 1) * sizeof(Subscriber));
            num_subscribers--;
            break;
        }
    }
}

void send_message() {
    char message[MAX_MESSAGE_SIZE];

    printf("Enter your message: ");
    scanf("%[^\n]", message);

    printf("Message sent to all subscribers.\n");
}

int main() {
    int choice;

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Send message\n");
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
                send_message();
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