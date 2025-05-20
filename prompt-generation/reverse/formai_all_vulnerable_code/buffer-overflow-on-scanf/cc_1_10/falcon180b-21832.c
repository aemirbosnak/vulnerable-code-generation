//Falcon-180B DATASET v1.0 Category: Email Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_LENGTH 1024
#define MAX_SUBJECT_LENGTH 256
#define MAX_RECIPIENT_LENGTH 256
#define MAX_BODY_LENGTH 4096

typedef struct {
    char from[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char recipient[MAX_RECIPIENT_LENGTH];
    int attachment_count;
    char attachments[MAX_EMAIL_LENGTH];
} Email;

int main() {
    Email email;
    char input[MAX_EMAIL_LENGTH];
    int i;

    printf("Enter your email address: ");
    scanf("%s", email.from);

    printf("Enter the recipient's email address: ");
    scanf("%s", email.recipient);

    printf("Enter the subject: ");
    scanf("%s", email.subject);

    printf("Enter the body: ");
    scanf("%s", email.body);

    printf("Do you want to attach a file? (y/n): ");
    scanf(" %c", &input[0]);

    if (input[0] == 'y') {
        printf("Enter the filename: ");
        scanf("%s", email.attachments);
        email.attachment_count = 1;
    } else {
        email.attachment_count = 0;
    }

    printf("Your email has been sent!\n");

    return 0;
}