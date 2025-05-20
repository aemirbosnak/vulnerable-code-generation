//Falcon-180B DATASET v1.0 Category: Email Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define SUBJECT_LENGTH 50
#define BODY_LENGTH 500
#define EMAIL_LENGTH 100

typedef struct email {
    char subject[SUBJECT_LENGTH];
    char body[BODY_LENGTH];
    char from[EMAIL_LENGTH];
    char to[EMAIL_LENGTH];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void print_email(int index) {
    printf("Subject: %s\n", emails[index].subject);
    printf("From: %s\n", emails[index].from);
    printf("To: %s\n", emails[index].to);
    printf("Body:\n%s\n", emails[index].body);
}

int main() {
    char input[1000];
    int choice;

    while(1) {
        printf("1. Compose Email\n");
        printf("2. View Inbox\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the subject of the email: ");
                scanf("%s", input);
                strcpy(emails[num_emails].subject, input);

                printf("Enter the body of the email: ");
                scanf("%[^\n]", emails[num_emails].body);

                printf("Enter the recipient's email address: ");
                scanf("%s", emails[num_emails].to);

                printf("Email composed successfully!\n");
                break;

            case 2:
                if(num_emails == 0) {
                    printf("Inbox is empty.\n");
                } else {
                    printf("Inbox:\n");
                    for(int i=0; i<num_emails; i++) {
                        print_email(i);
                    }
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}