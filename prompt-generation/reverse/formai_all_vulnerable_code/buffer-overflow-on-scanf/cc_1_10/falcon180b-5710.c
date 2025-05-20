//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 64
#define MAX_EMAIL_LEN 256
#define MAX_SUBJECTS 64
#define MAX_BODIES 2048
#define MAX_RECIPIENTS 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

typedef struct {
    char subject[MAX_SUBJECTS];
    char body[MAX_BODIES];
    Contact recipients[MAX_RECIPIENTS];
    int numRecipients;
} Email;

Email emails[100];
int numEmails = 0;

void addEmail(char *subject, char *body)
{
    printf("Enter recipient name: ");
    scanf("%s", emails[numEmails].recipients[0].name);
    printf("Enter recipient email: ");
    scanf("%s", emails[numEmails].recipients[0].email);

    strcpy(emails[numEmails].subject, subject);
    strcpy(emails[numEmails].body, body);

    numEmails++;
}

void sendEmails()
{
    for (int i = 0; i < numEmails; i++) {
        printf("Sending email to %s (%s)\n", emails[i].recipients[0].name, emails[i].recipients[0].email);
    }
}

int main()
{
    char choice;

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add email\n");
        printf("2. Send emails\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            addEmail("Test email", "Hello, this is a test email!");
            break;
        case '2':
            sendEmails();
            break;
        case '3':
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}