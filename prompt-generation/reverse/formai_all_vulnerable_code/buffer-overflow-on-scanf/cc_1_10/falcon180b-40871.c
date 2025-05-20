//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
} Contact;

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} Message;

void add_contact(Contact* contact, int num_contacts) {
    printf("Enter name: ");
    scanf("%s", contact->name);

    printf("Enter email: ");
    scanf("%s", contact->email);

    num_contacts++;
}

void send_message(Message* message, Contact* contacts, int num_contacts) {
    printf("Enter subject: ");
    scanf("%s", message->subject);

    printf("Enter message: ");
    scanf("%s", message->message);

    for (int i = 0; i < num_contacts; i++) {
        printf("Sending message to %s (%s)\n", contacts[i].name, contacts[i].email);
    }
}

int main() {
    int num_contacts = 0;
    Contact contacts[10];

    while (num_contacts < 10) {
        add_contact(&contacts[num_contacts], num_contacts);
    }

    Message message;
    send_message(&message, contacts, num_contacts);

    return 0;
}