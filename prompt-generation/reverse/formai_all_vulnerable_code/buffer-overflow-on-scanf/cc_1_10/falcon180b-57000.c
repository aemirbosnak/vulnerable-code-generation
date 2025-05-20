//Falcon-180B DATASET v1.0 Category: Email Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_RECIPIENTS 10

typedef struct {
    char *name;
    char *email;
} recipient_t;

typedef struct {
    char *subject;
    char *body;
    recipient_t recipients[MAX_RECIPIENTS];
    int num_recipients;
} email_t;

void add_recipient(email_t *email) {
    if (email->num_recipients >= MAX_RECIPIENTS) {
        printf("Error: Too many recipients.\n");
        return;
    }

    char name[50];
    char email_str[100];
    printf("Enter recipient name: ");
    scanf("%s", name);

    printf("Enter recipient email: ");
    scanf("%s", email_str);

    email->recipients[email->num_recipients].name = strdup(name);
    email->recipients[email->num_recipients].email = strdup(email_str);

    email->num_recipients++;
}

void send_email(email_t *email) {
    time_t now = time(NULL);
    char timestamp[20];
    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));

    FILE *file = fopen("emails.txt", "a");
    if (file == NULL) {
        printf("Error: Could not open emails file.\n");
        return;
    }

    fprintf(file, "From: %s\n", email->recipients[0].email);
    fprintf(file, "To: %s\n", email->recipients[0].email);
    fprintf(file, "Subject: %s\n", email->subject);
    fprintf(file, "Date: %s\n", timestamp);
    fprintf(file, "\n");
    fprintf(file, "%s\n", email->body);

    fclose(file);

    printf("Email sent successfully.\n");
}

int main() {
    email_t email;

    printf("Enter subject (max %d characters): ", MAX_SUBJECT_LENGTH);
    scanf("%s", email.subject);

    printf("Enter body (max %d characters): ", MAX_BODY_LENGTH);
    scanf("%s", email.body);

    int num_recipients = 0;
    while (num_recipients < MAX_RECIPIENTS) {
        add_recipient(&email);
        num_recipients++;
    }

    send_email(&email);

    return 0;
}