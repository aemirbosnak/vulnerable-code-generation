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

void initializePhoneBook(PhoneBook* pb) {
    pb->count = 0;
}

void addContact(PhoneBook* pb) {
    if (pb->count >= MAX_CONTACTS) {
        printf("Phone Book is full!\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", pb->contacts[pb->count].name);
    printf("Enter phone number: ");
    scanf("%s", pb->contacts[pb->count].phone);
    pb->count++;
    printf("Contact added successfully!\n");
}

void displayContacts(const PhoneBook* pb) {
    if (pb->count == 0) {
        printf("No contacts in the phone book.\n");
        return;
    }
    printf("\nPhone Book Contacts:\n");
    for (int i = 0; i < pb->count; i++) {
        printf("Contact %d: Name: %s, Phone: %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
}

void searchContact(const PhoneBook* pb) {
    char searchName[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, searchName) == 0) {
            printf("Found: Name: %s, Phone: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            return;
        }
    }
    printf("Contact not found!\n");
}

void deleteContact(PhoneBook* pb) {
    char deleteName[NAME_LENGTH];
    printf("Enter name of contact to delete: ");
    scanf("%s", deleteName);

    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, deleteName) == 0) {
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

void saveToFile(const PhoneBook* pb) {
    FILE* file = fopen("phonebook.txt", "w");
    if (file == NULL) {
        printf("Unable to open file for writing.\n");
        return;
    }
    for (int i = 0; i < pb->count; i++) {
        fprintf(file, "%s %s\n", pb->contacts[i].name, pb->contacts[i].phone);
    }
    fclose(file);
    printf("Contacts saved to file successfully!\n");
}

void loadFromFile(PhoneBook* pb) {
    FILE* file = fopen("phonebook.txt", "r");
    if (file == NULL) {
        printf("No saved contacts found.\n");
        return;
    }
    while (fscanf(file, "%s %s", pb->contacts[pb->count].name, pb->contacts[pb->count].phone) == 2) {
        pb->count++;
        if (pb->count >= MAX_CONTACTS) {
            printf("Reached maximum number of contacts from file.\n");
            break;
        }
    }
    fclose(file);
    printf("Contacts loaded from file successfully!\n");
}

void clearPhoneBook(PhoneBook* pb) {
    pb->count = 0;
    printf("Cleared all contacts from phone book.\n");
}

int main() {
    PhoneBook pb;
    initializePhoneBook(&pb);
    loadFromFile(&pb);

    int choice;
    do {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Save to File\n");
        printf("6. Load from File\n");
        printf("7. Clear Phone Book\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(&pb); break;
            case 2: displayContacts(&pb); break;
            case 3: searchContact(&pb); break;
            case 4: deleteContact(&pb); break;
            case 5: saveToFile(&pb); break;
            case 6: loadFromFile(&pb); break;
            case 7: clearPhoneBook(&pb); break;
            case 8: printf("Exiting program.\n"); break;
            default: printf("Invalid choice, try again!\n");
        }
    } while (choice != 8);

    return 0;
}