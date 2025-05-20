//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define EMAIL_LENGTH 50
#define ADDRESS_LENGTH 100

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char email[EMAIL_LENGTH];
    char address[ADDRESS_LENGTH];
} Contact;

void addContact(FILE *file);
void viewContacts(FILE *file);
void searchContact(FILE *file);
void clearBuffer();

int main() {
    FILE *file;
    int choice;

    file = fopen("contacts.dat", "a+");
    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }

    while (1) {
        printf("\n=== Address Book ===\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addContact(file);
                break;
            case 2:
                viewContacts(file);
                break;
            case 3:
                searchContact(file);
                break;
            case 4:
                fclose(file);
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

void addContact(FILE *file) {
    Contact newContact;

    printf("Enter name: ");
    fgets(newContact.name, NAME_LENGTH, stdin);
    strtok(newContact.name, "\n");  // Remove newline character

    printf("Enter phone: ");
    fgets(newContact.phone, PHONE_LENGTH, stdin);
    strtok(newContact.phone, "\n");

    printf("Enter email: ");
    fgets(newContact.email, EMAIL_LENGTH, stdin);
    strtok(newContact.email, "\n");

    printf("Enter address: ");
    fgets(newContact.address, ADDRESS_LENGTH, stdin);
    strtok(newContact.address, "\n");

    fwrite(&newContact, sizeof(Contact), 1, file);
    printf("Contact added successfully!\n");
}

void viewContacts(FILE *file) {
    Contact contact;
    
    rewind(file);
    printf("\n=== Contacts List ===\n");
    while (fread(&contact, sizeof(Contact), 1, file) == 1) {
        printf("Name: %s\n", contact.name);
        printf("Phone: %s\n", contact.phone);
        printf("Email: %s\n", contact.email);
        printf("Address: %s\n\n", contact.address);
    }
}

void searchContact(FILE *file) {
    char name[NAME_LENGTH];
    Contact contact;
    int found = 0;

    printf("Enter name to search: ");
    fgets(name, NAME_LENGTH, stdin);
    strtok(name, "\n");  // Remove newline character

    rewind(file);
    while (fread(&contact, sizeof(Contact), 1, file) == 1) {
        if (strcmp(contact.name, name) == 0) {
            printf("\n=== Contact Found ===\n");
            printf("Name: %s\n", contact.name);
            printf("Phone: %s\n", contact.phone);
            printf("Email: %s\n", contact.email);
            printf("Address: %s\n\n", contact.address);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void clearBuffer() {
    while (getchar() != '\n');
}