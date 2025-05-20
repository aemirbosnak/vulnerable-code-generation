//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: detailed
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
} Mail;

void add_contact(Contact* contacts, int num_contacts, char* name, char* email) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].email, email) == 0) {
            printf("Contact already exists.\n");
            return;
        }
    }
    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].email, email);
    num_contacts++;
}

void send_mail(Contact* contacts, int num_contacts, char* subject, char* message) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        printf("Sending mail to %s (%s)\n", contacts[i].name, contacts[i].email);
    }
}

int main() {
    Contact contacts[10];
    int num_contacts = 0;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];

    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter email: ");
    scanf("%s", email);
    add_contact(contacts, num_contacts, name, email);

    printf("Enter subject: ");
    scanf("%s", subject);
    printf("Enter message: ");
    scanf("%s", message);
    send_mail(contacts, num_contacts, subject, message);

    return 0;
}