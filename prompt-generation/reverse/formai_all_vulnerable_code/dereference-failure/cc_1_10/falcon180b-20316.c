//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECT_LEN 100
#define MAX_BODY_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
} message;

contact *create_contact(char *name, char *email) {
    contact *new_contact = (contact *)malloc(sizeof(contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->email, email);
    return new_contact;
}

message *create_message(char *subject, char *body) {
    message *new_message = (message *)malloc(sizeof(message));
    strcpy(new_message->subject, subject);
    strcpy(new_message->body, body);
    return new_message;
}

void send_message(contact *recipient, message *message) {
    printf("Sending message to %s (%s)\nSubject: %s\nBody:\n%s\n", recipient->name, recipient->email, message->subject, message->body);
}

int main() {
    contact *john = create_contact("John Doe", "john@example.com");
    contact *jane = create_contact("Jane Doe", "jane@example.com");

    message *greeting_message = create_message("Hello", "How are you doing today?");
    message *update_message = create_message("Update", "Just wanted to let you know that the project is on track.");

    send_message(john, greeting_message);
    send_message(jane, update_message);

    free(john);
    free(jane);
    free(greeting_message);
    free(update_message);

    return 0;
}