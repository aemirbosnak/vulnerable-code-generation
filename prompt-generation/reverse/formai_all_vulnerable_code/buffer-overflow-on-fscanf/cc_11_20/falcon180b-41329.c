//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAILS_COUNT 1000
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

int main() {
    int contacts_count = 0;
    Contact contacts[MAX_EMAILS_COUNT];

    FILE *file = fopen("contacts.txt", "r");
    if (file == NULL) {
        printf("Error: could not open contacts file.\n");
        return 1;
    }

    while (fscanf(file, "%s %s\n", contacts[contacts_count].name, contacts[contacts_count].email)!= EOF) {
        contacts_count++;
    }

    fclose(file);

    printf("Welcome to the post-apocalyptic mailing list manager!\n");

    while (1) {
        printf("\n");
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. Send message to all contacts\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", contacts[contacts_count].name);
            printf("Enter email: ");
            scanf("%s", contacts[contacts_count].email);
            contacts_count++;
            break;

        case 2:
            printf("Enter name to remove: ");
            scanf("%s", contacts[0].name);
            int found = 0;

            for (int i = 0; i < contacts_count - 1; i++) {
                if (strcmp(contacts[i].name, contacts[0].name) == 0) {
                    found = 1;
                    for (int j = i; j < contacts_count - 1; j++) {
                        contacts[j] = contacts[j+1];
                    }
                    contacts_count--;
                }
            }

            if (!found) {
                printf("Contact not found.\n");
            }

            break;

        case 3:
            printf("Enter message: ");
            char message[MAX_EMAIL_LENGTH];
            scanf("%s", message);

            for (int i = 0; i < contacts_count; i++) {
                printf("Sending message to %s (%s)...\n", contacts[i].name, contacts[i].email);
            }

            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}