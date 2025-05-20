//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    char email[MAX_SIZE];
} Contact;

void add_contact(Contact *contacts, int *num_contacts) {
    Contact new_contact;
    printf("Enter name: ");
    scanf("%s", new_contact.name);
    printf("Enter email: ");
    scanf("%s", new_contact.email);
    contacts[*num_contacts] = new_contact;
    (*num_contacts)++;
}

void delete_contact(Contact *contacts, int *num_contacts) {
    printf("Enter email to delete: ");
    char email[MAX_SIZE];
    scanf("%s", email);
    int i;
    for (i = 0; i < *num_contacts; i++) {
        if (strcmp(contacts[i].email, email) == 0) {
            memmove(&contacts[i], &contacts[i+1], (*num_contacts - i - 1) * sizeof(Contact));
            (*num_contacts)--;
            break;
        }
    }
}

void print_contacts(Contact *contacts, int num_contacts) {
    printf("Name\tEmail\n");
    int i;
    for (i = 0; i < num_contacts; i++) {
        printf("%s\t%s\n", contacts[i].name, contacts[i].email);
    }
}

int main() {
    Contact contacts[MAX_SIZE];
    int num_contacts = 0;

    while (1) {
        printf("1. Add contact\n2. Delete contact\n3. Print contacts\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(contacts, &num_contacts);
                break;
            case 2:
                delete_contact(contacts, &num_contacts);
                break;
            case 3:
                print_contacts(contacts, num_contacts);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}