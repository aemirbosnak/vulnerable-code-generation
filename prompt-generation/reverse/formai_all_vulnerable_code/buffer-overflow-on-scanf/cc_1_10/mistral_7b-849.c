//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SUBSCRIBERS 1000

typedef struct {
    char name[50];
    int is_subscribed;
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber(char *name) {
    if (num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Mail list is full.\n");
        return;
    }
    strcpy(subscribers[num_subscribers].name, name);
    subscribers[num_subscribers].is_subscribed = 1;
    num_subscribers++;
}

void remove_subscriber(char *name) {
    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (strcpy(subscribers[i].name, name) == name) {
            subscribers[i].is_subscribed = 0;
            num_subscribers--;
            for (int j = i; j < num_subscribers; j++) {
                strcpy(subscribers[j].name, subscribers[j+1].name);
            }
            break;
        }
    }
    if (i == num_subscribers) {
        printf("Subscriber not found.\n");
    }
}

void send_message(char *message) {
    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (subscribers[i].is_subscribed) {
            printf("%s: %s\n", subscribers[i].name, message);
        }
    }
}

int main() {
    char command[50];
    char name[50];
    int choice;
    char message[100];

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. Send Message\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                add_subscriber(name);
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                remove_subscriber(name);
                break;
            case 3:
                printf("Enter message: ");
                scanf("%s", message);
                send_message(message);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}