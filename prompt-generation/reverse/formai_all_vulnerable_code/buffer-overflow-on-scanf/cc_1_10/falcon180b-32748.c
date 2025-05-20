//Falcon-180B DATASET v1.0 Category: Email Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAIL_LENGTH 1024
#define MAX_SUBJECT_LENGTH 256
#define MAX_BODY_LENGTH 4096
#define MAX_ATTACHMENTS 10

typedef struct {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    int num_attachments;
    char attachments[MAX_ATTACHMENTS][MAX_EMAIL_LENGTH];
} Email;

int main() {
    Email email;
    char input[MAX_EMAIL_LENGTH];
    int i, j, k;

    // Prompt user for email details
    printf("From: ");
    fgets(input, MAX_EMAIL_LENGTH, stdin);
    strcpy(email.from, input);

    printf("To: ");
    fgets(input, MAX_EMAIL_LENGTH, stdin);
    strcpy(email.to, input);

    printf("Subject: ");
    fgets(input, MAX_SUBJECT_LENGTH, stdin);
    strcpy(email.subject, input);

    printf("Body: ");
    fgets(email.body, MAX_BODY_LENGTH, stdin);

    // Prompt user for attachments
    printf("Number of attachments: ");
    scanf("%d", &email.num_attachments);

    for (i = 0; i < email.num_attachments; i++) {
        printf("Attachment %d: ", i+1);
        fgets(input, MAX_EMAIL_LENGTH, stdin);
        strcpy(email.attachments[i], input);
    }

    // Send email
    time_t now = time(NULL);
    char timestamp[32];
    strftime(timestamp, 32, "%Y-%m-%d %H:%M:%S", localtime(&now));

    printf("Email sent on %s:\n", timestamp);
    printf("From: %s\n", email.from);
    printf("To: %s\n", email.to);
    printf("Subject: %s\n", email.subject);
    printf("Body:\n%s", email.body);

    for (i = 0; i < email.num_attachments; i++) {
        printf("\nAttachment %d:\n%s", i+1, email.attachments[i]);
    }

    return 0;
}