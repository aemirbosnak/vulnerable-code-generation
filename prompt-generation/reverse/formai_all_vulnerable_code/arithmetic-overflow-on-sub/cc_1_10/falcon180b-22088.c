//Falcon-180B DATASET v1.0 Category: Email Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LINE 1024
#define MAX_SUBJECT 1024
#define MAX_FROM 1024

typedef struct {
    char *subject;
    char *from;
    time_t date;
    char *body;
} Email;

Email *parse_email(char *line) {
    Email *email = malloc(sizeof(Email));
    char *p = line;
    char *subject = NULL;
    char *from = NULL;
    time_t date = 0;
    char *body = NULL;

    while (*p!= '\n') {
        if (*p == ':') {
            p++;
            if (subject == NULL) {
                subject = p;
            } else if (from == NULL) {
                from = p;
            } else if (body == NULL) {
                body = p;
            }
        }
        p++;
    }

    date = strtol(subject, NULL, 10);
    email->date = date;
    email->subject = strdup(subject);
    email->from = strdup(from);
    email->body = strdup(body);

    return email;
}

void print_email(Email *email) {
    printf("Date: %s\n", ctime(&email->date));
    printf("Subject: %s\n", email->subject);
    printf("From: %s\n", email->from);
    printf("Body:\n%s\n", email->body);
}

int main() {
    FILE *fp;
    char line[MAX_LINE];
    Email *email;

    fp = fopen("inbox.txt", "r");
    if (fp == NULL) {
        printf("Cannot open inbox.txt\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE, fp)!= NULL) {
        email = parse_email(line);
        print_email(email);
        free(email->subject);
        free(email->from);
        free(email->body);
        free(email);
    }

    fclose(fp);

    return 0;
}