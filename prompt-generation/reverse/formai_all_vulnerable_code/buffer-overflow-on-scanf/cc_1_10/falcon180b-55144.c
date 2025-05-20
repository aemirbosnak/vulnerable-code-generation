//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000

typedef struct {
    char name[100];
    char email[100];
} Email;

Email emails[MAX_EMAILS];
int numEmails = 0;

void addEmail() {
    printf("Enter name: ");
    scanf("%s", emails[numEmails].name);
    printf("Enter email: ");
    scanf("%s", emails[numEmails].email);
    numEmails++;
}

void removeEmail() {
    printf("Enter email to remove: ");
    char emailToRemove[100];
    scanf("%s", emailToRemove);
    int i;
    for (i = 0; i < numEmails; i++) {
        if (strcmp(emails[i].email, emailToRemove) == 0) {
            numEmails--;
            break;
        }
    }
}

void sendEmail() {
    printf("Enter email to send to: ");
    char emailToSend[100];
    scanf("%s", emailToSend);
    int i;
    for (i = 0; i < numEmails; i++) {
        if (strcmp(emails[i].email, emailToSend) == 0) {
            printf("Sending email to %s...\n", emails[i].name);
        }
    }
}

void viewEmails() {
    int i;
    for (i = 0; i < numEmails; i++) {
        printf("%s - %s\n", emails[i].name, emails[i].email);
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Add Email\n2. Remove Email\n3. Send Email\n4. View Emails\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEmail();
                break;
            case 2:
                removeEmail();
                break;
            case 3:
                sendEmail();
                break;
            case 4:
                viewEmails();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}