//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure to hold contact information
typedef struct {
    char name[100];
    char phone[15];
} Contact;

// Function prototypes
void add_contact(Contact *contacts, int *count);
void display_contacts(Contact *contacts, int count);
void search_contact(Contact *contacts, int count);
void delete_contact(Contact *contacts, int *count);
void save_contacts(Contact *contacts, int count);
void load_contacts(Contact *contacts, int *count);
void clear_buffer();

int main() {
    Contact contacts[100];
    int count = 0;
    int choice;

    // Load existing contacts from file
    load_contacts(contacts, &count);

    do {
        printf("\n=== Phone Book ===\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_buffer(); // Clear input buffer

        switch (choice) {
            case 1:
                add_contact(contacts, &count);
                break;
            case 2:
                display_contacts(contacts, count);
                break;
            case 3:
                search_contact(contacts, count);
                break;
            case 4:
                delete_contact(contacts, &count);
                break;
            case 5:
                save_contacts(contacts, count);
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}

// Function to add a new contact
void add_contact(Contact *contacts, int *count) {
    if (*count < 100) {
        printf("Enter name: ");
        fgets(contacts[*count].name, sizeof(contacts[*count].name), stdin);
        strtok(contacts[*count].name, "\n"); // Remove newline character
        printf("Enter phone: ");
        fgets(contacts[*count].phone, sizeof(contacts[*count].phone), stdin);
        strtok(contacts[*count].phone, "\n"); // Remove newline character
        (*count)++;
        printf("Contact added!\n");
    } else {
        printf("Contact list is full.\n");
    }
}

// Function to display all contacts
void display_contacts(Contact *contacts, int count) {
    if (count == 0) {
        printf("No contacts to display.\n");
        return;
    }
    printf("\n--- Contact List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
    }
}

// Function to search for a contact
void search_contact(Contact *contacts, int count) {
    char name[100];
    printf("Enter name to search: ");
    fgets(name, sizeof(name), stdin);
    strtok(name, "\n"); // Remove newline character
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Found Contact - Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to delete a contact
void delete_contact(Contact *contacts, int *count) {
    char name[100];
    printf("Enter name to delete: ");
    fgets(name, sizeof(name), stdin);
    strtok(name, "\n"); // Remove newline character
    int found = 0;

    for (int i = 0; i < *count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*count)--;
            found = 1;
            printf("Contact deleted!\n");
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to save contacts to a file
void save_contacts(Contact *contacts, int count) {
    FILE *file = fopen("contacts.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n%s\n", contacts[i].name, contacts[i].phone);
    }
    fclose(file);
    printf("Contacts saved successfully.\n");
}

// Function to load contacts from a file
void load_contacts(Contact *contacts, int *count) {
    FILE *file = fopen("contacts.txt", "r");
    if (file == NULL) {
        return; // No contacts found
    }
    while (fgets(contacts[*count].name, sizeof(contacts[*count].name), file)) {
        strtok(contacts[*count].name, "\n"); // Remove newline character
        fgets(contacts[*count].phone, sizeof(contacts[*count].phone), file);
        strtok(contacts[*count].phone, "\n"); // Remove newline character
        (*count)++;
    }
    fclose(file);
}

// Function to clear input buffer
void clear_buffer() {
    while (getchar() != '\n'); // Discard invalid input
}