//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: systematic
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
    int size;
} PhoneBook;

void initializePhoneBook(PhoneBook *pb) {
    pb->size = 0;
}

void addContact(PhoneBook *pb) {
    if (pb->size >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", pb->contacts[pb->size].name);
    printf("Enter phone: ");
    scanf("%s", pb->contacts[pb->size].phone);

    pb->size++;
    printf("Contact added successfully!\n");
}

void displayContacts(const PhoneBook *pb) {
    if (pb->size == 0) {
        printf("No contacts available.\n");
        return;
    }

    printf("\nContacts List:\n");
    for (int i = 0; i < pb->size; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    }
    printf("\n");
}

void deleteContact(PhoneBook *pb) {
    if (pb->size == 0) {
        printf("No contacts to delete.\n");
        return;
    }

    int index;
    displayContacts(pb);
    
    printf("Enter the contact number to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > pb->size) {
        printf("Invalid contact number!\n");
        return;
    }

    for (int i = index - 1; i < pb->size - 1; i++) {
        pb->contacts[i] = pb->contacts[i + 1];
    }
    pb->size--;
    printf("Contact deleted successfully!\n");
}

void searchContact(const PhoneBook *pb) {
    if (pb->size == 0) {
        printf("No contacts available to search.\n");
        return;
    }

    char name[NAME_LENGTH];
    printf("Enter the name to search: ");
    scanf("%s", name);

    printf("\nSearch Results:\n");
    int found = 0;
    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            printf("Name: %s, Phone: %s\n", pb->contacts[i].name, pb->contacts[i].phone);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Contact not found!\n");
    }
}

void editContact(PhoneBook *pb) {
    if (pb->size == 0) {
        printf("No contacts available to edit.\n");
        return;
    }

    int index;
    displayContacts(pb);
    printf("Enter the contact number to edit: ");
    scanf("%d", &index);

    if (index < 1 || index > pb->size) {
        printf("Invalid contact number!\n");
        return;
    }

    printf("Editing Contact: %s, %s\n", pb->contacts[index - 1].name, pb->contacts[index - 1].phone);
    printf("Enter new name (or press enter to skip): ");
    char newName[NAME_LENGTH];
    getchar();  // Clear newline character
    fgets(newName, NAME_LENGTH, stdin);
    newName[strcspn(newName, "\n")] = 0; // remove newline character

    printf("Enter new phone (or press enter to skip): ");
    char newPhone[PHONE_LENGTH];
    fgets(newPhone, PHONE_LENGTH, stdin);
    newPhone[strcspn(newPhone, "\n")] = 0; // remove newline character

    if (strlen(newName) > 0) {
        strcpy(pb->contacts[index - 1].name, newName);
    }
    
    if (strlen(newPhone) > 0) {
        strcpy(pb->contacts[index - 1].phone, newPhone);
    }

    printf("Contact edited successfully!\n");
}

void menu() {
    printf("\nPhone Book Menu:\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Delete Contact\n");
    printf("4. Search Contact\n");
    printf("5. Edit Contact\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    PhoneBook pb;
    initializePhoneBook(&pb);
    int choice;

    while (1) {
        menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addContact(&pb);
                break;
            case 2:
                displayContacts(&pb);
                break;
            case 3:
                deleteContact(&pb);
                break;
            case 4:
                searchContact(&pb);
                break;
            case 5:
                editContact(&pb);
                break;
            case 6:
                printf("Exiting Phone Book. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}