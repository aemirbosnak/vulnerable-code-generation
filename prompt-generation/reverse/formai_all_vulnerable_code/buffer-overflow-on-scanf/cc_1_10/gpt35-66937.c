//FormAI DATASET v1.0 Category: Email Client ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Email {
    char* to;
    char* from;
    char* subject;
    char* body;
};

void display_menu() {
    printf("Choose an option:\n");
    printf("1) Compose email\n");
    printf("2) View inbox\n");
    printf("3) Exit\n");
}

void compose_email(struct Email* email) {
    char* to = malloc(100);
    char* from = "me@example.com";
    char* subject = malloc(100);
    char* body = malloc(1000);

    printf("Enter recipient: ");
    scanf("%s", to);
    email->to = to;

    printf("Enter subject: ");
    scanf("%s", subject);
    email->subject = subject;

    printf("Enter message: ");
    scanf("%s", body);
    email->body = body;

    email->from = from;
}

void view_inbox() {
    printf("Inbox is empty\n");
}

int main() {
    int choice;
    struct Email email;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                compose_email(&email);
                printf("Email sent to %s with subject '%s'\n", email.to, email.subject);
                break;
            case 2:
                view_inbox();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

    } while (choice != 3);

    return 0;
}