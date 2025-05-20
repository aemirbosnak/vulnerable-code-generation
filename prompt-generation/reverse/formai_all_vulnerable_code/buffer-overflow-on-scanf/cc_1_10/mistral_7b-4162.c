//MISTRAL-7B DATASET v1.0 Category: Spam Detection System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EMAILS 100

typedef struct {
    char sender[50];
    char recipient[50];
    char message[200];
    int isSpam;
} EmailMessage;

int main() {
    EmailMessage emailBox[MAX_EMAILS];
    int numEmails = 0;

    printf("Welcome to the Spam Detector 3000!\n");

    while (numEmails < MAX_EMAILS) {
        EmailMessage newEmail;
        printf("Enter sender: ");
        scanf("%s", newEmail.sender);
        printf("Enter recipient: ");
        scanf("%s", newEmail.recipient);
        printf("Enter message: ");
        scanf("%s", newEmail.message);

        // Check for spam keywords
        if (strstr(newEmail.message, "Viagra") ||
            strstr(newEmail.message, "Credit Card") ||
            strstr(newEmail.message, "Nigerian Prince") ||
            strstr(newEmail.message, "You've won")) {
            newEmail.isSpam = 1;
        } else {
            newEmail.isSpam = 0;
        }

        // Store the new email in the emailBox array
        emailBox[numEmails] = newEmail;
        numEmails++;
    }

    printf("\nEmail Box:\n");
    for (int i = 0; i < numEmails; i++) {
        printf("\nSender: %s\n", emailBox[i].sender);
        printf("Recipient: %s\n", emailBox[i].recipient);
        printf("Message: %s\n", emailBox[i].message);

        if (emailBox[i].isSpam) {
            printf("Spam\n");
        } else {
            printf("Not Spam\n");
        }
    }

    return 0;
}