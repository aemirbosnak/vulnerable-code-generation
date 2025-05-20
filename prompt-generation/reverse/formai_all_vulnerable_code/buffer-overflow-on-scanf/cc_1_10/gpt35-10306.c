//FormAI DATASET v1.0 Category: Email Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct email {
    char sender[50];
    char recipient[50];
    char subject[100];
    char message[500];
};

int main(int argc, char const *argv[]) {
    char choice;
    int num_emails = 0;
    struct email inbox[10];

    printf("Welcome to the C Email Client!\n");

    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Compose an email\n");
        printf("2. View your inbox\n");
        printf("3. Exit\n\n");

        printf("Enter your choice (1-3): ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                if (num_emails == 10) {
                    printf("\nError: your inbox is full!\n");
                    break;
                }

                printf("\nEnter sender's email address: ");
                scanf("%s", inbox[num_emails].sender);

                printf("Enter recipient's email address: ");
                scanf("%s", inbox[num_emails].recipient);

                printf("Enter email subject: ");
                scanf("%s", inbox[num_emails].subject);

                printf("Enter email message: ");
                scanf("%s", inbox[num_emails].message);

                num_emails++;

                printf("\nEmail sent!\n");
                break;

            case '2':
                if (num_emails == 0) {
                    printf("\nYour inbox is empty!\n");
                    break;
                }

                printf("\nYour inbox:\n");

                for (int i = 0; i < num_emails; i++) {
                    printf("\nEmail #%d\n", i+1);
                    printf("From: %s\n", inbox[i].sender);
                    printf("To: %s\n", inbox[i].recipient);
                    printf("Subject: %s\n", inbox[i].subject);
                    printf("Message: %s\n", inbox[i].message);
                }

                break;

            case '3':
                printf("\nExiting C Email Client...");
                break;

            default:
                printf("\nError: Invalid choice. Please try again.\n");
                break;
        }

    } while(choice != '3');

    return 0;
}