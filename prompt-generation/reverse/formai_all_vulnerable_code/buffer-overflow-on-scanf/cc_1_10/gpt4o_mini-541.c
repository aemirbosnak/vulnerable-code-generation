//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: configurable
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

void addContact(PhoneBook *phoneBook, const char *name, const char *phone, const char *email) {
    if (phoneBook->count >= MAX_CONTACTS) {
        printf("Phone book is full! Cannot add more contacts.\n");
        return;
    }
    strcpy(phoneBook->contacts[phoneBook->count].name, name);
    strcpy(phoneBook->contacts[phoneBook->count].phone, phone);
    strcpy(phoneBook->contacts[phoneBook->count].email, email);
    phoneBook->count++;
    printf("Contact added: %s\n", name);
}

void displayContacts(const PhoneBook *phoneBook) {
    if (phoneBook->count == 0) {
        printf("Phone book is empty.\n");
        return;
    }
    printf("\nPhone Book Contacts:\n");
    for (int i = 0; i < phoneBook->count; i++) {
        printf("Name: %s, Phone: %s, Email: %s\n", 
            phoneBook->contacts[i].name,
            phoneBook->contacts[i].phone,
            phoneBook->contacts[i].email);
    }
}

void searchContact(const PhoneBook *phoneBook, const char *name) {
    for (int i = 0; i < phoneBook->count; i++) {
        if (strcmp(phoneBook->contacts[i].name, name) == 0) {
            printf("Found contact: Name: %s, Phone: %s, Email: %s\n", 
                phoneBook->contacts[i].name,
                phoneBook->contacts[i].phone,
                phoneBook->contacts[i].email);
            return;
        }
    }
    printf("Contact not found: %s\n", name);
}

void deleteContact(PhoneBook *phoneBook, const char *name) {
    for (int i = 0; i < phoneBook->count; i++) {
        if (strcmp(phoneBook->contacts[i].name, name) == 0) {
            for (int j = i; j < phoneBook->count - 1; j++) {
                phoneBook->contacts[j] = phoneBook->contacts[j + 1];
            }
            phoneBook->count--;
            printf("Deleted contact: %s\n", name);
            return;
        }
    }
    printf("Contact not found: %s\n", name);
}

void savePhoneBookToFile(const PhoneBook *phoneBook, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file for saving contacts.\n");
        return;
    }
    fwrite(phoneBook, sizeof(PhoneBook), 1, file);
    fclose(file);
    printf("Phone book saved to %s\n", filename);
}

void loadPhoneBookFromFile(PhoneBook *phoneBook, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file for loading contacts. Starting fresh phone book.\n");
        phoneBook->count = 0;
        return;
    }
    fread(phoneBook, sizeof(PhoneBook), 1, file);
    fclose(file);
    printf("Phone book loaded from %s\n", filename);
}

int main() {
    PhoneBook phoneBook = { .count = 0 };
    int choice;
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char email[EMAIL_LENGTH];

    loadPhoneBookFromFile(&phoneBook, "phonebook.dat");

    do {
        printf("\n=== Phone Book Menu ===\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Save & Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // remove newline

                printf("Enter Phone: ");
                fgets(phone, PHONE_LENGTH, stdin);
                phone[strcspn(phone, "\n")] = 0; // remove newline

                printf("Enter Email: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // remove newline
                
                addContact(&phoneBook, name, phone, email);
                break;
            case 2:
                displayContacts(&phoneBook);
                break;
            case 3:
                printf("Enter Name to Search: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // remove newline
                searchContact(&phoneBook, name);
                break;
            case 4:
                printf("Enter Name to Delete: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // remove newline
                deleteContact(&phoneBook, name);
                break;
            case 5:
                savePhoneBookToFile(&phoneBook, "phonebook.dat");
                printf("Exiting the phone book.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}