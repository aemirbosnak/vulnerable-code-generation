//FormAI DATASET v1.0 Category: Database simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_EMAIL_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

void add_contact(Contact *contacts, int *num_contacts) {
    if (*num_contacts == 10) {
        printf("Cannot add more contacts.\n");
        return;
    }

    Contact new_contact;
    printf("Enter name: ");
    scanf("%s", new_contact.name);

    printf("Enter email: ");
    scanf("%s", new_contact.email);

    printf("Enter phone number: ");
    scanf("%s", new_contact.phone);

    contacts[*num_contacts] = new_contact;
    *num_contacts += 1;
    printf("Contact added successfully.\n");
}

void search_contact(Contact *contacts, int num_contacts) {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            printf("Name: %s\nEmail: %s\nPhone: %s\n\n", contacts[i].name, contacts[i].email, contacts[i].phone);
            return;
        }
    }

    printf("Contact not found.\n");
}

void list_contacts(Contact *contacts, int num_contacts) {
    for (int i = 0; i < num_contacts; i++) {
        printf("Name: %s\nEmail: %s\nPhone: %s\n\n", contacts[i].name, contacts[i].email, contacts[i].phone);
    }
}

int main() {
    Contact contacts[10];
    int num_contacts = 0;
    int menu_choice;

    printf("***CONTACT DATABASE***\n\n");

    while (1) {
        printf("1. Add Contact\n2. Search Contact\n3. List Contacts\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &menu_choice);

        switch (menu_choice) {
            case 1:
                add_contact(contacts, &num_contacts);
                break;

            case 2:
                search_contact(contacts, num_contacts);
                break;

            case 3:
                list_contacts(contacts, num_contacts);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}