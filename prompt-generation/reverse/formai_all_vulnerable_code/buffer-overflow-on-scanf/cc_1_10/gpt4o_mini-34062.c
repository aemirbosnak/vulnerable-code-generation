//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LEN 50
#define PHONE_LEN 15

typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
} Contact;

Contact phoneBook[MAX_CONTACTS];
int totalContacts = 0;

void addContact() {
    if (totalContacts >= MAX_CONTACTS) {
        printf("Phone book is full! Can't add more contacts.\n");
        return;
    }
    
    printf("Enter name: ");
    fgets(phoneBook[totalContacts].name, NAME_LEN, stdin);
    phoneBook[totalContacts].name[strcspn(phoneBook[totalContacts].name, "\n")] = 0; // Remove newline
    
    printf("Enter phone number: ");
    fgets(phoneBook[totalContacts].phone, PHONE_LEN, stdin);
    phoneBook[totalContacts].phone[strcspn(phoneBook[totalContacts].phone, "\n")] = 0; // Remove newline
    
    totalContacts++;
    printf("Contact added successfully!\n");
}

void displayContacts() {
    if (totalContacts == 0) {
        printf("Phone book is empty! No contacts to display.\n");
        return;
    }
    
    printf("\n--- Contacts List ---\n");
    for (int i = 0; i < totalContacts; i++) {
        printf("Name: %s, Phone: %s\n", phoneBook[i].name, phoneBook[i].phone);
    }
}

void searchContact() {
    char searchName[NAME_LEN];
    int found = 0;
    
    printf("Enter contact name to search: ");
    fgets(searchName, NAME_LEN, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline
    
    for (int i = 0; i < totalContacts; i++) {
        if (strcasecmp(searchName, phoneBook[i].name) == 0) {
            printf("Found Contact: Name: %s, Phone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No contact found with the name '%s'.\n", searchName);
    }
}

void deleteContact() {
    char deleteName[NAME_LEN];
    int foundIndex = -1;

    printf("Enter contact name to delete: ");
    fgets(deleteName, NAME_LEN, stdin);
    deleteName[strcspn(deleteName, "\n")] = 0; // Remove newline

    for (int i = 0; i < totalContacts; i++) {
        if (strcasecmp(deleteName, phoneBook[i].name) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("No contact found with the name '%s'.\n", deleteName);
        return;
    }

    for (int i = foundIndex; i < totalContacts - 1; i++) {
        phoneBook[i] = phoneBook[i + 1];
    }

    totalContacts--;
    printf("Contact '%s' deleted successfully!\n", deleteName);
}

void menu() {
    int choice;
    do {
        printf("\n--- Phone Book Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character after scanf

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
                deleteContact();
                break;
            case 5:
                printf("Exiting the Phone Book. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    printf("Welcome to the Mind-Bending Phone Book!\n");
    menu();
    return 0;
}