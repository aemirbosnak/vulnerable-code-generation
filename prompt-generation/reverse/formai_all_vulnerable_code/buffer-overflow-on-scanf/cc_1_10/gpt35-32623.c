//FormAI DATASET v1.0 Category: Email Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 1024

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char to[50];
} Email;

int main(void) {
    Email inbox[MAX_EMAILS];
    int num_emails = 0;

    while(1) {
        printf("1. Compose new email\n2. View Inbox\n3. Exit\nOption: ");
        int option;
        scanf("%d", &option);

        if(option == 1) {
            Email new_email;
            printf("To: ");
            scanf("%s", new_email.to);
            getchar(); // To consume the newline character

            printf("Subject: ");
            fgets(new_email.subject, MAX_SUBJECT_LENGTH, stdin);
            new_email.subject[strcspn(new_email.subject, "\n")] = 0;

            printf("Body: ");
            fgets(new_email.body, MAX_BODY_LENGTH, stdin);
            new_email.body[strcspn(new_email.body, "\n")] = 0;

            inbox[num_emails++] = new_email;
            printf("Email Sent!\n\n");
        }

        else if(option == 2) {
            printf("Inbox:\n");
            if(num_emails == 0) {
                printf("No emails yet.\n\n");
            }
            else {
                for(int i=0; i<num_emails; i++) {
                    printf("Email %d:\n", i+1);
                    printf("To: %s\n", inbox[i].to);
                    printf("Subject: %s\n", inbox[i].subject);
                    printf("Body: %s\n", inbox[i].body);
                    printf("\n");
                }
            }
        }

        else if(option == 3) {
            printf("Goodbye!\n");
            break;
        }

        else {
            printf("Invalid option!\n\n");
        }
    }

    return 0;
}