//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int count;
} ContactList;

void initializeContactList(ContactList* cl) {
    cl->count = 0;
}

void addContact(ContactList* cl, const char* name, const char* phone) {
    if (cl->count < MAX_CONTACTS) {
        strncpy(cl->contacts[cl->count].name, name, NAME_LENGTH);
        strncpy(cl->contacts[cl->count].phone, phone, PHONE_LENGTH);
        cl->count++;
        printf("Contact added: %s - %s\n", name, phone);
    } else {
        printf("Contact list is full, cannot add more contacts.\n");
    }
}

void viewContacts(const ContactList* cl) {
    printf("\n--- Contact List ---\n");
    for (int i = 0; i < cl->count; i++) {
        printf("%d. %s - %s\n", i + 1, cl->contacts[i].name, cl->contacts[i].phone);
    }
    printf("---------------------\n");
}

void deleteContact(ContactList* cl, int index) {
    if (index >= 0 && index < cl->count) {
        printf("Deleting contact: %s - %s\n", cl->contacts[index].name, cl->contacts[index].phone);
        for (int i = index; i < cl->count - 1; i++) {
            cl->contacts[i] = cl->contacts[i + 1];
        }
        cl->count--;
    } else {
        printf("Invalid index. No contact deleted.\n");
    }
}

int main() {
    ContactList myContacts;
    initializeContactList(&myContacts);
    
    int choice;
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    int index;

    do {
        printf("\n--- Contact Management System ---\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf(" %[^\n]", name);
                printf("Enter phone number: ");
                scanf(" %[^\n]", phone);
                addContact(&myContacts, name, phone);
                break;

            case 2:
                viewContacts(&myContacts);
                break;

            case 3:
                printf("Enter contact index to delete (1 to %d): ", myContacts.count);
                scanf("%d", &index);
                deleteContact(&myContacts, index - 1);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice, please select again.\n");
        }
    } while (choice != 4);

    return 0;
}