//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: funny
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
int totalContacts = 0;

// Function declarations
void addContact();
void displayContacts();
void searchContact();
void deleteContact();
void menu();

// Insert a new contact into the phone book
void addContact() {
    if (totalContacts >= MAX_CONTACTS) {
        printf("Oh no! The phone book is full! Even my jokes couldn't fit in here!\n");
        return;
    }
    
    printf("Enter the name of the brilliant new contact: ");
    scanf("%s", phoneBook[totalContacts].name);
    
    printf("Enter the phone number of this awe-inspiring individual: ");
    scanf("%s", phoneBook[totalContacts].phone);
    
    totalContacts++;
    printf("Contact '%s' has been added! Yeah, let's celebrate with some virtual confetti!\n\n", phoneBook[totalContacts - 1].name);
}

// Display all contacts
void displayContacts() {
    if (totalContacts == 0) {
        printf("Your phone book is as empty as a comedian's wallet on Monday!\n\n");
        return;
    }
    
    printf("Here's the legendary list of your contacts:\n");
    for (int i = 0; i < totalContacts; i++) {
        printf("%d. %s - %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
    printf("\n");
}

// Search for a contact
void searchContact() {
    char name[NAME_LENGTH];
    printf("Enter the name of the genius you wish to seek: ");
    scanf("%s", name);
    
    for (int i = 0; i < totalContacts; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Found! %s - %s\n\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("Alas! We couldn't find anyone named '%s'. They might be hiding from your phone book!\n\n", name);
}

// Delete a contact
void deleteContact() {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact you wish to erase from history (hopefully they won't haunt you!): ");
    scanf("%s", name);

    for (int i = 0; i < totalContacts; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            // Shifting the contacts to fill the gap
            for (int j = i; j < totalContacts - 1; j++) {
                phoneBook[j] = phoneBook[j + 1];
            }
            totalContacts--;
            printf("Contact '%s' has been dropped faster than a hot potato!\n\n", name);
            return;
        }
    }
    printf("No contact named '%s' found! Maybe they're just not ready to be deleted yet!\n\n", name);
}

// Display a simple menu for user choice
void menu() {
    int choice;
    while (1) {
        printf("=== Welcome to the Super Cool Phone Book ===\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit (But who wants to leave?)\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
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
                printf("Goodbye! May your phone book always be filled with great contacts and awkward moments!\n");
                return;
            default:
                printf("Oops! That option doesn’t exist. Just like my last date!\n\n");
                break;
        }
    }
}

int main() {
    menu();
    return 0;
}