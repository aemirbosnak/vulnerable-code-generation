//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email(char *name, char *email) {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: Maximum number of emails reached.\n");
        return;
    }

    strcpy(emails[num_emails].name, name);
    strcpy(emails[num_emails].email, email);
    num_emails++;
}

void print_emails() {
    printf("Email List:\n");
    for (int i = 0; i < num_emails; i++) {
        printf("%s - %s\n", emails[i].name, emails[i].email);
    }
}

void send_emails() {
    for (int i = 0; i < num_emails; i++) {
        printf("Sending email to %s...\n", emails[i].email);
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];

    do {
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter email: ");
        scanf("%s", email);

        add_email(name, email);
    } while (num_emails < MAX_EMAILS);

    print_emails();
    send_emails();

    return 0;
}