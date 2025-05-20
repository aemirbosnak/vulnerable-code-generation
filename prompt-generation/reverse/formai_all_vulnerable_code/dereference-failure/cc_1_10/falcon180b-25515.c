//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define maximum number of subscribers
#define MAX_SUBSCRIBERS 1000

// define subscriber structure
typedef struct {
    char name[50];
    char email[100];
} subscriber;

// define mailing list structure
typedef struct {
    int num_subscribers;
    subscriber *subscribers;
} mailing_list;

// function to add a subscriber to the mailing list
void add_subscriber(mailing_list *list, char *name, char *email) {
    if (list->num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Error: Mailing list is full.\n");
        return;
    }

    list->subscribers[list->num_subscribers] = (subscriber) {
       .name = strdup(name),
       .email = strdup(email)
    };

    list->num_subscribers++;

    printf("Subscriber '%s' added to mailing list.\n", name);
}

// function to remove a subscriber from the mailing list
void remove_subscriber(mailing_list *list, char *name) {
    int i;

    for (i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].name, name) == 0) {
            free(list->subscribers[i].name);
            free(list->subscribers[i].email);

            list->subscribers[i] = list->subscribers[list->num_subscribers - 1];
            list->num_subscribers--;

            printf("Subscriber '%s' removed from mailing list.\n", name);

            return;
        }
    }

    printf("Subscriber '%s' not found in mailing list.\n", name);
}

// function to send an email to all subscribers
void send_email(mailing_list *list, char *subject, char *message) {
    int i;

    for (i = 0; i < list->num_subscribers; i++) {
        printf("Sending email to %s (%s)...\n", list->subscribers[i].name, list->subscribers[i].email);
    }
}

// main function
int main() {
    mailing_list list = {0};

    add_subscriber(&list, "John Doe", "john@example.com");
    add_subscriber(&list, "Jane Doe", "jane@example.com");

    send_email(&list, "Test Email", "Hello, World!");

    remove_subscriber(&list, "John Doe");

    send_email(&list, "Another Test Email", "Goodbye, World!");

    return 0;
}