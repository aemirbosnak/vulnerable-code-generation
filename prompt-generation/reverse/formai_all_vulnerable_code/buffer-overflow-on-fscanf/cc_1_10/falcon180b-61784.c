//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECT_LEN 100
#define MAX_MESSAGE_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char message[MAX_MESSAGE_LEN];
    int num_recipients;
    Contact *recipients;
} Message;

void read_contacts(Contact *contacts, int *num_contacts) {
    FILE *file = fopen("contacts.txt", "r");
    if (file == NULL) {
        printf("Error: could not open contacts file.\n");
        exit(1);
    }

    *num_contacts = 0;
    while (fscanf(file, "%s %s\n", contacts[*num_contacts].name, contacts[*num_contacts].email)!= EOF) {
        (*num_contacts)++;
    }

    fclose(file);
}

void read_message(Message *message, FILE *file) {
    fscanf(file, "%s\n%s\n%d\n", message->subject, message->message, &message->num_recipients);

    message->recipients = malloc(message->num_recipients * sizeof(Contact));
    for (int i = 0; i < message->num_recipients; i++) {
        fscanf(file, "%s %s\n", message->recipients[i].name, message->recipients[i].email);
    }
}

void send_message(Message *message) {
    printf("Subject: %s\n", message->subject);
    printf("Message:\n%s\n", message->message);

    for (int i = 0; i < message->num_recipients; i++) {
        printf("Recipient %d:\nName: %s\nEmail: %s\n", i + 1, message->recipients[i].name, message->recipients[i].email);
    }
}

int main() {
    Contact contacts[100];
    int num_contacts = 0;
    read_contacts(contacts, &num_contacts);

    Message message;
    FILE *file = fopen("message.txt", "r");
    if (file == NULL) {
        printf("Error: could not open message file.\n");
        exit(1);
    }

    read_message(&message, file);
    fclose(file);

    send_message(&message);

    return 0;
}