//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers;

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

    printf("Subscriber added successfully!\n");
}

void remove_subscriber() {
    printf("Enter the email of the subscriber you want to remove: ");
    char email[MAX_EMAIL_LENGTH];
    scanf("%s", email);

    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            strcpy(subscribers[i].name, "");
            strcpy(subscribers[i].email, "");
            num_subscribers--;
            printf("Subscriber removed successfully!\n");
            return;
        }
    }

    printf("Subscriber not found.\n");
}

void send_email() {
    printf("Enter the subject of the email: ");
    char subject[MAX_EMAIL_LENGTH];
    scanf("%s", subject);

    printf("Enter the body of the email: ");
    char body[MAX_EMAIL_LENGTH];
    scanf("%s", body);

    printf("Email sent successfully!\n");
}

int main() {
    num_subscribers = 0;

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Send email\n");
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
            send_email();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}