//Falcon-180B DATASET v1.0 Category: Email Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100

typedef struct {
    char sender[51];
    char recipient[51];
    char subject[101];
    char message[1001];
} Email;

int num_emails = 0;
Email emails[MAX_EMAILS];

void add_email() {
    if (num_emails >= MAX_EMAILS) {
        printf("Sorry, you can only have %d emails.\n", MAX_EMAILS);
        return;
    }

    printf("Sender: ");
    scanf("%[^\n]", emails[num_emails].sender);
    printf("Recipient: ");
    scanf("%[^\n]", emails[num_emails].recipient);
    printf("Subject: ");
    scanf("%[^\n]", emails[num_emails].subject);
    printf("Message: ");
    fgets(emails[num_emails].message, 1001, stdin);
    num_emails++;
}

void view_emails() {
    for (int i = 0; i < num_emails; i++) {
        printf("Email %d:\n");
        printf("Sender: %s\n", emails[i].sender);
        printf("Recipient: %s\n", emails[i].recipient);
        printf("Subject: %s\n", emails[i].subject);
        printf("Message:\n%s\n", emails[i].message);
        printf("\n");
    }
}

int main() {
    char choice;

    do {
        printf("Welcome to the Retro Email Client!\n");
        printf("A - Add email\n");
        printf("V - View emails\n");
        printf("Q - Quit\n");
        printf("Choice: ");
        scanf(" %c", &choice);

        switch (choice) {
        case 'A':
            add_email();
            break;
        case 'V':
            view_emails();
            break;
        case 'Q':
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 'Q');

    return 0;
}