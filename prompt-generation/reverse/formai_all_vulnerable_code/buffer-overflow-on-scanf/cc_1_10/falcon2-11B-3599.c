//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define MAX_EMAIL 100
#define MAX_SUBJECT 100
#define MAX_MESSAGE 1000

struct email {
    char email[MAX_EMAIL];
    char subject[MAX_SUBJECT];
    char message[MAX_MESSAGE];
    int sender;
};

void send_email(struct email* emails, int num_emails) {
    for (int i = 0; i < num_emails; i++) {
        printf("From: %s\nSubject: %s\n\n%s\n\n", emails[i].email, emails[i].subject, emails[i].message);
        sleep(1);
    }
}

void add_email(struct email* emails, int* num_emails, char* email, char* subject, char* message, int sender) {
    struct email new_email;
    strcpy(new_email.email, email);
    strcpy(new_email.subject, subject);
    strcpy(new_email.message, message);
    new_email.sender = sender;

    (*num_emails)++;
    emails[(*num_emails) - 1] = new_email;
}

void remove_email(struct email* emails, int* num_emails, int index) {
    for (int i = index; i < *num_emails - 1; i++) {
        emails[i] = emails[i + 1];
    }
    (*num_emails)--;
}

void display_emails(struct email* emails, int num_emails) {
    printf("Email list:\n");
    for (int i = 0; i < num_emails; i++) {
        printf("From: %s\nSubject: %s\n\n%s\n\n", emails[i].email, emails[i].subject, emails[i].message);
    }
}

int main() {
    struct email emails[MAX_EMAIL];
    int num_emails = 0;
    char email[MAX_EMAIL];
    char subject[MAX_SUBJECT];
    char message[MAX_MESSAGE];
    int sender;

    printf("Enter email address: ");
    scanf("%s", email);
    printf("Enter email subject: ");
    scanf("%s", subject);
    printf("Enter email message: ");
    scanf("%s", message);
    printf("Enter sender's email address: ");
    scanf("%d", &sender);

    add_email(emails, &num_emails, email, subject, message, sender);
    display_emails(emails, num_emails);

    printf("Do you want to add another email? (y/n): ");
    char choice;
    scanf(" %c", &choice);

    while (choice == 'y' || choice == 'Y') {
        printf("Enter email address: ");
        scanf("%s", email);
        printf("Enter email subject: ");
        scanf("%s", subject);
        printf("Enter email message: ");
        scanf("%s", message);
        printf("Enter sender's email address: ");
        scanf("%d", &sender);

        add_email(emails, &num_emails, email, subject, message, sender);
        display_emails(emails, num_emails);

        printf("Do you want to add another email? (y/n): ");
        scanf(" %c", &choice);
    }

    printf("Enter email index to remove: ");
    scanf("%d", &index);
    remove_email(emails, &num_emails, index);
    display_emails(emails, num_emails);

    send_email(emails, num_emails);

    return 0;
}