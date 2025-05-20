//FormAI DATASET v1.0 Category: Email Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EMAILS 10
#define MAX_SUBJECT_LENGTH 30
#define MAX_BODY_LENGTH 200

typedef struct Email {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char recipient[MAX_SUBJECT_LENGTH];
    char sender[MAX_SUBJECT_LENGTH];
} Email;

int main() {
    Email clientInbox[MAX_EMAILS];
    int emailCount = 0;
    int option;

    printf("Welcome to the C Email Client!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Send an email\n");
        printf("2. Check inbox\n");
        printf("3. Exit program\n");

        scanf("%d", &option);

        switch(option) {
            case 1:
                if(emailCount < MAX_EMAILS) {
                    Email newEmail;
                    printf("\nEnter the recipient's email address: ");
                    scanf("%s", newEmail.recipient);
                    printf("Enter your email address: ");
                    scanf("%s", newEmail.sender);
                    printf("Enter the email subject (max %d characters): ", MAX_SUBJECT_LENGTH);
                    getchar();
                    fgets(newEmail.subject, MAX_SUBJECT_LENGTH, stdin);
                    printf("Enter the email body (max %d characters): ", MAX_BODY_LENGTH);
                    fgets(newEmail.body, MAX_BODY_LENGTH, stdin);
                    clientInbox[emailCount] = newEmail;
                    emailCount++;
                    printf("\nEmail sent successfully!\n");
                } else {
                    printf("\nSorry, your inbox is full!\n");
                }
                break;
            case 2:
                printf("\nInbox:\n");
                if(emailCount == 0) {
                    printf("Empty!\n");
                } else {
                    for(int i = 0; i < emailCount; i++) {
                        printf("\nEmail %d:\n", i+1);
                        printf("Subject: %s\n", clientInbox[i].subject);
                        printf("From: %s\n", clientInbox[i].sender);
                        printf("To: %s\n", clientInbox[i].recipient);
                        printf("Body: %s\n", clientInbox[i].body);
                        printf("-------------------\n");
                    }
                }
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("\nInvalid option, please try again.\n");
                break;
        }
    } while(option != 3);

    return 0;
}