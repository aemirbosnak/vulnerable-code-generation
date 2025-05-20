//Falcon-180B DATASET v1.0 Category: Email Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct Email {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

int main() {
    Email emails[MAX_EMAILS];
    int numEmails = 0;

    while (1) {
        printf("Enter's' to send an email, 'r' to read emails, or 'q' to quit: ");
        char choice;
        scanf("%c", &choice);

        if (choice =='s') {
            if (numEmails >= MAX_EMAILS) {
                printf("Sorry, inbox is full.\n");
            } else {
                printf("Enter subject (max %d characters): ", MAX_SUBJECT_LENGTH - 1);
                scanf("%s", emails[numEmails].subject);

                printf("Enter body (max %d characters): ", MAX_BODY_LENGTH - 1);
                scanf("%[^\n]", emails[numEmails].body);

                numEmails++;
            }
        } else if (choice == 'r') {
            if (numEmails == 0) {
                printf("Inbox is empty.\n");
            } else {
                for (int i = 0; i < numEmails; i++) {
                    printf("Subject: %s\nBody: %s\n\n", emails[i].subject, emails[i].body);
                }
            }
        } else if (choice == 'q') {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}