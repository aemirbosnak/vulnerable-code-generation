//Falcon-180B DATASET v1.0 Category: Email Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RECIPIENTS 100

typedef struct {
    char *name;
    char *email;
} recipient;

typedef struct {
    char *subject;
    char *body;
    int num_recipients;
    recipient *recipients;
} email;

void add_recipient(recipient *recipients, int *num_recipients, char *name, char *email) {
    recipients[*num_recipients] = (recipient) {
       .name = name,
       .email = email
    };

    (*num_recipients)++;
}

int main() {
    char input[1024];
    char *subject = NULL;
    char *body = NULL;
    int num_recipients = 0;
    recipient *recipients = NULL;

    // Prompt user for email subject
    printf("Enter email subject: ");
    fgets(input, 1024, stdin);
    subject = strdup(input);
    subject = strtok(subject, "\n");

    // Prompt user for email body
    printf("Enter email body: ");
    fgets(input, 1024, stdin);
    body = strdup(input);
    body = strtok(body, "\n");

    // Prompt user for recipients
    while (1) {
        printf("Enter recipient name and email (or press enter to finish): ");
        fgets(input, 1024, stdin);
        char *name = strtok(input, ":");
        char *email = strtok(NULL, ":");

        if (name == NULL || email == NULL) {
            break;
        }

        add_recipient(recipients, &num_recipients, name, email);
    }

    // Send email to recipients
    for (int i = 0; i < num_recipients; i++) {
        recipient *r = &recipients[i];
        printf("Sending email to %s <%s>...\n", r->name, r->email);
    }

    return 0;
}