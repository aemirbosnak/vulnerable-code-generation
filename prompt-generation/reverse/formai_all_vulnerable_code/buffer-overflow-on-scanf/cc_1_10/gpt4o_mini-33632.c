//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LEN 50
#define PHONE_LEN 15
#define EMAIL_LEN 100

typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    char email[EMAIL_LEN];
} Contact;

void addContact(FILE *file, Contact contact) {
    fwrite(&contact, sizeof(Contact), 1, file);
}

void displayContact(Contact contact) {
    printf("Name: %s\n", contact.name);
    printf("Phone: %s\n", contact.phone);
    printf("Email: %s\n", contact.email);
}

void listContacts(FILE *file) {
    Contact contact;
    rewind(file);
    printf("\nAddress Book:\n");
    while(fread(&contact, sizeof(Contact), 1, file)) {
        displayContact(contact);
        printf("\n");
    }
}

Contact searchContact(FILE *file, const char *name) {
    Contact contact;
    rewind(file);
    while(fread(&contact, sizeof(Contact), 1, file)) {
        if (strcmp(contact.name, name) == 0) {
            return contact;
        }
    }
    contact.name[0] = '\0'; // Indicate not found
    return contact;
}

void displayMenu() {
    printf("\n--- Menu ---\n");
    printf("1. Add Contact\n");
    printf("2. List Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    FILE *file;
    Contact contact;
    int choice;
    char searchName[NAME_LEN];

    file = fopen("address_book.dat", "ab+"); // Open file for binary append
    if (file == NULL) {
        perror("Unable to open file");
        return EXIT_FAILURE;
    }

    while(1) {
        displayMenu();
        scanf("%d", &choice);
        while(getchar() != '\n'); // Clear input buffer
        
        switch(choice) {
            case 1:
                printf("Enter Name: ");
                fgets(contact.name, NAME_LEN, stdin);
                contact.name[strcspn(contact.name, "\n")] = 0; // Remove newline

                printf("Enter Phone: ");
                fgets(contact.phone, PHONE_LEN, stdin);
                contact.phone[strcspn(contact.phone, "\n")] = 0; // Remove newline

                printf("Enter Email: ");
                fgets(contact.email, EMAIL_LEN, stdin);
                contact.email[strcspn(contact.email, "\n")] = 0; // Remove newline

                addContact(file, contact);
                printf("Contact added successfully!\n");
                break;
            case 2:
                listContacts(file);
                break;
            case 3:
                printf("Enter Name to search: ");
                fgets(searchName, NAME_LEN, stdin);
                searchName[strcspn(searchName, "\n")] = 0; // Remove newline
                
                contact = searchContact(file, searchName);
                if (contact.name[0] != '\0') {
                    printf("Contact found!\n");
                    displayContact(contact);
                } else {
                    printf("Contact not found.\n");
                }
                break;
            case 4:
                fclose(file);
                printf("Exiting the program.\n");
                return EXIT_SUCCESS;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }
    fclose(file);
    return 0;
}