//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SUBSCRIBERS 1000
#define SUBSCRIBER_NAME_LENGTH 50

typedef struct Subscriber {
    char name[SUBSCRIBER_NAME_LENGTH];
    bool is_subscribed;
    struct Subscriber *next;
} Subscriber;

Subscriber *mailing_list = NULL;
int num_subscribers = 0;

void add_subscriber(char *name) {
    Subscriber *new_subscriber = (Subscriber *) malloc(sizeof(Subscriber));
    strcpy(new_subscriber->name, name);
    new_subscriber->is_subscribed = true;
    new_subscriber->next = mailing_list;
    mailing_list = new_subscriber;
    num_subscribers++;
}

bool remove_subscriber(char *name) {
    Subscriber *current = mailing_list;
    Subscriber *previous = NULL;

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
    Subscriber *current = mailing_list;

    printf("Mailing List:\n");
    while (current != NULL) {
        printf("%s - %s\n", current->name, current->is_subscribed ? "Subscribed" : "Unsubscribed");
        current = current->next;
    }
}

int main() {
    char name[SUBSCRIBER_NAME_LENGTH];
    int choice;

    while (true) {
        printf("\n1. Add subscriber\n2. Remove subscriber\n3. Print mailing list\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the subscriber: ");
                scanf("%s", name);
                add_subscriber(name);
                break;
            case 2:
                printf("Enter the name of the subscriber to remove: ");
                scanf("%s", name);
                remove_subscriber(name);
                break;
            case 3:
                print_mailing_list();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}