//FormAI DATASET v1.0 Category: Phone Book ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone_number[20];
} Contact;

void print_contact_list(Contact* contacts, int num_contacts) {
    printf("Contact List:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%d. %s: %s\n", i+1, contacts[i].name, contacts[i].phone_number);
    }
}

void add_contact(Contact* contacts, int* num_contacts) {
    printf("Enter name: ");
    scanf("%s", contacts[*num_contacts].name);

    printf("Enter phone number: ");
    scanf("%s", contacts[*num_contacts].phone_number);

    (*num_contacts)++;
    printf("Contact added successfully!\n");
}

void search_contact(Contact* contacts, int num_contacts) {
    char search_name[50];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(search_name, contacts[i].name) == 0) {
            printf("Phone number for %s: %s\n", search_name, contacts[i].phone_number);
            return;
        }
    }
    printf("%s not found in contact list.\n", search_name);
}

int main() {
    Contact* contacts = malloc(10 * sizeof(Contact));
    int num_contacts = 0;
    char choice;

    do {
        printf("\nMenu:\n");
        printf("1. Display contacts\n");
        printf("2. Add a contact\n");
        printf("3. Search for a contact\n");
        printf("4. Exit\n");

        printf("Enter choice (1-4): ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1': print_contact_list(contacts, num_contacts); break;
            case '2': add_contact(contacts, &num_contacts); break;
            case '3': search_contact(contacts, num_contacts); break;
            case '4': break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != '4');

    free(contacts);
    return 0;
}