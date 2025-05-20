//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define EMAIL_LENGTH 50
#define ADDRESS_LENGTH 100

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char email[EMAIL_LENGTH];
    char address[ADDRESS_LENGTH];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int count;
} PhoneBook;

// Function prototypes
void addContact(PhoneBook *pb);
void viewContacts(const PhoneBook *pb);
void searchContact(const PhoneBook *pb, const char *name);
void displayCyberpunkHeader();

int main() {
    PhoneBook pb = { .count = 0 };
    int choice;

    displayCyberpunkHeader();

    while (1) {
        printf("\nCyberpunk Phone Book v1.0 (Powered by neon-lit cyber circuits)\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

        switch (choice) {
            case 1:
                addContact(&pb);
                break;
            case 2:
                viewContacts(&pb);
                break;
            case 3: {
                char name[NAME_LENGTH];
                printf("Enter the name to search: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                searchContact(&pb, name);
                break;
            }
            case 4:
                printf("Shutting down the neon system...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addContact(PhoneBook *pb) {
    if (pb->count >= MAX_CONTACTS) {
        printf("Error: Phone book is full, can't add more contacts!\n");
        return;
    }

    Contact newContact;
    
    printf("Enter contact name: ");
    fgets(newContact.name, sizeof(newContact.name), stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0; // Remove newline

    printf("Enter phone number: ");
    fgets(newContact.phone, sizeof(newContact.phone), stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0; // Remove newline

    printf("Enter email: ");
    fgets(newContact.email, sizeof(newContact.email), stdin);
    newContact.email[strcspn(newContact.email, "\n")] = 0; // Remove newline

    printf("Enter address: ");
    fgets(newContact.address, sizeof(newContact.address), stdin);
    newContact.address[strcspn(newContact.address, "\n")] = 0; // Remove newline

    pb->contacts[pb->count] = newContact;
    pb->count++;
    printf("Contact added successfully to the mega-database!\n");
}

void viewContacts(const PhoneBook *pb) {
    if (pb->count == 0) {
        printf("No contacts found in the cybernetic database.\n");
        return;
    }

    printf("\n--- List of Contacts ---\n");
    for (int i = 0; i < pb->count; i++) {
        printf("Contact %d:\n", i + 1);
        printf("Name: %s\n", pb->contacts[i].name);
        printf("Phone: %s\n", pb->contacts[i].phone);
        printf("Email: %s\n", pb->contacts[i].email);
        printf("Address: %s\n", pb->contacts[i].address);
        printf("-----------------------\n");
    }
}

void searchContact(const PhoneBook *pb, const char *name) {
    for (int i = 0; i < pb->count; i++) {
        if (strcasecmp(pb->contacts[i].name, name) == 0) {
            printf("Contact Found:\n");
            printf("Name: %s\n", pb->contacts[i].name);
            printf("Phone: %s\n", pb->contacts[i].phone);
            printf("Email: %s\n", pb->contacts[i].email);
            printf("Address: %s\n", pb->contacts[i].address);
            return;
        }
    }
    printf("No contact found with the name '%s' in the network.\n", name);
}

void displayCyberpunkHeader() {
    printf("===== Welcome to the Neon Jungle =====\n");
    printf("   ┌─────────────────────────────┐\n");
    printf("   │    Cyberpunk Phone Book    │\n");
    printf("   │   Connecting the neon nodes │\n");
    printf("   └─────────────────────────────┘\n");
}