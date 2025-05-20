//FormAI DATASET v1.0 Category: Email Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_EMAILS 100

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

Email emails[MAX_EMAILS];
int numEmails = 0;

void sendEmail(char* to, char* subject, char* body) {
    // Code for sending email goes here
    // Not implemented for the purposes of this example program
}

void composeEmail() {
    char to[100];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];

    printf("To: ");
    scanf("%s", to);

    printf("Subject: ");
    scanf("%s", subject);

    printf("Body: ");
    getchar();
    fgets(body, MAX_BODY_LENGTH, stdin);

    sendEmail(to, subject, body);

    // Add the composed email to the list of sent emails
    Email newEmail;
    strcpy(newEmail.subject, subject);
    strcpy(newEmail.body, body);
    emails[numEmails++] = newEmail;

    printf("Email sent!\n");
}

void printEmails() {
    printf("------ YOUR EMAILS ------\n");
    for (int i = 0; i < numEmails; i++) {
        printf("Subject: %s\n", emails[i].subject);
        printf("%s\n", emails[i].body);
        printf("-------------------------\n");
    }
}

int main() {
    while (1) {
        printf("Welcome to the future email client!\n");
        printf("1. Compose Email\n");
        printf("2. View Emails\n");
        printf("3. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            composeEmail();
            break;
        case 2:
            printEmails();
            break;
        case 3:
            printf("Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}