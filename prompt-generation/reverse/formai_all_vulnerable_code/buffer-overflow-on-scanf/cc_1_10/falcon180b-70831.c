//Falcon-180B DATASET v1.0 Category: Email Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 50
#define MAX_RECIPIENTS 10
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 1000

typedef struct {
    char from[MAX_EMAILS][50];
    char to[MAX_RECIPIENTS][50];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t sent_time;
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void send_email(char* from, char* to, char* subject, char* body) {
    strcpy(emails[num_emails].from, from);
    strcpy(emails[num_emails].to[0], to);
    strcpy(emails[num_emails].subject, subject);
    strcpy(emails[num_emails].body, body);
    time(&emails[num_emails].sent_time);
    num_emails++;
}

void display_emails() {
    printf("From\tTo\tSubject\tSent Time\n");
    for (int i = 0; i < num_emails; i++) {
        printf("%s\t%s\t%s\t%s\n", emails[i].from, emails[i].to[0], emails[i].subject, ctime(&emails[i].sent_time));
    }
}

int main() {
    char from[50], to[50], subject[MAX_SUBJECT_LENGTH], body[MAX_BODY_LENGTH];
    while (1) {
        printf("Enter your email address: ");
        scanf("%s", from);
        printf("Enter recipient email address: ");
        scanf("%s", to);
        printf("Enter email subject: ");
        scanf("%s", subject);
        printf("Enter email body: ");
        scanf("%[^\n]", body);
        send_email(from, to, subject, body);
        printf("Email sent successfully.\n");
        display_emails();
    }
    return 0;
}