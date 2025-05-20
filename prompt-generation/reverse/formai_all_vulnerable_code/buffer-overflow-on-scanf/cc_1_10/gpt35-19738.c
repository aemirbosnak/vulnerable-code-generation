//FormAI DATASET v1.0 Category: Email Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_EMAILS 50

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char recipient[50];
} Email;

int main() {
    int numEmails = 0;
    Email emailBox[MAX_EMAILS];
    char input;
    while (1) {
        printf("Welcome to your very own C Email Client!\n");
        printf("What would you like to do?\n");
        printf("a - Compose a new email\n");
        printf("b - Read your emails\n");
        printf("q - Quit the email client\n");
        printf("Please enter your choice: ");
        scanf(" %c", &input);

        switch (input) {
            case 'a': {
                Email newEmail;
                printf("Please enter the recipient's email address: ");
                scanf("%s", newEmail.recipient);

                printf("Please enter the subject line of your email: ");
                scanf(" %[^\n]s", newEmail.subject);

                printf("Please enter the body of your email: ");
                scanf(" %[^\n]s", newEmail.body);

                emailBox[numEmails] = newEmail;
                numEmails++;

                printf("Email successfully sent to %s!\n\n", newEmail.recipient);
                break;
            }
            case 'b': {
                if (numEmails == 0) {
                    printf("You have no emails currently!\n\n");
                    break;
                }
                printf("Here are your current emails:\n");
                for (int i = 0; i < numEmails; i++) {
                    printf("%d. Subject: %s\n", i + 1, emailBox[i].subject);
                    printf("   From: %s\n", emailBox[i].recipient);
                    printf("   Body: %s\n\n", emailBox[i].body);
                }
                break;
            }
            case 'q': {
                printf("Thanks for using the C Email Client!\n");
                exit(0);
            }
            default: {
                printf("Invalid input, please try again!\n\n");
                break;
            }
        }
    }
    return 0;
}