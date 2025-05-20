//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 30
#define PHONE_LENGTH 15
#define FILE_NAME "phonebook.dat"

// Define a structure for a contact
typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

// Function declarations
void add_contact();
void view_contacts();
void search_contact();
void delete_contact();
void display_menu();

// Main function
int main() {
    while (1) {
        display_menu();
        int choice;
        printf("\nPlease enter your choice (1-5): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_contact(); break;
            case 2: view_contacts(); break;
            case 3: search_contact(); break;
            case 4: delete_contact(); break;
            case 5: printf("Goodbye! Have a great day! 😊\n"); exit(0);
            default: printf("Oops! That’s not a valid choice. Try again! 🎈\n");
        }
    }
}

void display_menu() {
    printf("\n=========================\n");
    printf("🎉 Welcome to the Phone Book! 🎉\n");
    printf("=========================\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
    printf("=========================\n");
}

void add_contact() {
    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        printf("Failed to open the phone book! 😔\n");
        return;
    }
    
    Contact new_contact;
    printf("Enter Name: ");
    scanf("%s", new_contact.name);
    printf("Enter Phone Number: ");
    scanf("%s", new_contact.phone);
    
    fwrite(&new_contact, sizeof(Contact), 1, file);
    fclose(file);
    printf("✨ Contact added successfully! ✨\n");
}

void view_contacts() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        printf("No contacts found! 📖\n");
        return;
    }
    
    printf("\nHere is your contact list:\n");
    Contact c;
    int count = 0;
    while (fread(&c, sizeof(Contact), 1, file)) {
        printf("%d. Name: %s, Phone: %s\n", ++count, c.name, c.phone);
    }
    fclose(file);
    
    if (count == 0) {
        printf("No contacts available! 📅\n");
    }
}

void search_contact() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        printf("No contacts found! 📖\n");
        return;
    }
    
    char search_name[NAME_LENGTH];
    printf("Enter the name to search: ");
    scanf("%s", search_name);
    
    Contact c;
    int found = 0;
    while (fread(&c, sizeof(Contact), 1, file)) {
        if (strcmp(c.name, search_name) == 0) {
            printf("Contact found! 🎉 Name: %s, Phone: %s\n", c.name, c.phone);
            found = 1;
            break;
        }
    }
    fclose(file);
    
    if (!found) {
        printf("Sorry! No contact found with that name. 😢\n");
    }
}

void delete_contact() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        printf("No contacts available! 📖\n");
        return;
    }
    
    // Create a temporary file to store contacts except the one to delete
    FILE *temp_file = fopen("temp.dat", "wb");
    if (!temp_file) {
        printf("Unable to create a temporary file! 😔\n");
        fclose(file);
        return;
    }
    
    char delete_name[NAME_LENGTH];
    printf("Enter the name to delete: ");
    scanf("%s", delete_name);
    
    Contact c;
    int found = 0;
    while (fread(&c, sizeof(Contact), 1, file)) {
        if (strcmp(c.name, delete_name) == 0) {
            printf("Deleting... Bye bye, %s! 👋\n", c.name);
            found = 1;
        } else {
            fwrite(&c, sizeof(Contact), 1, temp_file);
        }
    }
    
    fclose(file);
    fclose(temp_file);
    
    // Remove the original file and rename the temporary file
    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);
    
    if (!found) {
        printf("Oops! No contact found with that name to delete. 😢\n");
    }
}