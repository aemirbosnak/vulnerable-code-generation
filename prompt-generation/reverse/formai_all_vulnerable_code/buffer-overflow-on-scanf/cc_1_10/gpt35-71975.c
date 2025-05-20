//FormAI DATASET v1.0 Category: Email Client ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 500

void sendEmail(char* recipient, char* subject, char* body) {
    // Code for sending email
    printf("To: %s\n", recipient);
    printf("Subject: %s\n", subject);
    printf("Body: %s\n", body);
    printf("Message sent successfully!\n");
}

int main() {
    char recipient[50], subject[MAX_SUBJECT_LENGTH], body[MAX_BODY_LENGTH];
    int choice;

    printf("Welcome to GeniusMail!\n");
    printf("1. Compose\n");
    printf("2. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while (choice != 2) {
        switch (choice) {
            case 1:
                printf("Enter recipient's email: ");
                scanf("%s", recipient);
                getchar();

                printf("Enter subject: ");
                fgets(subject, MAX_SUBJECT_LENGTH, stdin);
                subject[strcspn(subject, "\n")] = 0;

                printf("Enter message body: ");
                fgets(body, MAX_BODY_LENGTH, stdin);
                body[strcspn(body, "\n")] = 0;

                sendEmail(recipient, subject, body);
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }

        printf("\n1. Compose\n");
        printf("2. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }

    return 0;
}