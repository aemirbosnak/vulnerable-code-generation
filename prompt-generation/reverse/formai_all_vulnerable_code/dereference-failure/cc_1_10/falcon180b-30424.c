//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Subscriber;

typedef struct {
    int size;
    int capacity;
    Subscriber *subscribers;
} MailingList;

void initMailingList(MailingList *list) {
    list->size = 0;
    list->capacity = 10;
    list->subscribers = (Subscriber *) malloc(list->capacity * sizeof(Subscriber));
}

void addSubscriber(MailingList *list, const char *name, const char *email) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->subscribers = (Subscriber *) realloc(list->subscribers, list->capacity * sizeof(Subscriber));
    }

    strcpy(list->subscribers[list->size].name, name);
    strcpy(list->subscribers[list->size].email, email);

    list->size++;
}

void removeSubscriber(MailingList *list, const char *email) {
    int i;

    for (i = 0; i < list->size; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            memmove(&list->subscribers[i], &list->subscribers[i+1], (list->size - i - 1) * sizeof(Subscriber));
            list->size--;
            return;
        }
    }
}

void sendEmail(const char *name, const char *email) {
    printf("Sending email to %s (%s)\n", name, email);
}

void sendEmails(MailingList *list) {
    int i;

    for (i = 0; i < list->size; i++) {
        sendEmail(list->subscribers[i].name, list->subscribers[i].email);
    }
}

int main() {
    MailingList list;
    initMailingList(&list);

    addSubscriber(&list, "John Doe", "johndoe@example.com");
    addSubscriber(&list, "Jane Smith", "janesmith@example.com");

    sendEmails(&list);

    removeSubscriber(&list, "johndoe@example.com");

    sendEmails(&list);

    return 0;
}