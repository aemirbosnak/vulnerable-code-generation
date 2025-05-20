//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 1000
#define MAX_BODY_LENGTH 10000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

typedef struct {
    Subscriber* subscribers;
    int num_subscribers;
} MailingList;

MailingList* create_mailing_list() {
    MailingList* mailing_list = (MailingList*)malloc(sizeof(MailingList));
    mailing_list->subscribers = NULL;
    mailing_list->num_subscribers = 0;
    return mailing_list;
}

void add_subscriber(MailingList* mailing_list, const char* name, const char* email) {
    Subscriber* subscriber = (Subscriber*)malloc(sizeof(Subscriber));
    strncpy(subscriber->name, name, MAX_NAME_LENGTH);
    strncpy(subscriber->email, email, MAX_EMAIL_LENGTH);
    mailing_list->subscribers = realloc(mailing_list->subscribers, sizeof(Subscriber) * (mailing_list->num_subscribers + 1));
    mailing_list->subscribers[mailing_list->num_subscribers] = *subscriber;
    mailing_list->num_subscribers++;
}

void send_email(const char* from, const char* to, const char* subject, const char* body) {
    printf("Sending email from %s to %s with subject %s:\n%s\n", from, to, subject, body);
}

void send_emails_to_list(MailingList* mailing_list, const char* from, const char* subject, const char* body) {
    for (int i = 0; i < mailing_list->num_subscribers; i++) {
        Subscriber* subscriber = &mailing_list->subscribers[i];
        send_email(from, subscriber->email, subject, body);
    }
}

int main() {
    MailingList* mailing_list = create_mailing_list();
    add_subscriber(mailing_list, "John Doe", "john@example.com");
    add_subscriber(mailing_list, "Jane Doe", "jane@example.com");

    send_emails_to_list(mailing_list, "you@example.com", "Hello, World!", "This is a test email.");

    free(mailing_list->subscribers);
    free(mailing_list);

    return 0;
}