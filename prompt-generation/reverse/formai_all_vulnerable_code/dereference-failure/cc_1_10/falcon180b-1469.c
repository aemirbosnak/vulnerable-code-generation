//Falcon-180B DATASET v1.0 Category: Email Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024
#define MAX_SUBJECT 80
#define MAX_EMAIL 80
#define MAX_BODY 2048

char *get_line(FILE *fp)
{
    char line[MAX_LINE];
    char *result = NULL;

    fgets(line, MAX_LINE, fp);
    result = strdup(line);
    result[strcspn(result, "\r\n")] = '\0';

    return result;
}

char *get_subject(FILE *fp)
{
    char line[MAX_LINE];
    char *result = NULL;

    fgets(line, MAX_LINE, fp);
    result = strdup(line);
    result[strcspn(result, ":")] = '\0';

    return result;
}

char *get_email(FILE *fp)
{
    char line[MAX_LINE];
    char *result = NULL;

    fgets(line, MAX_LINE, fp);
    result = strdup(line);
    result[strcspn(result, "\r\n")] = '\0';

    return result;
}

char *get_body(FILE *fp)
{
    char line[MAX_LINE];
    char *result = NULL;

    while (fgets(line, MAX_LINE, fp)) {
        if (strncmp(line, "\r\n", 2) == 0) {
            break;
        }
        result = realloc(result, strlen(result) + strlen(line) + 2);
        strcat(result, line);
    }

    return result;
}

void print_email(const char *subject, const char *email, const char *body)
{
    printf("Subject: %s\n", subject);
    printf("From: %s\n", email);
    printf("Body:\n%s\n", body);
}

int main(int argc, char *argv[])
{
    FILE *fp;
    char *filename;
    char *subject;
    char *email;
    char *body;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    filename = argv[1];
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    subject = get_subject(fp);
    email = get_email(fp);
    body = get_body(fp);

    print_email(subject, email, body);

    free(subject);
    free(email);
    free(body);
    fclose(fp);

    return 0;
}