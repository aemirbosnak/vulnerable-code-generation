//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECT_LEN 200
#define MAX_BODY_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
    Contact* recipients;
    int num_recipients;
} Message;

void add_contact(Contact* contacts, int num_contacts, char* name, char* email) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].email, email) == 0) {
            strcpy(contacts[i].name, name);
            return;
        }
    }
    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].email, email);
    num_contacts++;
}

void send_message(Message* message, Contact* contacts, int num_contacts) {
    for (int i = 0; i < num_contacts; i++) {
        printf("Sending message to %s (%s)\n", message->recipients[i].name, message->recipients[i].email);
    }
}

int main() {
    Contact contacts[100];
    int num_contacts = 0;
    char input[1000];
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        char* name = strtok(input, " ");
        char* email = strtok(NULL, " ");
        add_contact(contacts, num_contacts, name, email);
        num_contacts++;
    }
    Message message;
    strcpy(message.subject, "Futuristic Mailing List Manager");
    strcpy(message.body, "Hello, this is a message from the future!\n\n");
    message.recipients = contacts;
    message.num_recipients = num_contacts;
    send_message(&message, contacts, num_contacts);
    return 0;
}