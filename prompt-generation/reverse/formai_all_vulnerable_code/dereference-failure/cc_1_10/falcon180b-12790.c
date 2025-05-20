//Falcon-180B DATASET v1.0 Category: Email Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_EMAIL_SIZE 100
#define MAX_SUBJECT_SIZE 50
#define MAX_BODY_SIZE 1000

// Function prototypes
char* read_line(FILE* fp);
int is_valid_email(char* email);
void send_email(char* to, char* subject, char* body);

int main() {
    char input_buffer[MAX_LINE_SIZE];
    char* to = NULL;
    char* subject = NULL;
    char* body = NULL;
    char* email_ptr = NULL;
    char* line_ptr = NULL;
    char* token_ptr = NULL;
    char* token = NULL;
    int email_count = 0;
    int body_count = 0;

    printf("Enter the recipient's email address: ");
    fgets(input_buffer, MAX_LINE_SIZE, stdin);
    to = strtok(input_buffer, "\n");

    printf("Enter the email subject: ");
    fgets(input_buffer, MAX_LINE_SIZE, stdin);
    subject = strtok(input_buffer, "\n");

    printf("Enter the email body:\n");
    while (fgets(input_buffer, MAX_LINE_SIZE, stdin)!= NULL) {
        body_count++;
        if (body_count == 1) {
            body = strdup(input_buffer);
        } else {
            strcat(body, input_buffer);
        }
    }

    email_ptr = strtok(body, "\n");
    while (email_ptr!= NULL) {
        email_count++;
        if (email_count == 1) {
            to = strdup(email_ptr);
        } else if (is_valid_email(email_ptr)) {
            send_email(to, subject, body);
        }
        email_ptr = strtok(NULL, "\n");
    }

    return 0;
}

char* read_line(FILE* fp) {
    char* line = NULL;
    size_t n = 0;
    char ch;

    line = malloc(MAX_LINE_SIZE);
    if (line == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF && ch!= '\n') {
        line[n++] = ch;
    }

    line[n] = '\0';
    return line;
}

int is_valid_email(char* email) {
    int i = 0;
    int at_count = 0;
    int dot_count = 0;

    while (email[i]!= '\0') {
        if (email[i] == '@') {
            at_count++;
        } else if (email[i] == '.') {
            dot_count++;
        }
        i++;
    }

    if (at_count!= 1 || dot_count < 1) {
        return 0;
    }

    return 1;
}

void send_email(char* to, char* subject, char* body) {
    printf("Sending email to %s with subject '%s' and body:\n%s\n", to, subject, body);
}