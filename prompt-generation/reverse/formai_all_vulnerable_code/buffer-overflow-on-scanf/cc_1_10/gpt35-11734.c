//FormAI DATASET v1.0 Category: Phone Book ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char first_name[20];
    char last_name[20];
    char phone_number[20];
} Contact;

Contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void add_contact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    Contact new_contact;

    printf("Enter first name: ");
    scanf("%s", new_contact.first_name);

    printf("Enter last name: ");
    scanf("%s", new_contact.last_name);

    printf("Enter phone number: ");
    scanf("%s", new_contact.phone_number);

    contacts[num_contacts] = new_contact;
    num_contacts++;

    printf("Contact added!\n");
}

void search_contacts() {
    char search_term[20];
    printf("Enter search term: ");
    scanf("%s", search_term);

    printf("Search results:\n");

    for (int i = 0; i < num_contacts; i++) {
        Contact c = contacts[i];

        if (strcmp(c.first_name, search_term) == 0 ||
            strcmp(c.last_name, search_term) == 0 ||
            strcmp(c.phone_number, search_term) == 0) {

            printf("%s %s: %s\n", c.first_name, c.last_name, c.phone_number);
        }
    }
}

int main() {
    while (1) {
        printf("Phone Book Menu\n");
        printf("----------------\n");
        printf("1. Add Contact\n");
        printf("2. Search Contacts\n");
        printf("3. Exit\n");

        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contacts();
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}