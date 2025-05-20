//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

Contact phoneBook[MAX_ENTRIES];
int entryCount = 0;

void addContact();
void listContacts();
void searchContact();
void deleteContact();
void paranoidExit();

int main() {
    int choice;
    
    while (1) {
        printf("\n*** Paranoid Phone Book ***\n");
        printf("1. Add Contact\n");
        printf("2. List Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        while (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number: ");
            while (getchar() != '\n'); // Clear buffer
        }

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                listContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                paranoidExit();
                break;
            default:
                printf("This is NOT a valid choice! Try again wisely...\n");
                break;
        }
    }
    
    return 0;
}

void addContact() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Phone book is full! You will never find a contact again...\n");
        return;
    }
    
    printf("Enter name: ");
    scanf("%s", phoneBook[entryCount].name);
    
    printf("Enter phone: ");
    scanf("%s", phoneBook[entryCount].phone);
    
    entryCount++;
    printf("Contact added successfully. You did the right thing!\n");
}

void listContacts() {
    if (entryCount == 0) {
        printf("No contacts to list. Do they really exist?\n");
        return;
    }

    printf("\nListing Contacts:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

void searchContact() {
    char name[NAME_LENGTH];
    printf("Enter the name you wish to search for: ");
    scanf("%s", name);

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Found! Name: %s, Phone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }

    printf("No contact found with the name %s. They must be hiding...\n", name);
}

void deleteContact() {
    char name[NAME_LENGTH];
    printf("Enter the name of the contact you want to delete: ");
    scanf("%s", name);

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            for (int j = i; j < entryCount - 1; j++) {
                phoneBook[j] = phoneBook[j + 1]; // Shift left
            }
            entryCount--;
            printf("Contact deleted! They won't bother you anymore...\n");
            return;
        }
    }

    printf("No contact found with the name %s. It seems they're still lurking...\n", name);
}

void paranoidExit() {
    printf("You chose to exit! Are you sure? What if someone finds this data?\n");
    printf("Please type 'yes' to confirm: ");
    char confirmation[4];
    scanf("%s", confirmation);
    
    if (strcmp(confirmation, "yes") == 0) {
        printf("Exiting... Keep your secrets safe!\n");
        exit(0);
    } else {
        printf("You hesitated! We will remain vigilant...\n");
    }
}