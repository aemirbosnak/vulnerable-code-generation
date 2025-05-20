//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SUBSCRIBERS 1000

typedef struct Subscriber {
    char name[50];
    char email[100];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int subscriber_count = 0;

void add_subscriber(char *name, char *email) {
    if (subscriber_count >= MAX_SUBSCRIBERS) {
        printf("Error: Mailing list is full!\n");
        return;
    }

    strcpy(subscribers[subscriber_count].name, name);
    strcpy(subscribers[subscriber_count].email, email);
    subscriber_count++;
}

void remove_subscriber(char *email) {
    int i;

    for (i = 0; i < subscriber_count; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            for (int j = i; j < subscriber_count - 1; j++) {
                subscribers[j] = subscribers[j + 1];
            }
            subscriber_count--;
            printf("Subscriber removed successfully!\n");
            return;
        }
    }

    printf("Error: Subscriber not found!\n");
}

void send_email(char *subject, char *message) {
    int i;
    printf("Sending email to %d subscribers...\n", subscriber_count);

    for (i = 0; i < subscriber_count; i++) {
        char email[100];
        strcpy(email, subscribers[i].email);

        printf("\nTo: %s\n", subscribers[i].name);
        printf("Subject: %s\n", subject);
        printf("Message:\n%s\n", message);

        // Implement email sending logic here
        // ...
    }
}

int main() {
    char name[50], email[100];

    while (true) {
        printf("\nMailBlaster - The Mailing List Manager\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. Send Email\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                add_subscriber(name, email);
                break;

            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                remove_subscriber(email);
                break;

            case 3:
                printf("Enter subject: ");
                scanf("%s", name);
                printf("Enter message: ");
                getchar(); // consume newline character
                char message[200];
                fgets(message, sizeof(message), stdin);
                message[strlen(message) - 1] = '\0';
                send_email(name, message);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}