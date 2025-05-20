//Falcon-180B DATASET v1.0 Category: Email Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 2048
#define MAX_SUBJECT_LENGTH 2048
#define MAX_FROM_LENGTH 2048
#define MAX_TO_LENGTH 2048
#define MAX_BODY_LENGTH 2048

typedef struct {
    char *subject;
    char *from;
    char *to;
    char *body;
} email;

void read_email(email *e) {
    char line[MAX_LINE_LENGTH];
    char *p = e->body;
    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        if (strlen(line) > MAX_BODY_LENGTH - strlen(p)) {
            printf("Error: Email body exceeds maximum length.\n");
            exit(1);
        }
        strcat(p, line);
        p += strlen(line);
    }
    *p = '\0';
}

int main() {
    email e;
    char line[MAX_LINE_LENGTH];
    char *p = e.body;
    printf("Enter email subject: ");
    fgets(e.subject, MAX_SUBJECT_LENGTH, stdin);
    printf("Enter email recipient: ");
    fgets(e.to, MAX_TO_LENGTH, stdin);
    printf("Enter email sender: ");
    fgets(e.from, MAX_FROM_LENGTH, stdin);
    printf("Enter email body: ");
    read_email(&e);
    printf("Subject: %s\n", e.subject);
    printf("From: %s\n", e.from);
    printf("To: %s\n", e.to);
    printf("Body:\n%s", e.body);
    return 0;
}