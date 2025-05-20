//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} email;

int main() {
    FILE *contacts_file, *emails_file;
    contacts_file = fopen("contacts.txt", "r");
    if (contacts_file == NULL) {
        printf("Error: contacts.txt not found.\n");
        return 1;
    }
    emails_file = fopen("emails.txt", "r");
    if (emails_file == NULL) {
        printf("Error: emails.txt not found.\n");
        return 1;
    }
    contact contacts[100];
    email emails[100];
    int num_contacts = 0, num_emails = 0;
    while (fscanf(contacts_file, "%s %s", contacts[num_contacts].name, contacts[num_contacts].email)!= EOF) {
        num_contacts++;
    }
    fclose(contacts_file);
    while (fscanf(emails_file, "%s %s", emails[num_emails].subject, emails[num_emails].message)!= EOF) {
        num_emails++;
    }
    fclose(emails_file);
    printf("Enter the name of the contact you want to send an email to: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Enter the subject of the email: ");
            char subject[MAX_SUBJECT_LENGTH];
            scanf("%s", subject);
            printf("Enter the message of the email: ");
            char message[MAX_MESSAGE_LENGTH];
            scanf("%s", message);
            for (int j = 0; j < num_emails; j++) {
                if (strcmp(emails[j].subject, subject) == 0) {
                    strcat(emails[j].message, "\n\n");
                    strcat(emails[j].message, message);
                    break;
                }
            }
            printf("Email sent to %s.\n", contacts[i].email);
            break;
        }
    }
    return 0;
}