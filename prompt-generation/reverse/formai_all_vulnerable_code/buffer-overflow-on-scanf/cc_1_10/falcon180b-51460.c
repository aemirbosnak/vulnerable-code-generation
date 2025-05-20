//Falcon-180B DATASET v1.0 Category: Email Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>

#define MAX_EMAIL_LENGTH 1024
#define MAX_SUBJECT_LENGTH 256
#define MAX_BODY_LENGTH 4096
#define MAX_RECIPIENTS 100

typedef struct {
    char *name;
    char *email;
} contact;

typedef struct {
    char *name;
    char *email;
    char *subject;
    char *body;
    time_t timestamp;
} email;

typedef struct {
    email *emails;
    int num_emails;
} inbox;

void init_inbox(inbox *inbox) {
    inbox->emails = NULL;
    inbox->num_emails = 0;
}

void add_email(inbox *inbox, email *email) {
    inbox->emails = realloc(inbox->emails, sizeof(email) * (inbox->num_emails + 1));
    inbox->emails[inbox->num_emails] = *email;
    inbox->num_emails++;
}

void print_email(email *email) {
    printf("From: %s <%s>\n", email->name, email->email);
    printf("Subject: %s\n", email->subject);
    printf("Timestamp: %s\n", ctime(&email->timestamp));
    printf("Body:\n%s\n", email->body);
}

void print_inbox(inbox *inbox) {
    for (int i = 0; i < inbox->num_emails; i++) {
        print_email(&inbox->emails[i]);
    }
}

int main() {
    inbox inbox;
    init_inbox(&inbox);

    while (1) {
        printf("Enter command (send, read, quit): ");
        char command[64];
        scanf("%s", command);

        if (strcmp(command, "send") == 0) {
            char to[MAX_EMAIL_LENGTH];
            printf("Enter recipient email: ");
            scanf("%s", to);

            char subject[MAX_SUBJECT_LENGTH];
            printf("Enter subject: ");
            scanf("%s", subject);

            char body[MAX_BODY_LENGTH];
            printf("Enter body: ");
            fgets(body, MAX_BODY_LENGTH, stdin);
            body[strcspn(body, "\n")] = '\0';

            time_t timestamp = time(NULL);

            email email = {
               .name = "Your Name",
               .email = "your_email@example.com",
               .subject = subject,
               .body = body,
               .timestamp = timestamp
            };

            add_email(&inbox, &email);

            printf("Email sent to %s\n", to);
        } else if (strcmp(command, "read") == 0) {
            print_inbox(&inbox);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}