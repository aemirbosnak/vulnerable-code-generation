//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} subscriber;

subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber() {
    printf("Enter your name (max %d characters): ", MAX_NAME_LENGTH - 1);
    scanf("%s", subscribers[num_subscribers].name);

    printf("Enter your email (max %d characters): ", MAX_EMAIL_LENGTH - 1);
    scanf("%s", subscribers[num_subscribers].email);

    num_subscribers++;
}

void send_message() {
    char message[MAX_MESSAGE_LENGTH];

    printf("Enter your message (max %d characters): ", MAX_MESSAGE_LENGTH - 1);
    scanf("%s", message);

    for (int i = 0; i < num_subscribers; i++) {
        printf("Sending message to %s (%s)\n", subscribers[i].name, subscribers[i].email);

        // Code to send email to subscriber[i].email with message
    }
}

int main() {
    int choice;

    do {
        printf("Mailing List Manager\n");
        printf("1. Add subscriber\n");
        printf("2. Send message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
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
                printf("Invalid choice, please try again.\n");
        }
    } while (1);

    return 0;
}