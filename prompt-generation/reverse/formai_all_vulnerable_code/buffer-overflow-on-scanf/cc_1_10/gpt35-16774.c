//FormAI DATASET v1.0 Category: Email Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Email {
    char sender[50];
    char recipient[50];
    char subject[100];
    char message[500];
};

void viewInbox(struct Email inbox[], int numEmails);
void composeEmail(struct Email inbox[], int *numEmails);
void viewEmail(struct Email inbox[], int numEmails, int index);

int main() {
    struct Email inbox[50];
    int numEmails = 0;
    char choice = ' ';

    while (choice != 'Q') {
        printf("Welcome to the Science Email Client!\n");
        printf("====================================\n");
        printf("1. View inbox\n");
        printf("2. Compose email\n");
        printf("3. View email\n");
        printf("Q. Quit\n");
        printf("====================================\n");
        printf("What would you like to do? ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                viewInbox(inbox, numEmails);
                break;
            case '2':
                composeEmail(inbox, &numEmails);
                break;
            case '3':
                printf("Enter the index of the email you would like to view: ");
                int index;
                scanf("%d", &index);
                viewEmail(inbox, numEmails, index);
                break;
            case 'Q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    }

    return 0;
}

void viewInbox(struct Email inbox[], int numEmails) {
    if (numEmails == 0) {
        printf("Your inbox is empty.\n");
    } else {
        printf("Your inbox contains %d email(s):\n", numEmails);
        for (int i = 0; i < numEmails; i++) {
            printf("%d. From: %s\n   Subject: %s\n", i, inbox[i].sender, inbox[i].subject);
        }
    }
}

void composeEmail(struct Email inbox[], int *numEmails) {
    if (*numEmails == 50) {
        printf("Error: your inbox is full.\n");
    } else {
        struct Email newEmail;
        printf("Enter the recipient: ");
        scanf("%s", newEmail.recipient);
        printf("Enter the subject: ");
        scanf("%s", newEmail.subject);
        printf("Enter the message: ");
        char ch = ' ';
        int i = 0;
        while ((ch = getchar()) != '\n' && i < 500) {
            newEmail.message[i++] = ch;
        }
        newEmail.message[i] = '\0';
        strcpy(newEmail.sender, "Scientific Bot");
        inbox[*numEmails] = newEmail;
        *numEmails += 1;
        printf("Email sent!\n");
    }
}

void viewEmail(struct Email inbox[], int numEmails, int index) {
    if (index >= numEmails) {
        printf("Error: invalid index.\n");
    } else {
        struct Email email = inbox[index];
        printf("From: %s\n", email.sender);
        printf("To: %s\n", email.recipient);
        printf("Subject: %s\n", email.subject);
        printf("Message:\n%s\n", email.message);
    }
}