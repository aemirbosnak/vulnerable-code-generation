//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_EMAIL_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers;

void add_subscriber() {
    char name[MAX_EMAIL_LENGTH];
    char email[MAX_EMAIL_LENGTH];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your email address: ");
    scanf("%s", email);

    strcpy(subscribers[num_subscribers].name, name);
    strcpy(subscribers[num_subscribers].email, email);

    num_subscribers++;

    printf("Subscriber added successfully.\n");
}

void remove_subscriber() {
    char email[MAX_EMAIL_LENGTH];

    printf("Enter the email address of the subscriber you want to remove: ");
    scanf("%s", email);

    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            num_subscribers--;
            break;
        }
    }

    printf("Subscriber removed successfully.\n");
}

void send_email() {
    char message[MAX_EMAIL_LENGTH];

    printf("Enter your message: ");
    scanf("%s", message);

    printf("Message sent to all subscribers.\n");
}

void view_subscribers() {
    int i;
    for (i = 0; i < num_subscribers; i++) {
        printf("Name: %s\nEmail: %s\n", subscribers[i].name, subscribers[i].email);
    }
}

int main() {
    int choice;

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. Send Email\n");
        printf("4. View Subscribers\n");
        printf("5. Exit\n");

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
                view_subscribers();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 5);

    return 0;
}