//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: cheerful
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

Contact phoneBook[MAX_CONTACTS];
int contactCount = 0;

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Oh no! The phone book is full! Can't add more contacts! 😢\n");
        return;
    }
    
    printf("🎉 Let's add a new contact! 🎉\n");
    printf("Enter name: ");
    scanf(" %[^\n]s", phoneBook[contactCount].name); // Read string with spaces
    printf("Enter phone number: ");
    scanf(" %[^\n]s", phoneBook[contactCount].phone); // Read string with spaces
    
    contactCount++;
    printf("Yay! Contact added successfully! 🥳\n");
}

void viewContacts() {
    printf("\n📖 View Contacts 📖\n");
    if (contactCount == 0) {
        printf("Oops! No contacts to display! 👀\n");
        return;
    }
    
    for (int i = 0; i < contactCount; i++) {
        printf("Contact %d: %s - %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void searchContact() {
    char name[NAME_LEN];
    printf("🔍 Enter the name you want to search for: ");
    scanf(" %[^\n]s", name);
    
    for (int i = 0; i < contactCount; i++) {
        if (strcasecmp(phoneBook[i].name, name) == 0) {
            printf("🎉 Found! %s's phone number is %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    
    printf("Oh no! No contact found with the name %s! 😢\n", name);
}

void displayMenu() {
    printf("\n✨ Welcome to Your Cheerful Phone Book! ✨\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Search for a Contact\n");
    printf("4. Exit\n");
    printf("Please select an option (1-4): ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                printf("💖 Thank you for using the Cheerful Phone Book! Goodbye! 💖\n");
                exit(0);
            default:
                printf("Uh-oh! That's not a valid choice! Please try again! 😅\n");
                break;
        }
    }
    
    return 0;
}