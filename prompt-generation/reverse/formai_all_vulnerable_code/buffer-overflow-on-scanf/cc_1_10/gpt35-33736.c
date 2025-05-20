//FormAI DATASET v1.0 Category: Email Client ; Style: Romeo and Juliet
/*
 * Romeo and Juliet Email Client
 * Version 1.0
 * Written in C by achatbot
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LEN 100
#define MAX_BODY_LEN 1000
#define MAX_EMAILS 10

typedef struct {
    char sender[MAX_SUBJECT_LEN];
    char receiver[MAX_SUBJECT_LEN];
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
} Email;

int main() {
    Email emails[MAX_EMAILS];
    int num_emails = 0;

    printf("Enter your name: ");
    char romeo[MAX_SUBJECT_LEN];
    scanf("%s", romeo);

    printf("Enter the name of your beloved: ");
    char juliet[MAX_SUBJECT_LEN];
    scanf("%s", juliet);

    printf("\n\nWelcome, %s, to the Romeo and Juliet Email Client!\n", romeo);

    while(1) {
        char choice;
        printf("\nMenu:\n");
        printf("1. Compose Email\n");
        printf("2. View Inbox\n");
        printf("3. Exit\n");

        printf("Please enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1': {
                printf("\nEnter the subject: ");
                char subject[MAX_SUBJECT_LEN];
                scanf("%s", subject);

                printf("\nEnter the body text: ");
                char body[MAX_BODY_LEN];
                scanf("%s", body);

                Email new_email;
                strcpy(new_email.sender, romeo);
                strcpy(new_email.receiver, juliet);
                strcpy(new_email.subject, subject);
                strcpy(new_email.body, body);

                emails[num_emails] = new_email;
                num_emails++;

                printf("\nYour email has been sent!\n");
                break;
            }
            case '2': {
                if(num_emails == 0) {
                    printf("\nYour inbox is empty.\n");
                } else {
                    printf("\nYour Inbox:\n");
                    for(int i = 0; i < num_emails; i++) {
                        if(strcmp(emails[i].receiver, romeo) == 0) {
                            printf("From: %s\n", emails[i].sender);
                            printf("Subject: %s\n", emails[i].subject);
                            printf("Body: %s\n\n", emails[i].body);
                        }
                    }
                }
                break;
            }
            case '3': {
                printf("\nFarewell, %s!\n", romeo);
                exit(0);
            }
            default: {
                printf("\nInvalid choice.\n");
                break;
            }
        }
    }

    return 0;
}