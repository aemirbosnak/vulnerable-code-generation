//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_EMAIL 100
#define MAX_SUBJECT 200
#define MAX_MESSAGE 1000

typedef struct {
    char name[MAX_NAME];
    char email[MAX_EMAIL];
} contact;

typedef struct {
    contact sender;
    char subject[MAX_SUBJECT];
    char message[MAX_MESSAGE];
} email;

int main() {
    FILE *file;
    contact contacts[100];
    email emails[100];
    int num_contacts = 0, num_emails = 0;
    char choice;

    file = fopen("contacts.txt", "r");

    if (file == NULL) {
        printf("Error: contacts.txt not found.\n");
        return 1;
    }

    while (fscanf(file, "%s %s\n", contacts[num_contacts].name, contacts[num_contacts].email)!= EOF) {
        num_contacts++;
    }

    fclose(file);

    while (1) {
        printf("Mailing List Manager\n");
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. Send email\n");
        printf("4. Exit\n");

        scanf(" %c", &choice);

        switch (choice) {
        case '1':
            printf("Enter name: ");
            scanf("%s", contacts[num_contacts].name);
            printf("Enter email: ");
            scanf("%s", contacts[num_contacts].email);
            num_contacts++;
            break;

        case '2':
            printf("Enter name to remove: ");
            scanf("%s", contacts[num_contacts - 1].name);
            num_contacts--;
            break;

        case '3':
            printf("Enter sender's name: ");
            scanf("%s", emails[num_emails].sender.name);
            printf("Enter subject: ");
            scanf("%s", emails[num_emails].subject);
            printf("Enter message: ");
            scanf("%s", emails[num_emails].message);
            num_emails++;
            break;

        case '4':
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }
}