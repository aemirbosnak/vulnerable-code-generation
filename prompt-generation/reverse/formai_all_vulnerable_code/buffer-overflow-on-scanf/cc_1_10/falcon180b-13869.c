//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 1000
#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100

struct email {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

int num_emails = 0;
struct email emails[MAX_EMAILS];

void add_email() {
    printf("Enter name: ");
    scanf("%s", emails[num_emails].name);

    printf("Enter email: ");
    scanf("%s", emails[num_emails].email);

    num_emails++;
}

void remove_email() {
    printf("Enter email to remove: ");
    char email[MAX_EMAIL_LENGTH];
    scanf("%s", email);

    int i;
    for (i = 0; i < num_emails; i++) {
        if (strcmp(emails[i].email, email) == 0) {
            memmove(&emails[i], &emails[i+1], sizeof(struct email) * (num_emails - i - 1));
            num_emails--;
            break;
        }
    }
}

void send_email() {
    printf("Enter email to send to: ");
    char email[MAX_EMAIL_LENGTH];
    scanf("%s", email);

    int i;
    for (i = 0; i < num_emails; i++) {
        if (strcmp(emails[i].email, email) == 0) {
            printf("Sending email to %s...\n", emails[i].name);
        }
    }
}

void list_emails() {
    printf("Email list:\n");
    int i;
    for (i = 0; i < num_emails; i++) {
        printf("%s - %s\n", emails[i].name, emails[i].email);
    }
}

int main() {
    int choice;
    do {
        printf("1. Add email\n");
        printf("2. Remove email\n");
        printf("3. Send email\n");
        printf("4. List emails\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_email();
                break;
            case 2:
                remove_email();
                break;
            case 3:
                send_email();
                break;
            case 4:
                list_emails();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}