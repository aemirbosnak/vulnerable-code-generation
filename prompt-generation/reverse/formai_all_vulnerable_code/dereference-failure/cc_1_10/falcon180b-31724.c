//Falcon-180B DATASET v1.0 Category: Email Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_EMAIL_ADDRESS_LENGTH 100
#define MAX_EMAIL_SUBJECT_LENGTH 200
#define MAX_EMAIL_BODY_LENGTH 2000

typedef struct {
    char *email_address;
    char *email_subject;
    char *email_body;
    time_t timestamp;
} Email;

Email *emails;
int num_emails;

void add_email(char *email_address, char *email_subject, char *email_body) {
    Email *new_email = (Email *)malloc(sizeof(Email));
    new_email->email_address = strdup(email_address);
    new_email->email_subject = strdup(email_subject);
    new_email->email_body = strdup(email_body);
    new_email->timestamp = time(NULL);
    emails = (Email *)realloc(emails, sizeof(Email) * ++num_emails);
    emails[num_emails - 1] = *new_email;
    free(new_email);
}

void print_emails() {
    for (int i = 0; i < num_emails; i++) {
        printf("Email %d:\n", i + 1);
        printf("From: %s\n", emails[i].email_address);
        printf("Subject: %s\n", emails[i].email_subject);
        printf("Body:\n%s\n", emails[i].email_body);
        printf("Timestamp: %s\n\n", ctime(&emails[i].timestamp));
    }
}

int main() {
    emails = (Email *)malloc(sizeof(Email));
    num_emails = 0;

    char *email_address = "example@example.com";
    char *email_subject = "Test Email";
    char *email_body = "This is a test email. ";
    add_email(email_address, email_subject, email_body);

    print_emails();

    return 0;
}