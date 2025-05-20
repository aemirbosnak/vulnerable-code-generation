//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: configurable
// mailing_list.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

typedef struct {
    Subscriber *subscribers;
    int num_subscribers;
} MailingList;

MailingList *create_mailing_list() {
    MailingList *list = (MailingList *)malloc(sizeof(MailingList));
    list->subscribers = NULL;
    list->num_subscribers = 0;
    return list;
}

void add_subscriber(MailingList *list, char *name, char *email) {
    Subscriber *sub = (Subscriber *)malloc(sizeof(Subscriber));
    strcpy(sub->name, name);
    strcpy(sub->email, email);
    list->subscribers = realloc(list->subscribers, (list->num_subscribers + 1) * sizeof(Subscriber));
    list->subscribers[list->num_subscribers++] = *sub;
    free(sub);
}

void remove_subscriber(MailingList *list, char *name) {
    for (int i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].name, name) == 0) {
            list->num_subscribers--;
            for (int j = i; j < list->num_subscribers; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            break;
        }
    }
}

void print_subscribers(MailingList *list) {
    for (int i = 0; i < list->num_subscribers; i++) {
        printf("%s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
    }
}

int main() {
    MailingList *list = create_mailing_list();
    add_subscriber(list, "John Doe", "johndoe@example.com");
    add_subscriber(list, "Jane Doe", "janedoe@example.com");
    add_subscriber(list, "Jim Smith", "jimsmith@example.com");
    print_subscribers(list);
    remove_subscriber(list, "Jim Smith");
    print_subscribers(list);
    return 0;
}