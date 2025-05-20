//Falcon-180B DATASET v1.0 Category: Email Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LEN 1000

typedef struct {
    char from[MAX_EMAIL_LEN];
    char subject[MAX_EMAIL_LEN];
    char body[MAX_EMAIL_LEN];
    int unread;
} Email;

Email emails[MAX_EMAILS];
int num_emails;

int main() {
    char choice;
    int i;

    printf("Welcome to the email client!\n");
    printf("Enter 'c' to compose a new email, 'r' to read existing emails, or 'q' to quit.\n");

    do {
        choice = getchar();

        switch(choice) {
            case 'c':
                printf("Composing new email...\n");
                printf("Enter the recipient's email address: ");
                scanf("%s", emails[num_emails].from);
                printf("Enter the subject: ");
                scanf("%s", emails[num_emails].subject);
                printf("Enter the body: ");
                scanf("%s", emails[num_emails].body);
                emails[num_emails].unread = 1;
                num_emails++;
                printf("Email composed successfully!\n");
                break;
            case 'r':
                printf("Reading existing emails...\n");
                for(i = 0; i < num_emails; i++) {
                    if(emails[i].unread) {
                        printf("From: %s\nSubject: %s\nBody: %s\n\n", emails[i].from, emails[i].subject, emails[i].body);
                    }
                }
                break;
            case 'q':
                printf("Quitting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 'q');

    return 0;
}