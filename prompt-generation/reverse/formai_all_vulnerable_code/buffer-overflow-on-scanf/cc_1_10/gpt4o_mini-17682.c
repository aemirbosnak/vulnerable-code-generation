//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: grateful
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
int currentContactCount = 0;

void addContact() {
    if (currentContactCount >= MAX_CONTACTS) {
        printf("The phone book is full!\n");
        return;
    }
    
    printf("Please enter the name of the contact: ");
    fgets(phoneBook[currentContactCount].name, NAME_LENGTH, stdin);
    phoneBook[currentContactCount].name[strcspn(phoneBook[currentContactCount].name, "\n")] = 0; // Remove newline

    printf("Please enter the phone number: ");
    fgets(phoneBook[currentContactCount].phone, PHONE_LENGTH, stdin);
    phoneBook[currentContactCount].phone[strcspn(phoneBook[currentContactCount].phone, "\n")] = 0; // Remove newline
    
    printf("Thank you! Contact '%s' added successfully!\n", phoneBook[currentContactCount].name);
    currentContactCount++;
}

void displayContacts() {
    if (currentContactCount == 0) {
        printf("No contacts found in the phone book.\n");
        return;
    }

    printf("\nYour phone book contacts:\n");
    for (int i = 0; i < currentContactCount; i++) {
        printf("%d: %s - %s\n", i+1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void searchContact() {
    char searchName[NAME_LENGTH];
    printf("Please enter the name to search for: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline

    for (int i = 0; i < currentContactCount; i++) {
        if (strcasecmp(searchName, phoneBook[i].name) == 0) {
            printf("Contact found: %s - %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("Sorry, contact '%s' not found in the phone book.\n", searchName);
}

void deleteContact() {
    char deleteName[NAME_LENGTH];
    printf("Please enter the name of the contact to delete: ");
    fgets(deleteName, NAME_LENGTH, stdin);
    deleteName[strcspn(deleteName, "\n")] = 0; // Remove newline

    for (int i = 0; i < currentContactCount; i++) {
        if (strcasecmp(deleteName, phoneBook[i].name) == 0) {
            for (int j = i; j < currentContactCount - 1; j++) {
                phoneBook[j] = phoneBook[j + 1]; // Shift contacts left
            }
            currentContactCount--;
            printf("Contact '%s' deleted successfully!\n", deleteName);
            return;
        }
    }
    printf("Sorry, contact '%s' not found in the phone book.\n", deleteName);
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Welcome to the Phone Book ---\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Please enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please try again.\n");
            while(getchar() != '\n');  // Clear the buffer
            continue;
        }
        while (getchar() != '\n');  // Clear the buffer
        
        switch (choice) {
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
                deleteContact();
                break;
            case 5:
                printf("Thank you for using the Phone Book! Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}