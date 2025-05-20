//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 50
#define MAX_SUBJECT_LENGTH 100

typedef struct {
    char email[MAX_EMAIL_LENGTH];
    char name[MAX_NAME_LENGTH];
    int subscribed;
} Subscriber;

typedef struct {
    Subscriber* subscribers;
    int num_subscribers;
} MailingList;

void initialize_list(MailingList* list) {
    list->subscribers = NULL;
    list->num_subscribers = 0;
}

void subscribe(MailingList* list, const char* email, const char* name) {
    Subscriber* new_subscriber = malloc(sizeof(Subscriber));
    strcpy(new_subscriber->email, email);
    strcpy(new_subscriber->name, name);
    new_subscriber->subscribed = 1;
    list->subscribers = realloc(list->subscribers, sizeof(Subscriber) * (list->num_subscribers + 1));
    list->subscribers[list->num_subscribers] = *new_subscriber;
    list->num_subscribers++;
}

void unsubscribe(MailingList* list, const char* email) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            list->subscribers[i].subscribed = 0;
            break;
        }
    }
}

void send_email(MailingList* list, const char* subject, const char* message) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        if (list->subscribers[i].subscribed) {
            printf("Sending email to %s (%s)...\n", list->subscribers[i].name, list->subscribers[i].email);
        }
    }
}

int main() {
    MailingList list;
    initialize_list(&list);

    subscribe(&list, "john@example.com", "John Doe");
    subscribe(&list, "jane@example.com", "Jane Smith");

    send_email(&list, "Test Email", "This is a test email sent using the mailing list manager.");

    unsubscribe(&list, "john@example.com");

    send_email(&list, "Another Test Email", "This is another test email sent using the mailing list manager.");

    return 0;
}