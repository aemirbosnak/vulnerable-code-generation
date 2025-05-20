//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: happy
/*
 * A simple mailing list manager program in C
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 100

struct email {
    char subject[MAX_EMAIL_LENGTH];
    char body[MAX_EMAIL_LENGTH];
};

struct mailing_list {
    struct email emails[MAX_EMAILS];
    int num_emails;
};

void print_emails(struct mailing_list* mailing_list) {
    int i;
    for (i = 0; i < mailing_list->num_emails; i++) {
        printf("%s\n", mailing_list->emails[i].subject);
        printf("%s\n", mailing_list->emails[i].body);
    }
}

int main() {
    struct mailing_list mailing_list;
    mailing_list.num_emails = 0;
    char email_subject[MAX_EMAIL_LENGTH];
    char email_body[MAX_EMAIL_LENGTH];

    while (1) {
        printf("Enter the email subject: ");
        scanf("%s", email_subject);

        if (strcmp(email_subject, "quit") == 0) {
            break;
        }

        printf("Enter the email body: ");
        scanf("%s", email_body);

        struct email email;
        strcpy(email.subject, email_subject);
        strcpy(email.body, email_body);
        mailing_list.emails[mailing_list.num_emails] = email;
        mailing_list.num_emails++;
    }

    print_emails(&mailing_list);

    return 0;
}