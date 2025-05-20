//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define FILENAME "contacts.txt"

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

void displayMenu() {
    printf("\nContact Management System\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Delete Contact\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

void addContact() {
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    Contact contact;
    printf("Enter contact name: ");
    fgets(contact.name, NAME_LENGTH, stdin);
    contact.name[strcspn(contact.name, "\n")] = 0; // Remove newline

    printf("Enter contact phone: ");
    fgets(contact.phone, PHONE_LENGTH, stdin);
    contact.phone[strcspn(contact.phone, "\n")] = 0; // Remove newline

    fprintf(file, "%s,%s\n", contact.name, contact.phone);
    fclose(file);
    
    printf("Contact added successfully!\n");
}

void viewContacts() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("No contacts found.\n");
        return;
    }

    char line[NAME_LENGTH + PHONE_LENGTH + 2]; // +2 for comma and newline
    printf("\nList of Contacts:\n");
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        if (token != NULL) {
            printf("Name: %s, Phone: %s", token, strtok(NULL, "\n"));
        }
    }
    fclose(file);
}

void deleteContact() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("No contacts found to delete.\n");
        return;
    }

    Contact contacts[MAX_CONTACTS];
    int count = 0;
    char line[NAME_LENGTH + PHONE_LENGTH + 2];

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^,],%s", contacts[count].name, contacts[count].phone);
        count++;
    }
    fclose(file);

    if (count == 0) {
        printf("No contacts to delete.\n");
        return;
    }

    printf("Available Contacts to Delete:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, contacts[i].name);
    }

    int choice;
    printf("Enter the number of the contact you want to delete: ");
    scanf("%d", &choice);
    getchar(); // Clear newline from buffer

    if (choice < 1 || choice > count) {
        printf("Invalid choice.\n");
        return;
    }

    FILE *newFile = fopen("temp.txt", "w");
    for (int i = 0; i < count; i++) {
        if (i + 1 != choice) { // Skip the deleted contact
            fprintf(newFile, "%s,%s\n", contacts[i].name, contacts[i].phone);
        }
    }
    fclose(newFile);
    remove(FILENAME); // Remove the old contact file
    rename("temp.txt", FILENAME); // Rename temp file to original

    printf("Contact deleted successfully!\n");
}

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Clear any remaining newline characters

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                deleteContact();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    
    return 0;
}