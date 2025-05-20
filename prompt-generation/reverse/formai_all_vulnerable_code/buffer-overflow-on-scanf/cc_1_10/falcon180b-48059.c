//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 1000

typedef struct {
    char name[100];
    char email[100];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email(char* name, char* email) {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: Maximum number of emails reached.\n");
        return;
    }

    strcpy(emails[num_emails].name, name);
    strcpy(emails[num_emails].email, email);
    num_emails++;
}

void print_emails() {
    printf("Name\tEmail\n");
    for (int i = 0; i < num_emails; i++) {
        printf("%s\t%s\n", emails[i].name, emails[i].email);
    }
}

void send_email(char* name) {
    printf("Sending email to %s...\n", name);
}

int main() {
    char input[100];
    while (1) {
        printf("Enter command (add/print/send/exit): ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            char name[100], email[100];
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter email: ");
            scanf("%s", email);
            add_email(name, email);
        } else if (strcmp(input, "print") == 0) {
            print_emails();
        } else if (strcmp(input, "send") == 0) {
            char name[100];
            printf("Enter name to send email: ");
            scanf("%s", name);
            send_email(name);
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}