//FormAI DATASET v1.0 Category: Email Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 200

typedef struct email {
    char recipient[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

void display_menu() {
    printf("Welcome to C Email Client\n");
    printf("1. Compose Email\n");
    printf("2. View Inbox\n");
    printf("3. Exit\n");
}

void compose_email(Email *e) {
    printf("Enter recipient email address: ");
    scanf("%s", e->recipient);

    printf("Enter email subject: ");
    scanf("%s", e->subject);

    printf("Enter email body: ");
    scanf(" %[^\n]s", e->body);

    printf("\nEmail Sent!\n\n");
}

void view_inbox() {
    FILE *fp = fopen("inbox.txt", "r");

    if (fp == NULL) {
        printf("No emails to display.\n\n");
        return;
    }

    char line[256];

    while (fgets(line, sizeof(line), fp)) {
        printf("%s\n", line);
    }

    fclose(fp);
}

int main() {
    int choice;
    Email email;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                compose_email(&email);
                char filename[MAX_EMAIL_LENGTH + 5];
                sprintf(filename, "%s.txt", email.recipient);
                FILE *fp = fopen(filename, "a");
                fprintf(fp, "From: cemailclient@gmail.com\n");
                fprintf(fp, "To: %s\n", email.recipient);
                fprintf(fp, "Subject: %s\n", email.subject);
                fprintf(fp, "Body: %s\n\n", email.body);
                fclose(fp);
                break;
            case 2:
                view_inbox();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n\n");
        }
    }

    return 0;
}