//Falcon-180B DATASET v1.0 Category: Email Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SUBJECT_LENGTH 80
#define MAX_BODY_LENGTH 1024
#define MAX_RECIPIENTS 10

typedef struct {
    char *name;
    char *email;
} Recipient;

typedef struct {
    char *subject;
    char *body;
    Recipient recipients[MAX_RECIPIENTS];
    int num_recipients;
    time_t timestamp;
} Email;

void add_recipient(Email *email, char *name, char *email_address) {
    Recipient *recipient = &email->recipients[email->num_recipients];
    recipient->name = strdup(name);
    recipient->email = strdup(email_address);
    email->num_recipients++;
}

Email *create_email() {
    Email *email = malloc(sizeof(Email));
    email->num_recipients = 0;
    email->timestamp = time(NULL);
    return email;
}

void send_email(Email *email) {
    printf("Sending email:\n");
    printf("Subject: %s\n", email->subject);
    printf("Body:\n%s\n", email->body);
    printf("Recipients:\n");
    for (int i = 0; i < email->num_recipients; i++) {
        printf("  %s <%s>\n", email->recipients[i].name, email->recipients[i].email);
    }
}

int main() {
    Email *email = create_email();
    char from_name[20];
    char from_email[50];
    printf("Enter your name: ");
    scanf("%s", from_name);
    printf("Enter your email address: ");
    scanf("%s", from_email);
    strcpy(email->recipients[0].name, from_name);
    strcpy(email->recipients[0].email, from_email);
    char to_name[20];
    char to_email[50];
    int num_recipients = 0;
    while (num_recipients < MAX_RECIPIENTS) {
        printf("Enter recipient %d's name: ", num_recipients + 1);
        scanf("%s", to_name);
        printf("Enter recipient %d's email address: ", num_recipients + 1);
        scanf("%s", to_email);
        add_recipient(email, to_name, to_email);
        num_recipients++;
    }
    printf("Enter subject: ");
    scanf("%s", email->subject);
    printf("Enter body:\n");
    fgets(email->body, MAX_BODY_LENGTH, stdin);
    send_email(email);
    return 0;
}