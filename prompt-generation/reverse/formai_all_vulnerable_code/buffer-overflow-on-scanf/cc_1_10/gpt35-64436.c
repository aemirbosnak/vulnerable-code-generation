//FormAI DATASET v1.0 Category: Email Client ; Style: retro
#include <stdio.h>
#define MAX_EMAILS 100 // Maximum number of emails that can be stored

typedef struct {
    char sender[50];
    char recipient[50];
    char subject[100];
    char body[500];
} Email;

Email inbox[MAX_EMAILS]; // Array of emails

int num_emails = 0; // Number of emails currently in inbox

void add_email(char s[], char r[], char sub[], char b[]) {
    // Add a new email to the inbox array
    Email new_email;
    strcpy(new_email.sender, s);
    strcpy(new_email.recipient, r);
    strcpy(new_email.subject, sub);
    strcpy(new_email.body, b);
    inbox[num_emails] = new_email;
    num_emails++;
    printf("New email added to inbox!\n");
}

void print_inbox() {
    // Print all emails in the inbox array
    printf("INBOX:\n");
    for (int i = 0; i < num_emails; i++) {
        printf("Email %d\nFrom: %s\nTo: %s\nSubject: %s\nBody: %s\n", i+1, inbox[i].sender, inbox[i].recipient, inbox[i].subject, inbox[i].body);
    }
}

int main() {
    int choice;
    char sender[50], recipient[50], subject[100], body[500];

    while (1) {
        printf("1 - Compose an email\n2 - View inbox\n3 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter sender: ");
                scanf("%s", sender);
                printf("Enter recipient: ");
                scanf("%s", recipient);
                printf("Enter subject: ");
                scanf("%s", subject);
                printf("Enter body: ");
                scanf("%s", body);
                add_email(sender, recipient, subject, body);
                break;
            case 2:
                print_inbox();
                break;
            case 3:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}