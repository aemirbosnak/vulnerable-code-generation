//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

typedef struct {
    Subscriber* subscribers;
    int num_subscribers;
} MailingList;

void init_subscriber(Subscriber* sub) {
    strcpy(sub->name, "");
    strcpy(sub->email, "");
}

void init_mailing_list(MailingList* ml) {
    ml->subscribers = (Subscriber*)malloc(MAX_SUBSCRIBERS * sizeof(Subscriber));
    ml->num_subscribers = 0;
}

void add_subscriber(MailingList* ml, char* name, char* email) {
    if (ml->num_subscribers == MAX_SUBSCRIBERS) {
        printf("Error: Mailing list is full.\n");
        return;
    }

    Subscriber* sub = ml->subscribers + ml->num_subscribers;
    init_subscriber(sub);

    strncpy(sub->name, name, MAX_NAME_LENGTH);
    strncpy(sub->email, email, MAX_EMAIL_LENGTH);

    ml->num_subscribers++;
}

void delete_subscriber(MailingList* ml, char* email) {
    int i;
    for (i = 0; i < ml->num_subscribers; i++) {
        if (strcmp(ml->subscribers[i].email, email) == 0) {
            ml->subscribers[i] = ml->subscribers[--ml->num_subscribers];
            break;
        }
    }
}

void send_email(MailingList* ml, char* subject, char* body) {
    int i;
    for (i = 0; i < ml->num_subscribers; i++) {
        printf("Sending email to %s <%s>...\n", ml->subscribers[i].name, ml->subscribers[i].email);
    }
}

int main() {
    MailingList ml;
    init_mailing_list(&ml);

    add_subscriber(&ml, "John Doe", "john.doe@example.com");
    add_subscriber(&ml, "Jane Doe", "jane.doe@example.com");

    send_email(&ml, "Test Email", "Hello world!");

    delete_subscriber(&ml, "john.doe@example.com");

    send_email(&ml, "Another Test Email", "Goodbye world!");

    return 0;
}