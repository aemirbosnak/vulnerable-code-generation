//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: unmistakable
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
int num_subscribers = 0;

void add_subscriber() {
    Subscriber new_subscriber;
    printf("Enter name: ");
    scanf("%s", new_subscriber.name);
    printf("Enter email: ");
    scanf("%s", new_subscriber.email);
    strcpy(subscribers[num_subscribers].name, new_subscriber.name);
    strcpy(subscribers[num_subscribers].email, new_subscriber.email);
    num_subscribers++;
}

void remove_subscriber() {
    int index;
    printf("Enter index of subscriber to remove: ");
    scanf("%d", &index);
    if (index >= 0 && index < num_subscribers) {
        num_subscribers--;
        for (int i = index; i < num_subscribers; i++) {
            strcpy(subscribers[i].name, subscribers[i+1].name);
            strcpy(subscribers[i].email, subscribers[i+1].email);
        }
    } else {
        printf("Invalid index.\n");
    }
}

void send_email() {
    printf("Enter email to send to: ");
    scanf("%s", subscribers[0].email);
    printf("Email sent to %s.\n", subscribers[0].name);
}

void view_subscribers() {
    for (int i = 0; i < num_subscribers; i++) {
        printf("%d. %s (%s)\n", i+1, subscribers[i].name, subscribers[i].email);
    }
}

int main() {
    int choice;
    do {
        printf("\nMailing List Manager\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Send email\n");
        printf("4. View subscribers\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);
    return 0;
}