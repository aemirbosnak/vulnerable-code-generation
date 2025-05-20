//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECT_LEN 100
#define MAX_MESSAGE_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char message[MAX_MESSAGE_LEN];
} Email;

int main() {
    char choice;
    int num_contacts = 0;
    Contact contacts[100];
    Email email;

    do {
        printf("Mailing List Manager\n");
        printf("A - Add contact\n");
        printf("S - Send email\n");
        printf("Q - Quit\n");
        scanf("%c", &choice);

        switch (choice) {
        case 'A':
            printf("Enter name: ");
            scanf("%s", contacts[num_contacts].name);
            printf("Enter email: ");
            scanf("%s", contacts[num_contacts].email);
            num_contacts++;
            break;
        case 'S':
            printf("Enter email subject: ");
            scanf("%s", email.subject);
            printf("Enter email message: ");
            scanf("%s", email.message);

            for (int i = 0; i < num_contacts; i++) {
                printf("Sending email to %s (%s)\n", contacts[i].name, contacts[i].email);
                // Code to send email to each contact
            }
            break;
        case 'Q':
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 'Q');

    return 0;
}