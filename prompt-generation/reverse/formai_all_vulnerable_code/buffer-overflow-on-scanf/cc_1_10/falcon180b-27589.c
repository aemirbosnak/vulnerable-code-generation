//Falcon-180B DATASET v1.0 Category: Email Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024
#define MAX_SUBJECT_LEN 256
#define MAX_FROM_LEN 256
#define MAX_TO_LEN 256
#define MAX_BODY_LEN 1024

typedef struct {
    char *subject;
    char *from;
    char *to;
    char *body;
} Email;

void read_email(FILE *fp, Email *email) {
    char line[MAX_LINE_LEN];
    char *ptr;
    char *subject_start = NULL;
    char *body_start = NULL;

    email->subject = NULL;
    email->from = NULL;
    email->to = NULL;
    email->body = NULL;

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        ptr = line;
        while (*ptr!= '\n' && *ptr!= '\r') {
            if (subject_start == NULL && strncasecmp(ptr, "Subject:", 8) == 0) {
                subject_start = ptr + 8;
            } else if (body_start == NULL && strncasecmp(ptr, "Content-Type:", 13) == 0) {
                ptr += 13;
                while (*ptr!= '\n' && *ptr!= '\r') {
                    if (*ptr == ';') {
                        break;
                    }
                    ptr++;
                }
                if (*ptr == '\n' || *ptr == '\r') {
                    ptr++;
                    body_start = ptr;
                }
            }
            ptr++;
        }

        if (subject_start!= NULL) {
            email->subject = strndup(subject_start, MAX_SUBJECT_LEN);
            subject_start = NULL;
        }

        if (body_start!= NULL) {
            email->body = strndup(body_start, MAX_BODY_LEN);
            body_start = NULL;
        }
    }
}

void print_email(Email *email) {
    printf("Subject: %s\n", email->subject);
    printf("From: %s\n", email->from);
    printf("To: %s\n", email->to);
    printf("Body:\n%s\n", email->body);
}

int main() {
    FILE *fp;
    char filename[MAX_LINE_LEN];
    Email email;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(1);
    }

    read_email(fp, &email);
    print_email(&email);

    fclose(fp);
    free(email.subject);
    free(email.from);
    free(email.to);
    free(email.body);

    return 0;
}