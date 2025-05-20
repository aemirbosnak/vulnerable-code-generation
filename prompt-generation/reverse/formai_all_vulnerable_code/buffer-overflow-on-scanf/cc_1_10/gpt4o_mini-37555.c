//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

Contact phoneBook[MAX_CONTACTS];
int contactCount = 0;

void addContact();
void viewContacts();
void deleteContact();
void searchContact();
void saveContacts();
void loadContacts();

int main() {
    int choice;
    loadContacts();

    while (1) {
        printf("\n--- Phone Book Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Search Contact\n");
        printf("5. Save and Exit\n");
        printf("6. Exit without Saving\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: deleteContact(); break;
            case 4: searchContact(); break;
            case 5: saveContacts(); return 0;
            case 6: return 0;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phone book is full! Cannot add more contacts.\n");
        return;
    }
    printf("Enter contact name: ");
    getchar(); // consume leftover newline
    fgets(phoneBook[contactCount].name, MAX_NAME_LENGTH, stdin);
    phoneBook[contactCount].name[strcspn(phoneBook[contactCount].name, "\n")] = 0; // Remove newline
    
    printf("Enter contact phone: ");
    fgets(phoneBook[contactCount].phone, MAX_PHONE_LENGTH, stdin);
    phoneBook[contactCount].phone[strcspn(phoneBook[contactCount].phone, "\n")] = 0; // Remove newline
    
    contactCount++;
    printf("Contact added successfully!\n");
}

void viewContacts() {
    if (contactCount == 0) {
        printf("No contacts available.\n");
        return;
    }
    printf("\n--- Contact List ---\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void deleteContact() {
    int index;
    if (contactCount == 0) {
        printf("No contacts available to delete.\n");
        return;
    }
    viewContacts();
    printf("Enter the contact number to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > contactCount) {
        printf("Invalid contact number.\n");
        return;
    }
    for (int i = index - 1; i < contactCount - 1; i++) {
        phoneBook[i] = phoneBook[i + 1]; // Shift contacts left
    }
    contactCount--;
    printf("Contact deleted successfully!\n");
}

void searchContact() {
    char searchName[MAX_NAME_LENGTH];
    printf("Enter the name to search: ");
    getchar(); // consume leftover newline
    fgets(searchName, MAX_NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline

    int found = 0;
    printf("\n--- Search Results ---\n");
    for (int i = 0; i < contactCount; i++) {
        if (strcasestr(phoneBook[i].name, searchName) != NULL) {
            printf("Name: %s, Phone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            found = 1;
        }
    }
    if (!found) {
        printf("No contacts found with that name.\n");
    }
}

void saveContacts() {
    FILE *file = fopen("contacts.txt", "w");
    if (file == NULL) {
        printf("Error saving contacts!\n");
        return;
    }
    for (int i = 0; i < contactCount; i++) {
        fprintf(file, "%s\n%s\n", phoneBook[i].name, phoneBook[i].phone);
    }
    fclose(file);
    printf("Contacts saved successfully!\n");
}

void loadContacts() {
    FILE *file = fopen("contacts.txt", "r");
    if (file == NULL) {
        printf("No previous contacts found. Starting fresh.\n");
        return;
    }
    while (fscanf(file, "%49[^\n]\n%14[^\n]\n", phoneBook[contactCount].name, phoneBook[contactCount].phone) == 2) {
        contactCount++;
        if (contactCount >= MAX_CONTACTS) {
            break;
        }
    }
    fclose(file);
    printf("%d contacts loaded from file.\n", contactCount);
}