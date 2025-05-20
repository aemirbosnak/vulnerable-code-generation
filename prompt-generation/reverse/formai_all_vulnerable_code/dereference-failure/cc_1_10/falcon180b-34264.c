//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000
#define MAX_RECIPIENTS 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} recipient;

typedef struct {
    recipient *recipients;
    int num_recipients;
} mailing_list;

void add_recipient(mailing_list *list, char *name, char *email) {
    recipient *new_recipient = (recipient *)malloc(sizeof(recipient));
    strcpy(new_recipient->name, name);
    strcpy(new_recipient->email, email);
    list->recipients = (recipient *)realloc(list->recipients, sizeof(recipient) * (list->num_recipients + 1));
    list->recipients[list->num_recipients] = *new_recipient;
    list->num_recipients++;
}

void send_email(mailing_list *list, char *subject, char *message) {
    for (int i = 0; i < list->num_recipients; i++) {
        char to[MAX_EMAIL_LENGTH];
        strcpy(to, list->recipients[i].email);
        char from[MAX_EMAIL_LENGTH];
        strcpy(from, "you@example.com");
        char headers[MAX_SUBJECT_LENGTH + MAX_MESSAGE_LENGTH + 2 * MAX_EMAIL_LENGTH];
        sprintf(headers, "From: %s\r\nTo: %s\r\nSubject: %s\r\nContent-Type: text/plain\r\n\r\n", from, to, subject);
        send(list->recipients[i].email, headers, strlen(headers), 0);
    }
}

int main() {
    mailing_list list;
    list.num_recipients = 0;
    list.recipients = NULL;

    add_recipient(&list, "John Doe", "john@example.com");
    add_recipient(&list, "Jane Smith", "jane@example.com");

    send_email(&list, "Hello, world!", "This is a test email.");

    return 0;
}