//FormAI DATASET v1.0 Category: Email Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Email {
    char sender[50];
    char recipient[50];
    char subject[100];
    char body[500];
};

int main() {
    struct Email email;
    char choice;
    FILE *fp;

    fp = fopen("emails.txt", "a+");

    if (fp == NULL) {
        printf("Error opening emails.txt\n");
        return 1;
    }

    printf("Welcome to the Introspective Email Client!\n");
    printf("Would you like to read or compose an email? (r/c)\n");

    scanf("%c", &choice);

    if (choice == 'r') {
        char recipient[50];
        printf("Enter the recipient's email address: ");
        scanf("%s", &recipient);

        while (fread(&email, sizeof(struct Email), 1, fp)) {
            if (strcmp(email.recipient, recipient) == 0) {
                printf("From: %s\n", email.sender);
                printf("Subject: %s\n", email.subject);
                printf("Body: %s\n", email.body);
            }
        }
    } else if (choice == 'c') {
        printf("Enter your email address: ");
        scanf("%s", &email.sender);

        printf("Enter the recipient's email address: ");
        scanf("%s", &email.recipient);

        printf("Enter the email subject: ");
        scanf("%s", &email.subject);

        printf("Enter the email body: ");
        scanf(" %[^\n]s", &email.body);

        fwrite(&email, sizeof(struct Email), 1, fp);
    } else {
        printf("Invalid choice, please try again.\n");
    }

    fclose(fp);

    return 0;
}