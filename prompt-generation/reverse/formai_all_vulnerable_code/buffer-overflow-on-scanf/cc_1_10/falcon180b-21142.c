//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000
#define MAX_RECIPIENTS 1000

typedef struct {
    char email[MAX_EMAIL_LENGTH];
    char name[MAX_EMAIL_LENGTH];
} recipient;

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    int num_recipients;
    recipient *recipients;
} email_template;

void add_recipient(email_template *template, char *email, char *name) {
    if (template->num_recipients >= MAX_RECIPIENTS) {
        printf("Error: Maximum number of recipients reached.\n");
        return;
    }
    strcpy(template->recipients[template->num_recipients].email, email);
    strcpy(template->recipients[template->num_recipients].name, name);
    template->num_recipients++;
}

void send_email(email_template *template) {
    printf("Sending email to %d recipients:\n", template->num_recipients);
    for (int i = 0; i < template->num_recipients; i++) {
        printf("Email: %s\nName: %s\n", template->recipients[i].email, template->recipients[i].name);
    }
}

int main() {
    email_template template;
    char email[MAX_EMAIL_LENGTH];
    char name[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];

    printf("Enter email address: ");
    scanf("%s", email);
    printf("Enter name: ");
    scanf("%s", name);

    add_recipient(&template, email, name);

    printf("Enter subject: ");
    scanf("%s", subject);
    printf("Enter message: ");
    scanf("%[^\n]", message);

    strcpy(template.subject, subject);
    strcpy(template.message, message);

    send_email(&template);

    return 0;
}