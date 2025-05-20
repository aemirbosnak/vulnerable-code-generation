//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
    int age;
    char address[100];
} Contact;

void print_contact(Contact *contact) {
    printf("Name: %s\n", contact->name);
    printf("Phone: %s\n", contact->phone);
    printf("Email: %s\n", contact->email);
    printf("Age: %d\n", contact->age);
    printf("Address: %s\n", contact->address);
}

int main() {
    Contact *contacts = malloc(MAX_CONTACTS * sizeof(Contact));
    if (!contacts) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    int num_contacts = 0;

    while (1) {
        Contact new_contact;
        printf("Enter contact name (or 'quit' to exit): ");
        fgets(new_contact.name, sizeof(new_contact.name), stdin);
        new_contact.name[strcspn(new_contact.name, "\n")] = '\0';

        if (strcmp(new_contact.name, "quit") == 0) {
            break;
        }

        printf("Enter contact phone number: ");
        fgets(new_contact.phone, sizeof(new_contact.phone), stdin);
        new_contact.phone[strcspn(new_contact.phone, "\n")] = '\0';

        printf("Enter contact email: ");
        fgets(new_contact.email, sizeof(new_contact.email), stdin);
        new_contact.email[strcspn(new_contact.email, "\n")] = '\0';

        printf("Enter contact age: ");
        scanf("%d", &new_contact.age);

        printf("Enter contact address: ");
        fgets(new_contact.address, sizeof(new_contact.address), stdin);
        new_contact.address[strcspn(new_contact.address, "\n")] = '\0';

        contacts[num_contacts++] = new_contact;
    }

    printf("\nContacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        print_contact(&contacts[i]);
    }

    free(contacts);

    return 0;
}