//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: detailed
// mailing_list.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100

typedef struct {
    char email[100];
    char name[100];
} Email;

void add_email(Email* emails, char* email, char* name) {
    int i;
    for (i = 0; i < MAX_EMAILS; i++) {
        if (emails[i].email[0] == '\0') {
            strcpy(emails[i].email, email);
            strcpy(emails[i].name, name);
            return;
        }
    }
}

void remove_email(Email* emails, char* email) {
    int i;
    for (i = 0; i < MAX_EMAILS; i++) {
        if (strcmp(emails[i].email, email) == 0) {
            emails[i].email[0] = '\0';
            emails[i].name[0] = '\0';
            return;
        }
    }
}

void print_emails(Email* emails) {
    int i;
    for (i = 0; i < MAX_EMAILS; i++) {
        if (emails[i].email[0] != '\0') {
            printf("%s <%s>\n", emails[i].name, emails[i].email);
        }
    }
}

int main() {
    Email emails[MAX_EMAILS];
    char email[100];
    char name[100];

    printf("Welcome to the mailing list manager\n");

    while (1) {
        printf("Enter an email address: ");
        scanf("%s", email);
        if (strcmp(email, "exit") == 0) {
            break;
        }

        printf("Enter a name: ");
        scanf("%s", name);
        if (strcmp(name, "exit") == 0) {
            break;
        }

        add_email(emails, email, name);
    }

    printf("Emails:\n");
    print_emails(emails);

    printf("Enter an email address to remove: ");
    scanf("%s", email);
    remove_email(emails, email);

    printf("Emails:\n");
    print_emails(emails);

    return 0;
}