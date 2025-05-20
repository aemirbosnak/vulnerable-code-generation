//Falcon-180B DATASET v1.0 Category: Email Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024
#define MAX_SUBJECT 1024
#define MAX_BODY 1024

typedef struct {
    char *to;
    char *subject;
    char *body;
} Email;

Email *read_email(FILE *fp) {
    Email *email = malloc(sizeof(Email));
    fscanf(fp, "To: %s\n", email->to);
    fscanf(fp, "Subject: %s\n", email->subject);
    fscanf(fp, "Body: %s\n", email->body);
    return email;
}

void print_email(Email *email) {
    printf("To: %s\n", email->to);
    printf("Subject: %s\n", email->subject);
    printf("Body: %s\n", email->body);
}

int main() {
    FILE *fp;
    char filename[MAX_LINE];
    char line[MAX_LINE];
    Email email;

    printf("Enter the filename: ");
    fgets(filename, MAX_LINE, stdin);
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE, fp)!= NULL) {
        if (strncmp(line, "From:", 6) == 0) {
            printf("From: %s\n", line + 6);
        } else if (strncmp(line, "To:", 4) == 0) {
            printf("To: %s\n", line + 4);
        } else if (strncmp(line, "Subject:", 9) == 0) {
            printf("Subject: %s\n", line + 9);
        } else if (strncmp(line, "Body:", 5) == 0) {
            email.to = strdup(line + 6);
            email.subject = strdup(line + 6);
            email.body = strdup(line + 6);
            break;
        }
    }

    email.to = strdup(line + 5);
    email.subject = strdup(line + 5);
    email.body = strdup(line + 5);

    printf("To: %s\n", email.to);
    printf("Subject: %s\n", email.subject);
    printf("Body: %s\n", email.body);

    fclose(fp);
    return 0;
}