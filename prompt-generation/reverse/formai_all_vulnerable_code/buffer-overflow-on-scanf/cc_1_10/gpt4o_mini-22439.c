//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_CITY_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char city[MAX_CITY_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

void display_menu() {
    printf("Contact Management System\n");
    printf("1. Add Contact\n");
    printf("2. Display All Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

void add_contact(Contact *contacts, int *size) {
    if (*size >= MAX_ENTRIES) {
        printf("Contact list is full!\n");
        return;
    }
    
    printf("Enter name: ");
    scanf(" %[^\n]s", contacts[*size].name);
    printf("Enter city: ");
    scanf(" %[^\n]s", contacts[*size].city);
    printf("Enter phone number: ");
    scanf(" %[^\n]s", contacts[*size].phone);
    
    (*size)++;
    printf("Contact added successfully!\n");
}

void display_contacts(const Contact *contacts, int size) {
    if (size == 0) {
        printf("No contacts to display.\n");
        return;
    }
    
    printf("Displaying Contacts:\n");
    for (int i = 0; i < size; i++) {
        printf("Contact #%d: Name: %s, City: %s, Phone: %s\n",
               i + 1, contacts[i].name, contacts[i].city, contacts[i].phone);
    }
}

void search_contact(const Contact *contacts, int size) {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf(" %[^\n]s", search_name);
    
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            printf("Found Contact: Name: %s, City: %s, Phone: %s\n",
                   contacts[i].name, contacts[i].city, contacts[i].phone);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Contact not found.\n");
    }
}

void delete_contact(Contact *contacts, int *size) {
    char delete_name[MAX_NAME_LENGTH];
    printf("Enter name of contact to delete: ");
    scanf(" %[^\n]s", delete_name);
    
    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (strcmp(contacts[i].name, delete_name) == 0) {
            found = 1;
            for (int j = i; j < *size - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*size)--;
            printf("Contact deleted successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    Contact contacts[MAX_ENTRIES];
    int size = 0;
    int option;

    while (1) {
        display_menu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                add_contact(contacts, &size);
                break;
            case 2:
                display_contacts(contacts, size);
                break;
            case 3:
                search_contact(contacts, size);
                break;
            case 4:
                delete_contact(contacts, &size);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}