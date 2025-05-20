//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define INITIAL_CAPACITY 5

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

typedef struct {
    Contact* contacts;
    int size;
    int capacity;
} PhoneBook;

// Function prototypes
PhoneBook* createPhoneBook();
void addContact(PhoneBook* phoneBook, const char* name, const char* phone);
void displayContacts(const PhoneBook* phoneBook);
void freePhoneBook(PhoneBook* phoneBook);
void searchContact(const PhoneBook* phoneBook, const char* name);
void removeContact(PhoneBook* phoneBook, const char* name);

int main() {
    PhoneBook* phoneBook = createPhoneBook();
    int choice;
    char name[NAME_LENGTH], phone[PHONE_LENGTH];

    do {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Remove Contact\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                addContact(phoneBook, name, phone);
                break;
            case 2:
                displayContacts(phoneBook);
                break;
            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);
                searchContact(phoneBook, name);
                break;
            case 4:
                printf("Enter name to remove: ");
                scanf("%s", name);
                removeContact(phoneBook, name);
                break;
            case 5:
                freePhoneBook(phoneBook);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

PhoneBook* createPhoneBook() {
    PhoneBook* phoneBook = (PhoneBook*)malloc(sizeof(PhoneBook));
    phoneBook->size = 0;
    phoneBook->capacity = INITIAL_CAPACITY;
    phoneBook->contacts = (Contact*)malloc(phoneBook->capacity * sizeof(Contact));
    return phoneBook;
}

void addContact(PhoneBook* phoneBook, const char* name, const char* phone) {
    if (phoneBook->size >= phoneBook->capacity) {
        phoneBook->capacity *= 2;
        phoneBook->contacts = realloc(phoneBook->contacts, phoneBook->capacity * sizeof(Contact));
    }
    strcpy(phoneBook->contacts[phoneBook->size].name, name);
    strcpy(phoneBook->contacts[phoneBook->size].phone, phone);
    phoneBook->size++;
    printf("Contact added: %s, %s\n", name, phone);
}

void displayContacts(const PhoneBook* phoneBook) {
    printf("\nContacts:\n");
    if (phoneBook->size == 0) {
        printf("No contacts found.\n");
    } else {
        for (int i = 0; i < phoneBook->size; i++) {
            printf("Name: %s, Phone: %s\n", phoneBook->contacts[i].name, phoneBook->contacts[i].phone);
        }
    }
}

void freePhoneBook(PhoneBook* phoneBook) {
    free(phoneBook->contacts);
    free(phoneBook);
}

void searchContact(const PhoneBook* phoneBook, const char* name) {
    for (int i = 0; i < phoneBook->size; i++) {
        if (strcmp(phoneBook->contacts[i].name, name) == 0) {
            printf("Contact found: Name: %s, Phone: %s\n", phoneBook->contacts[i].name, phoneBook->contacts[i].phone);
            return;
        }
    }
    printf("Contact not found: %s\n", name);
}

void removeContact(PhoneBook* phoneBook, const char* name) {
    int found = 0;
    for (int i = 0; i < phoneBook->size; i++) {
        if (strcmp(phoneBook->contacts[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < phoneBook->size - 1; j++) {
                phoneBook->contacts[j] = phoneBook->contacts[j + 1];
            }
            phoneBook->size--;
            printf("Contact removed: %s\n", name);
            break;
        }
    }
    if (!found) {
        printf("Contact not found: %s\n", name);
    }
}