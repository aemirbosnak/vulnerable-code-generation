//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: Sherlock Holmes
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
    if (contactCount < MAX_CONTACTS) {
        printf("Enter the name of your contact: ");
        scanf(" %[^\n]", phoneBook[contactCount].name);
        printf("Enter the phone number of your contact: ");
        scanf(" %[^\n]", phoneBook[contactCount].phone);
        contactCount++;
        printf("Contact added successfully, dear Watson!\n");
    } else {
        printf("The phone book is full, Watson! Cannot add more contacts.\n");
    }
}

void searchContact() {
    char searchName[NAME_LENGTH];
    printf("Enter the name you wish to search for: ");
    scanf(" %[^\n]", searchName);
    
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, searchName) == 0) {
            printf("Contact found! Name: %s, Phone: %s\n", 
                   phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("Alas, I have not encountered this individual before.\n");
}

void displayContacts() {
    if (contactCount == 0) {
        printf("The phone book is empty, like the mind of a criminal!\n");
    } else {
        printf("Here are the contacts collected in our esteemed book of numbers:\n");
        for (int i = 0; i < contactCount; i++) {
            printf("Contact %d: Name: %s, Phone: %s\n", 
                   i + 1, phoneBook[i].name, phoneBook[i].phone);
        }
    }
}

void menu() {
    printf("\n===========================\n");
    printf("Welcome to the Sherlock Holmes Phone Book\n");
    printf("===========================\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Display All Contacts\n");
    printf("4. Exit\n");
    printf("===========================\n");
}

int main() {
    int choice;
    do {
        menu();
        printf("Please choose an option (1-4): ");
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
                printf("Farewell, dear Watson. Until next time!\n");
                break;
            default:
                printf("That is not a valid option, my friend!\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}