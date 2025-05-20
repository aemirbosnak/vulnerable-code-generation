//FormAI DATASET v1.0 Category: Email Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_SUBJECT_LENGTH 100
#define MAX_CONTENT_LENGTH 500

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char content[MAX_CONTENT_LENGTH];
    char recipient[MAX_EMAILS][MAX_SUBJECT_LENGTH];
    char sender[MAX_SUBJECT_LENGTH];
} Email;

Email emails[MAX_EMAILS];
int totalEmails = 0;

void sendEmail(char subject[], char content[], char recipient[], char sender[]);
void viewInbox();
void viewEmail(int emailIndex);

int main() {
    char input;

    do {
        printf("\n\n*** Happy Email Client ***\n");
        printf("1) Send Email\n");
        printf("2) View Inbox\n");
        printf("3) Exit\n");
        printf("Enter choice: ");
        scanf(" %c", &input);
        fflush(stdin);

        switch(input) {
            case '1': {
                // Send email
                char subject[MAX_SUBJECT_LENGTH];
                char content[MAX_CONTENT_LENGTH];
                char recipient[MAX_EMAILS][MAX_SUBJECT_LENGTH];
                char sender[MAX_SUBJECT_LENGTH];

                printf("\nEnter subject: ");
                fgets(subject, MAX_SUBJECT_LENGTH, stdin);
                subject[strcspn(subject, "\n")] = 0;

                printf("Enter content: ");
                fgets(content, MAX_CONTENT_LENGTH, stdin);
                content[strcspn(content, "\n")] = 0;

                printf("Enter recipient(s) (separate multiple with commas): ");
                fgets(recipient[0], MAX_SUBJECT_LENGTH, stdin);
                recipient[0][strcspn(recipient[0], "\n")] = 0;

                printf("Enter sender: ");
                fgets(sender, MAX_SUBJECT_LENGTH, stdin);
                sender[strcspn(sender, "\n")] = 0;

                sendEmail(subject, content, recipient[0], sender);

                printf("\nEmail sent!\n");
                break;
            }

            case '2': {
                // View Inbox
                viewInbox();
                break;
            }

            case '3': {
                // Exit
                printf("\nGoodbye!!\n");
                break;
            }

            default: {
                printf("\nInvalid Choice!!\n");
                break;
            }
        }
    } while(input != '3');

    return 0;
}

void sendEmail(char subject[], char content[], char recipient[], char sender[]) {
    Email newEmail;

    strcpy(newEmail.subject, subject);
    strcpy(newEmail.content, content);
    strcpy(newEmail.recipient[0], recipient);
    strcpy(newEmail.sender, sender);

    // Add email to collection
    emails[totalEmails++] = newEmail;
}

void viewInbox() {
    printf("\n*** Inbox (%d) ***\n", totalEmails);

    if(totalEmails == 0) {
        printf("No Emails Found!!!\n\n");
    } else {
        for(int i = 0; i < totalEmails; i++) {
            printf("%d) %s => %s\n", (i + 1), emails[i].subject, emails[i].recipient[0]);
        }

        printf("Enter email number to view (or 0 to go back): ");

        int choice;
        scanf("%d", &choice);

        if(choice == 0) {
            // Go back
            viewInbox();
        } else {
            // View Email
            viewEmail(choice - 1);
        }
    }
}

void viewEmail(int emailIndex) {
    printf("\n*** Email (%d) ***\n", (emailIndex + 1));
    printf("Subject: %s\n", emails[emailIndex].subject);
    printf("Content: %s\n", emails[emailIndex].content);
    printf("Recipient: %s\n", emails[emailIndex].recipient[0]);
    printf("Sender: %s\n\n", emails[emailIndex].sender);
}