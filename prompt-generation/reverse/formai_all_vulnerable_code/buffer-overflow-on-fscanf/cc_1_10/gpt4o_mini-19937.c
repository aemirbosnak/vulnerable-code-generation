//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a data structure for a contact
struct Contact {
    char name[50];
    char phone[15];
};

// Function prototypes
void addContact(struct Contact *contacts, int *count);
void displayContacts(struct Contact *contacts, int count);
void searchContact(struct Contact *contacts, int count);
void deleteContact(struct Contact *contacts, int *count);
void saveContacts(struct Contact *contacts, int count);
void loadContacts(struct Contact *contacts, int *count);

// Main function
int main() {
    struct Contact contacts[100];
    int count = 0;
    int choice;

    // Load existing contacts from file
    loadContacts(contacts, &count);

    do {
        printf("\n--- Phone Book Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                displayContacts(contacts, count);
                break;
            case 3:
                searchContact(contacts, count);
                break;
            case 4:
                deleteContact(contacts, &count);
                break;
            case 5:
                saveContacts(contacts, count);
                printf("Exiting the Phone Book. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add a contact
void addContact(struct Contact *contacts, int *count) {
    if (*count >= 100) {
        printf("Phone Book is full! Cannot add more contacts.\n");
        return;
    }
    printf("Enter name: ");
    fgets(contacts[*count].name, sizeof(contacts[*count].name), stdin);
    contacts[*count].name[strcspn(contacts[*count].name, "\n")] = 0; // Remove newline
    printf("Enter phone number: ");
    fgets(contacts[*count].phone, sizeof(contacts[*count].phone), stdin);
    contacts[*count].phone[strcspn(contacts[*count].phone, "\n")] = 0; // Remove newline
    (*count)++;
    printf("Contact added successfully!\n");
}

// Function to display all contacts
void displayContacts(struct Contact *contacts, int count) {
    if (count == 0) {
        printf("Phone Book is empty!\n");
        return;
    }
    printf("\n--- Contacts ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

// Function to search for a contact
void searchContact(struct Contact *contacts, int count) {
    char searchName[50];
    printf("Enter the name you want to search for: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline
    
    for (int i = 0; i < count; i++) {
        if (strcasecmp(contacts[i].name, searchName) == 0) {
            printf("Contact found: Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("Contact not found!\n");
}

// Function to delete a contact
void deleteContact(struct Contact *contacts, int *count) {
    int index;
    printf("Enter the index of the contact to delete (1-%d): ", *count);
    scanf("%d", &index);
    getchar(); // Consume newline

    if (index < 1 || index > *count) {
        printf("Invalid index!\n");
        return;
    }

    // Shift contacts left to fill the gap
    for (int i = index - 1; i < *count - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    (*count)--;
    printf("Contact deleted successfully!\n");
}

// Function to save contacts to a file
void saveContacts(struct Contact *contacts, int count) {
    FILE *file = fopen("contacts.txt", "w");
    if (!file) {
        printf("Error saving contacts!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%s\n", contacts[i].name, contacts[i].phone);
    }
    fclose(file);
}

// Function to load contacts from a file
void loadContacts(struct Contact *contacts, int *count) {
    FILE *file = fopen("contacts.txt", "r");
    if (file) {
        while (fscanf(file, "%[^,],%s\n", contacts[*count].name, contacts[*count].phone) != EOF) {
            (*count)++;
        }
        fclose(file);
    }
}