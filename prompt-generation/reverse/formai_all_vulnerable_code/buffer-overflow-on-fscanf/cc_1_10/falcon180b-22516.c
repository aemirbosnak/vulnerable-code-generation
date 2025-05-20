//Falcon-180B DATASET v1.0 Category: Email Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

struct Email {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
};

void print_email(struct Email email) {
    printf("Subject: %s\n", email.subject);
    printf("Body:\n%s\n", email.body);
    printf("Timestamp: %s\n\n", ctime(&email.timestamp));
}

int main() {
    FILE *emails_file;
    char filename[20];
    int num_emails = 0;
    struct Email emails[MAX_EMAILS];

    printf("Enter the name of the emails file (without extension): ");
    scanf("%s", filename);

    emails_file = fopen(filename, "r");

    if (emails_file == NULL) {
        printf("Error: could not open emails file.\n");
        return 1;
    }

    while (num_emails < MAX_EMAILS && fscanf(emails_file, "%s %s %ld", emails[num_emails].subject, emails[num_emails].body, &emails[num_emails].timestamp)!= EOF) {
        num_emails++;
    }

    fclose(emails_file);

    printf("Number of emails: %d\n", num_emails);

    for (int i = 0; i < num_emails; i++) {
        print_email(emails[i]);
    }

    return 0;
}