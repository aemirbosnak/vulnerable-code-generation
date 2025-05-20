//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define EMAIL_LENGTH 50
#define FILENAME "contacts.txt"

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char email[EMAIL_LENGTH];
} Contact;

void addContact();
void displayContacts();
void searchContact();
void clearInputBuffer();

int main() {
    int choice;

    do {
        printf("\nContact Book Menu\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();  // Clear the input buffer

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
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addContact() {
    Contact newContact;
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Unable to open file!");
        return;
    }

    printf("Enter name: ");
    fgets(newContact.name, NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0; // Remove newline character
    
    printf("Enter phone: ");
    fgets(newContact.phone, PHONE_LENGTH, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0; // Remove newline character
    
    printf("Enter email: ");
    fgets(newContact.email, EMAIL_LENGTH, stdin);
    newContact.email[strcspn(newContact.email, "\n")] = 0; // Remove newline character

    fprintf(file, "%s,%s,%s\n", newContact.name, newContact.phone, newContact.email);
    fclose(file);
    printf("Contact added successfully!\n");
}

void displayContacts() {
    Contact contact;
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file!");
        return;
    }

    printf("\nContacts List:\n");
    while (fscanf(file, "%[^,],%[^,],%[^\n]\n", contact.name, contact.phone, contact.email) != EOF) {
        printf("Name: %s, Phone: %s, Email: %s\n", contact.name, contact.phone, contact.email);
    }
    fclose(file);
}

void searchContact() {
    char searchName[NAME_LENGTH];
    Contact contact;
    int found = 0;

    printf("Enter name of the contact to search: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline character

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file!");
        return;
    }

    while (fscanf(file, "%[^,],%[^,],%[^\n]\n", contact.name, contact.phone, contact.email) != EOF) {
        if (strcasecmp(contact.name, searchName) == 0) {
            found = 1;
            printf("Contact Found: Name: %s, Phone: %s, Email: %s\n", contact.name, contact.phone, contact.email);
            break;
        }
    }

    if (!found) {
        printf("Contact with name '%s' was not found.\n", searchName);
    }

    fclose(file);
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}