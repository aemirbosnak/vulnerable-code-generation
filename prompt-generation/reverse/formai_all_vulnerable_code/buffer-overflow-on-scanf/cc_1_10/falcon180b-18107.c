//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 1000
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECT_LEN 100
#define MAX_BODY_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email(char *name, char *email) {
    strcpy(emails[num_emails].name, name);
    strcpy(emails[num_emails].email, email);
    num_emails++;
}

void send_email(char *subject, char *body) {
    for (int i = 0; i < num_emails; i++) {
        printf("Sending email to %s (%s)\n", emails[i].name, emails[i].email);
        system(sprintf("echo '%s' | mail -s '%s' %s", body, subject, emails[i].email));
    }
}

int main() {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your email: ");
    scanf("%s", email);

    add_email(name, email);

    printf("Enter the subject of the email: ");
    scanf("%s", subject);

    printf("Enter the body of the email:\n");
    fgets(body, MAX_BODY_LEN, stdin);

    send_email(subject, body);

    return 0;
}