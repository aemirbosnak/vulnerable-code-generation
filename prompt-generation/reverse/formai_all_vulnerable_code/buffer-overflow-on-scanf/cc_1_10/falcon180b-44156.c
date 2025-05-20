//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct {
    Contact sender;
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} Email;

int main() {
    int num_contacts = 0;
    Contact contacts[100];
    int num_emails = 0;
    Email emails[100];

    // Add contacts
    printf("Enter the name and email of each contact (enter 'done' when finished):\n");
    while (scanf("%s %s", contacts[num_contacts].name, contacts[num_contacts].email) == 2) {
        num_contacts++;
    }

    // Add emails
    printf("Enter the sender, subject, and message for each email (enter 'done' when finished):\n");
    while (scanf("%s %s %s", emails[num_emails].sender.name, emails[num_emails].sender.email, emails[num_emails].subject) == 3) {
        scanf("%s", emails[num_emails].message);
        num_emails++;
    }

    // Send emails
    for (int i = 0; i < num_emails; i++) {
        for (int j = 0; j < num_contacts; j++) {
            if (strcmp(emails[i].sender.email, contacts[j].email) == 0) {
                printf("Sending email from %s to %s with subject '%s'...\n", emails[i].sender.name, contacts[j].name, emails[i].subject);
                printf("Message: %s\n\n", emails[i].message);
            }
        }
    }

    return 0;
}