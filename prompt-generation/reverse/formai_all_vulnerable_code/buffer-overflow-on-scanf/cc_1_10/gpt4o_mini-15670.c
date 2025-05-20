//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define EMAIL_LENGTH 50
#define ADDRESS_LENGTH 100

typedef struct Contact {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char email[EMAIL_LENGTH];
    char address[ADDRESS_LENGTH];
    struct Contact* next;
} Contact;

Contact* head = NULL;

void addContact();
void displayContacts();
void searchContact();
void deleteContact();
void freeContacts();

int main() {
    int choice;

    while (1) {
        printf("\n----- Phone Book -----\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                freeContacts();
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void addContact() {
    Contact* new_contact = (Contact*)malloc(sizeof(Contact));
    if (!new_contact) {
        printf("Memory allocation failed.\n");
        return;
    }
    
    printf("Enter Name: ");
    getchar(); // to consume newline character
    fgets(new_contact->name, NAME_LENGTH, stdin);
    new_contact->name[strcspn(new_contact->name, "\n")] = 0; // Remove newline

    printf("Enter Phone: ");
    fgets(new_contact->phone, PHONE_LENGTH, stdin);
    new_contact->phone[strcspn(new_contact->phone, "\n")] = 0;

    printf("Enter Email: ");
    fgets(new_contact->email, EMAIL_LENGTH, stdin);
    new_contact->email[strcspn(new_contact->email, "\n")] = 0;

    printf("Enter Address: ");
    fgets(new_contact->address, ADDRESS_LENGTH, stdin);
    new_contact->address[strcspn(new_contact->address, "\n")] = 0;

    new_contact->next = head;
    head = new_contact;

    printf("Contact added successfully!\n");
}

void displayContacts() {
    if (head == NULL) {
        printf("No contacts found!\n");
        return;
    }

    Contact* temp = head;
    printf("\n--- Contacts List ---\n");
    while (temp != NULL) {
        printf("Name: %s\n", temp->name);
        printf("Phone: %s\n", temp->phone);
        printf("Email: %s\n", temp->email);
        printf("Address: %s\n", temp->address);
        printf("-----------------------\n");
        temp = temp->next;
    }
}

void searchContact() {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to search: ");
    getchar(); // to consume newline character
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;

    Contact* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Contact found!\n");
            printf("Name: %s\n", temp->name);
            printf("Phone: %s\n", temp->phone);
            printf("Email: %s\n", temp->email);
            printf("Address: %s\n", temp->address);
            return;
        }
        temp = temp->next;
    }
    printf("Contact not found!\n");
}

void deleteContact() {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    getchar(); // to consume newline character
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;

    Contact* temp = head;
    Contact* prev = NULL;

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Contact not found!\n");
        return;
    }

    if (prev == NULL) {
        head = temp->next; // Deleting the head
    } else {
        prev->next = temp->next; // Deleting middle or last element
    }
    free(temp);
    printf("Contact deleted successfully!\n");
}

void freeContacts() {
    Contact* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}