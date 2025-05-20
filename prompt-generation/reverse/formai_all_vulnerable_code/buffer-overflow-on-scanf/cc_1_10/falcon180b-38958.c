//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAILS 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAILS][100];
    int num_emails;
} Contact;

void add_email(Contact* contact) {
    printf("Enter email address: ");
    scanf("%s", contact->email[contact->num_emails]);
    contact->num_emails++;
}

void print_contact(Contact contact) {
    printf("Name: %s\n", contact.name);
    printf("Email addresses:\n");
    for (int i = 0; i < contact.num_emails; i++) {
        printf("%s\n", contact.email[i]);
    }
}

void sort_contacts(Contact contacts[], int num_contacts) {
    for (int i = 0; i < num_contacts - 1; i++) {
        for (int j = i + 1; j < num_contacts; j++) {
            if (strcmp(contacts[i].name, contacts[j].name) > 0) {
                Contact temp = contacts[i];
                contacts[i] = contacts[j];
                contacts[j] = temp;
            }
        }
    }
}

int main() {
    Contact contacts[MAX_EMAILS];
    int num_contacts = 0;

    while (num_contacts < MAX_EMAILS) {
        printf("Enter name: ");
        scanf("%s", contacts[num_contacts].name);

        printf("Enter email address: ");
        scanf("%s", contacts[num_contacts].email[0]);
        contacts[num_contacts].num_emails = 1;

        num_contacts++;
    }

    printf("Unsorted contacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        print_contact(contacts[i]);
    }

    sort_contacts(contacts, num_contacts);

    printf("\nSorted contacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        print_contact(contacts[i]);
    }

    return 0;
}