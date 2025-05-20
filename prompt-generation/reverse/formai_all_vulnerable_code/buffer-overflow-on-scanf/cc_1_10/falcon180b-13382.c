//Falcon-180B DATASET v1.0 Category: Email Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define SUBJECT_LENGTH 50
#define BODY_LENGTH 500

typedef struct Email {
    char subject[SUBJECT_LENGTH];
    char body[BODY_LENGTH];
    int read;
} Email;

Email emails[MAX_EMAILS];
int num_emails;

void print_menu() {
    printf("=== EMAIL CLIENT ===\n");
    printf("1. Check for new emails\n");
    printf("2. Read an email\n");
    printf("3. Mark an email as read\n");
    printf("4. Exit\n");
}

void check_for_new_emails() {
    // TODO: Implement checking for new emails
}

void read_email(int index) {
    if (index >= 0 && index < num_emails) {
        Email *email = &emails[index];
        if (!email->read) {
            printf("Subject: %s\n", email->subject);
            printf("Body:\n%s\n", email->body);
            email->read = 1;
        } else {
            printf("This email has already been read.\n");
        }
    } else {
        printf("Invalid email index.\n");
    }
}

void mark_as_read(int index) {
    if (index >= 0 && index < num_emails) {
        Email *email = &emails[index];
        email->read = 1;
    } else {
        printf("Invalid email index.\n");
    }
}

int main() {
    num_emails = 0;

    while (1) {
        print_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                check_for_new_emails();
                break;
            case 2:
                printf("Enter email index: ");
                int index;
                scanf("%d", &index);
                read_email(index);
                break;
            case 3:
                printf("Enter email index: ");
                int mark_index;
                scanf("%d", &mark_index);
                mark_as_read(mark_index);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}