//Falcon-180B DATASET v1.0 Category: Email Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 10000
#define MAX_RECIPIENTS 100
#define MAX_ATTACHMENTS 10

typedef struct {
    char* name;
    char* email;
} recipient;

typedef struct {
    char* filename;
    char* content;
} attachment;

typedef struct {
    char* subject;
    char* body;
    int num_recipients;
    recipient* recipients;
    int num_attachments;
    attachment* attachments;
    time_t timestamp;
} email;

void send_email(email* e) {
    printf("Sending email...\n");
    printf("Subject: %s\n", e->subject);
    printf("Body:\n%s\n", e->body);
    for (int i = 0; i < e->num_recipients; i++) {
        printf("Recipient %d: %s <%s>\n", i+1, e->recipients[i].name, e->recipients[i].email);
    }
    for (int i = 0; i < e->num_attachments; i++) {
        printf("Attachment %d: %s\n", i+1, e->attachments[i].filename);
    }
}

int main() {
    email e;
    strcpy(e.subject, "Happy Email!");
    strcpy(e.body, "Hello world!");

    e.num_recipients = 1;
    e.recipients = malloc(sizeof(recipient));
    strcpy(e.recipients[0].name, "John Doe");
    strcpy(e.recipients[0].email, "johndoe@example.com");

    e.num_attachments = 0;
    e.attachments = NULL;

    time_t now = time(NULL);
    e.timestamp = now;

    send_email(&e);

    return 0;
}