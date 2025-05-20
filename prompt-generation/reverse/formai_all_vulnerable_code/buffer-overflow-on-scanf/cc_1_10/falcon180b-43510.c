//Falcon-180B DATASET v1.0 Category: Email Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_RECIPIENTS 10
#define MAX_ATTACHMENTS 5

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char from[MAX_SUBJECT_LENGTH];
    char to[MAX_SUBJECT_LENGTH];
    char cc[MAX_SUBJECT_LENGTH];
    char bcc[MAX_SUBJECT_LENGTH];
    char attachments[MAX_ATTACHMENTS][MAX_SUBJECT_LENGTH];
    int num_attachments;
} Email;

void read_email(Email *email) {
    printf("Enter the subject of the email: ");
    scanf("%s", email->subject);

    printf("Enter the body of the email: ");
    fgets(email->body, MAX_BODY_LENGTH, stdin);
    email->body[strcspn(email->body, "\n")] = '\0';

    printf("Enter the sender's email address: ");
    scanf("%s", email->from);

    printf("Enter the recipient's email address: ");
    scanf("%s", email->to);

    printf("Enter any CC recipients (press enter if none): ");
    scanf("%s", email->cc);

    printf("Enter any BCC recipients (press enter if none): ");
    scanf("%s", email->bcc);

    printf("Enter the number of attachments (0-5): ");
    scanf("%d", &email->num_attachments);

    for (int i = 0; i < email->num_attachments; i++) {
        printf("Enter the filename of attachment %d: ", i+1);
        scanf("%s", email->attachments[i]);
    }
}

void send_email(Email *email) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char timestamp[20];
    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", t);

    printf("From: %s\nTo: %s\nSubject: %s\n\n%s\n",
           email->from, email->to, email->subject, email->body);

    if (email->num_attachments > 0) {
        printf("Attachments:\n");
        for (int i = 0; i < email->num_attachments; i++) {
            printf("%s\n", email->attachments[i]);
        }
    }

    printf("Sent on: %s\n", timestamp);
}

int main() {
    Email email;
    read_email(&email);
    send_email(&email);

    return 0;
}