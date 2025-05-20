//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECT_LEN 100
#define MAX_MESSAGE_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char message[MAX_MESSAGE_LEN];
} email;

void print_contact(contact c) {
    printf("Name: %s\n", c.name);
    printf("Email: %s\n", c.email);
}

void print_email(email e) {
    printf("Subject: %s\n", e.subject);
    printf("Message: %s\n", e.message);
}

int main() {
    int num_contacts, i;
    contact contacts[100];
    email email_to_send;

    printf("Welcome to the Cheerful Mailing List Manager!\n");
    printf("How many contacts do you have? ");
    scanf("%d", &num_contacts);

    for (i = 0; i < num_contacts; i++) {
        printf("Enter contact #%d's name: ", i+1);
        scanf("%s", contacts[i].name);
        printf("Enter contact #%d's email: ", i+1);
        scanf("%s", contacts[i].email);
    }

    printf("\nChoose a contact to send an email to:\n");
    for (i = 0; i < num_contacts; i++) {
        printf("%d. %s (%s)\n", i+1, contacts[i].name, contacts[i].email);
    }

    scanf("%d", &i);
    printf("You chose %s (%s).\n", contacts[i-1].name, contacts[i-1].email);

    printf("\nEnter the subject of your email: ");
    scanf("%s", email_to_send.subject);

    printf("\nEnter the message of your email: ");
    scanf("%s", email_to_send.message);

    printf("\nYour cheerful email has been sent to %s!\n", contacts[i-1].name);

    return 0;
}