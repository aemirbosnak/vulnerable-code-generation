//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: detailed
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

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int count;
} PhoneBook;

void initializePhoneBook(PhoneBook *pb) {
    pb->count = 0;
}

void addContact(PhoneBook *pb) {
    if (pb->count >= MAX_CONTACTS) {
        printf("Phone Book is full!\n");
        return;
    }
    Contact newContact;
    printf("Enter name: ");
    scanf(" %[^\n]", newContact.name);  // Read string with spaces
    printf("Enter phone number: ");
    scanf(" %[^\n]", newContact.phone);  // Read string with spaces
    pb->contacts[pb->count] = newContact;
    pb->count++;
    printf("Contact added successfully!\n");
}

void displayContacts(const PhoneBook *pb) {
    if (pb->count == 0) {
        printf("No contacts available.\n");
        return;
    }
    printf("\n--- Phone Book Contacts ---\n");
    for (int i = 0; i < pb->count; i++) {
        printf("Contact %d: %s - %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
    printf("-----------------------------\n");
}

void searchContact(const PhoneBook *pb) {
    char searchName[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf(" %[^\n]", searchName);
    
    int found = 0;
    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, searchName) == 0) {
            printf("Found: %s - %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found!\n");
    }
}

void deleteContact(PhoneBook *pb) {
    char deleteName[NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf(" %[^\n]", deleteName);
    
    int found = 0;
    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, deleteName) == 0) {
            found = 1;
            for (int j = i; j < pb->count - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];  // Shift contacts left
            }
            pb->count--;
            printf("Contact deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Contact not found!\n");
    }
}

void saveContactsToFile(const PhoneBook *pb) {
    FILE *file = fopen("contacts.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    for (int i = 0; i < pb->count; i++) {
        fprintf(file, "%s\n%s\n", pb->contacts[i].name, pb->contacts[i].phone);
    }
    fclose(file);
    printf("Contacts saved to contacts.txt\n");
}

void loadContactsFromFile(PhoneBook *pb) {
    FILE *file = fopen("contacts.txt", "r");
    if (file == NULL) {
        printf("No saved contacts found!\n");
        return;
    }
    while (fscanf(file, " %[^\n] %[^\n]", pb->contacts[pb->count].name, pb->contacts[pb->count].phone) == 2) {
        pb->count++;
        if (pb->count >= MAX_CONTACTS) break;
    }
    fclose(file);
    printf("Contacts loaded successfully!\n");
}

void displayMenu() {
    printf("\n--- Phone Book Menu ---\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Save Contacts to File\n");
    printf("6. Load Contacts from File\n");
    printf("7. Exit\n");
}

int main() {
    PhoneBook pb;
    initializePhoneBook(&pb);
    loadContactsFromFile(&pb);

    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addContact(&pb);
                break;
            case 2:
                displayContacts(&pb);
                break;
            case 3:
                searchContact(&pb);
                break;
            case 4:
                deleteContact(&pb);
                break;
            case 5:
                saveContactsToFile(&pb);
                break;
            case 6:
                loadContactsFromFile(&pb);
                break;
            case 7:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}