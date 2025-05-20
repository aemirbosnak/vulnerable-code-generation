//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    contact *recipient;
    struct node *next;
} message;

typedef struct node {
    message *data;
    struct node *next;
} node;

void add_contact(contact *list, char *name, char *email) {
    int i = 0;
    while (list[i].name[0]!= '\0') {
        i++;
    }
    strcpy(list[i].name, name);
    strcpy(list[i].email, email);
}

int search_contact(contact *list, int size, char *email) {
    int i = 0;
    while (i < size) {
        if (strcmp(list[i].email, email) == 0) {
            return i;
        }
        i++;
    }
    return -1;
}

void add_message(message *list, int size, char *subject, char *email) {
    int recipient_index = search_contact(list->recipient, size, email);
    if (recipient_index == -1) {
        printf("Contact not found.\n");
        return;
    }
    strcpy(list[size].subject, subject);
    list[size].recipient = &list[recipient_index];
    size++;
}

void send_messages(message *list, int size) {
    int i = 0;
    while (i < size) {
        printf("Sending message to %s about %s...\n", list[i].recipient->email, list[i].subject);
        i++;
    }
}

int main() {
    contact contacts[10];
    int num_contacts = 0;
    char input[MAX_NAME_LENGTH + MAX_EMAIL_LENGTH + 2];

    printf("Enter name and email in the format 'name@email':\n");
    while (num_contacts < 10 && scanf("%[^\n]", input) == 1) {
        char *name = strtok(input, "@");
        char *email = strtok(NULL, "@");
        add_contact(contacts, name, email);
        num_contacts++;
        printf("Enter another name and email? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice!= 'y') {
            break;
        }
    }

    message messages[10];
    int num_messages = 0;

    printf("Enter message subject and recipient email in the format'subject@email':\n");
    while (num_messages < 10 && scanf("%[^\n]", input) == 1) {
        char *subject = strtok(input, "@");
        char *email = strtok(NULL, "@");
        int recipient_index = search_contact(contacts, num_contacts, email);
        if (recipient_index == -1) {
            printf("Recipient not found.\n");
            continue;
        }
        add_message(messages, num_messages, subject, email);
        num_messages++;
        printf("Enter another message? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice!= 'y') {
            break;
        }
    }

    send_messages(messages, num_messages);

    return 0;
}