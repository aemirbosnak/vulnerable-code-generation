//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: energetic
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
        printf("Oops! Phone book is full! Can't add more contacts.\n");
        return;
    }
    printf("\nAdding a new contact...\n");
    printf("Enter Name: ");
    getchar(); // Consume newline from previous input
    fgets(phoneBook[contactCount].name, NAME_LENGTH, stdin);
    strtok(phoneBook[contactCount].name, "\n"); // Remove newline character

    printf("Enter Phone: ");
    fgets(phoneBook[contactCount].phone, PHONE_LENGTH, stdin);
    strtok(phoneBook[contactCount].phone, "\n"); // Remove newline character

    contactCount++;
    printf("Contact added successfully! 🎉\n");
}

void searchContact() {
    char name[NAME_LENGTH];
    printf("\nEnter the name of the contact to search: ");
    getchar(); // Consume newline from previous input
    fgets(name, NAME_LENGTH, stdin);
    strtok(name, "\n"); // Remove newline character

    printf("\nSearching for %s...\n", name);
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Contact Found! 📞\n");
            printf("Name: %s, Phone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("No contact found with the name %s! 🤷‍♂️\n", name);
}

void displayContacts() {
    if (contactCount == 0) {
        printf("\nPhone book is empty! 📖\n");
        return;
    }
    printf("\nDisplaying Contacts:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("Contact #%d: %s - %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void showMenu() {
    printf("\nWelcome to the Energetic Phone Book! 🎊\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Display All Contacts\n");
    printf("4. Exit\n");
    printf("Choose an option (1-4): ");
}

int main() {
    int choice;

    while (1) {
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
                printf("Exiting the Phone Book. Goodbye! ✌️\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again. 🚫\n");
        }
    }

    return 0;
}