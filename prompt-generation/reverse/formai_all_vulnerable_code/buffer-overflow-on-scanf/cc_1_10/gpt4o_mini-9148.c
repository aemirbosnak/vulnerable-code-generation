//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phoneNumber[PHONE_LENGTH];
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
        printf("Phone book is full!\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", pb->contacts[pb->count].name);
    printf("Enter phone number: ");
    scanf("%s", pb->contacts[pb->count].phoneNumber);
    pb->count++;
    printf("Contact added successfully!\n");
}

void deleteContact(PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    scanf("%s", name);
    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            for (int j = i; j < pb->count - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->count--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

void viewContacts(PhoneBook *pb) {
    if (pb->count == 0) {
        printf("No contacts available.\n");
        return;
    }
    printf("Contacts:\n");
    for (int i = 0; i < pb->count; i++) {
        printf("Name: %s, Phone: %s\n", pb->contacts[i].name, pb->contacts[i].phoneNumber);
    }
}

void searchContact(PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to search: ");
    scanf("%s", name);
    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("Found - Name: %s, Phone: %s\n", pb->contacts[i].name, pb->contacts[i].phoneNumber);
            return;
        }
    }
    printf("Contact not found!\n");
}

void saveToFile(PhoneBook *pb) {
    FILE *file = fopen("phonebook.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    for (int i = 0; i < pb->count; i++) {
        fprintf(file, "%s %s\n", pb->contacts[i].name, pb->contacts[i].phoneNumber);
    }
    fclose(file);
    printf("Contacts saved to phonebook.txt\n");
}

void loadFromFile(PhoneBook *pb) {
    FILE *file = fopen("phonebook.txt", "r");
    if (file == NULL) {
        printf("No saved contacts found!\n");
        return;
    }
    while (fscanf(file, "%s %s", pb->contacts[pb->count].name, pb->contacts[pb->count].phoneNumber) != EOF) {
        pb->count++;
    }
    fclose(file);
    printf("Contacts loaded from phonebook.txt\n");
}

int main() {
    PhoneBook myPhoneBook;
    initializePhoneBook(&myPhoneBook);
    
    loadFromFile(&myPhoneBook);
    
    int choice;
    do {
        printf("\nPhone Book Menu\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. View Contacts\n");
        printf("4. Search Contact\n");
        printf("5. Save Contacts\n");
        printf("6. Load Contacts\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(&myPhoneBook);
                break;
            case 2:
                deleteContact(&myPhoneBook);
                break;
            case 3:
                viewContacts(&myPhoneBook);
                break;
            case 4:
                searchContact(&myPhoneBook);
                break;
            case 5:
                saveToFile(&myPhoneBook);
                break;
            case 6:
                loadFromFile(&myPhoneBook);
                break;
            case 7:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 7);

    return 0;
}