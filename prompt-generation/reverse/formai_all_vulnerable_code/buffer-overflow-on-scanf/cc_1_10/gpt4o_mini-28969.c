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

void displayMenu() {
    printf("\n");
    printf("🎉 Welcome to the Happy Phone Book! 🎉\n");
    printf("=======================================\n");
    printf("1. Add a contact\n");
    printf("2. View all contacts\n");
    printf("3. Delete a contact\n");
    printf("4. Exit\n");
    printf("=======================================\n");
    printf("Select an option (1-4): ");
}

void addContact() {
    if (contactCount < MAX_CONTACTS) {
        printf("📝 Enter the name: ");
        fgets(phoneBook[contactCount].name, NAME_LENGTH, stdin);
        phoneBook[contactCount].name[strcspn(phoneBook[contactCount].name, "\n")] = 0; // Remove newline

        printf("📞 Enter the phone number: ");
        fgets(phoneBook[contactCount].phone, PHONE_LENGTH, stdin);
        phoneBook[contactCount].phone[strcspn(phoneBook[contactCount].phone, "\n")] = 0; // Remove newline

        contactCount++;
        printf("🎊 Contact added successfully!\n");
    } else {
        printf("😢 Sorry, the phone book is full!\n");
    }
}

void viewContacts() {
    printf("\n✨ Your Contacts:\n");
    if (contactCount == 0) {
        printf("😔 No contacts available!\n");
    } else {
        for (int i = 0; i < contactCount; i++) {
            printf("%d. %s - %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
        }
    }
}

void deleteContact() {
    viewContacts();
    if (contactCount == 0) return;

    printf("🗑️ Enter the contact number to delete: ");
    int index;
    scanf("%d", &index);
    getchar(); // Consume leftover newline

    if (index > 0 && index <= contactCount) {
        for (int i = index - 1; i < contactCount - 1; i++) {
            phoneBook[i] = phoneBook[i + 1];
        }
        contactCount--;
        printf("🎉 Contact deleted successfully!\n");
    } else {
        printf("🚫 Invalid contact number!\n");
    }
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume leftover newline

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                deleteContact();
                break;
            case 4:
                printf("👋 Thank you for using the Happy Phone Book! Goodbye! 🎈\n");
                exit(0);
            default:
                printf("🚫 Invalid option, please try again!\n");
        }
    }

    return 0;
}