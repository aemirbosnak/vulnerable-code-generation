//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct Contact {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    struct Contact *next;
} Contact;

Contact *head = NULL;

void addContact() {
    Contact *newContact = (Contact *)malloc(sizeof(Contact));
    printf("Enter Name: ");
    scanf(" %[^\n]%*c", newContact->name);
    printf("Enter Phone: ");
    scanf(" %[^\n]%*c", newContact->phone);
    newContact->next = head;
    head = newContact;
    printf("Contact added successfully!\n");
}

void viewContacts() {
    if (head == NULL) {
        printf("Phone Book is empty!\n");
        return;
    }
    Contact *temp = head;
    printf("\nContact List:\n");
    while (temp != NULL) {
        printf("Name: %s, Phone: %s\n", temp->name, temp->phone);
        temp = temp->next;
    }
}

void searchContact() {
    char name[NAME_LENGTH];
    printf("Enter Name to Search: ");
    scanf(" %[^\n]%*c", name);
    Contact *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Found - Name: %s, Phone: %s\n", temp->name, temp->phone);
            return;
        }
        temp = temp->next;
    }
    printf("Contact not found.\n");
}

void updateContact() {
    char name[NAME_LENGTH];
    printf("Enter Name for Updating: ");
    scanf(" %[^\n]%*c", name);
    Contact *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Enter New Phone: ");
            scanf(" %[^\n]%*c", temp->phone);
            printf("Contact updated successfully!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Contact not found.\n");
}

void deleteContact() {
    char name[NAME_LENGTH];
    printf("Enter Name to Delete: ");
    scanf(" %[^\n]%*c", name);
    
    Contact *temp = head, *prev = NULL;
    
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (prev == NULL) {
                head = temp->next; // Deleting the head
            } else {
                prev->next = temp->next; // Bypassing the deleted node
            }
            free(temp);
            printf("Contact deleted successfully!\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Contact not found.\n");
}

void freeMemory() {
    Contact *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int choice;
    do {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                updateContact();
                break;
            case 5:
                deleteContact();
                break;
            case 6:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    
    freeMemory();
    return 0;
}