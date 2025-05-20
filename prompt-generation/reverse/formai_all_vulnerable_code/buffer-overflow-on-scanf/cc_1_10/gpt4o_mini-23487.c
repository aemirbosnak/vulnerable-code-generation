//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: scalable
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

void addContact(const char *filename);
void viewContacts(const char *filename);
void deleteContact(const char *filename);
void loadContacts(const char *filename, Contact contacts[], int *count);
void saveContacts(const char *filename, Contact contacts[], int count);
void displayMenu();

int main() {
    const char *filename = "contacts.txt";
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline after scanf

        switch (choice) {
            case 1:
                addContact(filename);
                break;
            case 2:
                viewContacts(filename);
                break;
            case 3:
                deleteContact(filename);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n----- Contact Management System -----\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Delete Contact\n");
    printf("4. Exit\n");
}

void addContact(const char *filename) {
    Contact newContact;
    FILE *file = fopen(filename, "a");

    if (file == NULL) {
        perror("Unable to open file!");
        return;
    }

    printf("Enter Name: ");
    fgets(newContact.name, NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0'; // Remove newline
    printf("Enter Phone: ");
    fgets(newContact.phone, PHONE_LENGTH, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0'; // Remove newline

    fprintf(file, "%s,%s\n", newContact.name, newContact.phone);
    fclose(file);

    printf("Contact added successfully!\n");
}

void viewContacts(const char *filename) {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Unable to open file!");
        return;
    }

    printf("\n----- Contact List -----\n");
    while (fscanf(file, "%49[^,],%14[^\n]\n", contacts[count].name, contacts[count].phone) == 2) {
        printf("Name: %s, Phone: %s\n", contacts[count].name, contacts[count].phone);
        count++;
    }

    fclose(file);

    if (count == 0) {
        printf("No contacts found!\n");
    }
}

void deleteContact(const char *filename) {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    char nameToDelete[NAME_LENGTH];
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Unable to open file!");
        return;
    }

    while (fscanf(file, "%49[^,],%14[^\n]\n", contacts[count].name, contacts[count].phone) == 2) {
        count++;
    }
    fclose(file);

    printf("Enter the name of the contact to delete: ");
    fgets(nameToDelete, NAME_LENGTH, stdin);
    nameToDelete[strcspn(nameToDelete, "\n")] = '\0'; // Remove newline

    file = fopen(filename, "w");
    if (file == NULL) {
        perror("Unable to open file!");
        return;
    }

    int deleted = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, nameToDelete) != 0) {
            fprintf(file, "%s,%s\n", contacts[i].name, contacts[i].phone);
        } else {
            deleted = 1;
        }
    }

    fclose(file);

    if (deleted) {
        printf("Contact deleted successfully!\n");
    } else {
        printf("Contact not found!\n");
    }
}