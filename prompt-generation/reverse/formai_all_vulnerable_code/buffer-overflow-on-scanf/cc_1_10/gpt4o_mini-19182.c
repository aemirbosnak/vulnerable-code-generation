//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact {
    char name[50];
    char phone[15];
    struct Contact* next;
} Contact;

Contact* head = NULL;

void addContact();
void displayContacts();
void findContact();
void deleteContact();
void clearContacts();
void menu();

int main() {
    menu();
    clearContacts();
    return 0;
}

void menu() {
    int choice;
    do {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Find Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf

        switch (choice) {
            case 1: 
                addContact(); 
                break;
            case 2: 
                displayContacts(); 
                break;
            case 3: 
                findContact(); 
                break;
            case 4: 
                deleteContact(); 
                break;
            case 5: 
                printf("Exiting Phone Book...\n");
                break;
            default: 
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
}

void addContact() {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    if (!newContact) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter Name: ");
    fgets(newContact->name, sizeof(newContact->name), stdin);
    newContact->name[strcspn(newContact->name, "\n")] = 0; // Remove newline

    printf("Enter Phone Number: ");
    fgets(newContact->phone, sizeof(newContact->phone), stdin);
    newContact->phone[strcspn(newContact->phone, "\n")] = 0; // Remove newline

    newContact->next = head;
    head = newContact; // Insert at head
    printf("Contact added successfully!\n");
}

void displayContacts() {
    if (head == NULL) {
        printf("No contacts in the phone book.\n");
        return;
    }

    printf("\nContacts:\n");
    Contact* temp = head;
    while (temp != NULL) {
        printf("Name: %s, Phone: %s\n", temp->name, temp->phone);
        temp = temp->next;
    }
}

void findContact() {
    char name[50];
    printf("Enter the name to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    Contact* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Contact found! Name: %s, Phone: %s\n", temp->name, temp->phone);
            return;
        }
        temp = temp->next;
    }
    printf("Contact not found.\n");
}

void deleteContact() {
    char name[50];
    printf("Enter the name of the contact to delete: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    Contact *temp = head, *prev = NULL;
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Contact not found.\n");
        return;
    }

    if (prev == NULL) {
        head = temp->next; // Deleting head
    } else {
        prev->next = temp->next; // Bypass the contact
    }

    free(temp);
    printf("Contact deleted successfully!\n");
}

void clearContacts() {
    Contact* current = head;
    Contact* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
    printf("All contacts cleared.\n");
}