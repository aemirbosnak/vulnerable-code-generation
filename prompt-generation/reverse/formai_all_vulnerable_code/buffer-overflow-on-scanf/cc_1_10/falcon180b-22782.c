//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: shocked
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

contact contacts[100];
int num_contacts = 0;

void add_contact(char* name, char* email) {
    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].email, email);
    num_contacts++;
}

void send_email(char* subject, char* message) {
    for (int i = 0; i < num_contacts; i++) {
        email email = {subject, message};
        printf("Sending email to %s (%s)\n", contacts[i].name, contacts[i].email);
    }
}

int main() {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your email: ");
    scanf("%s", email);

    add_contact(name, email);

    char subject[MAX_SUBJECT_LEN];
    char message[MAX_MESSAGE_LEN];

    printf("Enter email subject: ");
    scanf("%s", subject);

    printf("Enter email message: ");
    scanf("%s", message);

    send_email(subject, message);

    return 0;
}