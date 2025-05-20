//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAILS_PER_NAME 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int num_emails;
    char emails[MAX_EMAILS_PER_NAME][100];
} contact;

contact *contacts = NULL;
int num_contacts = 0;

void add_contact() {
    contact *new_contact = malloc(sizeof(contact));
    if (new_contact == NULL) {
        printf("Error: could not allocate memory for new contact.\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", new_contact->name);
    new_contact->num_emails = 0;
    contacts = realloc(contacts, sizeof(contact) * ++num_contacts);
    contacts[num_contacts - 1] = *new_contact;
    free(new_contact);
}

void delete_contact() {
    int index;
    printf("Enter index of contact to delete: ");
    scanf("%d", &index);
    if (index < 0 || index >= num_contacts) {
        printf("Invalid index.\n");
        return;
    }
    contacts = realloc(contacts, sizeof(contact) * --num_contacts);
}

void list_contacts() {
    for (int i = 0; i < num_contacts; i++) {
        printf("%s\n", contacts[i].name);
    }
}

void add_email() {
    printf("Enter index of contact: ");
    int index;
    scanf("%d", &index);
    if (index < 0 || index >= num_contacts) {
        printf("Invalid index.\n");
        return;
    }
    contact *contact = &contacts[index];
    printf("Enter email: ");
    scanf("%s", contact->emails[contact->num_emails]);
    contact->num_emails++;
}

void send_email() {
    printf("Enter index of contact: ");
    int index;
    scanf("%d", &index);
    if (index < 0 || index >= num_contacts) {
        printf("Invalid index.\n");
        return;
    }
    contact *contact = &contacts[index];
    for (int i = 0; i < contact->num_emails; i++) {
        printf("Sending email to %s...\n", contact->emails[i]);
    }
}

int main() {
    printf("Mailing list manager\n");
    while (1) {
        printf("\n1. Add contact\n2. Delete contact\n3. List contacts\n4. Add email\n5. Send email\n6. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_contact();
            break;
        case 2:
            delete_contact();
            break;
        case 3:
            list_contacts();
            break;
        case 4:
            add_email();
            break;
        case 5:
            send_email();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}