//Falcon-180B DATASET v1.0 Category: Email Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

Email emails[100];
int num_emails = 0;

void add_email(char* subject, char* body) {
    if (num_emails >= 100) {
        printf("Error: Email limit reached\n");
        return;
    }
    strcpy(emails[num_emails].subject, subject);
    strcpy(emails[num_emails].body, body);
    num_emails++;
}

void display_emails() {
    if (num_emails == 0) {
        printf("No emails found\n");
        return;
    }
    for (int i = 0; i < num_emails; i++) {
        printf("Subject: %s\nBody:\n%s\n\n", emails[i].subject, emails[i].body);
    }
}

int main() {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];

    printf("Welcome to the email client\n");
    while (1) {
        printf("\nEnter 'a' to add an email, 'd' to display emails, or 'q' to quit: ");
        char choice;
        scanf("%c", &choice);

        switch (choice) {
            case 'a':
                printf("Enter subject: ");
                scanf("%[^\n]", subject);
                printf("Enter body: ");
                fgets(body, MAX_BODY_LENGTH, stdin);
                body[strcspn(body, "\n")] = '\0';
                add_email(subject, body);
                break;
            case 'd':
                display_emails();
                break;
            case 'q':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}