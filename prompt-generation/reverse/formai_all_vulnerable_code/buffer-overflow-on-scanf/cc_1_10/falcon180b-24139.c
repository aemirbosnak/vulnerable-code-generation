//Falcon-180B DATASET v1.0 Category: Email Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 1024

typedef struct {
    char subject[MAX_EMAIL_LENGTH];
    char sender[MAX_EMAIL_LENGTH];
    char message[MAX_EMAIL_LENGTH];
    int length;
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email() {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: email inbox is full.\n");
        return;
    }

    printf("Enter the subject of the email: ");
    scanf("%s", emails[num_emails].subject);

    printf("Enter the sender of the email: ");
    scanf("%s", emails[num_emails].sender);

    printf("Enter the message of the email: ");
    scanf("%s", emails[num_emails].message);

    emails[num_emails].length = strlen(emails[num_emails].message);

    num_emails++;
}

void view_emails() {
    int i;

    printf("\nEmail inbox:\n");
    for (i = 0; i < num_emails; i++) {
        printf("%d. %s\n", i+1, emails[i].subject);
    }
}

void read_email(int index) {
    if (index < 0 || index >= num_emails) {
        printf("Error: invalid email index.\n");
        return;
    }

    printf("\nEmail from %s:\n", emails[index].sender);
    printf("%s\n", emails[index].message);
}

int main() {
    int choice;

    while (1) {
        printf("\nEmail client\n");
        printf("1. Add email\n");
        printf("2. View emails\n");
        printf("3. Read email\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_email();
                break;
            case 2:
                view_emails();
                break;
            case 3:
                printf("Enter the email index to read: ");
                scanf("%d", &choice);
                read_email(choice-1);
                break;
            case 4:
                exit(0);
            default:
                printf("Error: invalid choice.\n");
        }
    }

    return 0;
}