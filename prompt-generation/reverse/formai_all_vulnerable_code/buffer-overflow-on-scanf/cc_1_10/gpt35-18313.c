//FormAI DATASET v1.0 Category: Mailing list manager ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 50
#define MAX_LEN 50

struct Email {
    char to[MAX_LEN];
    char from[MAX_LEN];
    char subject[MAX_LEN];
    char message[MAX_LEN];
};

int num_emails = 0;
struct Email emails[MAX_EMAILS];

void add_email() {
    if (num_emails == MAX_EMAILS) {
        printf("Error: Mailing list is full\n");
        return;
    }

    printf("Enter email information:\n");
    printf("To: ");
    fgets(emails[num_emails].to, MAX_LEN, stdin);
    printf("From: ");
    fgets(emails[num_emails].from, MAX_LEN, stdin);
    printf("Subject: ");
    fgets(emails[num_emails].subject, MAX_LEN, stdin);
    printf("Message: ");
    fgets(emails[num_emails].message, MAX_LEN, stdin);
    num_emails++;
}

void print_emails() {
    if (num_emails == 0) {
        printf("Mailing list is empty\n");
        return;
    }

    printf("Mailing List:\n");
    for (int i = 0; i < num_emails; i++) {
        printf("To: %s", emails[i].to);
        printf("From: %s", emails[i].from);
        printf("Subject: %s", emails[i].subject);
        printf("Message: %s", emails[i].message);
        printf("\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n1. Add Email\n");
        printf("2. Print Emails\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: add_email(); break;
            case 2: print_emails(); break;
            case 3: printf("Goodbye!\n"); break;
            default: printf("Invalid choice\n"); break;
        }
    } while (choice != 3);

    return 0;
}