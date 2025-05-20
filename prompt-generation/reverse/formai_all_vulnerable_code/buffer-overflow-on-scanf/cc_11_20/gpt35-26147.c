//FormAI DATASET v1.0 Category: Email Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 50
#define MAX_EMAIL_LENGTH 500

typedef struct Email {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_EMAIL_LENGTH];
    char sender[MAX_SUBJECT_LENGTH];
    char recipient[MAX_SUBJECT_LENGTH];
} Email;

int main() {
    Email email;
    char input[MAX_EMAIL_LENGTH];
    char recipient_email[MAX_SUBJECT_LENGTH];
    char email_body[MAX_EMAIL_LENGTH];
    char email_subject[MAX_SUBJECT_LENGTH];
    char email_sender[MAX_SUBJECT_LENGTH];
    FILE *fp;
    int choice;

    while (1) {
        printf("Welcome to the Unique C Email Client!\n");
        printf("1. Compose new email\n");
        printf("2. View inbox\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter recipient email: ");
                scanf("%s", recipient_email);
                printf("Enter email subject: ");
                scanf("%s", email_subject);
                printf("Enter email body: ");
                scanf("%s", email_body);
                printf("Enter your email address: ");
                scanf("%s", email_sender);

                fp = fopen("inbox.txt", "a");
                if (fp == NULL) {
                    printf("Error: Unable to open inbox file.\n");
                    exit(1);
                }

                fprintf(fp, "From: %s\n", email_sender);
                fprintf(fp, "To: %s\n", recipient_email);
                fprintf(fp, "Subject: %s\n", email_subject);
                fprintf(fp, "Body:\n%s\n\n", email_body);
                fclose(fp);

                printf("Email sent!\n");
                break;

            case 2:
                fp = fopen("inbox.txt", "r");
                if (fp == NULL) {
                    printf("Inbox is empty!\n");
                    break;
                }

                while (fgets(input, MAX_EMAIL_LENGTH, fp)) {
                    if (strstr(input, "From: ")) {
                        sscanf(input, "From: %s", email.sender);
                    } else if (strstr(input, "To: ")) {
                        sscanf(input, "To: %s", email.recipient);
                    } else if (strstr(input, "Subject: ")) {
                        sscanf(input, "Subject: %s", email.subject);
                    } else if (strstr(input, "Body:")) {
                        int i = 0;
                        while (fgets(input, MAX_EMAIL_LENGTH, fp)) {
                            input[strcspn(input, "\n")] = 0;
                            strcat(email.body, input);
                            strcat(email.body, "\n");
                            if (strstr(input, "")) {
                                break;
                            }
                        }
                        
                        printf("From: %s\n", email.sender);
                        printf("To: %s\n", email.recipient);
                        printf("Subject: %s\n", email.subject);
                        printf("%s", email.body);
                        printf("------------------------------\n");

                        memset(email.body, 0, sizeof(email.body));
                    }
                }
                fclose(fp);
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}