//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECTS 100
#define MAX_BODY 500

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct {
    char subject[MAX_SUBJECTS];
    char body[MAX_BODY];
} message;

int main() {
    FILE *file;
    contact contacts[100];
    message messages[100];
    int num_contacts = 0, num_messages = 0;
    char choice;

    // Open contacts file
    file = fopen("contacts.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open contacts file.\n");
        exit(1);
    }

    // Read contacts from file
    while (fscanf(file, "%s %s", contacts[num_contacts].name, contacts[num_contacts].email) == 2) {
        num_contacts++;
    }
    fclose(file);

    // Main menu loop
    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. Send message\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                // Add contact
                printf("Enter name: ");
                scanf(" %s", contacts[num_contacts].name);
                printf("Enter email: ");
                scanf(" %s", contacts[num_contacts].email);
                num_contacts++;
                break;
            case '2':
                // Remove contact
                printf("Enter name to remove: ");
                scanf(" %s", contacts[num_contacts - 1].name);
                num_contacts--;
                break;
            case '3':
                // Send message
                printf("Enter subject: ");
                scanf(" %s", messages[num_messages].subject);
                printf("Enter body: ");
                scanf(" %s", messages[num_messages].body);
                num_messages++;
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}