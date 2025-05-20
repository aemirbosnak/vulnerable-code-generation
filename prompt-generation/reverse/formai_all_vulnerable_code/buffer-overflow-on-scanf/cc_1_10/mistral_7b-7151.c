//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SUBSCRIBERS 100

typedef struct {
    char name[50];
    bool is_subscribed;
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber(const char *name) {
    if (num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Mailing list is full.\n");
        return;
    }
    strcpy(subscribers[num_subscribers].name, name);
    subscribers[num_subscribers].is_subscribed = true;
    num_subscribers++;
}

void remove_subscriber(const char *name) {
    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].name, name) == 0) {
            subscribers[i].is_subscribed = false;
            num_subscribers--;
            i--; // since we've modified the array size
            break;
        }
    }
}

void list_subscribers() {
    int i;
    for (i = 0; i < num_subscribers; i++) {
        printf("%s%s\n", subscribers[i].name,
               (i < num_subscribers - 1) ? ", " : "");
    }
}

int main() {
    char command[50], name[50];
    int choice;

    while (true) {
        printf("1. Subscribe\n2. Unsubscribe\n3. List Subscribers\n4. Quit\nEnter your choice: ");
        scanf("%s", command);

        choice = atoi(command);

        switch (choice) {
        case 1:
            printf("Enter your name: ");
            scanf("%s", name);
            add_subscriber(name);
            break;
        case 2:
            printf("Enter your name: ");
            scanf("%s", name);
            remove_subscriber(name);
            break;
        case 3:
            list_subscribers();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}