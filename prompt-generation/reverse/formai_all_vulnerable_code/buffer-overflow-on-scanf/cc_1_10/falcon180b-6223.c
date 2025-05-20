//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECTS 100
#define MAX_BODY 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct {
    char subject[MAX_SUBJECTS];
    char body[MAX_BODY];
} Email;

void add_contact(Contact* contacts, int num_contacts, char* name, char* email) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].email, email) == 0) {
            printf("Contact already exists.\n");
            return;
        }
    }
    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].email, email);
    num_contacts++;
}

void send_email(Email* email, Contact* contacts, int num_contacts) {
    printf("Sending email to %s...\n", email->subject);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(email->subject, contacts[i].name) == 0) {
            printf("Email sent to %s.\n", contacts[i].email);
        }
    }
}

int main() {
    int num_contacts = 0;
    Contact contacts[100];
    char input[100];

    while (1) {
        printf("1. Add contact\n2. Send email\n3. Exit\n");
        scanf("%d", &num_contacts);

        switch (num_contacts) {
            case 1:
                printf("Enter name: ");
                scanf("%s", input);
                printf("Enter email: ");
                scanf("%s", input);
                add_contact(contacts, num_contacts, input, input);
                break;
            case 2:
                printf("Enter subject: ");
                scanf("%s", input);
                printf("Enter body: ");
                scanf("%s", input);
                Email email = {"", ""};
                strcpy(email.subject, input);
                strcpy(email.body, input);
                send_email(&email, contacts, num_contacts);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}