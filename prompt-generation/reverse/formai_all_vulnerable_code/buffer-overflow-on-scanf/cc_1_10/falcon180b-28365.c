//Falcon-180B DATASET v1.0 Category: Email Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 1000
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct email {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void print_email(Email email) {
    printf("Subject: %s\n", email.subject);
    printf("Body:\n%s\n", email.body);
    printf("Timestamp: %s\n\n", ctime(&email.timestamp));
}

int main() {
    int choice;
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];

    do {
        printf("Choose an option:\n");
        printf("1. Compose email\n");
        printf("2. View emails\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter email subject: ");
                scanf("%s", subject);
                printf("Enter email body: ");
                fgets(body, MAX_BODY_LENGTH, stdin);
                emails[num_emails] = (Email) {
                   .subject = subject,
                   .body = body,
                   .timestamp = time(NULL)
                };
                num_emails++;
                printf("Email composed successfully!\n");
                break;
            case 2:
                if(num_emails == 0) {
                    printf("No emails found.\n");
                } else {
                    printf("List of emails:\n");
                    for(int i=0; i<num_emails; i++) {
                        print_email(emails[i]);
                    }
                }
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 3);

    return 0;
}