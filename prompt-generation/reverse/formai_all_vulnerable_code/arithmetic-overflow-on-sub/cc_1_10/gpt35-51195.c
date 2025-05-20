//FormAI DATASET v1.0 Category: Email Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_CHARS 1000

typedef struct {
    char from[50];
    char to[50];
    char subject[100];
    char body[MAX_CHARS];
} Email;

int numEmails = 0;
Email emails[MAX_EMAILS];

void printMenu() {
    printf("\n\nSimple Email Client\n");
    printf("-------------------\n");
    printf("1. Write Email\n");
    printf("2. List Inbox\n");
    printf("3. Read Email\n");
    printf("4. Exit\n");
}

void writeEmail() {
    Email email;
    printf("\n\nWrite Email\n");
    printf("-----------\n");
    printf("From: ");
    scanf("%s", email.from);
    printf("To: ");
    scanf("%s", email.to);
    printf("Subject: ");
    scanf("%s", email.subject);
    printf("Body: ");
    getchar();
    fgets(email.body, MAX_CHARS, stdin);
    emails[numEmails] = email;
    numEmails++;
    printf("Email sent successfully!\n");
}

void listInbox() {
    printf("\n\nInbox\n");
    printf("-----\n");
    if (numEmails == 0) {
        printf("No emails in inbox.\n");
    } else {
        for (int i = 0; i < numEmails; i++) {
            printf("%d. From: %s\n", i+1, emails[i].from);
            printf("   Subject: %s\n", emails[i].subject);
        }
    }
}

void readEmail() {
    int index;
    printf("\n\nRead Email\n");
    printf("----------\n");
    printf("Enter the index of the email: ");
    scanf("%d", &index);
    index--;
    printf("\nFrom: %s\n", emails[index].from);
    printf("To: %s\n", emails[index].to);
    printf("Subject: %s\n", emails[index].subject);
    printf("Body: \n%s\n", emails[index].body);
}

int main() {
    int choice;

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                writeEmail();
                break;
            case 2:
                listInbox();
                break;
            case 3:
                readEmail();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Choose again.\n");
        }
    }

    return 0;
}