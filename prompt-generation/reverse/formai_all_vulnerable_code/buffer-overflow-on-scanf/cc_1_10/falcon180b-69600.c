//Falcon-180B DATASET v1.0 Category: Email Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024
#define MAX_EMAIL_LEN 256
#define MAX_SUBJECT_LEN 256
#define MAX_BODY_LEN 1024

typedef struct email {
    char sender[MAX_EMAIL_LEN];
    char recipient[MAX_EMAIL_LEN];
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
} Email;

void read_email_file(char *filename, Email *email) {
    FILE *fp;
    char line[MAX_LINE_LEN];
    int in_body = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    memset(email, 0, sizeof(Email));

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        if (in_body) {
            strncat(email->body, line, MAX_BODY_LEN - strlen(email->body) - 1);
        } else if (strncmp(line, "From:", 5) == 0) {
            strncpy(email->sender, line + 6, MAX_EMAIL_LEN - 1);
        } else if (strncmp(line, "To:", 3) == 0) {
            strncpy(email->recipient, line + 4, MAX_EMAIL_LEN - 1);
        } else if (strncmp(line, "Subject:", 8) == 0) {
            strncpy(email->subject, line + 9, MAX_SUBJECT_LEN - 1);
        } else if (strncmp(line, "Body:", 5) == 0) {
            in_body = 1;
        }
    }

    fclose(fp);
}

void send_email(Email *email) {
    printf("Sending email from %s to %s with subject %s:\n\n", email->sender, email->recipient, email->subject);
    printf("%s\n", email->body);
}

int main() {
    Email email;
    char filename[MAX_LINE_LEN];

    printf("Enter filename: ");
    scanf("%s", filename);

    read_email_file(filename, &email);
    send_email(&email);

    return 0;
}