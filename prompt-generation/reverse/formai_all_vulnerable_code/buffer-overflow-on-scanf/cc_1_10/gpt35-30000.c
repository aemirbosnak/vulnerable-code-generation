//FormAI DATASET v1.0 Category: Email Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT 100
#define MAX_CONTENT 1000

int main() {
    char emails[MAX_EMAILS][50];
    char subject[MAX_SUBJECT];
    char content[MAX_CONTENT];
    int num_emails = 0;

    printf("Welcome to the Awesome Email Client!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Compose a new email\n");
        printf("2. Check Inbox\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter recipient's email address: ");
                char email[50];
                scanf("%s", email);
                strcpy(emails[num_emails], email);

                printf("Enter subject: ");
                scanf("%s", subject);

                printf("Enter content: ");
                char ch;
                int i = 0;
                getchar(); // clear the newline character
                while ((ch = getchar()) != '\n') {
                    content[i++] = ch;
                }
                content[i] = '\0';

                printf("Email sent successfully! :)\n");
                num_emails++;
                break;
            case 2:
                printf("********** Your Inbox **********\n");
                for (int i = 0; i < num_emails; i++) {
                    printf("Email %d\n", i+1);
                    printf("From: %s\n", emails[i]);
                    printf("Subject: %s\n", subject);
                    printf("Content: %s\n", content);
                }
                printf("*********************************\n");
                break;
            case 3:
                printf("Thank you for using Awesome Email Client! Goodbye! :)\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }

    return 0;
}