//Falcon-180B DATASET v1.0 Category: Email Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 80
#define MAX_SUBJECT 80
#define MAX_BODY 1000
#define MAX_RECIPIENTS 10

typedef struct recipient {
    char name[MAX_LINE];
    char email[MAX_LINE];
} recipient_t;

typedef struct email {
    char from[MAX_LINE];
    char to[MAX_LINE];
    char cc[MAX_LINE];
    char subject[MAX_SUBJECT];
    char body[MAX_BODY];
    int num_recipients;
    recipient_t recipients[MAX_RECIPIENTS];
} email_t;

void read_recipients(FILE *fp, email_t *email) {
    char line[MAX_LINE];
    int i = 0;

    while (fgets(line, MAX_LINE, fp)!= NULL) {
        line[strcspn(line, "\r\n")] = '\0';

        if (i >= MAX_RECIPIENTS) {
            printf("Too many recipients!\n");
            break;
        }

        if (strlen(line) == 0) {
            break;
        }

        strcpy(email->recipients[i].name, line);
        strcpy(email->recipients[i].email, "");
        i++;
    }

    email->num_recipients = i;
}

void read_email(FILE *fp, email_t *email) {
    char line[MAX_LINE];
    int i = 0;

    while (fgets(line, MAX_LINE, fp)!= NULL) {
        line[strcspn(line, "\r\n")] = '\0';

        if (i >= MAX_BODY) {
            printf("Body too long!\n");
            break;
        }

        if (strlen(line) == 0) {
            break;
        }

        strcat(email->body, line);
        strcat(email->body, "\r\n");
        i++;
    }
}

int main() {
    FILE *fp;
    email_t email;

    fp = fopen("email.txt", "r");

    if (fp == NULL) {
        printf("Could not open file!\n");
        return 1;
    }

    fscanf(fp, "%s", email.from);
    fscanf(fp, "%s", email.to);
    fscanf(fp, "%s", email.cc);
    fscanf(fp, "%s", email.subject);

    read_recipients(fp, &email);
    read_email(fp, &email);

    fclose(fp);

    printf("From: %s\n", email.from);
    printf("To: %s\n", email.to);
    printf("Cc: %s\n", email.cc);
    printf("Subject: %s\n", email.subject);
    printf("Body:\n%s", email.body);

    return 0;
}