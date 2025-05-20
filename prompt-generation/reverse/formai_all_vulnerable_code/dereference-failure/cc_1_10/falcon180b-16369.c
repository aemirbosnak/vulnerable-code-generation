//Falcon-180B DATASET v1.0 Category: Email Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 100
#define MAX_RECIPIENTS 10
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char *email;
    char *subject;
    char *body;
    time_t timestamp;
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email(char *email, char *subject, char *body) {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: Too many emails.\n");
        return;
    }

    emails[num_emails].email = strdup(email);
    emails[num_emails].subject = strdup(subject);
    emails[num_emails].body = strdup(body);
    emails[num_emails].timestamp = time(NULL);

    num_emails++;
}

void print_emails() {
    printf("Subject\tSender\tTimestamp\n");
    for (int i = 0; i < num_emails; i++) {
        printf("%s\t%s\t%s\n", emails[i].subject, emails[i].email, ctime(&emails[i].timestamp));
    }
}

void send_email(char *to, char *subject, char *body) {
    printf("Sending email to %s with subject '%s'...\n", to, subject);
}

int main() {
    add_email("john@example.com", "Hello, world!", "This is my first email.");
    add_email("jane@example.com", "Testing 1, 2, 3", "Just checking if this works.");

    print_emails();

    send_email("john@example.com", "Important message", "Please read this ASAP!");

    return 0;
}