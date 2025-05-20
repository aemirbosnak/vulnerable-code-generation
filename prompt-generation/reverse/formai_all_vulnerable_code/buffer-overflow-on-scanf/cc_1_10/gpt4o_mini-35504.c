//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_SIZE 50
#define PHONE_SIZE 15

typedef struct {
    char name[NAME_SIZE];
    char phone[PHONE_SIZE];
} Contact;

void add_contact(Contact contacts[], int* contact_count);
void view_contacts(const Contact contacts[], int contact_count);
void search_contact(const Contact contacts[], int contact_count);
void save_contacts_to_file(const Contact contacts[], int contact_count, const char* filename);
void load_contacts_from_file(Contact contacts[], int* contact_count, const char* filename);

int main() {
    Contact contacts[MAX_CONTACTS];
    int contact_count = 0;
    const char* filename = "contacts.txt";
    
    load_contacts_from_file(contacts, &contact_count, filename);
    
    int choice;
    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                add_contact(contacts, &contact_count);
                save_contacts_to_file(contacts, contact_count, filename);
                break;
            case 2:
                view_contacts(contacts, contact_count);
                break;
            case 3:
                search_contact(contacts, contact_count);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}

void add_contact(Contact contacts[], int* contact_count) {
    if (*contact_count >= MAX_CONTACTS) {
        printf("Contact list is full, cannot add more contacts.\n");
        return;
    }
    
    printf("Enter name: ");
    fgets(contacts[*contact_count].name, NAME_SIZE, stdin);
    contacts[*contact_count].name[strcspn(contacts[*contact_count].name, "\n")] = 0; // remove newline

    printf("Enter phone number: ");
    fgets(contacts[*contact_count].phone, PHONE_SIZE, stdin);
    contacts[*contact_count].phone[strcspn(contacts[*contact_count].phone, "\n")] = 0; // remove newline
    
    (*contact_count)++;
    printf("Contact added successfully.\n");
}

void view_contacts(const Contact contacts[], int contact_count) {
    printf("\nContacts List:\n");
    for (int i = 0; i < contact_count; i++) {
        printf("Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
    }
}

void search_contact(const Contact contacts[], int contact_count) {
    char search_name[NAME_SIZE];
    printf("Enter the name to search: ");
    fgets(search_name, NAME_SIZE, stdin);
    search_name[strcspn(search_name, "\n")] = 0; // remove newline

    int found = 0;
    for (int i = 0; i < contact_count; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            printf("Contact found: Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Contact not found.\n");
    }
}

void save_contacts_to_file(const Contact contacts[], int contact_count, const char* filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < contact_count; i++) {
        fprintf(file, "%s\n%s\n", contacts[i].name, contacts[i].phone);
    }
    fclose(file);
}

void load_contacts_from_file(Contact contacts[], int* contact_count, const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("No existing contacts file found. Starting fresh.\n");
        return;
    }

    while (fgets(contacts[*contact_count].name, NAME_SIZE, file) && 
           fgets(contacts[*contact_count].phone, PHONE_SIZE, file)) {
        contacts[*contact_count].name[strcspn(contacts[*contact_count].name, "\n")] = 0; // remove newline
        contacts[*contact_count].phone[strcspn(contacts[*contact_count].phone, "\n")] = 0; // remove newline
        (*contact_count)++;
    }
    fclose(file);
}