//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char email[MAX_EMAIL_LENGTH];
    int subscribed;
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email(char* email) {
    if (num_emails >= MAX_EMAILS) {
        printf("Sorry, email list is full.\n");
        return;
    }
    strcpy(emails[num_emails].email, email);
    emails[num_emails].subscribed = 1;
    num_emails++;
}

void remove_email(char* email) {
    int i;
    for (i = 0; i < num_emails; i++) {
        if (strcmp(emails[i].email, email) == 0) {
            emails[i].subscribed = 0;
            printf("Email removed from list.\n");
            return;
        }
    }
    printf("Email not found in list.\n");
}

void send_email(char* subject, char* body) {
    int i;
    for (i = 0; i < num_emails; i++) {
        if (emails[i].subscribed) {
            printf("Sending email to %s...\n", emails[i].email);
        }
    }
}

int main() {
    char email[MAX_EMAIL_LENGTH];
    while (1) {
        printf("Enter an email (leave blank to stop): ");
        scanf("%s", email);
        if (strcmp(email, "") == 0) {
            break;
        }
        add_email(email);
    }
    while (1) {
        printf("Enter an email to remove (leave blank to stop): ");
        scanf("%s", email);
        if (strcmp(email, "") == 0) {
            break;
        }
        remove_email(email);
    }
    while (1) {
        printf("Enter a subject (leave blank to stop): ");
        scanf("%s", email);
        if (strcmp(email, "") == 0) {
            break;
        }
        send_email(email, "Hello World!");
    }
    return 0;
}