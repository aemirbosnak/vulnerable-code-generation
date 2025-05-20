//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SUBSCRIBERS 100

typedef struct {
    char name[50];
    char email[100];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

bool is_full() {
    return num_subscribers >= MAX_SUBSCRIBERS;
}

bool add_subscriber(const char *name, const char *email) {
    if (is_full()) {
        printf("Mailing list is full.\n");
        return false;
    }

    strcpy(subscribers[num_subscribers].name, name);
    strcpy(subscribers[num_subscribers].email, email);
    num_subscribers++;

    return true;
}

bool remove_subscriber(const char *email) {
    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            for (int j = i; j < num_subscribers - 1; j++) {
                subscribers[j] = subscribers[j + 1];
            }
            num_subscribers--;
            return true;
        }
    }

    printf("Subscriber with email %s not found.\n", email);
    return false;
}

void display_subscribers() {
    int i;
    printf("\nSubscribers:\n");
    for (i = 0; i < num_subscribers; i++) {
        printf("%s (%s)\n", subscribers[i].name, subscribers[i].email);
    }
}

int main() {
    char name[50];
    char email[100];

    while (true) {
        printf("\nMailing List Manager\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Display subscribers\n");
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
                display_subscribers();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}