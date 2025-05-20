//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECTS 100
#define MAX_BODY 500

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct {
    char subject[MAX_SUBJECTS];
    char body[MAX_BODY];
    Contact* recipients;
    int num_recipients;
} Message;

Contact* create_contact(char* name, char* email) {
    Contact* contact = (Contact*)malloc(sizeof(Contact));
    strcpy(contact->name, name);
    strcpy(contact->email, email);
    return contact;
}

void add_recipient(Message* message, Contact* recipient) {
    message->recipients = (Contact*)realloc(message->recipients, sizeof(Contact) * (message->num_recipients + 1));
    strcpy(message->recipients[message->num_recipients].name, recipient->name);
    strcpy(message->recipients[message->num_recipients].email, recipient->email);
    message->num_recipients++;
}

void send_message(Message* message) {
    printf("Sending message to %d recipients:\n", message->num_recipients);
    for (int i = 0; i < message->num_recipients; i++) {
        printf("Name: %s\nEmail: %s\n", message->recipients[i].name, message->recipients[i].email);
    }
}

int main() {
    Contact* john = create_contact("John Doe", "john@example.com");
    Contact* jane = create_contact("Jane Doe", "jane@example.com");

    Message* message = (Message*)malloc(sizeof(Message));
    strcpy(message->subject, "Test Message");
    strcpy(message->body, "Hello World!");
    add_recipient(message, john);
    add_recipient(message, jane);

    send_message(message);

    free(message->recipients);
    free(message);
    free(john);
    free(jane);

    return 0;
}