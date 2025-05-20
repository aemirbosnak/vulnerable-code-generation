//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 200
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} email;

int num_contacts;
contact *contacts;
int num_emails;
email *emails;

void read_contacts(FILE *file) {
    rewind(file);
    fscanf(file, "%d", &num_contacts);
    contacts = malloc(num_contacts * sizeof(contact));
    for (int i = 0; i < num_contacts; i++) {
        fscanf(file, "%s %s", contacts[i].name, contacts[i].email);
    }
}

void read_emails(FILE *file) {
    rewind(file);
    fscanf(file, "%d", &num_emails);
    emails = malloc(num_emails * sizeof(email));
    for (int i = 0; i < num_emails; i++) {
        fscanf(file, "%s %s", emails[i].subject, emails[i].message);
    }
}

void send_emails(FILE *file) {
    fprintf(file, "To: %s\r\n", contacts[0].email);
    fprintf(file, "From: sender@example.com\r\n");
    fprintf(file, "Subject: %s\r\n", emails[0].subject);
    fprintf(file, "\r\n%s", emails[0].message);
}

int main() {
    FILE *contacts_file = fopen("contacts.txt", "r");
    FILE *emails_file = fopen("emails.txt", "r");

    if (contacts_file == NULL || emails_file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    read_contacts(contacts_file);
    read_emails(emails_file);

    send_emails(stdout);

    fclose(contacts_file);
    fclose(emails_file);

    return 0;
}