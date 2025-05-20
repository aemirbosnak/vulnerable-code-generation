//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Max number of contacts
#define MAX_CONTACTS 100

// Structure representing a contact
typedef struct {
    char name[50];
    char phone_number[20];
    char email[50];
} Contact;

// Array of contacts
Contact contacts[MAX_CONTACTS];

// Current number of contacts
int num_contacts = 0;

// Function to add a new contact
void add_contact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Error: maximum number of contacts reached\n");
        return;
    }

    // Prompt for contact details
    printf("Enter contact name: ");
    scanf("%49s", contacts[num_contacts].name);
    
    printf("Enter phone number: ");
    scanf("%19s", contacts[num_contacts].phone_number);
    
    printf("Enter email address: ");
    scanf("%49s", contacts[num_contacts].email);

    // Increment the number of contacts
    num_contacts++;
}

// Function to search for a contact by name
void search_contact() {
    char name[50];

    // Prompt for contact name
    printf("Enter contact name: ");
    scanf("%49s", name);

    // Search for the contact
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            // Contact found
            printf("Contact found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone number: %s\n", contacts[i].phone_number);
            printf("Email address: %s\n", contacts[i].email);
            return;
        }
    }

    // Contact not found
    printf("Contact not found\n");
}

// Function to delete a contact by name
void delete_contact() {
    char name[50];

    // Prompt for contact name
    printf("Enter contact name: ");
    scanf("%49s", name);

    // Search for the contact
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            // Contact found
            // Shift the remaining contacts to the left
            for (int j = i; j < num_contacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }

            // Decrement the number of contacts
            num_contacts--;

            // Contact deleted successfully
            printf("Contact deleted successfully\n");
            return;
        }
    }

    // Contact not found
    printf("Contact not found\n");
}

// Function to print all contacts
void print_contacts() {
    if (num_contacts == 0) {
        printf("No contacts to display\n");
        return;
    }

    // Print the contacts
    printf("Contacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%d. %s\n", i + 1, contacts[i].name);
    }
}

// Function to sort contacts by name
void sort_contacts() {
    // Use bubble sort to sort the contacts
    for (int i = 0; i < num_contacts - 1; i++) {
        for (int j = 0; j < num_contacts - i - 1; j++) {
            if (strcmp(contacts[j].name, contacts[j + 1].name) > 0) {
                // Swap the contacts
                Contact temp = contacts[j];
                contacts[j] = contacts[j + 1];
                contacts[j + 1] = temp;
            }
        }
    }
}

// Function to save contacts to a file
void save_contacts() {
    // Open a file for writing
    FILE *file = fopen("contacts.txt", "w");
    if (file == NULL) {
        printf("Error: unable to open file for writing\n");
        return;
    }

    // Write the contacts to the file
    for (int i = 0; i < num_contacts; i++) {
        fprintf(file, "%s\n", contacts[i].name);
        fprintf(file, "%s\n", contacts[i].phone_number);
        fprintf(file, "%s\n", contacts[i].email);
    }

    // Close the file
    fclose(file);

    // Contacts saved successfully
    printf("Contacts saved successfully\n");
}

// Function to load contacts from a file
void load_contacts() {
    // Open a file for reading
    FILE *file = fopen("contacts.txt", "r");
    if (file == NULL) {
        printf("Error: unable to open file for reading\n");
        return;
    }

    // Read the contacts from the file
    while (!feof(file)) {
        fscanf(file, "%49s\n", contacts[num_contacts].name);
        fscanf(file, "%19s\n", contacts[num_contacts].phone_number);
        fscanf(file, "%49s\n", contacts[num_contacts].email);
        num_contacts++;
    }

    // Close the file
    fclose(file);

    // Contacts loaded successfully
    printf("Contacts loaded successfully\n");
}

// Main function
int main() {
    bool running = true;

    while (running) {
        // Display the menu
        printf("Phone Book Menu\n");
        printf("1. Add a new contact\n");
        printf("2. Search for a contact\n");
        printf("3. Delete a contact\n");
        printf("4. Print all contacts\n");
        printf("5. Sort contacts by name\n");
        printf("6. Save contacts to a file\n");
        printf("7. Load contacts from a file\n");
        printf("8. Quit\n");

        // Get the user's choice
        int choice;
        scanf("%d", &choice);

        // Execute the user's choice
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                delete_contact();
                break;
            case 4:
                print_contacts();
                break;
            case 5:
                sort_contacts();
                break;
            case 6:
                save_contacts();
                break;
            case 7:
                load_contacts();
                break;
            case 8:
                running = false;
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}