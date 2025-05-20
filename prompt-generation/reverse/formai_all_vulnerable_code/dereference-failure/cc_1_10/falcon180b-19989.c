//Falcon-180B DATASET v1.0 Category: Email Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024
#define MAX_EMAIL_LEN 100

typedef struct {
    char *subject;
    char *body;
    char from[MAX_EMAIL_LEN];
    char to[MAX_EMAIL_LEN];
    char date[MAX_LINE];
} Email;

void read_email(Email *email, FILE *fp) {
    char line[MAX_LINE];
    char *p;
    int len;

    fgets(line, MAX_LINE, fp);
    if (strncmp(line, "From:", 6) == 0) {
        p = strchr(line, ':');
        if (p) {
            p++;
            len = strlen(p);
            strncpy(email->from, p, len < MAX_EMAIL_LEN? len : MAX_EMAIL_LEN - 1);
        }
    } else if (strncmp(line, "To:", 4) == 0) {
        p = strchr(line, ':');
        if (p) {
            p++;
            len = strlen(p);
            strncpy(email->to, p, len < MAX_EMAIL_LEN? len : MAX_EMAIL_LEN - 1);
        }
    } else if (strncmp(line, "Subject:", 9) == 0) {
        p = strchr(line, ':');
        if (p) {
            p++;
            len = strlen(p);
            strncpy(email->subject, p, len < MAX_LINE? len : MAX_LINE - 1);
        }
    } else if (strncmp(line, "Date:", 6) == 0) {
        p = strchr(line, ':');
        if (p) {
            p++;
            len = strlen(p);
            strncpy(email->date, p, len < MAX_LINE? len : MAX_LINE - 1);
        }
    }
}

int main() {
    FILE *fp;
    Email email;

    fp = fopen("test.eml", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fgets(email.body, MAX_LINE, fp)!= NULL) {
        read_email(&email, fp);
        printf("From: %s\n", email.from);
        printf("To: %s\n", email.to);
        printf("Subject: %s\n", email.subject);
        printf("Date: %s\n", email.date);
        printf("Body:\n%s", email.body);
        printf("\n");
    }

    fclose(fp);
    return 0;
}