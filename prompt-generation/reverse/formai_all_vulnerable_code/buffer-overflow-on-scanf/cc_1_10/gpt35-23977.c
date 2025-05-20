//FormAI DATASET v1.0 Category: Phone Book ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
} Contact;

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int add_contact(Contact contacts[], int n) {
    if (n == MAX_CONTACTS) {
        printf("Phone book is full, cannot add any more contacts.\n");
        return n;
    }

    Contact new_contact;

    printf("Enter name (max 49 characters): ");
    fgets(new_contact.name, 50, stdin);

    // remove trailing newline character
    new_contact.name[strcspn(new_contact.name, "\n")] = '\0';

    printf("Enter phone number (max 19 characters): ");
    fgets(new_contact.phone, 20, stdin);

    // remove trailing newline character
    new_contact.phone[strcspn(new_contact.phone, "\n")] = '\0';

    contacts[n] = new_contact;

    printf("Contact added successfully!\n");

    return n + 1;
}

void print_contact(Contact contact) {
    printf("Name: %s\n", contact.name);
    printf("Phone: %s\n", contact.phone);
}

void search_contact(Contact contacts[], int n) {
    char search_term[50];
    printf("Enter name to search for: ");
    fgets(search_term, 50, stdin);

    // remove trailing newline character
    search_term[strcspn(search_term, "\n")] = '\0';

    int found = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(contacts[i].name, search_term) == 0) {
            print_contact(contacts[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No contacts found with that name.\n");
    }
}

void print_phonebook(Contact contacts[], int n) {
    printf("Phone Book:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - %s\n", i+1, contacts[i].name, contacts[i].phone);
    }
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;
    int choice = 0;

    printf("--- C Phone Book ---\n");

    while (choice != 4) {
        printf("\nMenu:\n");
        printf("1. Add Contact\n");
        printf("2. Search for Contact\n");
        printf("3. Print All Contacts\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);
        clear_input_buffer();

        if (choice == 1) {
            num_contacts = add_contact(contacts, num_contacts);
        }
        else if (choice == 2) {
            search_contact(contacts, num_contacts);
        }
        else if (choice == 3) {
            print_phonebook(contacts, num_contacts);
        }
        else if (choice != 4) {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("Exiting phone book...\n");

    return 0;
}