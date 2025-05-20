//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "contacts.txt"
#define MAX_NAME_LEN 100
#define MAX_PHONE_LEN 15

typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
} Contact;

void addContact();
void viewContacts();
void searchContact();

int main() {
    int choice;

    while (1) {
        printf("\n--- Phone Book ---\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: searchContact(); break;
            case 4: exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void addContact() {
    Contact contact;
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    printf("Enter name: ");
    fgets(contact.name, MAX_NAME_LEN, stdin);
    contact.name[strcspn(contact.name, "\n")] = 0; // Remove newline
    printf("Enter phone number: ");
    fgets(contact.phone, MAX_PHONE_LEN, stdin);
    contact.phone[strcspn(contact.phone, "\n")] = 0; // Remove newline

    fprintf(file, "%s,%s\n", contact.name, contact.phone);
    fclose(file);
    printf("Contact added successfully!\n");
}

void viewContacts() {
    Contact contact;
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    printf("\n--- Contacts ---\n");
    while (fscanf(file, "%99[^,],%14[^\n]\n", contact.name, contact.phone) == 2) {
        printf("Name: %s, Phone: %s\n", contact.name, contact.phone);
    }
    fclose(file);
}

void searchContact() {
    char searchName[MAX_NAME_LEN];
    Contact contact;
    int found = 0;

    printf("Enter the name to search: ");
    fgets(searchName, MAX_NAME_LEN, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    while (fscanf(file, "%99[^,],%14[^\n]\n", contact.name, contact.phone) == 2) {
        if (strcasecmp(contact.name, searchName) == 0) {
            printf("Contact found! Name: %s, Phone: %s\n", contact.name, contact.phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
    fclose(file);
}