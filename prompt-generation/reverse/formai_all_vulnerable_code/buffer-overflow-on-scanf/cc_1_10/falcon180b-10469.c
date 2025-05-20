//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EMAILS 1000
#define MAX_EMAIL_LENGTH 1000

struct email {
    char address[MAX_EMAIL_LENGTH];
    time_t last_sent;
};

struct email emails[MAX_EMAILS];
int num_emails = 0;

void add_email(char* address) {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: Maximum number of emails reached.\n");
        return;
    }

    strcpy(emails[num_emails].address, address);
    emails[num_emails].last_sent = 0;

    num_emails++;
}

int send_email(char* address) {
    int i;

    for (i = 0; i < num_emails; i++) {
        if (strcmp(emails[i].address, address) == 0) {
            if (difftime(time(NULL), emails[i].last_sent) < 86400) {
                printf("Error: Email already sent within the last 24 hours.\n");
                return 0;
            }

            emails[i].last_sent = time(NULL);
            return 1;
        }
    }

    printf("Error: Email address not found.\n");
    return 0;
}

void print_emails() {
    int i;

    for (i = 0; i < num_emails; i++) {
        printf("%s\n", emails[i].address);
    }
}

int main() {
    char command[100];

    while (1) {
        printf("Enter command (add, send, print, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char address[MAX_EMAIL_LENGTH];

            printf("Enter email address: ");
            scanf("%s", address);

            add_email(address);
        } else if (strcmp(command, "send") == 0) {
            char address[MAX_EMAIL_LENGTH];

            printf("Enter email address: ");
            scanf("%s", address);

            if (send_email(address)) {
                printf("Email sent successfully.\n");
            }
        } else if (strcmp(command, "print") == 0) {
            print_emails();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Error: Invalid command.\n");
        }
    }

    return 0;
}