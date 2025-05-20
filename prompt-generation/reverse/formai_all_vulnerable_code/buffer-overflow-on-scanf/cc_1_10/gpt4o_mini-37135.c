//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LEN];
    char phone[15];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int size;
} ContactList;

// Function prototypes
void addContact(ContactList *list);
void displayContacts(const ContactList *list);
int findContact(const ContactList *list, const char *name);
void deleteContact(ContactList *list);
void menu();

int main() {
    ContactList list = { .size = 0 };
    int choice;

    while (1) {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // to consume newline character

        switch (choice) {
            case 1:
                addContact(&list);
                break;
            case 2:
                displayContacts(&list);
                break;
            case 3:
                deleteContact(&list);
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void menu() {
    printf("\n***** Contact List Menu *****\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Delete Contact\n");
    printf("0. Exit\n");
}

void addContact(ContactList *list) {
    if (list->size >= MAX_CONTACTS) {
        printf("Contact list is full!\n");
        return;
    }
    
    Contact newContact;
    
    printf("Enter name: ");
    fgets(newContact.name, MAX_NAME_LEN, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0; // remove newline
    
    printf("Enter phone number: ");
    fgets(newContact.phone, 15, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0; // remove newline

    list->contacts[list->size] = newContact;
    list->size++;
    printf("Contact added successfully!\n");
}

void displayContacts(const ContactList *list) {
    if (list->size == 0) {
        printf("Contact list is empty!\n");
        return;
    }

    printf("\n=== Contact List ===\n");
    for (int i = 0; i < list->size; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, list->contacts[i].name, list->contacts[i].phone);
    }
}

int findContact(const ContactList *list, const char *name) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->contacts[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void deleteContact(ContactList *list) {
    char name[MAX_NAME_LEN];
    
    printf("Enter the name of the contact to delete: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = 0; // remove newline

    int index = findContact(list, name);
    if (index == -1) {
        printf("Contact not found!\n");
        return;
    }

    // Shift remaining contacts to fill the gap
    for (int i = index; i < list->size - 1; i++) {
        list->contacts[i] = list->contacts[i + 1];
    }
    list->size--;
    printf("Contact deleted successfully!\n");
}