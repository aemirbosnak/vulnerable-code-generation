//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SUBSCRIBERS 100

typedef struct Subscriber {
    char name[50];
    bool isSubscribed;
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int numSubscribers = 0;

void addSubscriber(char *name) {
    if (numSubscribers >= MAX_SUBSCRIBERS) {
        printf("Mailing list is full.\n");
        return;
    }
    strcpy(subscribers[numSubscribers].name, name);
    subscribers[numSubscribers].isSubscribed = true;
    numSubscribers++;
}

void removeSubscriber(char *name) {
    int i;
    for (i = 0; i < numSubscribers; i++) {
        if (strcmp(subscribers[i].name, name) == 0) {
            subscribers[i].isSubscribed = false;
            numSubscribers--;
            i--;
            break;
        }
    }
}

void viewSubscribers() {
    int i;
    printf("Current subscribers:\n");
    for (i = 0; i < numSubscribers; i++) {
        printf("%s\n", subscribers[i].name);
    }
}

int main() {
    char command[20];
    char name[50];

    while (true) {
        printf("Enter command (add, remove, view, or quit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            addSubscriber(name);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            removeSubscriber(name);
        } else if (strcmp(command, "view") == 0) {
            viewSubscribers();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}