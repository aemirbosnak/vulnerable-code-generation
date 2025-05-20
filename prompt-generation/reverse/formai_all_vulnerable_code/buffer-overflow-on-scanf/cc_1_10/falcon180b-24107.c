//Falcon-180B DATASET v1.0 Category: Email Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/timeb.h>

#define MAX_EMAILS 1000
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char sender[MAX_SUBJECT_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
} Email;

int num_emails = 0;
Email emails[MAX_EMAILS];

void add_email(char* sender, char* subject, char* body) {
    strcpy(emails[num_emails].sender, sender);
    strcpy(emails[num_emails].subject, subject);
    strcpy(emails[num_emails].body, body);
    emails[num_emails].timestamp = time(NULL);
    num_emails++;
}

void print_emails() {
    for (int i = 0; i < num_emails; i++) {
        printf("Sender: %s\nSubject: %s\nBody:\n%s\n\n", emails[i].sender, emails[i].subject, emails[i].body);
    }
}

int main() {
    char sender[MAX_SUBJECT_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    while (1) {
        printf("Enter sender email: ");
        scanf("%s", sender);
        printf("Enter subject: ");
        scanf("%s", subject);
        printf("Enter body:\n");
        fgets(body, MAX_BODY_LENGTH, stdin);
        body[strcspn(body, "\n")] = '\0'; // Remove newline character
        add_email(sender, subject, body);
    }
    return 0;
}