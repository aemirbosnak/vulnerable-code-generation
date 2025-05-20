//FormAI DATASET v1.0 Category: Email Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 1000
#define MAX_EMAILS 100

typedef struct {
    char sender[50];
    char recipient[50];
    char subject[200];
    char message[MAX_MSG_LEN];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void send_email() {
    char sender[50], recipient[50], subject[200], message[MAX_MSG_LEN];
    printf("Enter sender: ");
    scanf("%s", sender);
    printf("Enter recipient: ");
    scanf("%s", recipient);
    printf("Enter subject: ");
    getchar(); // consume newline character
    fgets(subject, 200, stdin);
    printf("Enter message: ");
    fgets(message, MAX_MSG_LEN, stdin);
    // create email object and add to array
    Email new_email = { .sender = sender, .recipient = recipient, .subject = subject, .message = message };
    emails[num_emails] = new_email;
    num_emails++;
}

void display_emails() {
    printf("Total emails: %d\n", num_emails);
    for (int i = 0; i < num_emails; i++) {
        printf("Email %d\n", i+1);
        printf("Sender: %s\n", emails[i].sender);
        printf("Recipient: %s\n", emails[i].recipient);
        printf("Subject: %s\n", emails[i].subject);
        printf("Message: %s\n", emails[i].message);
    }
}

int main() {
    char selection;
    do {
        printf("\n\n----- Email Client Menu -----\n");
        printf("1. Send email\n");
        printf("2. View emails\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%c", &selection);
        getchar(); // consume newline character
        switch (selection) {
            case '1':
                send_email();
                printf("Email sent successfully.\n");
                break;
            case '2':
                display_emails();
                break;
            case '3':
                printf("Exiting email client...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (selection != '3');
    return 0;
}