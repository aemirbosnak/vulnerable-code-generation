//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define EMAIL_LENGTH 50
#define FILE_NAME "phonebook.dat"

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char email[EMAIL_LENGTH];
} Contact;

Contact contacts[MAX_CONTACTS];
int contactCount = 0;

// Function prototypes
void addContact();
void viewContacts();
void editContact();
void deleteContact();
void saveContactsToFile();
void loadContactsFromFile();
void displayMenu();

int main() {
    loadContactsFromFile();
    
    int choice;
    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                editContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                saveContactsToFile();
                printf("Contacts saved successfully!\n");
                break;
            case 6:
                printf("Exiting the program...\n");
                saveContactsToFile();
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n---- Phone Book Menu ----\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Edit Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Save Contacts to File\n");
    printf("6. Exit\n");
}

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Contact list is full!\n");
        return;
    }
    printf("Enter name: ");
    getchar(); // To consume newline left by previous input
    fgets(contacts[contactCount].name, NAME_LENGTH, stdin);
    contacts[contactCount].name[strcspn(contacts[contactCount].name, "\n")] = 0; // Remove newline

    printf("Enter phone: ");
    fgets(contacts[contactCount].phone, PHONE_LENGTH, stdin);
    contacts[contactCount].phone[strcspn(contacts[contactCount].phone, "\n")] = 0;

    printf("Enter email: ");
    fgets(contacts[contactCount].email, EMAIL_LENGTH, stdin);
    contacts[contactCount].email[strcspn(contacts[contactCount].email, "\n")] = 0;

    contactCount++;
    printf("Contact added successfully!\n");
}

void viewContacts() {
    if (contactCount == 0) {
        printf("No contacts available.\n");
        return;
    }
    printf("\n---- Contact List ----\n");
    for (int i = 0; i < contactCount; i++) {
        printf("Contact %d: %s, %s, %s\n", i + 1, contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

void editContact() {
    viewContacts();
    int index;
    printf("Enter the contact number you want to edit: ");
    scanf("%d", &index);
    index--; // Adjust index to be zero-based

    if (index < 0 || index >= contactCount) {
        printf("Invalid contact number.\n");
        return;
    }

    printf("Editing contact %d: %s\n", index + 1, contacts[index].name);
    printf("Enter new name (leave blank for no change): ");
    getchar(); 
    char name[NAME_LENGTH];
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;

    if (strlen(name) > 0) {
        strcpy(contacts[index].name, name);
    }

    printf("Enter new phone (leave blank for no change): ");
    fgets(name, PHONE_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;

    if (strlen(name) > 0) {
        strcpy(contacts[index].phone, name);
    }

    printf("Enter new email (leave blank for no change): ");
    fgets(name, EMAIL_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;

    if (strlen(name) > 0) {
        strcpy(contacts[index].email, name);
    }

    printf("Contact updated successfully!\n");
}

void deleteContact() {
    viewContacts();
    int index;
    printf("Enter the contact number you want to delete: ");
    scanf("%d", &index);
    index--; // Adjust index to be zero-based

    if (index < 0 || index >= contactCount) {
        printf("Invalid contact number.\n");
        return;
    }

    for (int i = index; i < contactCount - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    contactCount--;
    printf("Contact deleted successfully!\n");
}

void saveContactsToFile() {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(contacts, sizeof(Contact), contactCount, file);
    fclose(file);
}

void loadContactsFromFile() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("No previous contacts found. Starting fresh...\n");
        return;
    }
    contactCount = fread(contacts, sizeof(Contact), MAX_CONTACTS, file);
    fclose(file);
}