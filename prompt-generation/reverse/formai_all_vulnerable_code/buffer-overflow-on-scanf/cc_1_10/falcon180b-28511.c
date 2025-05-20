//Falcon-180B DATASET v1.0 Category: Email Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 500

struct Email {
    char subject[MAX_SUBJECT_LENGTH+1];
    char body[MAX_BODY_LENGTH+1];
};

int num_emails = 0;
struct Email emails[MAX_EMAILS];

void print_emails() {
    printf("Number of emails: %d\n", num_emails);
    for (int i = 0; i < num_emails; i++) {
        printf("Email %d:\n", i+1);
        printf("Subject: %s\n", emails[i].subject);
        printf("Body: %s\n\n", emails[i].body);
    }
}

void add_email() {
    char subject[MAX_SUBJECT_LENGTH+1];
    char body[MAX_BODY_LENGTH+1];

    printf("Enter email subject: ");
    scanf("%s", subject);

    printf("Enter email body: ");
    scanf("%[^\n]", body);

    strcpy(emails[num_emails].subject, subject);
    strcpy(emails[num_emails].body, body);

    num_emails++;
}

int main() {
    int choice;

    do {
        printf("\nEmail Client\n");
        printf("1. Add email\n");
        printf("2. Print emails\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_email();
                break;
            case 2:
                print_emails();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}