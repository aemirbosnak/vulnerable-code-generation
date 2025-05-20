//Falcon-180B DATASET v1.0 Category: Email Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_LEN 1024
#define MAX_SUBJECT_LEN 256
#define MAX_RECIPIENTS 10

typedef struct {
    char name[MAX_EMAIL_LEN];
    char email[MAX_EMAIL_LEN];
} recipient;

typedef struct {
    char from[MAX_EMAIL_LEN];
    char to[MAX_EMAIL_LEN];
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_EMAIL_LEN];
    int num_recipients;
    recipient recipients[MAX_RECIPIENTS];
} email;

void process_input(email* email) {
    printf("Enter the sender's email address: ");
    scanf("%s", email->from);

    printf("Enter the recipient's email address: ");
    scanf("%s", email->to);

    printf("Enter the email subject: ");
    scanf("%s", email->subject);

    printf("Enter the email body: ");
    fgets(email->body, MAX_EMAIL_LEN, stdin);
    email->body[strcspn(email->body, "\n")] = '\0'; // Remove newline character

    printf("Enter the number of recipients: ");
    scanf("%d", &email->num_recipients);

    for (int i = 0; i < email->num_recipients; i++) {
        printf("Enter recipient %d's name: ", i+1);
        scanf("%s", email->recipients[i].name);

        printf("Enter recipient %d's email address: ", i+1);
        scanf("%s", email->recipients[i].email);
    }
}

void send_email(email* email) {
    printf("Sending email to %s...\n", email->to);
    for (int i = 0; i < email->num_recipients; i++) {
        printf("Sending email to %s (%s)...\n", email->recipients[i].name, email->recipients[i].email);
    }
}

int main() {
    email email;
    process_input(&email);
    send_email(&email);

    return 0;
}