//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone[15];
} Contact;

typedef struct {
    Contact *contacts;
    int size;
    int capacity;
} PhoneBook;

void initializePhoneBook(PhoneBook *pb) {
    pb->size = 0;
    pb->capacity = 2; 
    pb->contacts = (Contact *)malloc(pb->capacity * sizeof(Contact));
}

void freePhoneBook(PhoneBook *pb) {
    free(pb->contacts);
}

void resizePhoneBook(PhoneBook *pb) {
    pb->capacity *= 2;
    pb->contacts = (Contact *)realloc(pb->contacts, pb->capacity * sizeof(Contact));
}

void addContact(PhoneBook *pb) {
    if (pb->size >= pb->capacity) {
        resizePhoneBook(pb);
    }
    
    printf("Enter name: ");
    scanf(" %[^\n]", pb->contacts[pb->size].name);
    printf("Enter phone number: ");
    scanf(" %[^\n]", pb->contacts[pb->size].phone);
    
    pb->size++;
    printf("Contact added successfully!\n");
}

void displayContacts(PhoneBook *pb) {
    if (pb->size == 0) {
        printf("No contacts in the phone book.\n");
        return;
    }

    printf("\nContact List:\n");
    for (int i = 0; i < pb->size; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
}

void searchContact(PhoneBook *pb) {
    char searchName[50];
    printf("Enter the name to search: ");
    scanf(" %[^\n]", searchName);
    
    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->contacts[i].name, searchName) == 0) {
            printf("Found: Name: %s, Phone: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            return;
        }
    }
    
    printf("Contact not found.\n");
}

void removeContact(PhoneBook *pb) {
    char removeName[50];
    printf("Enter the name to remove: ");
    scanf(" %[^\n]", removeName);
    
    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->contacts[i].name, removeName) == 0) {
            for (int j = i; j < pb->size - 1; j++) {
                pb->contacts[j] = pb->contacts[j + 1];
            }
            pb->size--;
            printf("Contact removed successfully!\n");
            return;
        }
    }
    
    printf("Contact not found.\n");
}

void displayMenu() {
    printf("\nPhone Book Menu:\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Remove Contact\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    PhoneBook pb;
    initializePhoneBook(&pb);
    int choice;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addContact(&pb);
                break;
            case 2:
                displayContacts(&pb);
                break;
            case 3:
                searchContact(&pb);
                break;
            case 4:
                removeContact(&pb);
                break;
            case 5:
                freePhoneBook(&pb);
                printf("Exiting... Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    
    return 0;
}