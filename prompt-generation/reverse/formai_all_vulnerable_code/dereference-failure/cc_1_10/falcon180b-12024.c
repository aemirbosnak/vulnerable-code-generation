//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

typedef struct {
    char subject[MAX_SUBJECTS];
    Subscriber* subscribers;
    int num_subscribers;
} MailingList;

void addSubscriber(MailingList* list, const char* name, const char* email) {
    Subscriber* newSubscriber = malloc(sizeof(Subscriber));
    strcpy(newSubscriber->name, name);
    strcpy(newSubscriber->email, email);
    list->subscribers = realloc(list->subscribers, sizeof(Subscriber) * (list->num_subscribers + 1));
    list->subscribers[list->num_subscribers] = *newSubscriber;
    list->num_subscribers++;
}

void removeSubscriber(MailingList* list, const char* email) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            list->subscribers = realloc(list->subscribers, sizeof(Subscriber) * (list->num_subscribers - 1));
            memmove(&list->subscribers[i], &list->subscribers[i + 1], sizeof(Subscriber) * (list->num_subscribers - i - 1));
            list->num_subscribers--;
            break;
        }
    }
}

void sendEmail(MailingList* list, const char* subject, const char* message) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        printf("Sending email to %s (%s)\n", list->subscribers[i].name, list->subscribers[i].email);
    }
}

int main() {
    MailingList list;
    list.num_subscribers = 0;

    addSubscriber(&list, "John Doe", "john.doe@example.com");
    addSubscriber(&list, "Jane Smith", "jane.smith@example.com");

    sendEmail(&list, "Hello, World!", "This is a test email.");

    removeSubscriber(&list, "john.doe@example.com");

    sendEmail(&list, "Goodbye, John!", "We'll miss you!");

    return 0;
}