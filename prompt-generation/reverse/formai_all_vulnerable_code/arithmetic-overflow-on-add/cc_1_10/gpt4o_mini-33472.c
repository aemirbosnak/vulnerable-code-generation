//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define EMAIL_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char email[EMAIL_LENGTH];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int count;
} PhoneBook;

void initializePhoneBook(PhoneBook *pb) {
    pb->count = 0;
}

void addContact(PhoneBook *pb) {
    if (pb->count < MAX_CONTACTS) {
        printf("Enter name: ");
        scanf(" %[^\n]", pb->contacts[pb->count].name);
        printf("Enter phone: ");
        scanf(" %[^\n]", pb->contacts[pb->count].phone);
        printf("Enter email: ");
        scanf(" %[^\n]", pb->contacts[pb->count].email);
        pb->count++;
        printf("Contact added successfully!\n");
    } else {
        printf("Phone book is full. Cannot add more contacts.\n");
    }
}

void displayContacts(const PhoneBook *pb) {
    if (pb->count == 0) {
        printf("No contacts to display.\n");
        return;
    }
    for (int i = 0; i < pb->count; i++) {
        printf("Contact %d:\n", i + 1);
        printf("Name: %s\n", pb->contacts[i].name);
        printf("Phone: %s\n", pb->contacts[i].phone);
        printf("Email: %s\n", pb->contacts[i].email);
        printf("-----------------------\n");
    }
}

void searchContact(const PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter the name to search: ");
    scanf(" %[^\n]", name);
    
    int found = 0;
    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("Contact Found:\n");
            printf("Name: %s\n", pb->contacts[i].name);
            printf("Phone: %s\n", pb->contacts[i].phone);
            printf("Email: %s\n", pb->contacts[i].email);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Contact not found.\n");
    }
}

void deleteContact(PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    scanf(" %[^\n]", name);
    
    int found = 0;
    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < pb->count - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->count--;
            printf("Contact deleted successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Contact not found.\n");
    }
}

void saveContactsToFile(const PhoneBook *pb) {
    FILE *file = fopen("phonebook.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    for (int i = 0; i < pb->count; i++) {
        fprintf(file, "%s\n%s\n%s\n", pb->contacts[i].name, pb->contacts[i].phone, pb->contacts[i].email);
    }
    fclose(file);
    printf("Contacts saved to phonebook.txt\n");
}

void loadContactsFromFile(PhoneBook *pb) {
    FILE *file = fopen("phonebook.txt", "r");
    if (file == NULL) {
        printf("No saved contacts found.\n");
        return;
    }
    
    while (fscanf(file, " %[^\n]", pb->contacts[pb->count].name) != EOF) {
        fscanf(file, " %[^\n]", pb->contacts[pb->count].phone);
        fscanf(file, " %[^\n]", pb->contacts[pb->count].email);
        pb->count++;
    }
    fclose(file);
    printf("Contacts loaded successfully!\n");
}

int main() {
    PhoneBook pb;
    initializePhoneBook(&pb);
    loadContactsFromFile(&pb);
    
    int choice;
    do {
        printf("Phone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Save Contacts\n");
        printf("6. Exit\n");
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
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}