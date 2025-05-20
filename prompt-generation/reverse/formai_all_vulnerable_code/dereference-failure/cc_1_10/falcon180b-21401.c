//Falcon-180B DATASET v1.0 Category: Email Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_SUBJECT_LENGTH 256
#define MAX_FROM_LENGTH 256
#define MAX_TO_LENGTH 256
#define MAX_CONTENT_LENGTH 10240

typedef struct {
    char *subject;
    char *from;
    char *to;
    char *content;
} Email;

Email *read_email_file(FILE *fp) {
    Email *email = malloc(sizeof(Email));
    char line[MAX_LINE_LENGTH];
    char *content = NULL;
    size_t content_length = 0;

    email->subject = NULL;
    email->from = NULL;
    email->to = NULL;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (strlen(line) == 0) {
            break;
        }
        if (line[0] == 'S') {
            email->subject = strdup(line + 2);
        } else if (line[0] == 'F') {
            email->from = strdup(line + 2);
        } else if (line[0] == 'T') {
            email->to = strdup(line + 2);
        } else {
            strcat(content, line);
            content_length += strlen(line);
        }
    }

    email->content = strdup(content);
    free(content);

    return email;
}

void print_email(Email *email) {
    printf("Subject: %s\n", email->subject);
    printf("From: %s\n", email->from);
    printf("To: %s\n", email->to);
    printf("Content:\n%s\n", email->content);
}

void free_email(Email *email) {
    free(email->subject);
    free(email->from);
    free(email->to);
    free(email->content);
    free(email);
}

void send_email(Email *email) {
    printf("Sending email to %s...\n", email->to);
    printf("Email sent successfully!\n");
}

int main() {
    Email *email;
    FILE *fp;
    char filename[MAX_LINE_LENGTH];

    printf("Enter email filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found.\n");
        return 1;
    }

    email = read_email_file(fp);
    print_email(email);
    send_email(email);

    free_email(email);
    fclose(fp);

    return 0;
}