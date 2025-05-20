//Falcon-180B DATASET v1.0 Category: Email Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_EMAILS 1000
#define MAX_EMAIL_SIZE 1024
#define MAX_SUBJECT_SIZE 1024
#define MAX_BODY_SIZE 1024
#define MAX_RECIPIENTS 100

typedef struct email {
    char *from;
    char *to;
    char *subject;
    char *body;
    int num_recipients;
    char **recipients;
} Email;

typedef struct email_client {
    Email *emails;
    int num_emails;
} EmailClient;

void init_client(EmailClient *client) {
    client->emails = NULL;
    client->num_emails = 0;
}

void free_client(EmailClient *client) {
    int i;
    for (i = 0; i < client->num_emails; i++) {
        free(client->emails[i].from);
        free(client->emails[i].to);
        free(client->emails[i].subject);
        free(client->emails[i].body);
        free(client->emails[i].recipients);
    }
    free(client->emails);
}

void add_email(EmailClient *client, char *from, char *to, char *subject, char *body, int num_recipients, char **recipients) {
    Email *email = malloc(sizeof(Email));
    email->from = strdup(from);
    email->to = strdup(to);
    email->subject = strdup(subject);
    email->body = strdup(body);
    email->num_recipients = num_recipients;
    email->recipients = malloc(num_recipients * sizeof(char *));
    int j;
    for (j = 0; j < num_recipients; j++) {
        email->recipients[j] = strdup(recipients[j]);
    }
    client->emails = realloc(client->emails, sizeof(Email) * (client->num_emails + 1));
    client->emails[client->num_emails] = *email;
    client->num_emails++;
}

void print_email(Email *email) {
    printf("From: %s\n", email->from);
    printf("To: %s\n", email->to);
    printf("Subject: %s\n", email->subject);
    printf("Body:\n%s\n", email->body);
    printf("Recipients:\n");
    int i;
    for (i = 0; i < email->num_recipients; i++) {
        printf("%s\n", email->recipients[i]);
    }
}

int main() {
    EmailClient client;
    init_client(&client);

    add_email(&client, "sender@example.com", "recipient1@example.com", "Test Email", "Hello, World!", 1, (char **) {"recipient2@example.com"});

    int i;
    for (i = 0; i < client.num_emails; i++) {
        print_email(client.emails + i);
    }

    free_client(&client);
    return 0;
}