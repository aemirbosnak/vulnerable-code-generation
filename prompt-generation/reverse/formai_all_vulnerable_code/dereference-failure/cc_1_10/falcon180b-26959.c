//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBJECTS 1000
#define MAX_EMAILS 10000
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECT_LEN 100

typedef struct {
    char email[MAX_EMAIL_LEN];
    char subject[MAX_SUBJECT_LEN];
} Subject;

Subject subjects[MAX_SUBJECTS];
int num_subjects = 0;

void add_subject(char* email, char* subject) {
    strncpy(subjects[num_subjects].email, email, MAX_EMAIL_LEN);
    strncpy(subjects[num_subjects].subject, subject, MAX_SUBJECT_LEN);
    num_subjects++;
}

void print_subjects() {
    for (int i = 0; i < num_subjects; i++) {
        printf("%s - %s\n", subjects[i].email, subjects[i].subject);
    }
}

void send_email(char* email, char* subject) {
    printf("Sending email to %s about %s...\n", email, subject);
}

int main() {
    char input[MAX_EMAIL_LEN + MAX_SUBJECT_LEN + 2];
    char email[MAX_EMAIL_LEN];
    char subject[MAX_SUBJECT_LEN];

    while (1) {
        printf("Enter an email and subject (separated by a space): ");
        fgets(input, sizeof(input), stdin);

        if (strlen(input) == 0) {
            break;
        }

        char* token = strtok(input, " ");
        strncpy(email, token, MAX_EMAIL_LEN);

        token = strtok(NULL, " ");
        strncpy(subject, token, MAX_SUBJECT_LEN);

        add_subject(email, subject);
    }

    print_subjects();

    return 0;
}