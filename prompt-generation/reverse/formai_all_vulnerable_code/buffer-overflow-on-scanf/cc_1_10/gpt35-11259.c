//FormAI DATASET v1.0 Category: Email Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFF_SIZE 1024 // maximum message size

typedef struct {
    char from[100];
    char to[100];
    char subject[100];
    char message[MAX_BUFF_SIZE];
} Email;

int main() {
    Email email;
    char choice;
    FILE *fp;
    char temp[100];

    printf("Welcome to the C Email Client!\n\n");

    printf("Enter your email address: ");
    scanf("%s", email.from);

    printf("\n\nDo you want to compose an email? (y/n) ");
    scanf(" %c", &choice);

    if(choice == 'y' || choice == 'Y') {
        printf("\nEnter email address of the recipient: ");
        scanf("%s", email.to);

        printf("\nEnter the email subject: ");
        scanf("%s", email.subject);

        printf("\nEnter the email message: ");
        getchar(); // to flush newline from buffer
        fgets(email.message, MAX_BUFF_SIZE, stdin);

        printf("\nSending email...\n");

        fp = fopen(strcat(email.to, ".txt"), "w+");
        fprintf(fp, "From: %s\nTo: %s\nSubject: %s\n\n%s", email.from, email.to, email.subject, email.message);
        fclose(fp);

        printf("\nEmail sent successfully!\n");
    }
    else {
        printf("\nOpening inbox...\n");

        fp = fopen(strcat(email.from, ".txt"), "r");

        if(fp == NULL) {
            printf("\nError: Inbox is empty!\n");
            exit(1);
        }

        while(fgets(temp, MAX_BUFF_SIZE, fp)) {
            printf("%s", temp);
        }

        fclose(fp);
    }

    return 0;
}