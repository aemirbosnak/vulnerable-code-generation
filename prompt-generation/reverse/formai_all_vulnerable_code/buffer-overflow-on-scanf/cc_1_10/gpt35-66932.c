//FormAI DATASET v1.0 Category: Email Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct email {
    char to[50];
    char subject[100];
    char message[1000];
};

void view_emails(struct email *emails, int count) {
    if (count == 0) {
        printf("No emails in inbox.\n");
        return;
    }
    printf("\nInbox:\n");
    for (int i = 0; i < count; i++) {
        printf("Email %d:\n", i+1);
        printf("To: %s\n", emails[i].to);
        printf("Subject: %s\n", emails[i].subject);
        printf("Message: %s\n", emails[i].message);
        printf("\n");
    }
}

void send_email(struct email *emails, int *count) {
    printf("\nTo: ");
    fgets(emails[*count].to, 50, stdin);
    printf("Subject: ");
    fgets(emails[*count].subject, 100, stdin);
    printf("Message: ");
    fgets(emails[*count].message, 1000, stdin);
    (*count)++;
    printf("Email sent successfully.\n");
}

int main() {
    struct email emails[10];
    int count = 0;
    int option;
    while (1) {
        printf("\nMenu:\n");
        printf("1. View Emails\n");
        printf("2. Send an Email\n");
        printf("3. Quit\n");
        printf("Enter an option: ");
        scanf("%d", &option);
        while ((getchar()) != '\n'); // Clear input buffer
        switch (option) {
            case 1:
                view_emails(emails, count);
                break;
            case 2:
                send_email(emails, &count);
                break;
            case 3:
                printf("Quitting...\n");
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    }
    return 0;
}