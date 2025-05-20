//Falcon-180B DATASET v1.0 Category: Email Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 80
#define MAX_BODY_LENGTH 1024
#define MAX_RECIPIENTS 10

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char recipients[MAX_RECIPIENTS][80];
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
    int choice;
    char input[80];

    do {
        printf("\nEmail Client\n");
        printf("1. Compose Email\n2. Send Email\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Compose Email\n");
                printf("Enter subject (max %d characters): ", MAX_SUBJECT_LENGTH);
                scanf("%s", email.subject);
                printf("Enter body (max %d characters): ", MAX_BODY_LENGTH);
                scanf("%s", email.body);
                printf("Enter number of recipients (max %d): ", MAX_RECIPIENTS);
                scanf("%d", &email.num_recipients);

                for (int i = 0; i < email.num_recipients; i++) {
                    printf("Enter recipient %d (max %d characters): ", i+1, 80);
                    scanf("%s", email.recipients[i]);
                }
                break;
            case 2:
                send_email(&email);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}