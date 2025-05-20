//Falcon-180B DATASET v1.0 Category: Email Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_SUBJECT_LENGTH 256
#define MAX_BODY_LENGTH 1024*10

typedef struct {
    char *subject;
    char *body;
    int body_length;
} Email;

Email *parse_email(char *line) {
    Email *email = malloc(sizeof(Email));
    email->body = NULL;
    email->body_length = 0;
    char *ptr = strchr(line, ':');
    if (ptr == NULL) {
        free(email);
        return NULL;
    }
    *ptr = '\0';
    email->subject = strdup(line);
    line = ptr + 1;
    while (isspace(*line)) {
        line++;
    }
    while (*line!= '\0' && *line!= '\r' && *line!= '\n') {
        email->body_length++;
        line++;
    }
    email->body = malloc(email->body_length + 1);
    strncpy(email->body, line, email->body_length);
    email->body[email->body_length] = '\0';
    return email;
}

void print_email(Email *email) {
    printf("Subject: %s\n", email->subject);
    printf("Body:\n%s\n", email->body);
}

void free_email(Email *email) {
    free(email->subject);
    free(email->body);
    free(email);
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    Email *email = NULL;
    fp = fopen("email.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        email = parse_email(line);
        if (email!= NULL) {
            print_email(email);
            free_email(email);
        }
    }
    fclose(fp);
    return 0;
}