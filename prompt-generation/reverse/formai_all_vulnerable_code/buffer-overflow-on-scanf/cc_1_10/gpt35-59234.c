//FormAI DATASET v1.0 Category: Email Client ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct email {
    char sender[50], receiver[50], subject[100], message[1000];
};

void send_email(struct email e) {
    printf("Sending Email...\n\n");
    printf("From: %s\n", e.sender);
    printf("To: %s\n", e.receiver);
    printf("Subject: %s\n", e.subject);
    printf("Message: %s\n", e.message);
    printf("\nEmail Sent Successfully!\n\n");
}

void view_previous_emails() {
    printf("Viewing Previous Emails...\n\n");

    FILE *fptr;
    char c;

    fptr = fopen("previous_emails.txt", "r");
    if (fptr == NULL) {
        printf("No Previous Emails Found!\n\n");
        return;
    }

    c = fgetc(fptr);
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(fptr);
    }

    fclose(fptr);

    printf("\n\n");
}

void delete_all_previous_emails() {
    printf("Deleting All Previous Emails...\n\n");

    FILE *fptr;
    fptr = fopen("previous_emails.txt", "w");
    fprintf(fptr, "");
    fclose(fptr);

    printf("All Previous Emails Deleted!\n\n");
}

int main() {
    char choice;
    struct email e;

    printf("Welcome to the Unique Email Client!\n\n");

    do {
        printf("Menu:\n");
        printf("1. Send Email\n");
        printf("2. View Previous Emails\n");
        printf("3. Delete All Previous Emails\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%c", &choice);
        getchar();

        switch (choice) {
            case '1':
                printf("Enter Sender Email Address: ");
                fgets(e.sender, 50, stdin);
                e.sender[strcspn(e.sender, "\n")] = 0;

                printf("Enter Receiver Email Address: ");
                fgets(e.receiver, 50, stdin);
                e.receiver[strcspn(e.receiver, "\n")] = 0;

                printf("Enter Email Subject: ");
                fgets(e.subject, 100, stdin);
                e.subject[strcspn(e.subject, "\n")] = 0;

                printf("Enter Email Message: ");
                fgets(e.message, 1000, stdin);
                e.message[strcspn(e.message, "\n")] = 0;

                send_email(e);

                FILE *fptr;
                fptr = fopen("previous_emails.txt", "a");
                fprintf(fptr, "\nFrom: %s\nTo: %s\nSubject: %s\nMessage: %s\n", e.sender, e.receiver, e.subject, e.message);
                fclose(fptr);

                break;

            case '2':
                view_previous_emails();
                break;

            case '3':
                delete_all_previous_emails();
                break;

            case '4':
                printf("Exiting Program...\n\n");
                exit(0);

            default:
                printf("Invalid Choice! Please Try Again.\n\n");
                break;
        }
    } while (1);

    return 0;
}