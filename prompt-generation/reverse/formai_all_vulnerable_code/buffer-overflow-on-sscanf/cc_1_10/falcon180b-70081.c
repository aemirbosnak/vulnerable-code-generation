//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_NAME_LEN 64
#define MAX_EMAIL_LEN 256
#define MAX_SUBJECT_LEN 256
#define MAX_MESSAGE_LEN 2048

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char message[MAX_MESSAGE_LEN];
} Email;

void add_contact(Contact *contacts, int *num_contacts, char *name, char *email) {
    int i;
    for (i = 0; i < *num_contacts; i++) {
        if (strcmp(contacts[i].email, email) == 0) {
            // Contact already exists, update name if necessary
            if (strcmp(contacts[i].name, name)!= 0) {
                strcpy(contacts[i].name, name);
            }
            return;
        }
    }
    // Add new contact
    strcpy(contacts[*num_contacts].name, name);
    strcpy(contacts[*num_contacts].email, email);
    (*num_contacts)++;
}

void send_email(Contact *contacts, int num_contacts, char *subject, char *message) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        printf("Sending email to %s (%s)\n", contacts[i].name, contacts[i].email);
    }
}

int main() {
    Contact contacts[100];
    int num_contacts = 0;
    char input_buffer[1024];
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];

    printf("Enter contacts (name email):\n");
    while (fgets(input_buffer, sizeof(input_buffer), stdin)!= NULL) {
        if (sscanf(input_buffer, "%s %s", name, email) == 2) {
            add_contact(contacts, &num_contacts, name, email);
        }
    }

    printf("Enter subject:\n");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    char subject[MAX_SUBJECT_LEN];
    strcpy(subject, input_buffer);
    input_buffer[0] = '\0';

    printf("Enter message:\n");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    char message[MAX_MESSAGE_LEN];
    strcpy(message, input_buffer);

    send_email(contacts, num_contacts, subject, message);

    return 0;
}