//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_EMAILS 1000
#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Email;

void addEmail(Email *emails, int *count, char *name, char *email) {
    if (*count >= MAX_EMAILS) {
        printf("Error: Maximum number of emails reached.\n");
        return;
    }

    int len = strlen(name);
    if (len > MAX_NAME_LENGTH - 1) {
        printf("Error: Name is too long.\n");
        return;
    }

    int emailLen = strlen(email);
    if (emailLen > MAX_EMAIL_LENGTH - 1) {
        printf("Error: Email is too long.\n");
        return;
    }

    strncpy(emails[*count].name, name, MAX_NAME_LENGTH);
    strncpy(emails[*count].email, email, MAX_EMAIL_LENGTH);

    (*count)++;
}

void printEmails(Email *emails, int count) {
    printf("Name\tEmail\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\n", emails[i].name, emails[i].email);
    }
}

int main() {
    Email emails[MAX_EMAILS];
    int count = 0;

    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];

    printf("Enter names and emails (enter 'done' to finish):\n");

    while (true) {
        printf("Name: ");
        scanf("%s", name);

        if (strcmp(name, "done") == 0) {
            break;
        }

        printf("Email: ");
        scanf("%s", email);

        addEmail(emails, &count, name, email);
    }

    printEmails(emails, count);

    return 0;
}