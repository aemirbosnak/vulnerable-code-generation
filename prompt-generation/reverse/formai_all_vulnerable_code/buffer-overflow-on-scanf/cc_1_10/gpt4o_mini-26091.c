//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

Contact phoneBook[MAX_CONTACTS];
int contactCount = 0;

// Function prototypes
void addContact();
void displayContacts();
void searchContact();
void deleteContact();
void saveToFile();
void loadFromFile();
void displayMenu();

int main() {
    loadFromFile();
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                saveToFile();
                printf("Contacts saved successfully!\n");
                break;
            case 6:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("\nPhone Book Menu:\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Save Contacts\n");
    printf("6. Exit\n");
}

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }
    
    printf("Enter contact name: ");
    fgets(phoneBook[contactCount].name, NAME_LENGTH, stdin);
    phoneBook[contactCount].name[strcspn(phoneBook[contactCount].name, "\n")] = 0;  // Remove newline
    
    printf("Enter contact phone: ");
    fgets(phoneBook[contactCount].phone, PHONE_LENGTH, stdin);
    phoneBook[contactCount].phone[strcspn(phoneBook[contactCount].phone, "\n")] = 0;  // Remove newline
    
    contactCount++;
    printf("Contact added successfully!\n");
}

void displayContacts() {
    if (contactCount == 0) {
        printf("No contacts to display.\n");
        return;
    }
    
    printf("\nList of Contacts:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. %s - %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void searchContact() {
    char name[NAME_LENGTH];
    printf("Enter the name to search: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;  // Remove newline

    for (int i = 0; i < contactCount; i++) {
        if (strcasecmp(phoneBook[i].name, name) == 0) {
            printf("Found: %s - %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void deleteContact() {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;  // Remove newline

    for (int i = 0; i < contactCount; i++) {
        if (strcasecmp(phoneBook[i].name, name) == 0) {
            for (int j = i; j < contactCount - 1; j++) {
                phoneBook[j] = phoneBook[j + 1];  // Shift contacts left
            }
            contactCount--;
            printf("Contact deleted successfully.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

void saveToFile() {
    FILE *file = fopen("phonebook.txt", "w");
    if (file == NULL) {
        printf("Error saving contacts to file!\n");
        return;
    }
    for (int i = 0; i < contactCount; i++) {
        fprintf(file, "%s,%s\n", phoneBook[i].name, phoneBook[i].phone);
    }
    fclose(file);
}

void loadFromFile() {
    FILE *file = fopen("phonebook.txt", "r");
    if (file == NULL) {
        return;  // File doesn't exist yet
    }

    while (fscanf(file, "%49[^,],%14[^\n]\n", phoneBook[contactCount].name, phoneBook[contactCount].phone) == 2) {
        contactCount++;
    }
    fclose(file);
}