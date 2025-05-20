//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100
#define MAX_EMAIL 100
#define MAX_SUBJECT 100
#define MAX_MESSAGE 1000

typedef struct {
    char name[MAX_NAME];
    char email[MAX_EMAIL];
} contact;

typedef struct {
    char subject[MAX_SUBJECT];
    char message[MAX_MESSAGE];
} email;

contact contacts[100];
int num_contacts = 0;

void add_contact(char *name, char *email) {
    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].email, email);
    num_contacts++;
}

void send_email(char *subject, char *message, int to_contact) {
    email email_to_send;
    strcpy(email_to_send.subject, subject);
    strcpy(email_to_send.message, message);
    printf("Sending email to %s...\n", contacts[to_contact].email);
}

int main() {
    int choice, to_contact;
    char name[MAX_NAME], email[MAX_EMAIL], subject[MAX_SUBJECT], message[MAX_MESSAGE];

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add contact\n2. Send email\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter email: ");
            scanf("%s", email);
            add_contact(name, email);
            break;
        case 2:
            printf("Enter subject: ");
            scanf("%s", subject);
            printf("Enter message: ");
            fgets(message, MAX_MESSAGE, stdin);
            to_contact = 0;
            printf("Enter recipient contact number: ");
            scanf("%d", &to_contact);
            send_email(subject, message, to_contact);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}