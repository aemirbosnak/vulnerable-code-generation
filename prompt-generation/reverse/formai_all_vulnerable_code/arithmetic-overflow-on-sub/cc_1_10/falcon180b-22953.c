//Falcon-180B DATASET v1.0 Category: Email Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 1000
#define SUBJECT_MAX_LENGTH 100
#define BODY_MAX_LENGTH 1000
#define SENDER_MAX_LENGTH 100
#define RECIPIENT_MAX_LENGTH 100

typedef struct {
    char subject[SUBJECT_MAX_LENGTH];
    char body[BODY_MAX_LENGTH];
    char sender[SENDER_MAX_LENGTH];
    char recipient[RECIPIENT_MAX_LENGTH];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email() {
    printf("Enter subject: ");
    scanf("%s", emails[num_emails].subject);

    printf("Enter body: ");
    scanf("%[^\n]", emails[num_emails].body);

    printf("Enter sender: ");
    scanf("%s", emails[num_emails].sender);

    printf("Enter recipient: ");
    scanf("%s", emails[num_emails].recipient);

    num_emails++;
}

void send_email(int index) {
    printf("Sending email...\n");
    printf("Subject: %s\n", emails[index].subject);
    printf("Body: ");
    printf("%s", emails[index].body);
    printf("\n");
}

void main() {
    int choice;
    while(1) {
        printf("\nEmail Client\n");
        printf("1. Add email\n");
        printf("2. Send email\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_email();
                break;
            case 2:
                printf("Enter email index to send: ");
                scanf("%d", &choice);
                send_email(choice-1);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}