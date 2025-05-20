//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 200
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Recipient;

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    int recipient_count;
    Recipient recipients[MAX_EMAILS];
} Email;

void add_recipient(Email *email) {
    printf("Enter the name of the recipient: ");
    scanf("%s", email->recipients[email->recipient_count].name);
    printf("Enter the email address of the recipient: ");
    scanf("%s", email->recipients[email->recipient_count].email);
    email->recipient_count++;
}

void send_email(Email *email) {
    printf("Sending email to %s (%s) with subject '%s' and message:\n%s\n", 
        email->recipients[0].name, email->recipients[0].email, 
        email->subject, email->message);
}

int main() {
    Email email;
    email.recipient_count = 0;

    printf("Enter the subject of the email: ");
    scanf("%s", email.subject);

    printf("Enter the message of the email:\n");
    fgets(email.message, MAX_MESSAGE_LENGTH, stdin);

    add_recipient(&email);

    send_email(&email);

    return 0;
}