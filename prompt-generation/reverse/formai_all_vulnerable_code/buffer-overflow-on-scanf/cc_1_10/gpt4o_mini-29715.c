//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: cheerful
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

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Oh no! The phone book is full! Can't add more contacts!\n");
        return;
    }
    printf("🎉 Let's add a new contact! 🎉\n");
    printf("Enter name: ");
    scanf("%s", phoneBook[contactCount].name);
    printf("Enter phone number: ");
    scanf("%s", phoneBook[contactCount].phone);
    contactCount++;
    printf("⭐ Contact added successfully! ⭐\n");
}

void searchContact() {
    char name[NAME_LENGTH];
    printf("🔍 Enter the name to search: ");
    scanf("%s", name);
    
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("📞 Found contact: %s - %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("😢 Sorry, I couldn't find any contact with that name!\n");
}

void displayContacts() {
    printf("📖 Here are all your contacts:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. %s - %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
    if (contactCount == 0) {
        printf("😅 The phone book is empty! Add some contacts!\n");
    }
}

void clearScreen() {
    printf("\033[H\033[J");
}

void showMenu() {
    printf("🌟 Welcome to the Cheerful Phone Book! 🌟\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Display All Contacts\n");
    printf("4. Exit\n");
    printf("Please choose an option: ");
}

int main() {
    int choice;
    
    while (1) {
        clearScreen();
        showMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                displayContacts();
                break;
            case 4:
                printf("Goodbye! Have a fantastic day! ☀️\n");
                exit(0);
            default:
                printf("😅 Oops! That's not a valid option. Please choose again.\n");
        }
        printf("Press Enter to continue...\n");
        while (getchar() != '\n'); // Clear input buffer
        getchar(); // Wait for a key press
    }
    
    return 0;
}