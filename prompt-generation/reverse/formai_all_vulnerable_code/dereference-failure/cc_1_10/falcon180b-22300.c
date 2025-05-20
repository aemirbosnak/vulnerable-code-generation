//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EMAILS 1000
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char email[MAX_EMAIL_LENGTH];
    time_t last_sent;
} email_t;

typedef struct {
    email_t *emails;
    int num_emails;
} mailing_list_t;

void mailing_list_init(mailing_list_t *list) {
    list->emails = NULL;
    list->num_emails = 0;
}

void mailing_list_add_email(mailing_list_t *list, const char *email) {
    email_t *new_email = (email_t *) malloc(sizeof(email_t));
    strncpy(new_email->email, email, MAX_EMAIL_LENGTH);
    new_email->last_sent = 0;
    list->emails = realloc(list->emails, sizeof(email_t) * (list->num_emails + 1));
    list->emails[list->num_emails++] = *new_email;
}

void mailing_list_send_emails(mailing_list_t *list) {
    time_t now = time(NULL);
    for (int i = 0; i < list->num_emails; i++) {
        if (list->emails[i].last_sent + 86400 < now) { // Send email once per day
            printf("Sending email to %s...\n", list->emails[i].email);
            list->emails[i].last_sent = now;
        }
    }
}

int main() {
    mailing_list_t list;
    mailing_list_init(&list);

    char email[MAX_EMAIL_LENGTH];
    while (fgets(email, MAX_EMAIL_LENGTH, stdin)!= NULL) {
        mailing_list_add_email(&list, email);
    }

    while (1) {
        mailing_list_send_emails(&list);
        sleep(86400); // Send emails once per day
    }

    return 0;
}