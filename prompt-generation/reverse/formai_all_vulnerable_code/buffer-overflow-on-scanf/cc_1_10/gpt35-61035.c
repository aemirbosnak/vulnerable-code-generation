//FormAI DATASET v1.0 Category: Email Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 20
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 500

typedef struct {
    char sender[50];
    char recipient[50];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

Email inbox[MAX_EMAILS];
int num_emails = 0;

void print_menu() {
    printf("Email Client Menu:\n");
    printf("1. Compose a new email\n");
    printf("2. View inbox\n");
    printf("3. Exit\n");
}

void compose_email() {
    Email new_email;

    printf("Enter sender's email address: ");
    fgets(new_email.sender, 50, stdin);
    printf("Enter recipient's email address: ");
    fgets(new_email.recipient, 50, stdin);
    printf("Enter email subject (max %d characters): ", MAX_SUBJECT_LENGTH);
    fgets(new_email.subject, MAX_SUBJECT_LENGTH, stdin);
    printf("Enter email body (max %d characters): ", MAX_BODY_LENGTH);
    fgets(new_email.body, MAX_BODY_LENGTH, stdin);

    inbox[num_emails++] = new_email;
    printf("Email sent successfully!\n");
}

void view_inbox() {
    if (num_emails == 0) {
        printf("Inbox is empty.\n");
        return;
    }
    printf("Inbox contents:\n");
    for (int i = 0; i < num_emails; i++) {
        printf("Email %d\n", i+1);
        printf("From: %s", inbox[i].sender);
        printf("To: %s", inbox[i].recipient);
        printf("Subject: %s", inbox[i].subject);
        printf("Body: %s", inbox[i].body);
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        print_menu();

        printf("Enter choice (1-3): ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left behind by scanf()

        switch (choice) {
            case 1:
                compose_email();
                break;
            case 2:
                view_inbox();
                break;
            case 3:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number from 1 to 3.\n");
        }
        printf("\n");
    } while (choice != 3);

    return 0;
}