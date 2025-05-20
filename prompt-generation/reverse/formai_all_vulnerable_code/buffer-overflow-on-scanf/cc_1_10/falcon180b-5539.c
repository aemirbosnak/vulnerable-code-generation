//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} email;

contact contacts[100];
int num_contacts = 0;

void add_contact(char name[], char email[]) {
    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].email, email);
    num_contacts++;
}

void send_email(char subject[], char message[], int recipient_index) {
    printf("Sending email to %s:\n", contacts[recipient_index].name);
    printf("Subject: %s\n", subject);
    printf("Message:\n%s", message);
}

void send_to_all() {
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];

    printf("\nEnter subject: ");
    scanf("%s", subject);

    printf("\nEnter message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0';

    for (int i = 0; i < num_contacts; i++) {
        send_email(subject, message, i);
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];

    printf("Welcome to the Mailing List Manager!\n\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add contact\n2. Send email to all\n3. Exit\n");
        scanf("%d", &num_contacts);

        switch (num_contacts) {
        case 1:
            printf("\nEnter name: ");
            scanf("%s", name);
            printf("Enter email: ");
            scanf("%s", email);
            add_contact(name, email);
            break;

        case 2:
            send_to_all();
            break;

        case 3:
            printf("\nExiting program...\n");
            exit(0);

        default:
            printf("\nInvalid option!\n");
        }
    }

    return 0;
}