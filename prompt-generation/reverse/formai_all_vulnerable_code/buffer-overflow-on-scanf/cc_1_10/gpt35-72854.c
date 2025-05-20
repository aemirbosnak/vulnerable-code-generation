//FormAI DATASET v1.0 Category: Phone Book ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LEN 30
#define PHONE_NUM_LEN 15

struct Contact {
    char name[NAME_LEN];
    char phone_number[PHONE_NUM_LEN];
};

struct Contact phonebook[MAX_CONTACTS];
int num_contacts = 0;

void add_contact(void);
void search_contact(void);
void display_contacts(void);

int main(void) {
    int choice;
    
    printf("Welcome to Sherlock's Phonebook\n");
    printf("*******************************\n\n");
    
    while (1) {
        printf("Choose an option below:\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Display all contacts\n");
        printf("4. Quit\n\n");
        
        printf("Enter your choice number: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                display_contacts();
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n\n");
                break;
        }
    }
}

void add_contact(void) {
    if (num_contacts >= MAX_CONTACTS) {
        printf("The phonebook is full!\n\n");
        return;
    }
    
    struct Contact new_contact;
    
    printf("Enter the name of the contact: ");
    scanf("%s", new_contact.name);
    
    printf("Enter the phone number of the contact: ");
    scanf("%s", new_contact.phone_number);
    
    phonebook[num_contacts++] = new_contact;
    
    printf("Contact added successfully!\n\n");
}

void search_contact(void) {
    if (num_contacts == 0) {
        printf("There are no contacts to search for!\n\n");
        return;
    }
    
    char search_name[NAME_LEN];
    int i;
    int found = 0;
    
    printf("Enter the name of the contact: ");
    scanf("%s", search_name);
    
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(search_name, phonebook[i].name) == 0) {
            printf("Name: %s\nPhone Number: %s\n\n", phonebook[i].name, phonebook[i].phone_number);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Contact not found!\n\n");
    }
}

void display_contacts(void) {
    if (num_contacts == 0) {
        printf("There are no contacts to display!\n\n");
        return;
    }
    
    int i;
    
    for (i = 0; i < num_contacts; i++) {
        printf("Name: %s\nPhone Number: %s\n\n", phonebook[i].name, phonebook[i].phone_number);
    }
}