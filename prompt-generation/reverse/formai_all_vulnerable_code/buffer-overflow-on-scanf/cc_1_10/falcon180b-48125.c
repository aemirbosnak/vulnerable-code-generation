//Falcon-180B DATASET v1.0 Category: Email Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBJECT_LENGTH 80
#define MAX_BODY_LENGTH 1000
#define MAX_TO_LENGTH 80
#define MAX_FROM_LENGTH 80
#define MAX_CC_LENGTH 80
#define MAX_BCC_LENGTH 80

typedef struct {
    char subject[MAX_SUBJECT_LENGTH + 1];
    char body[MAX_BODY_LENGTH + 1];
    char to[MAX_TO_LENGTH + 1];
    char from[MAX_FROM_LENGTH + 1];
    char cc[MAX_CC_LENGTH + 1];
    char bcc[MAX_BCC_LENGTH + 1];
} email;

void read_email(email *e) {
    printf("Enter the Subject (Max %d characters): ", MAX_SUBJECT_LENGTH);
    scanf("%[^\n]", e->subject);

    printf("Enter the Body (Max %d characters): ", MAX_BODY_LENGTH);
    scanf("%[^\n]", e->body);

    printf("Enter the To (Max %d characters): ", MAX_TO_LENGTH);
    scanf("%[^\n]", e->to);

    printf("Enter the From (Max %d characters): ", MAX_FROM_LENGTH);
    scanf("%[^\n]", e->from);

    printf("Enter the CC (Max %d characters): ", MAX_CC_LENGTH);
    scanf("%[^\n]", e->cc);

    printf("Enter the BCC (Max %d characters): ", MAX_BCC_LENGTH);
    scanf("%[^\n]", e->bcc);
}

void send_email(email *e) {
    printf("Subject: %s\n", e->subject);
    printf("Body:\n%s\n", e->body);
    printf("To: %s\n", e->to);
    printf("From: %s\n", e->from);
    printf("CC: %s\n", e->cc);
    printf("BCC: %s\n", e->bcc);
}

int main() {
    email e;
    char choice;

    do {
        printf("\nSherlock Holmes' Email Client\n");
        printf("1. Read Email\n");
        printf("2. Send Email\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                read_email(&e);
                send_email(&e);
                break;
            case '2':
                read_email(&e);
                printf("Email composed successfully!\n");
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= '3');

    return 0;
}