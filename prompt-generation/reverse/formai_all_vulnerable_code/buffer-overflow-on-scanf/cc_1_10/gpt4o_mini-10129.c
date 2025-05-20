//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: expert-level
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

// Function prototypes
void addContact(PhoneBook *pb);
void displayContacts(const PhoneBook *pb);
void searchContact(const PhoneBook *pb);
void deleteContact(PhoneBook *pb);
void saveContacts(const PhoneBook *pb, const char *filename);
void loadContacts(PhoneBook *pb, const char *filename);
void clearInputBuffer();

int main() {
    PhoneBook phoneBook = {{0}, 0};
    int choice;
    const char *filename = "contacts.txt";
    loadContacts(&phoneBook, filename);

    do {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Save Contacts\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addContact(&phoneBook);
                break;
            case 2:
                displayContacts(&phoneBook);
                break;
            case 3:
                searchContact(&phoneBook);
                break;
            case 4:
                deleteContact(&phoneBook);
                break;
            case 5:
                saveContacts(&phoneBook, filename);
                break;
            case 0:
                printf("Exiting program... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void addContact(PhoneBook *pb) {
    if (pb->count >= MAX_CONTACTS) {
        printf("Phone book is full! Cannot add more contacts.\n");
        return;
    }
    
    Contact newContact;
    printf("Enter name: ");
    fgets(newContact.name, NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0'; // Remove newline

    printf("Enter phone: ");
    fgets(newContact.phone, PHONE_LENGTH, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0'; // Remove newline

    printf("Enter email: ");
    fgets(newContact.email, EMAIL_LENGTH, stdin);
    newContact.email[strcspn(newContact.email, "\n")] = '\0'; // Remove newline

    pb->contacts[pb->count++] = newContact;
    printf("Contact added successfully!\n");
}

void displayContacts(const PhoneBook *pb) {
    if (pb->count == 0) {
        printf("No contacts to display.\n");
        return;
    }
    
    printf("\nContact List:\n");
    for (int i = 0; i < pb->count; i++) {
        printf("Name: %s, Phone: %s, Email: %s\n", pb->contacts[i].name, pb->contacts[i].phone, pb->contacts[i].email);
    }
}

void searchContact(const PhoneBook *pb) {
    char searchName[NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Remove newline

    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, searchName) == 0) {
            printf("Found Contact - Name: %s, Phone: %s, Email: %s\n",
                   pb->contacts[i].name, pb->contacts[i].phone, pb->contacts[i].email);
            return;
        }
    }
    printf("Contact not found.\n");
}

void deleteContact(PhoneBook *pb) {
    char deleteName[NAME_LENGTH];
    printf("Enter name to delete: ");
    fgets(deleteName, NAME_LENGTH, stdin);
    deleteName[strcspn(deleteName, "\n")] = '\0'; // Remove newline

    int i;
    for (i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, deleteName) == 0) {
            break;
        }
    }
    
    if (i == pb->count) {
        printf("Contact not found.\n");
        return;
    }

    for (int j = i; j < pb->count - 1; j++) {
        pb->contacts[j] = pb->contacts[j + 1];
    }
    pb->count--;
    printf("Contact deleted successfully.\n");
}

void saveContacts(const PhoneBook *pb, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < pb->count; i++) {
        fprintf(file, "%s\n%s\n%s\n", pb->contacts[i].name, pb->contacts[i].phone, pb->contacts[i].email);
    }
    
    fclose(file);
    printf("Contacts saved successfully.\n");
}

void loadContacts(PhoneBook *pb, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("No contact file found. Starting a fresh phone book.\n");
        return;
    }

    while (fgetc(file) != EOF) {
        fseek(file, -1, SEEK_CUR);
        
        Contact contact;
        fgets(contact.name, NAME_LENGTH, file);
        contact.name[strcspn(contact.name, "\n")] = '\0'; // Remove newline
        fgets(contact.phone, PHONE_LENGTH, file);
        contact.phone[strcspn(contact.phone, "\n")] = '\0'; // Remove newline
        fgets(contact.email, EMAIL_LENGTH, file);
        contact.email[strcspn(contact.email, "\n")] = '\0'; // Remove newline

        pb->contacts[pb->count++] = contact;
    }
    
    fclose(file);
    printf("Contacts loaded successfully.\n");
}

void clearInputBuffer() {
    while (getchar() != '\n');
}