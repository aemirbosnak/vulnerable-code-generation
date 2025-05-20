//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LEN 50
#define PHONE_LEN 15

typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int totalContacts;
} PhoneBook;

void initPhoneBook(PhoneBook *pb) {
    pb->totalContacts = 0;
}

void addContact(PhoneBook *pb) {
    if (pb->totalContacts == MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }
    
    Contact newContact;
    
    printf("Enter name: ");
    scanf(" %[^\n]", newContact.name);
    
    printf("Enter phone number: ");
    scanf(" %[^\n]", newContact.phone);
    
    pb->contacts[pb->totalContacts] = newContact;
    pb->totalContacts++;
    printf("Contact added successfully!\n");
}

void deleteContact(PhoneBook *pb) {
    char name[NAME_LEN];
    printf("Enter the name of the contact to delete: ");
    scanf(" %[^\n]", name);
    
    for (int i = 0; i < pb->totalContacts; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            for (int j = i; j < pb->totalContacts - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->totalContacts--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    
    printf("Contact not found!\n");
}

void searchContact(PhoneBook *pb) {
    char name[NAME_LEN];
    printf("Enter name to search: ");
    scanf(" %[^\n]", name);
    
    for (int i = 0; i < pb->totalContacts; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("Contact found: %s - %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            return;
        }
    }
    
    printf("Contact not found!\n");
}

void listContacts(PhoneBook *pb) {
    if (pb->totalContacts == 0) {
        printf("Phone book is empty!\n");
        return;
    }
    
    printf("\nContacts List:\n");
    for (int i = 0; i < pb->totalContacts; i++) {
        printf("%d. %s - %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
}

void saveToFile(PhoneBook *pb) {
    FILE *file = fopen("phonebook.txt", "w");
    if (!file) {
        printf("Failed to open file for writing!\n");
        return;
    }

    for (int i = 0; i < pb->totalContacts; i++) {
        fprintf(file, "%s;%s\n", pb->contacts[i].name, pb->contacts[i].phone);
    }
    
    fclose(file);
    printf("Phone book saved to file successfully!\n");
}

void loadFromFile(PhoneBook *pb) {
    FILE *file = fopen("phonebook.txt", "r");
    if (!file) {
        printf("No saved phone book found.\n");
        return;
    }
    
    while (fscanf(file, " %[^\n];%[^\n]\n", pb->contacts[pb->totalContacts].name, pb->contacts[pb->totalContacts].phone) != EOF) {
        pb->totalContacts++;
        if (pb->totalContacts == MAX_CONTACTS) break;
    }
    
    fclose(file);
    printf("Phone book loaded successfully!\n");
}

void displayMenu() {
    printf("\nPhone Book Menu:\n");
    printf("1. Add Contact\n");
    printf("2. Delete Contact\n");
    printf("3. Search Contact\n");
    printf("4. List Contacts\n");
    printf("5. Save to File\n");
    printf("6. Load from File\n");
    printf("0. Exit\n");
    printf("Choose an option: ");
}

int main() {
    PhoneBook pb;
    initPhoneBook(&pb);
  
    loadFromFile(&pb);
    
    int choice;
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addContact(&pb); break;
            case 2: deleteContact(&pb); break;
            case 3: searchContact(&pb); break;
            case 4: listContacts(&pb); break;
            case 5: saveToFile(&pb); break;
            case 6: loadFromFile(&pb); break;
            case 0: printf("Exiting the program...\n"); break;
            default: printf("Invalid choice! Please try again.\n"); break;
        }
    } while (choice != 0);

    return 0;
}