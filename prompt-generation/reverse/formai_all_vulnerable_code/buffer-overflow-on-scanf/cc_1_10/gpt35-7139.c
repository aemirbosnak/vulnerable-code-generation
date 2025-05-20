//FormAI DATASET v1.0 Category: Email Client ; Style: sophisticated
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define EMAIL_MAX_LENGTH 200
#define SUBJECT_MAX_LENGTH 100
#define BODY_MAX_LENGTH 500

struct email {
    char recipient[EMAIL_MAX_LENGTH];
    char sender[EMAIL_MAX_LENGTH];
    char subject[SUBJECT_MAX_LENGTH];
    char body[BODY_MAX_LENGTH];
};

int main() {
    struct email enew;
    char c;
    int choice, i = 0;
    FILE *fileptr;

    printf("Welcome to C Email Client\n");

    printf("\nEnter recipient email address: ");
    fgets(enew.recipient, EMAIL_MAX_LENGTH, stdin);

    printf("\nEnter sender email address: ");
    fgets(enew.sender, EMAIL_MAX_LENGTH, stdin);

    printf("\nEnter email subject: ");
    fgets(enew.subject, SUBJECT_MAX_LENGTH, stdin);

    printf("\nEnter email body: ");
    fgets(enew.body, BODY_MAX_LENGTH, stdin);

    printf("\nDo you want to save the email? (1-Yes, 2-No) : ");
    scanf("%d", &choice);

    if(choice == 1) {
        fileptr = fopen("email.txt", "w");

        fprintf(fileptr, "Recipient: %s", enew.recipient);
        fprintf(fileptr, "Sender: %s", enew.sender);        
        fprintf(fileptr, "Subject: %s", enew.subject);
        fprintf(fileptr, "Body: %s", enew.body);

        fclose(fileptr);
        printf("\nEmail has been successfully saved to file.\n");
    } else {
        printf("\nEmail has not been saved to file.\n");
    }

    return 0;
}