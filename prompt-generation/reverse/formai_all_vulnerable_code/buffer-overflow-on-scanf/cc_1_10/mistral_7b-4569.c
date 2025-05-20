//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SUBSCRIBERS 1000

typedef struct Subscriber {
    char name[50];
    char email[100];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber(const char *name, const char *email) {
    if (num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Error: Mailing list is full.\n");
        return;
    }

    strcpy(subscribers[num_subscribers].name, name);
    strcpy(subscribers[num_subscribers].email, email);
    num_subscribers++;
}

void remove_subscriber(int index) {
    if (index < 0 || index >= num_subscribers) {
        printf("Error: Invalid index.\n");
        return;
    }

    memmove(&subscribers[index], &subscribers[index + 1],
             (num_subscribers - index - 1) * sizeof(Subscriber));
    num_subscribers--;
}

void send_email(const char *subject, const char *message) {
    for (int i = 0; i < num_subscribers; i++) {
        printf("Sending email to %s (%s)\n",
               subscribers[i].name, subscribers[i].email);
        // Implement email sending logic here
    }
}

void display_subscribers() {
    printf("Current number of subscribers: %d\n", num_subscribers);
    printf("Subscribers:\n");

    for (int i = 0; i < num_subscribers; i++) {
        printf("%d. %s <%s>\n", i + 1, subscribers[i].name, subscribers[i].email);
    }
}

int main() {
    char command[50];
    int index;

    while (true) {
        printf("Enter command (add <name> <email>, remove <index>, list, send <subject> <message>, quit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char name[50], email[100];
            scanf("%s %s", name, email);
            add_subscriber(name, email);
            continue;
        }

        if (strcmp(command, "remove") == 0) {
            scanf("%d", &index);
            remove_subscriber(index - 1);
            continue;
        }

        if (strcmp(command, "list") == 0) {
            display_subscribers();
            continue;
        }

        if (strcmp(command, "send") == 0) {
            char subject[100], message[200];
            scanf("%s %s", subject, message);
            send_email(subject, message);
            continue;
        }

        if (strcmp(command, "quit") == 0) {
            break;
        }

        printf("Error: Invalid command.\n");
    }

    return 0;
}