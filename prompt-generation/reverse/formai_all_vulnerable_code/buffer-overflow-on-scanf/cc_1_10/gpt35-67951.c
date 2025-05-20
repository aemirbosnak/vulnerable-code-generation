//FormAI DATASET v1.0 Category: Email Client ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {
    printf("\nWelcome to the unique C Email Client!\n\n");

    char email[1000], subject[100], to[100], body[1000], attachment[100];
    int choice;
    char recipient[100], reply[50];

    do {
        printf("==============================\n");
        printf(" Menu\n");
        printf("==============================\n");
        printf(" 1. Compose Email\n");
        printf(" 2. View Inbox\n");
        printf(" 3. View Sent Items\n");
        printf(" 4. Exit\n");
        printf("==============================\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nCompose Email\n");
                printf("==============\n");

                printf("Enter recipient: ");
                scanf("%s", to);

                printf("Enter subject: ");
                scanf("%s", subject);

                printf("Enter message: ");
                scanf(" %[^\n]%*c", body);

                printf("Would you like to attach a file? (y/n): ");
                scanf("%s", reply);

                if (strcmp(reply, "y") == 0) {
                    printf("Enter attachment path: ");
                    scanf("%s", attachment);

                    sprintf(email, "To: %s\nSubject: %s\n%s\nFile Attached: %s", to, subject, body, attachment);
                } else {
                    sprintf(email, "To: %s\nSubject: %s\n%s", to, subject, body);
                }

                printf("\nEmail successfully sent!\n");
                printf("==============================\n\n");
                break;

            case 2:
                printf("\nInbox\n");
                printf("==============\n");

                printf("From: John\nSubject: Hello\nMessage: How are you?\n\n");
                printf("From: Sarah\nSubject: Meeting\nMessage: Can you meet me tomorrow at 2pm?\n\n");

                printf("==============================\n\n");
                break;

            case 3:
                printf("\nSent Items\n");
                printf("==============\n");

                printf("To: John\nSubject: Hello\nMessage: I'm doing good, thanks for asking.\n\n");
                printf("To: Sarah\nSubject: Meeting\nMessage: Sure, I can meet you at 2pm tomorrow.\n\n");

                printf("==============================\n\n");
                break;

            case 4:
                printf("\nThank you for using the unique C Email Client!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}