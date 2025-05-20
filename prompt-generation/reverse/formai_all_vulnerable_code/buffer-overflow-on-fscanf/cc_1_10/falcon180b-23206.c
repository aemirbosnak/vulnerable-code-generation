//Falcon-180B DATASET v1.0 Category: Email Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char subject[MAX_SUBJECT_LENGTH + 1];
    char body[MAX_BODY_LENGTH + 1];
    time_t timestamp;
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void read_emails() {
    FILE *file = fopen("emails.txt", "r");
    if (file == NULL) {
        printf("No emails found.\n");
        return;
    }

    Email email;
    while (fscanf(file, "%s %s %ld\n", email.subject, email.body, &email.timestamp) == 3) {
        if (num_emails >= MAX_EMAILS) {
            printf("Too many emails.\n");
            break;
        }
        strcpy(emails[num_emails].subject, email.subject);
        strcpy(emails[num_emails].body, email.body);
        num_emails++;
    }

    fclose(file);
}

void write_email(char *subject, char *body) {
    if (num_emails >= MAX_EMAILS) {
        printf("Too many emails.\n");
        return;
    }

    strcpy(emails[num_emails].subject, subject);
    strcpy(emails[num_emails].body, body);
    time(&emails[num_emails].timestamp);
    num_emails++;

    FILE *file = fopen("emails.txt", "a");
    if (file == NULL) {
        printf("Error writing email.\n");
        return;
    }

    fprintf(file, "%s %s %ld\n", emails[num_emails - 1].subject, emails[num_emails - 1].body, emails[num_emails - 1].timestamp);
    fclose(file);
}

void print_emails() {
    if (num_emails == 0) {
        printf("No emails found.\n");
        return;
    }

    printf("Subject\tTimestamp\n");
    for (int i = 0; i < num_emails; i++) {
        printf("%s\t%s\n", emails[i].subject, ctime(&emails[i].timestamp));
    }
}

int main() {
    read_emails();

    char subject[MAX_SUBJECT_LENGTH + 1];
    char body[MAX_BODY_LENGTH + 1];

    while (1) {
        printf("Enter subject: ");
        scanf("%s", subject);
        getchar(); // consume newline

        printf("Enter body: ");
        fgets(body, MAX_BODY_LENGTH, stdin);
        body[strcspn(body, "\n")] = '\0'; // remove newline

        write_email(subject, body);
    }

    return 0;
}