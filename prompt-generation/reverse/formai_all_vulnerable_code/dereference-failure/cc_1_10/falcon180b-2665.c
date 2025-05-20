//Falcon-180B DATASET v1.0 Category: Email Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 2048
#define MAX_EMAIL_LENGTH 1024
#define MAX_SUBJECT_LENGTH 2048
#define MAX_BODY_LENGTH 2048

typedef struct {
    char *from;
    char *to;
    char *subject;
    char *body;
} email_t;

int main() {
    FILE *input_file;
    email_t email;
    char line[MAX_LINE_LENGTH];
    char *buffer = NULL;
    size_t buffer_size = 0;

    input_file = fopen("emails.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    email.from = NULL;
    email.to = NULL;
    email.subject = NULL;
    email.body = NULL;

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        if (email.from == NULL) {
            email.from = strdup(line);
        } else if (email.to == NULL) {
            email.to = strdup(line);
        } else if (email.subject == NULL) {
            email.subject = strdup(line);
        } else if (email.body == NULL) {
            email.body = strdup(line);
        } else {
            buffer_size += strlen(line);
            buffer = realloc(buffer, buffer_size + 1);
            strcat(buffer, line);
        }
    }

    if (buffer!= NULL) {
        email.body = strdup(buffer);
    }

    fclose(input_file);

    printf("From: %s\n", email.from);
    printf("To: %s\n", email.to);
    printf("Subject: %s\n", email.subject);
    printf("Body:\n%s\n", email.body);

    free(email.from);
    free(email.to);
    free(email.subject);
    free(email.body);
    free(buffer);

    return 0;
}