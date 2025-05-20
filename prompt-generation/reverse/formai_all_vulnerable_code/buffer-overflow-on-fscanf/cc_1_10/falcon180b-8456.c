//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 200
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

typedef struct {
    contact recipient;
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} email;

int main() {
    FILE *contacts_file, *emails_file;
    contact contacts[100];
    email emails[100];
    int num_contacts = 0, num_emails = 0;
    char choice;

    // Load contacts from file
    contacts_file = fopen("contacts.txt", "r");
    if (contacts_file == NULL) {
        printf("Error: could not open contacts file.\n");
        exit(1);
    }
    while (fscanf(contacts_file, "%s %s", contacts[num_contacts].name, contacts[num_contacts].email)!= EOF) {
        num_contacts++;
    }
    fclose(contacts_file);

    // Main menu
    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. Send email\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            // Add contact
            printf("Enter name: ");
            scanf("%s", contacts[num_contacts].name);
            printf("Enter email: ");
            scanf("%s", contacts[num_contacts].email);
            num_contacts++;
            break;
        case '2':
            // Remove contact
            printf("Enter name to remove: ");
            scanf("%s", contacts[num_contacts - 1].name);
            for (int i = 0; i < num_contacts - 1; i++) {
                strcpy(contacts[i].name, contacts[i + 1].name);
                strcpy(contacts[i].email, contacts[i + 1].email);
            }
            num_contacts--;
            break;
        case '3':
            // Send email
            printf("Enter recipient name: ");
            scanf("%s", emails[num_emails].recipient.name);
            printf("Enter subject: ");
            scanf("%s", emails[num_emails].subject);
            printf("Enter message: ");
            scanf("%s", emails[num_emails].message);
            num_emails++;
            break;
        case '4':
            // Exit
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}