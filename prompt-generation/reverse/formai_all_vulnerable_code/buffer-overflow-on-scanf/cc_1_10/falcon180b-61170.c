//Falcon-180B DATASET v1.0 Category: Email Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBJECT_LENGTH 80
#define MAX_BODY_LENGTH 4096

typedef struct {
    char from[MAX_SUBJECT_LENGTH];
    char to[MAX_SUBJECT_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

Email* create_email() {
    Email* email = (Email*) malloc(sizeof(Email));
    strcpy(email->from, "");
    strcpy(email->to, "");
    strcpy(email->subject, "");
    strcpy(email->body, "");
    return email;
}

void print_email(Email* email) {
    printf("From: %s\n", email->from);
    printf("To: %s\n", email->to);
    printf("Subject: %s\n", email->subject);
    printf("Body:\n%s", email->body);
}

int main() {
    Email* email = create_email();

    char input[256];
    printf("Enter the sender's email address: ");
    scanf("%s", input);
    strcpy(email->from, input);

    printf("Enter the recipient's email address: ");
    scanf("%s", input);
    strcpy(email->to, input);

    printf("Enter the subject: ");
    scanf("%s", input);
    strcpy(email->subject, input);

    printf("Enter the body of the email:\n");
    fgets(email->body, MAX_BODY_LENGTH, stdin);

    print_email(email);

    free(email);
    return 0;
}