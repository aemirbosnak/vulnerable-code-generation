#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_RECIPIENT_LENGTH 50
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 200

void sendEmail(char recipient[MAX_RECIPIENT_LENGTH], char subject[MAX_SUBJECT_LENGTH], char body[MAX_BODY_LENGTH]) {
    printf("Sending email to %s with subject: %s\n", recipient, subject);
    printf("Email body:\n%s\n", body);
}

int main() {
    char recipient[MAX_RECIPIENT_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];

    printf("Enter recipient's email address:\n");
    scanf("%s", recipient);

    printf("Enter email subject:\n");
    scanf("%s", subject);

    printf("Enter email body:\n");
    scanf("%s", body);

    sendEmail(recipient, subject, body);

    return 0;
}
