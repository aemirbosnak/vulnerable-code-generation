//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 1000
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    int subscribed;
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email(char *name, char *email) {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: Too many emails\n");
        return;
    }
    strcpy(emails[num_emails].name, name);
    strcpy(emails[num_emails].email, email);
    emails[num_emails].subscribed = 1;
    num_emails++;
}

void remove_email(char *email) {
    int i;
    for (i = 0; i < num_emails; i++) {
        if (strcmp(emails[i].email, email) == 0) {
            emails[i].subscribed = 0;
            break;
        }
    }
}

void send_email(char *subject, char *body) {
    int i;
    for (i = 0; i < num_emails; i++) {
        if (emails[i].subscribed) {
            printf("Sending email to %s (%s)\n", emails[i].name, emails[i].email);
        }
    }
}

int main() {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char action[MAX_NAME_LEN];
    char subject[MAX_NAME_LEN];
    char body[MAX_EMAIL_LEN];

    while (1) {
        printf("Enter action (add/remove/send): ");
        scanf("%s", action);
        if (strcmp(action, "add") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter email: ");
            scanf("%s", email);
            add_email(name, email);
        } else if (strcmp(action, "remove") == 0) {
            printf("Enter email: ");
            scanf("%s", email);
            remove_email(email);
        } else if (strcmp(action, "send") == 0) {
            printf("Enter subject: ");
            scanf("%s", subject);
            printf("Enter body: ");
            scanf("%s", body);
            send_email(subject, body);
        } else {
            printf("Invalid action\n");
        }
    }

    return 0;
}