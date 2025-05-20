//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    Contact sender;
} Email;

void print_contact(Contact contact) {
    printf("Name: %s\n", contact.name);
    printf("Email: %s\n", contact.email);
}

void print_email(Email email) {
    printf("Subject: %s\n", email.subject);
    printf("Message:\n%s\n", email.message);
    print_contact(email.sender);
}

int main() {
    int num_contacts = 0;
    Contact contacts[100];

    while (num_contacts < 100) {
        printf("Enter name (or 'done' to finish): ");
        scanf("%s", contacts[num_contacts].name);

        if (strcmp(contacts[num_contacts].name, "done") == 0) {
            break;
        }

        printf("Enter email: ");
        scanf("%s", contacts[num_contacts].email);

        num_contacts++;
    }

    int num_emails = 0;
    Email emails[100];

    while (num_emails < 100) {
        printf("\nEnter subject: ");
        scanf("%s", emails[num_emails].subject);

        printf("Enter message: ");
        scanf("%[^\n]", emails[num_emails].message);

        printf("Enter sender's name: ");
        scanf("%s", emails[num_emails].sender.name);

        strcpy(emails[num_emails].sender.email, contacts[0].email);

        num_emails++;
    }

    printf("\nContact List:\n");
    for (int i = 0; i < num_contacts; i++) {
        print_contact(contacts[i]);
    }

    printf("\nEmail List:\n");
    for (int i = 0; i < num_emails; i++) {
        print_email(emails[i]);
    }

    return 0;
}