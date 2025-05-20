//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECTS 100
#define MAX_BODY 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

void add_contact(contact *contacts, int *num_contacts) {
    printf("Enter name: ");
    scanf("%s", contacts[*num_contacts].name);

    printf("Enter email: ");
    scanf("%s", contacts[*num_contacts].email);

    (*num_contacts)++;
}

void print_contacts(contact *contacts, int num_contacts) {
    for (int i = 0; i < num_contacts; i++) {
        printf("%s <%s>\n", contacts[i].name, contacts[i].email);
    }
}

void send_mail(contact *contacts, int num_contacts, char *subject, char *body) {
    for (int i = 0; i < num_contacts; i++) {
        char to[MAX_EMAIL_LEN];
        strcpy(to, contacts[i].email);

        char from[MAX_EMAIL_LEN] = "sender@example.com";
        char headers[MAX_SUBJECTS + MAX_BODY + 100];
        sprintf(headers, "From: %s\r\nTo: %s\r\nSubject: %s\r\nContent-Type: text/plain\r\n\r\n%s", from, to, subject, body);

        system("echo -e \"$headers\" | ssmtp \"$to\"");
        printf("Mail sent to %s\n", contacts[i].name);
    }
}

int main() {
    contact contacts[100];
    int num_contacts = 0;

    add_contact(contacts, &num_contacts);
    add_contact(contacts, &num_contacts);
    add_contact(contacts, &num_contacts);

    printf("Contacts:\n");
    print_contacts(contacts, num_contacts);

    char subject[MAX_SUBJECTS] = "Test Mail";
    char body[MAX_BODY] = "Hello World! This is a test mail sent using the mailing list manager.";

    send_mail(contacts, num_contacts, subject, body);

    return 0;
}