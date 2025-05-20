//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: happy
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

Contact phoneBook[MAX_CONTACTS];
int contactCount = 0;

void addContact();
void displayContacts();
void searchContact();
void clearBuffer();

int main() {
    int choice;
    
    printf("🎉 Welcome to Your Happy Phone Book! 🎉\n");
    
    do {
        printf("\nChoose an option:\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear buffer to avoid issues with fgets and scanf

        switch(choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                printf("🎊 Thank you for using the Happy Phone Book! Goodbye! 🎊\n");
                break;
            default:
                printf("😄 Oops! Please enter a valid option (1-4).\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("😞 Your phone book is full! Can't add more contacts.\n");
        return;
    }
    
    printf("😊 Adding a new contact...\n");
    
    printf("Enter name: ");
    fgets(phoneBook[contactCount].name, NAME_LENGTH, stdin);
    phoneBook[contactCount].name[strcspn(phoneBook[contactCount].name, "\n")] = 0; // Remove newline

    printf("Enter phone number: ");
    fgets(phoneBook[contactCount].phone, PHONE_LENGTH, stdin);
    phoneBook[contactCount].phone[strcspn(phoneBook[contactCount].phone, "\n")] = 0; // Remove newline
    
    contactCount++;
    printf("🎉 Contact added successfully! 🎉\n");
}

void displayContacts() {
    if (contactCount == 0) {
        printf("😢 Your phone book is empty. Add some contacts first!\n");
        return;
    }

    printf("\n📖 Your Contacts:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. %s - %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void searchContact() {
    if (contactCount == 0) {
        printf("🧐 Your phone book is empty, no contacts to search!\n");
        return;
    }

    char searchName[NAME_LENGTH];
    printf("🔍 Enter the name of the contact to search: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline

    printf("Searching for '%s'...\n", searchName);
    for (int i = 0; i < contactCount; i++) {
        if (strcasecmp(searchName, phoneBook[i].name) == 0) {
            printf("🎉 Found: %s - %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }

    printf("😕 No contact found with the name '%s'!\n", searchName);
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}