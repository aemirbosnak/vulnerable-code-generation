//FormAI DATASET v1.0 Category: Phone Book ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing contact's information
struct Contact {
    char name[50];
    char phone_num[15];
};

// Function for adding a new contact
void add_contact(struct Contact *contacts, int *num_contacts) {
    char name[50];
    char phone_num[15];
    
    // Clear input buffer
    fflush(stdin);
    
    // Get name and phone number from user
    printf("Enter name: ");
    fgets(name, 50, stdin);
    printf("Enter phone number: ");
    fgets(phone_num, 15, stdin);
    
    // Remove newline characters from input
    name[strcspn(name, "\n")] = '\0';
    phone_num[strcspn(phone_num, "\n")] = '\0';
    
    // Add new contact to array
    strcpy(contacts[*num_contacts].name, name);
    strcpy(contacts[*num_contacts].phone_num, phone_num);
    
    // Increment number of contacts
    (*num_contacts)++;
    
    printf("Contact added.\n");
}

// Function for searching for a contact
void search_contact(struct Contact *contacts, int num_contacts) {
    char search_name[50];
    int found = 0;
    
    // Clear input buffer
    fflush(stdin);
    
    // Get name to search for from user
    printf("Enter name to search for: ");
    fgets(search_name, 50, stdin);
    search_name[strcspn(search_name, "\n")] = '\0';
    
    // Search for matching name
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            // If match is found, display the contact's information
            printf("Name: %s\nPhone Number: %s\n", contacts[i].name, contacts[i].phone_num);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function for deleting a contact
void delete_contact(struct Contact *contacts, int *num_contacts) {
    char delete_name[50];
    
    // Clear input buffer
    fflush(stdin);
    
    // Get name to delete from user
    printf("Enter name to delete: ");
    fgets(delete_name, 50, stdin);
    delete_name[strcspn(delete_name, "\n")] = '\0';
    
    // Search for matching name
    for (int i = 0; i < *num_contacts; i++) {
        if (strcmp(contacts[i].name, delete_name) == 0) {
            // Shift all contacts after the deleted contact up one index in the array
            for (int j = i; j < *num_contacts-1; j++) {
                strcpy(contacts[j].name, contacts[j+1].name);
                strcpy(contacts[j].phone_num, contacts[j+1].phone_num);
            }
            
            // Decrement number of contacts
            (*num_contacts)--;
            
            printf("Contact deleted.\n");
            return;
        }
    }
    
    printf("Contact not found.\n");
}

// Main function
int main() {
    struct Contact contacts[50];
    int num_contacts = 0;
    int choice;
    
    printf("***PHONE BOOK***\n");
    
    while (1) {
        printf("\n1. Add Contact\n2. Search Contact\n3. Delete Contact\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_contact(contacts, &num_contacts);
                break;
            case 2:
                search_contact(contacts, num_contacts);
                break;
            case 3:
                delete_contact(contacts, &num_contacts);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}