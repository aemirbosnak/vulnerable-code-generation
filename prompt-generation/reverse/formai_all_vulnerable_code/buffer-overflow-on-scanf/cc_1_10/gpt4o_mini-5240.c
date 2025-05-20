//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 50
#define MAX_CONTACTS 100

typedef struct {
    char name[NAME_SIZE];
    char phone[NAME_SIZE];
} Contact;

Contact* create_contact(const char* name, const char* phone) {
    Contact* new_contact = (Contact*) malloc(sizeof(Contact));
    if (new_contact == NULL) {
        printf("Memory allocation failed! Exiting...\n");
        exit(EXIT_FAILURE);
    }
    strncpy(new_contact->name, name, NAME_SIZE);
    strncpy(new_contact->phone, phone, NAME_SIZE);
    return new_contact;
}

void free_contact(Contact* contact) {
    free(contact);
}

void display_contact(const Contact* contact) {
    if (contact != NULL) {
        printf("Name: %s, Phone: %s\n", contact->name, contact->phone);
    }
}

typedef struct {
    Contact** contacts;
    int size;
} ContactList;

ContactList* create_contact_list() {
    ContactList* list = (ContactList*) malloc(sizeof(ContactList));
    if (list == NULL) {
        printf("Memory allocation failed! Exiting...\n");
        exit(EXIT_FAILURE);
    }
    list->contacts = (Contact**) malloc(MAX_CONTACTS * sizeof(Contact*));
    list->size = 0;
    return list;
}

void add_contact(ContactList* list, const char* name, const char* phone) {
    if (list->size >= MAX_CONTACTS) {
        printf("Contact list is full! Cannot add more contacts.\n");
        return;
    }
    Contact* new_contact = create_contact(name, phone);
    list->contacts[list->size++] = new_contact;
}

void display_contacts(const ContactList* list) {
    printf("Contact List:\n");
    for (int i = 0; i < list->size; ++i) {
        display_contact(list->contacts[i]);
    }
}

void delete_contact(ContactList* list, const char* name) {
    for (int i = 0; i < list->size; ++i) {
        if (strcmp(list->contacts[i]->name, name) == 0) {
            printf("Deleting contact: %s\n", list->contacts[i]->name);
            free_contact(list->contacts[i]);
            // Shift remaining contacts down
            for (int j = i; j < list->size - 1; ++j) {
                list->contacts[j] = list->contacts[j + 1];
            }
            list->size--;
            return;
        }
    }
    printf("Contact not found!\n");
}

void free_contact_list(ContactList* list) {
    for (int i = 0; i < list->size; ++i) {
        free_contact(list->contacts[i]);
    }
    free(list->contacts);
    free(list);
}

int main() {
    ContactList* my_contacts = create_contact_list();
    
    int choice;
    char name[NAME_SIZE];
    char phone[NAME_SIZE];

    do {
        printf("\n======== Contact Management System ========\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("===========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Flush newline from the input buffer

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, NAME_SIZE, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                printf("Enter phone: ");
                fgets(phone, NAME_SIZE, stdin);
                phone[strcspn(phone, "\n")] = 0; // Remove newline
                add_contact(my_contacts, name, phone);
                break;

            case 2:
                display_contacts(my_contacts);
                break;

            case 3:
                printf("Enter name of contact to delete: ");
                fgets(name, NAME_SIZE, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                delete_contact(my_contacts, name);
                break;

            case 4:
                printf("Exiting the contact management system. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    free_contact_list(my_contacts);
    return 0;
}