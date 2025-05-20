//FormAI DATASET v1.0 Category: Email Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100

typedef struct email {
    char sender[MAX_EMAIL_LENGTH];
    char recipient[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_LINE_LENGTH];
} Email;

void print_email(Email email) {
    printf("From: %s\n", email.sender);
    printf("To: %s\n", email.recipient);
    printf("Subject: %s\n", email.subject);
    printf("%s\n", email.body);
}

int main() {
    Email email;
    char input[MAX_LINE_LENGTH];
    int i = 0;

    printf("Enter sender name: ");
    fgets(input, MAX_LINE_LENGTH, stdin);
    sscanf(input, "%s", email.sender);

    printf("Enter recipient name: ");
    fgets(input, MAX_LINE_LENGTH, stdin);
    sscanf(input, "%s", email.recipient);

    printf("Enter subject: ");
    fgets(input, MAX_LINE_LENGTH, stdin);
    sscanf(input, "%s", email.subject);

    printf("Enter body (enter '.' on a new line to end):\n");
    while (1) {
        fgets(input, MAX_LINE_LENGTH, stdin);
        if (input[0] == '.' && isspace(input[1])) {
            break;
        }
        strncpy(email.body + i, input, strlen(input));
        i += strlen(input);
    }
    email.body[i] = '\0';

    print_email(email);

    return 0;
}