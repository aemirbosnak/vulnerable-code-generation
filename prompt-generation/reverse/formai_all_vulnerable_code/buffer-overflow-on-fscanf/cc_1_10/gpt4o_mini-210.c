//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define FILENAME "contacts.txt"

typedef struct {
    char name[NAME_LENGTH];
    char phone[15];
} Contact;

void add_contact(Contact contacts[], int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Contact list is full. Cannot add more contacts.\n");
        return;
    }
    
    printf("Enter name: ");
    scanf("%s", contacts[*count].name);
    printf("Enter phone number: ");
    scanf("%s", contacts[*count].phone);
    (*count)++;
    printf("Contact added successfully!\n");
}

void list_contacts(Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts available.\n");
        return;
    }
    
    printf("\nContacts:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
    }
}

void save_contacts(Contact contacts[], int count) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%s\n", contacts[i].name, contacts[i].phone);
    }
    fclose(file);
    printf("Contacts saved successfully!\n");
}

void load_contacts(Contact contacts[], int *count) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No saved contacts found. Starting fresh.\n");
        return;
    }
    
    while (fscanf(file, "%[^,],%s\n", contacts[*count].name, contacts[*count].phone) != EOF) {
        (*count)++;
    }
    fclose(file);
    printf("Contacts loaded successfully! Total contacts: %d\n", *count);
}

void search_contact(Contact contacts[], int count) {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to search: ");
    scanf("%s", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Found: Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void delete_contact(Contact contacts[], int *count) {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    scanf("%s", name);
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*count)--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

void display_menu() {
    printf("\nContact Management System\n");
    printf("1. Add Contact\n");
    printf("2. List Contacts\n");
    printf("3. Save Contacts\n");
    printf("4. Load Contacts\n");
    printf("5. Search Contact\n");
    printf("6. Delete Contact\n");
    printf("7. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Contact contacts[MAX_ENTRIES];
    int count = 0;
    int choice;
    
    load_contacts(contacts, &count);

    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_contact(contacts, &count);
                break;
            case 2:
                list_contacts(contacts, count);
                break;
            case 3:
                save_contacts(contacts, count);
                break;
            case 4:
                load_contacts(contacts, &count);
                break;
            case 5:
                search_contact(contacts, count);
                break;
            case 6:
                delete_contact(contacts, &count);
                break;
            case 7:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}