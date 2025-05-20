//FormAI DATASET v1.0 Category: Phone Book ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct contact {
    char name[30];
    char phone_number[20];
    char email[50];
};

void add_contact(struct contact *contacts, int *num_contacts);
void search_contact(struct contact *contacts, int num_contacts);
void edit_contact(struct contact *contacts, int num_contacts);
void delete_contact(struct contact *contacts, int *num_contacts);
void print_contact(struct contact contact);

int main() {
    struct contact contacts[MAX_CONTACTS];
    int num_contacts = 0;
    int choice;
    
    do {
        printf("\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. Print all contacts\n");
        printf("6. Exit\n");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_contact(contacts, &num_contacts);
                break;
            case 2:
                search_contact(contacts, num_contacts);
                break;
            case 3:
                edit_contact(contacts, num_contacts);
                break;
            case 4:
                delete_contact(contacts, &num_contacts);
                break;
            case 5:
                for (int i = 0; i < num_contacts; i++)
                    print_contact(contacts[i]);
                break;
            case 6:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}

// Function to add a new contact
void add_contact(struct contact *contacts, int *num_contacts) {
    if (*num_contacts == MAX_CONTACTS) {
        printf("\nPhone book is full, cannot add more contacts.\n");
        return;
    }
    
    struct contact new_contact;
    
    printf("\nEnter name: ");
    scanf("%s", new_contact.name);
    
    printf("Enter phone number: ");
    scanf("%s", new_contact.phone_number);
    
    printf("Enter email: ");
    scanf("%s", new_contact.email);
    
    contacts[*num_contacts] = new_contact;
    (*num_contacts)++;
    
    printf("\nContact added successfully.\n");
}

// Function to search for a contact
void search_contact(struct contact *contacts, int num_contacts) {
    char search_term[30];
    int found = 0;
    
    printf("\nEnter a name to search: ");
    scanf("%s", search_term);
    
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, search_term) == 0) {
            printf("\nContact found:\n");
            print_contact(contacts[i]);
            found = 1;
            break;
        }
    }
    
    if (!found)
        printf("\nContact not found.\n");
}

// Function to edit a contact
void edit_contact(struct contact *contacts, int num_contacts) {
    char search_term[30];
    int found = 0;
    
    printf("\nEnter a name to edit: ");
    scanf("%s", search_term);
    
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, search_term) == 0) {
            printf("\nEnter new name: ");
            scanf("%s", contacts[i].name);
            
            printf("Enter new phone number: ");
            scanf("%s", contacts[i].phone_number);
            
            printf("Enter new email: ");
            scanf("%s", contacts[i].email);
            
            printf("\nContact updated successfully.\n");
            found = 1;
            break;
        }
    }
    
    if (!found)
        printf("\nContact not found.\n");
}

// Function to delete a contact
void delete_contact(struct contact *contacts, int *num_contacts) {
    char search_term[30];
    int found = 0;
    
    printf("\nEnter a name to delete: ");
    scanf("%s", search_term);
    
    for (int i = 0; i < *num_contacts; i++) {
        if (strcmp(contacts[i].name, search_term) == 0) {
            for (int j = i; j < *num_contacts - 1; j++)
                contacts[j] = contacts[j + 1];
                
            (*num_contacts)--;
            printf("\nContact deleted successfully.\n");
            found = 1;
            break;
        }
    }
    
    if (!found)
        printf("\nContact not found.\n");
}

// Function to print a contact
void print_contact(struct contact contact) {
    printf("\nName: %s\n", contact.name);
    printf("Phone number: %s\n", contact.phone_number);
    printf("Email: %s\n", contact.email);
}