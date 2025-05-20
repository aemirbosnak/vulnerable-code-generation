//Falcon-180B DATASET v1.0 Category: Email Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAIL_LENGTH 1024
#define MAX_RECIPIENTS 10
#define MAX_SUBJECT_LENGTH 128
#define MAX_BODY_LENGTH 10240

typedef struct {
    char *name;
    char *email;
} recipient;

typedef struct {
    char *subject;
    char *body;
    recipient *recipients;
    int num_recipients;
    time_t timestamp;
} email;

email *create_email(char *subject, char *body) {
    email *e = malloc(sizeof(email));
    e->subject = strdup(subject);
    e->body = strdup(body);
    e->recipients = NULL;
    e->num_recipients = 0;
    e->timestamp = time(NULL);
    return e;
}

void add_recipient(email *e, char *name, char *email) {
    recipient *r = malloc(sizeof(recipient));
    r->name = strdup(name);
    r->email = strdup(email);
    e->recipients = realloc(e->recipients, sizeof(recipient) * (e->num_recipients + 1));
    e->recipients[e->num_recipients] = *r;
    e->num_recipients++;
}

void send_email(email *e) {
    printf("Sending email with subject '%s' to %d recipient(s):\n", e->subject, e->num_recipients);
    for (int i = 0; i < e->num_recipients; i++) {
        printf("  %s <%s>\n", e->recipients[i].name, e->recipients[i].email);
    }
}

void free_email(email *e) {
    free(e->subject);
    free(e->body);
    for (int i = 0; i < e->num_recipients; i++) {
        free(e->recipients[i].name);
        free(e->recipients[i].email);
    }
    free(e->recipients);
    free(e);
}

int main() {
    email *e = create_email("Test email", "This is a test email sent from the C email client.");
    add_recipient(e, "John Doe", "john.doe@example.com");
    add_recipient(e, "Jane Doe", "jane.doe@example.com");
    send_email(e);
    free_email(e);
    return 0;
}