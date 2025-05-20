//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: invasive
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
} Message;

void add_contact(Contact *contacts, int *num_contacts, char *name, char *email) {
    (*num_contacts)++;
    contacts = realloc(contacts, sizeof(Contact) * (*num_contacts));
    strcpy(contacts[*num_contacts - 1].name, name);
    strcpy(contacts[*num_contacts - 1].email, email);
}

void send_message(Contact *contacts, int num_contacts, Message message) {
    for (int i = 0; i < num_contacts; i++) {
        printf("Sending message to %s (%s)\n", contacts[i].name, contacts[i].email);
        printf("Subject: %s\n", message.subject);
        printf("Body:\n%s\n", message.body);
    }
}

int main() {
    Contact *contacts = NULL;
    int num_contacts = 0;

    add_contact(contacts, &num_contacts, "John Doe", "john.doe@example.com");
    add_contact(contacts, &num_contacts, "Jane Doe", "jane.doe@example.com");

    Message message;
    strcpy(message.subject, "Test Message");
    strcpy(message.body, "Hello, this is a test message!");

    send_message(contacts, num_contacts, message);

    for (int i = 0; i < num_contacts; i++) {
        free(contacts[i].name);
        free(contacts[i].email);
    }
    free(contacts);

    return 0;
}