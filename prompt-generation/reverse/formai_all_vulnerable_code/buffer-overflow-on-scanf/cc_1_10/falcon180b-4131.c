//Falcon-180B DATASET v1.0 Category: Email Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_RECIPIENTS 50

typedef struct {
    char subject[MAX_SUBJECT_LENGTH + 1];
    char body[MAX_BODY_LENGTH + 1];
    char recipients[MAX_RECIPIENTS][100];
    int num_recipients;
} Email;

void send_email(Email* email) {
    printf("Sending email...\n");
    printf("Subject: %s\n", email->subject);
    printf("Body:\n%s\n", email->body);
    printf("Recipients:\n");
    for (int i = 0; i < email->num_recipients; i++) {
        printf("%s\n", email->recipients[i]);
    }
}

int main() {
    Email email;

    printf("Welcome to the Cheerful Email Client!\n\n");

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Compose email\n");
        printf("2. Send email\n");
        printf("3. Quit\n");

        char choice;
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Composing email...\n");
                printf("Enter subject (max %d characters): ", MAX_SUBJECT_LENGTH);
                scanf("%[^\n]", email.subject);
                email.subject[strcspn(email.subject, "\n")] = '\0';

                printf("Enter body (max %d characters): ", MAX_BODY_LENGTH);
                fgets(email.body, MAX_BODY_LENGTH + 1, stdin);
                email.body[strcspn(email.body, "\n")] = '\0';

                int num_recipients = 0;
                printf("Enter recipients (max %d): ", MAX_RECIPIENTS);
                while (num_recipients < MAX_RECIPIENTS && scanf("%[^\n]", email.recipients[num_recipients])!= EOF) {
                    email.recipients[num_recipients][strcspn(email.recipients[num_recipients], "\n")] = '\0';
                    num_recipients++;
                }
                email.num_recipients = num_recipients;
                break;
            case '2':
                send_email(&email);
                break;
            case '3':
                printf("Exiting Cheerful Email Client...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}