//FormAI DATASET v1.0 Category: Email Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_EMAILS 100

typedef struct email {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char sender[MAX_SUBJECT_LENGTH];
    char recipient[MAX_SUBJECT_LENGTH];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void send_email();
void view_inbox();
void view_email();

int main() {
    int choice;
    do {
        printf("\nWelcome to our Email Client!\n");
        printf("1) Send Email\n");
        printf("2) View Inbox\n");
        printf("3) Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                send_email();
                break;
            case 2:
                view_inbox();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);
    return 0;
}

void send_email() {
    Email new_email;
    printf("Enter the subject: ");
    scanf("%s", new_email.subject);
    printf("Enter the recipient: ");
    scanf("%s", new_email.recipient);
    printf("Enter the body: ");
    scanf("%s", new_email.body);
    printf("Enter the sender: ");
    scanf("%s", new_email.sender);
    emails[num_emails] = new_email;
    num_emails++;
    printf("Email sent!\n");
}

void view_inbox() {
    printf("Inbox:\n");
    for (int i = 0; i < num_emails; i++) {
        printf("%d) %s\n", i+1, emails[i].subject);
    }
    printf("Enter the number of the email to view (0 to cancel): ");
    int choice;
    scanf("%d", &choice);
    if (choice == 0) {
        return;
    }
    view_email(choice-1);
}

void view_email(int index) {
    printf("Subject: %s\n", emails[index].subject);
    printf("From: %s\n", emails[index].sender);
    printf("To: %s\n", emails[index].recipient);
    printf("Body: %s\n", emails[index].body);
}