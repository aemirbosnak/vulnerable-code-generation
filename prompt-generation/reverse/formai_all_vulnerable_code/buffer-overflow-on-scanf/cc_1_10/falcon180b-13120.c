//Falcon-180B DATASET v1.0 Category: Email Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_RECIPIENTS 10

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
    char to[MAX_RECIPIENTS][100];
    int num_recipients;
} Email;

void add_recipient(Email *email, char *to) {
    int i;
    for (i = 0; i < email->num_recipients; i++) {
        if (strcmp(to, email->to[i]) == 0) {
            return;
        }
    }
    strcpy(email->to[email->num_recipients], to);
    email->num_recipients++;
}

void send_email(Email *email) {
    FILE *file;
    int i;
    file = fopen("emails.txt", "a");
    fprintf(file, "Subject: %s\n", email->subject);
    fprintf(file, "To: %s\n", email->to[0]);
    fprintf(file, "Timestamp: %s\n", ctime(&email->timestamp));
    fprintf(file, "Body:\n%s\n", email->body);
    fclose(file);
}

int main() {
    Email email;
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char to[MAX_RECIPIENTS][100];
    int num_recipients = 0;
    char choice;
    do {
        printf("Enter subject (up to %d characters):\n", MAX_SUBJECT_LENGTH - 1);
        scanf("%s", subject);
        printf("Enter body (up to %d characters):\n", MAX_BODY_LENGTH - 1);
        scanf("%[^\n]", body);
        printf("Enter recipient (or type 'done' when finished):\n");
        scanf("%s", to[num_recipients]);
        if (strcmp(to[num_recipients], "done") == 0) {
            break;
        }
        num_recipients++;
    } while (num_recipients < MAX_RECIPIENTS);
    email.num_recipients = num_recipients;
    strcpy(email.subject, subject);
    strcpy(email.body, body);
    time(&email.timestamp);
    for (int i = 0; i < num_recipients; i++) {
        strcpy(email.to[i], to[i]);
    }
    send_email(&email);
    return 0;
}