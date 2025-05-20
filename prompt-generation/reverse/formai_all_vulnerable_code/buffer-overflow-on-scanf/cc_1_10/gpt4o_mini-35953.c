//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define FILE_NAME "phonebook.dat"

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

void addContact();
void deleteContact();
void displayContacts();
void searchContact();
void saveContacts(Contact contacts[], int count);
int loadContacts(Contact contacts[]);

int main() {
    int choice;

    while (1) {
        printf("\n--- Phone Book Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Display Contacts\n");
        printf("4. Search Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                deleteContact();
                break;
            case 3:
                displayContacts();
                break;
            case 4:
                searchContact();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void addContact() {
    Contact contact;
    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        perror("Unable to open file");
        return;
    }
    printf("Enter name: ");
    scanf("%s", contact.name);
    printf("Enter phone number: ");
    scanf("%s", contact.phone);
    fprintf(file, "%s %s\n", contact.name, contact.phone);
    fclose(file);
    printf("Contact added successfully!\n");
}

void deleteContact() {
    Contact contacts[MAX_CONTACTS];
    int count = loadContacts(contacts);
    char nameToDelete[NAME_LENGTH];
    int found = 0;

    if (count == 0) {
        printf("No contacts to delete.\n");
        return;
    }

    printf("Enter name of the contact to delete: ");
    scanf("%s", nameToDelete);

    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        perror("Error in opening file");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, nameToDelete) != 0) {
            fprintf(file, "%s %s\n", contacts[i].name, contacts[i].phone);
        } else {
            found = 1;
        }
    }
    
    fclose(file);
    if (found) {
        printf("Contact deleted successfully!\n");
    } else {
        printf("Contact not found!\n");
    }
}

void displayContacts() {
    Contact contacts[MAX_CONTACTS];
    int count = loadContacts(contacts);

    if (count == 0) {
        printf("No contacts to display.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
    }
}

void searchContact() {
    Contact contacts[MAX_CONTACTS];
    int count = loadContacts(contacts);
    char nameToSearch[NAME_LENGTH];
    int found = 0;

    if (count == 0) {
        printf("No contacts to search.\n");
        return;
    }

    printf("Enter name of the contact to search: ");
    scanf("%s", nameToSearch);

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, nameToSearch) == 0) {
            printf("Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found!\n");
    }
}

void saveContacts(Contact contacts[], int count) {
    FILE *file = fopen(FILE_NAME, "w");
    if (file) {
        for (int i = 0; i < count; i++) {
            fprintf(file, "%s %s\n", contacts[i].name, contacts[i].phone);
        }
        fclose(file);
    } else {
        perror("Error saving contacts");
    }
}

int loadContacts(Contact contacts[]) {
    int count = 0;
    FILE *file = fopen(FILE_NAME, "r");
    if (file) {
        while (fscanf(file, "%s %s", contacts[count].name, contacts[count].phone) != EOF) {
            count++;
        }
        fclose(file);
    }
    return count;
}