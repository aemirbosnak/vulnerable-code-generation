//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SUBSCRIBERS 1000
#define SUBSCRIBER_NAME_LENGTH 50
#define SUBSCRIBER_EMAIL_LENGTH 100

typedef struct subscriber {
    char name[SUBSCRIBER_NAME_LENGTH];
    char email[SUBSCRIBER_EMAIL_LENGTH];
    struct subscriber *next;
} subscriber_t;

subscriber_t *mailing_list = NULL;
int num_subscribers = 0;

void add_subscriber(char *name, char *email) {
    subscriber_t *new_subscriber = (subscriber_t *) malloc(sizeof(subscriber_t));
    strcpy(new_subscriber->name, name);
    strcpy(new_subscriber->email, email);
    new_subscriber->next = mailing_list;
    mailing_list = new_subscriber;
    num_subscribers++;
}

bool remove_subscriber(char *name) {
    subscriber_t *current = mailing_list;
    subscriber_t *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                mailing_list = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            num_subscribers--;
            return true;
        }
        previous = current;
        current = current->next;
    }

    return false;
}

void print_mailing_list() {
    subscriber_t *current = mailing_list;

    printf("Mailing List:\n");
    while (current != NULL) {
        printf("%s (%s)\n", current->name, current->email);
        current = current->next;
    }
}

int main() {
    char name[SUBSCRIBER_NAME_LENGTH];
    char email[SUBSCRIBER_EMAIL_LENGTH];
    char command[20];

    while (1) {
        printf("Listus Torvalds> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Name: ");
            scanf("%s", name);
            printf("Email: ");
            scanf("%s", email);
            add_subscriber(name, email);
        } else if (strcmp(command, "remove") == 0) {
            printf("Name: ");
            scanf("%s", name);
            remove_subscriber(name);
        } else if (strcmp(command, "print") == 0) {
            print_mailing_list();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}