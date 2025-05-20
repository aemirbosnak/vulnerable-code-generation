//FormAI DATASET v1.0 Category: Email Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_SIZE 1024
#define MAX_USERNAME_SIZE 20
#define MAX_PASSWORD_SIZE 20
#define MAX_SUBJECT_SIZE 50
#define MAX_BODY_SIZE 500
#define MAX_RECIPIENTS_SIZE 100

struct Email {
    char from[MAX_USERNAME_SIZE];
    char password[MAX_PASSWORD_SIZE];
    char subject[MAX_SUBJECT_SIZE];
    char body[MAX_BODY_SIZE];
    char recipients[MAX_RECIPIENTS_SIZE];
};

void send_email(struct Email email) {
    printf("Sending email from %s to %s\n", email.from, email.recipients);
    printf("Subject: %s\n", email.subject);
    printf("Body: %s\n", email.body);
}

int main() {
    char username[MAX_USERNAME_SIZE];
    char password[MAX_PASSWORD_SIZE];
    char to[MAX_RECIPIENTS_SIZE];
    char subject[MAX_SUBJECT_SIZE];
    char body[MAX_BODY_SIZE];
    
    printf("Enter your email username: ");
    scanf("%s", username);
    
    printf("Enter your email password: ");
    scanf("%s", password);
    
    printf("Enter email recipients (Separated by comma): ");
    scanf("%s", to);
    
    printf("Enter email subject: ");
    scanf("%s", subject);
    
    printf("Enter email body: ");
    scanf("%s", body);
    
    struct Email email;
    strcpy(email.from, username);
    strcpy(email.password, password);
    strcpy(email.recipients, to);
    strcpy(email.subject, subject);
    strcpy(email.body, body);
    
    send_email(email);
    
    return 0;
}