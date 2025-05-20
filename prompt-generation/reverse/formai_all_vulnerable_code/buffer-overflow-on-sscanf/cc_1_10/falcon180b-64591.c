//Falcon-180B DATASET v1.0 Category: Email Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_EMAIL_LENGTH 256
#define MAX_SUBJECT_LENGTH 1024
#define MAX_BODY_LENGTH 4096

typedef struct email_t {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

void read_email(Email* email) {
    char line[MAX_LINE_LENGTH];
    int line_count = 0;

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        if (line_count == 0) {
            sscanf(line, "From: %s", email->from);
        } else if (line_count == 1) {
            sscanf(line, "To: %s", email->to);
        } else if (line_count == 2) {
            sscanf(line, "Subject: %s", email->subject);
        } else if (line_count == 3) {
            email->body[0] = '\0';
        } else if (line_count >= 4) {
            strcat(email->body, line);
            strcat(email->body, "\n");
        }

        line_count++;
    }
}

void print_email(Email* email) {
    printf("From: %s\n", email->from);
    printf("To: %s\n", email->to);
    printf("Subject: %s\n", email->subject);
    printf("Body:\n%s", email->body);
}

int main() {
    Email email;
    read_email(&email);
    print_email(&email);

    return 0;
}