//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct Contact {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

typedef struct PhoneBook {
    Contact contacts[MAX_CONTACTS];
    int size;
} PhoneBook;

// Function Prototypes
void initializePhoneBook(PhoneBook *pb);
void addContact(PhoneBook *pb, const char *name, const char *phone);
void displayContacts(const PhoneBook *pb);
int searchContact(const PhoneBook *pb, const char *name);
void editContact(PhoneBook *pb, int index, const char *newName, const char *newPhone);
void deleteContact(PhoneBook *pb, int index);
void executeChoice(PhoneBook *pb, int choice);

int main() {
    PhoneBook pb; // Declare a PhoneBook instance
    initializePhoneBook(&pb); // Initialize the phone book

    int choice;
    do {
        printf("\n=== Phone Book Menu ===\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Edit Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        executeChoice(&pb, choice); // Execute user's choice
    } while (choice != 5); // Continue until exit option is chosen

    return 0;
}

void initializePhoneBook(PhoneBook *pb) {
    pb->size = 0; // Initialize size
}

void addContact(PhoneBook *pb, const char *name, const char *phone) {
    if (pb->size < MAX_CONTACTS) {
        strcpy(pb->contacts[pb->size].name, name);
        strcpy(pb->contacts[pb->size].phone, phone);
        pb->size++; // Increment size after adding
        printf("Contact added successfully!\n");
    } else {
        printf("Phone Book is full! Cannot add more contacts.\n");
    }
}

void displayContacts(const PhoneBook *pb) {
    if (pb->size == 0) {
        printf("No contacts to display.\n");
        return;
    }
    printf("\n=== Contact List ===\n");
    for (int i = 0; i < pb->size; i++) {
        printf("Contact %d: Name: %s, Phone: %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
}

int searchContact(const PhoneBook *pb, const char *name) {
    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            return i; // Return the index of the found contact
        }
    }
    return -1; // Not found
}

void editContact(PhoneBook *pb, int index, const char *newName, const char *newPhone) {
    if (index >= 0 && index < pb->size) {
        strcpy(pb->contacts[index].name, newName);
        strcpy(pb->contacts[index].phone, newPhone);
        printf("Contact updated successfully!\n");
    } else {
        printf("Invalid contact index.\n");
    }
}

void deleteContact(PhoneBook *pb, int index) {
    if (index >= 0 && index < pb->size) {
        for (int i = index; i < pb->size - 1; i++) {
            pb->contacts[i] = pb->contacts[i + 1]; // Shift contacts left
        }
        pb->size--; // Decrement size
        printf("Contact deleted successfully!\n");
    } else {
        printf("Invalid contact index.\n");
    }
}

void executeChoice(PhoneBook *pb, int choice) {
    char name[NAME_LENGTH], phone[PHONE_LENGTH];
    int index;

    switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter phone: ");
            scanf("%s", phone);
            addContact(pb, name, phone);
            break;
        case 2:
            displayContacts(pb);
            break;
        case 3:
            printf("Enter name to edit: ");
            scanf("%s", name);
            index = searchContact(pb, name);
            if (index != -1) {
                printf("Enter new name: ");
                scanf("%s", name);
                printf("Enter new phone: ");
                scanf("%s", phone);
                editContact(pb, index, name, phone);
            } else {
                printf("Contact not found.\n");
            }
            break;
        case 4:
            printf("Enter name to delete: ");
            scanf("%s", name);
            index = searchContact(pb, name);
            if (index != -1) {
                deleteContact(pb, index);
            } else {
                printf("Contact not found.\n");
            }
            break;
        case 5:
            printf("Exiting the Phone Book program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}