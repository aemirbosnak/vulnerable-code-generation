//Falcon-180B DATASET v1.0 Category: Email Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 100
#define MAX_RECIPIENTS 50
#define MAX_SUBJECT_LENGTH 100
#define MAX_EMAIL_LENGTH 10000

typedef struct {
    char *subject;
    char *body;
    time_t timestamp;
} Email;

typedef struct {
    char *name;
    char *email;
} Recipient;

Email emails[MAX_EMAILS];
Recipient recipients[MAX_RECIPIENTS];
int num_emails = 0;
int num_recipients = 0;

void add_email(char *subject, char *body) {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: Cannot add more emails.\n");
        return;
    }

    emails[num_emails].subject = strdup(subject);
    emails[num_emails].body = strdup(body);
    emails[num_emails].timestamp = time(NULL);

    num_emails++;
}

void add_recipient(char *name, char *email) {
    if (num_recipients >= MAX_RECIPIENTS) {
        printf("Error: Cannot add more recipients.\n");
        return;
    }

    recipients[num_recipients].name = strdup(name);
    recipients[num_recipients].email = strdup(email);

    num_recipients++;
}

void send_email(int email_index, char *recipient_email) {
    Email *email = &emails[email_index];
    Recipient *recipient = NULL;

    for (int i = 0; i < num_recipients; i++) {
        if (!strcmp(recipients[i].email, recipient_email)) {
            recipient = &recipients[i];
            break;
        }
    }

    if (recipient == NULL) {
        printf("Error: Recipient not found.\n");
        return;
    }

    char *subject = email->subject;
    char *body = email->body;
    time_t timestamp = email->timestamp;

    char *date_str = ctime(&timestamp);
    date_str[strcspn(date_str, "\n")] = '\0';

    printf("Sending email to %s (%s) with subject '%s' and body:\n%s\n",
           recipient->name, recipient->email, subject, body);
}

int main() {
    add_email("Test email", "Hello, world!");
    add_recipient("John Doe", "john.doe@example.com");

    send_email(0, "john.doe@example.com");

    return 0;
}