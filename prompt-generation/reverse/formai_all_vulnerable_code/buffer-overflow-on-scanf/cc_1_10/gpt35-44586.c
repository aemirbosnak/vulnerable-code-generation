//FormAI DATASET v1.0 Category: Phone Book ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum size of phone book
#define MAX_SIZE 100

// Define structure for contact information
struct Contact {
    char name[50];
    char phone_number[15];
    char email[50];
};

// Define function prototypes
void addContact(struct Contact * contacts, int * count);
void viewContacts(struct Contact * contacts, int count);
void searchContacts(struct Contact * contacts, int count);
void deleteContact(struct Contact * contacts, int * count);

int main() {
    struct Contact contacts[MAX_SIZE];
    int count = 0, choice;
    
    // Loop through menu options until user exits program
    while (1) {
        // Display menu options
        printf("\n------PHONE BOOK MENU------\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contacts\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        getchar(); // consume newline character from input buffer
        
        // Execute menu option based on user input
        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                viewContacts(contacts, count);
                break;
            case 3:
                searchContacts(contacts, count);
                break;
            case 4:
                deleteContact(contacts, &count);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}

void addContact(struct Contact * contacts, int * count) {
    // Check if phone book is full
    if (*count == MAX_SIZE) {
        printf("Phone book is full.\n");
        return;
    }
    
    // Get contact data from user
    printf("\nEnter contact name: ");
    scanf("%[^\n]", contacts[*count].name);
    getchar(); // consume newline character from input buffer
    printf("Enter contact phone number: ");
    scanf("%[^\n]", contacts[*count].phone_number);
    getchar(); // consume newline character from input buffer
    printf("Enter contact email: ");
    scanf("%[^\n]", contacts[*count].email);
    getchar(); // consume newline character from input buffer
    
    // Increment contact count
    (*count)++;
    
    // Print success message
    printf("Contact added successfully.\n");
}

void viewContacts(struct Contact * contacts, int count) {
    // Check if phone book is empty
    if (count == 0) {
        printf("Phone book is empty.\n");
        return;
    }
    
    // Print table header
    printf("\n%26s | %15s | %26s\n", "Name", "Phone Number", "Email");
    printf("%s\n", "-------------------------------------------------------");
    
    // Print all contacts in phone book
    for (int i = 0; i < count; i++) {
        printf("%26s | %15s | %26s\n", contacts[i].name, contacts[i].phone_number, contacts[i].email);
    }
}

void searchContacts(struct Contact * contacts, int count) {
    // Check if phone book is empty
    if (count == 0) {
        printf("Phone book is empty.\n");
        return;
    }
    
    // Get search query from user
    char query[50];
    printf("\nEnter search query: ");
    scanf("%[^\n]", query);
    getchar(); // consume newline character from input buffer
    
    // Print table header
    printf("\n%26s | %15s | %26s\n", "Name", "Phone Number", "Email");
    printf("%s\n", "-------------------------------------------------------");
    
    // Print matching contacts
    int match_found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(contacts[i].name, query) || strstr(contacts[i].phone_number, query) || strstr(contacts[i].email, query)) {
            printf("%26s | %15s | %26s\n", contacts[i].name, contacts[i].phone_number, contacts[i].email);
            match_found = 1;
        }
    }
    
    // Print message if no matches were found
    if (!match_found) {
        printf("No matching contacts found.\n");
    }
}

void deleteContact(struct Contact * contacts, int * count) {
    // Check if phone book is empty
    if (*count == 0) {
        printf("Phone book is empty.\n");
        return;
    }
    
    // Get contact name to delete from user
    char name[50];
    printf("\nEnter name of contact to delete: ");
    scanf("%[^\n]", name);
    getchar(); // consume newline character from input buffer
    
    // Iterate through contacts to find matching name
    int match_found = 0, i;
    for (i = 0; i < *count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            match_found = 1;
            break;
        }
    }
    
    // Delete contact and shift remaining contacts up in array
    if (match_found) {
        for (int j = i; j < *count - 1; j++) {
            strcpy(contacts[j].name, contacts[j+1].name);
            strcpy(contacts[j].phone_number, contacts[j+1].phone_number);
            strcpy(contacts[j].email, contacts[j+1].email);
        }
        (*count)--;
        printf("Contact deleted successfully.\n");
    } else {
        printf("Contact not found.\n");
    }
}