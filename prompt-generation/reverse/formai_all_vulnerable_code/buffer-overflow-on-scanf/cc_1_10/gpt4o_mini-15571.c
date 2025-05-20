//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

typedef struct {
    Contact contacts[MAX_ENTRIES];
    int count;
} PhoneBook;

void initializePhoneBook(PhoneBook *pb) {
    pb->count = 0;
}

void addContact(PhoneBook *pb) {
    if (pb->count >= MAX_ENTRIES) {
        printf("Phone book is full! Cannot add more contacts.\n");
        return;
    }
    
    Contact c;
    printf("Enter name: ");
    fgets(c.name, NAME_LENGTH, stdin);
    c.name[strcspn(c.name, "\n")] = '\0'; // Remove trailing newline
    
    printf("Enter phone number: ");
    fgets(c.phone, PHONE_LENGTH, stdin);
    c.phone[strcspn(c.phone, "\n")] = '\0'; // Remove trailing newline
    
    pb->contacts[pb->count] = c;
    pb->count++;
    printf("Contact added: %s - %s\n", c.name, c.phone);
}

void displayContacts(PhoneBook *pb) {
    if (pb->count == 0) {
        printf("No contacts in the phone book.\n");
        return;
    }
    
    printf("\n--- Phone Book Contacts ---\n");
    for (int i = 0; i < pb->count; i++) {
        printf("%d. %s - %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
}

void searchContact(PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to search: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove trailing newline

    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("Contact found: %s - %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            return;
        }
    }
    printf("Contact not found!\n");
}

void deleteContact(PhoneBook *pb) {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove trailing newline

    for (int i = 0; i < pb->count; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            // Shift the following contacts to fill the gap
            for (int j = i; j < pb->count - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->count--;
            printf("Contact %s deleted.\n", name);
            return;
        }
    }
    printf("Contact not found!\n");
}

void savePhoneBook(PhoneBook *pb) {
    FILE *file = fopen("phonebook.dat", "wb");
    if (file == NULL) {
        printf("Unable to open file for writing.\n");
        return;
    }
    
    fwrite(pb, sizeof(PhoneBook), 1, file);
    fclose(file);
    printf("Phone book saved to phonebook.dat\n");
}

void loadPhoneBook(PhoneBook *pb) {
    FILE *file = fopen("phonebook.dat", "rb");
    if (file == NULL) {
        printf("No saved phone book found.\n");
        return;
    }
    
    fread(pb, sizeof(PhoneBook), 1, file);
    fclose(file);
    printf("Phone book loaded from phonebook.dat\n");
}

void displayMenu() {
    printf("\n--- Phone Book Menu ---\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Save Phone Book\n");
    printf("6. Load Phone Book\n");
    printf("7. Exit\n");
    printf("-----------------------\n");
    printf("Choose an option: ");
}

int main() {
    PhoneBook pb;
    initializePhoneBook(&pb);
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume newline left by scanf

        switch (choice) {
            case 1: addContact(&pb); break;
            case 2: displayContacts(&pb); break;
            case 3: searchContact(&pb); break;
            case 4: deleteContact(&pb); break;
            case 5: savePhoneBook(&pb); break;
            case 6: loadPhoneBook(&pb); break;
            case 7: printf("Exiting program. Goodbye!\n"); exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}