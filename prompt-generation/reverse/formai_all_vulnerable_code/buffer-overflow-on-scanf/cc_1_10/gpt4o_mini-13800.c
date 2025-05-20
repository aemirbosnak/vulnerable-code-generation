//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a contact
typedef struct {
    char name[50];
    char phone[15];
} Contact;

// Define a structure for the phone book
typedef struct {
    Contact *contacts;
    int size;
    int capacity;
} PhoneBook;

// Function to create a phone book
PhoneBook* createPhoneBook(int capacity) {
    PhoneBook *pb = (PhoneBook *)malloc(sizeof(PhoneBook));
    pb->contacts = (Contact *)malloc(capacity * sizeof(Contact));
    pb->size = 0;
    pb->capacity = capacity;
    return pb;
}

// Function to add a new contact
void addContact(PhoneBook *pb, char *name, char *phone) {
    if (pb->size >= pb->capacity) {
        pb->capacity *= 2;
        pb->contacts = (Contact *)realloc(pb->contacts, pb->capacity * sizeof(Contact));
    }
    strcpy(pb->contacts[pb->size].name, name);
    strcpy(pb->contacts[pb->size].phone, phone);
    pb->size++;
    printf("Contact added: %s - %s\n", name, phone);
}

// Function to view all contacts
void viewContacts(PhoneBook *pb) {
    printf("\nPhone Book:\n");
    for (int i = 0; i < pb->size; i++) {
        printf("%d: %s - %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
}

// Function to search for a contact by name
void searchContact(PhoneBook *pb, char *name) {
    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("Found: %s - %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            return;
        }
    }
    printf("Contact not found: %s\n", name);
}

// Function to delete a contact by name
void deleteContact(PhoneBook *pb, char *name) {
    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            for (int j = i; j < pb->size - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->size--;
            printf("Contact deleted: %s\n", name);
            return;
        }
    }
    printf("Contact not found to delete: %s\n", name);
}

// Free the memory allocated for the phone book
void freePhoneBook(PhoneBook *pb) {
    free(pb->contacts);
    free(pb);
}

int main() {
    PhoneBook *pb = createPhoneBook(5);
    int choice;
    char name[50], phone[15];

    do {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone: ");
                scanf("%s", phone);
                addContact(pb, name, phone);
                break;

            case 2:
                viewContacts(pb);
                break;

            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);
                searchContact(pb, name);
                break;

            case 4:
                printf("Enter name to delete: ");
                scanf("%s", name);
                deleteContact(pb, name);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    freePhoneBook(pb);
    return 0;
}