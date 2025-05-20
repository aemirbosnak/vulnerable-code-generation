//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100
#define FILE_NAME "contacts.txt"

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

void displayMenu() {
    printf("\n--- Contact Management System ---\n");
    printf("1. Add Contact\n");
    printf("2. List Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

void addContact() {
    Contact newContact;
    FILE *file = fopen(FILE_NAME, "a");

    if (!file) {
        perror("Unable to open file");
        return;
    }

    printf("\nEnter Name: ");
    fgets(newContact.name, MAX_NAME_LEN, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0; // Remove newline

    printf("Enter Email: ");
    fgets(newContact.email, MAX_EMAIL_LEN, stdin);
    newContact.email[strcspn(newContact.email, "\n")] = 0; // Remove newline

    fwrite(&newContact, sizeof(Contact), 1, file);
    fclose(file);
    
    printf("Contact added successfully!\n");
}

void listContacts() {
    Contact tempContact;
    FILE *file = fopen(FILE_NAME, "r");

    if (!file) {
        perror("Unable to open file");
        return;
    }

    printf("\n--- List of Contacts ---\n");
    while (fread(&tempContact, sizeof(Contact), 1, file)) {
        printf("Name: %s, Email: %s\n", tempContact.name, tempContact.email);
    }
    
    fclose(file);
}

void searchContact() {
    char searchName[MAX_NAME_LEN];
    Contact tempContact;
    FILE *file = fopen(FILE_NAME, "r");
    int found = 0;

    if (!file) {
        perror("Unable to open file");
        return;
    }

    printf("\nEnter Name to Search: ");
    fgets(searchName, MAX_NAME_LEN, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline

    while (fread(&tempContact, sizeof(Contact), 1, file)) {
        if (strcmp(tempContact.name, searchName) == 0) {
            printf("Contact Found! Name: %s, Email: %s\n", tempContact.name, tempContact.email);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact Not Found!\n");
    }
    
    fclose(file);
}

void deleteContact() {
    char deleteName[MAX_NAME_LEN];
    Contact tempContact;
    FILE *file = fopen(FILE_NAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    int found = 0;

    if (!file || !tempFile) {
        perror("Unable to open file");
        return;
    }

    printf("\nEnter Name to Delete: ");
    fgets(deleteName, MAX_NAME_LEN, stdin);
    deleteName[strcspn(deleteName, "\n")] = 0; // Remove newline

    while (fread(&tempContact, sizeof(Contact), 1, file)) {
        if (strcmp(tempContact.name, deleteName) == 0) {
            found = 1;
            printf("Deleted Contact: %s, Email: %s\n", tempContact.name, tempContact.email);
        } else {
            fwrite(&tempContact, sizeof(Contact), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);
    
    if(found) {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("Contact deleted successfully!\n");
    } else {
        remove("temp.txt");
        printf("Contact not found!\n");
    }
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                listContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}