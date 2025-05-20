//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 30
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

void displayContacts(Contact contacts[], int count);
void addContact(Contact contacts[], int *count);
void searchContact(Contact contacts[], int count);
void clearBuffer();

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    do {
        printf("\n----- Phone Book Menu -----\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        clearBuffer();  // Clear newline character from buffer

        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                displayContacts(contacts, count);
                break;
            case 3:
                searchContact(contacts, count);
                break;
            case 4:
                printf("Exiting Phone Book... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}

void addContact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Phone book is full! Cannot add more contacts.\n");
        return;
    }
    
    printf("Enter name: ");
    fgets(contacts[*count].name, NAME_LENGTH, stdin);
    contacts[*count].name[strcspn(contacts[*count].name, "\n")] = '\0'; // Remove newline
    
    printf("Enter phone number: ");
    fgets(contacts[*count].phone, PHONE_LENGTH, stdin);
    contacts[*count].phone[strcspn(contacts[*count].phone, "\n")] = '\0'; // Remove newline
    
    (*count)++;
    printf("Contact added successfully!\n");
}

void displayContacts(Contact contacts[], int count) {
    if (count == 0) {
        printf("Phone book is empty! No contacts to display.\n");
        return;
    }
    
    printf("\n----- Contacts List -----\n");
    for (int i = 0; i < count; i++) {
        printf("Contact %d: %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void searchContact(Contact contacts[], int count) {
    if (count == 0) {
        printf("Phone book is empty! No contacts to search.\n");
        return;
    }
    
    char name[NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(contacts[i].name, name) == 0) {
            printf("Found contact: %s - %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Contact '%s' not found.\n", name);
    }
}

void clearBuffer() {
    while(getchar() != '\n'); // Clear the input buffer
}