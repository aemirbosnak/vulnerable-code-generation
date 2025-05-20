//FormAI DATASET v1.0 Category: Phone Book ; Style: accurate
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_CONTACTS 50

// Defining the structure to represent a contact in phone book
struct Contact {
    char name[50];
    char phone[20];
};

// Function to add a new contact to the phone book
int addContact(struct Contact pb[], char name[], char phone[]) {
    for(int i = 0; i < MAX_CONTACTS; i++) {
        if(strlen(pb[i].name) == 0) { // Check if the contact is empty
            strcpy(pb[i].name, name);
            strcpy(pb[i].phone, phone);
            return 1;
        }
    }
    return 0;
}

// Function to search for a contact in the phone book
int searchContact(struct Contact pb[], char name[]) {
    for(int i = 0; i < MAX_CONTACTS; i++) {
        if(strcmp(pb[i].name, name) == 0) { // Check if the names match
            printf("Phone number for %s is %s\n", name, pb[i].phone);
            return 1;
        }
    }
    printf("Contact not found\n"); 
    return 0;
}

// Function to display all contacts in the phone book
int displayContacts(struct Contact pb[]) {
    int count = 0;
    for(int i = 0; i < MAX_CONTACTS; i++) {
        if(strlen(pb[i].name) != 0) { // Check if the contact is not empty
            printf("%s - %s\n", pb[i].name, pb[i].phone);
            count++;
        }
    }
    return count;
}

int main() {
    struct Contact phoneBook[MAX_CONTACTS]; // Creating the phone book
    int choice;
    char name[50], phone[20];
    do {
        printf("1. Add contact\n2. Search contact\n3. Display all contacts\n4. Quit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clearing the buffer
        switch(choice) {
            case 1:
                printf("Enter the name: ");
                fgets(name, 50, stdin); // Allowing spaces in the name
                printf("Enter the phone number: ");
                fgets(phone, 20, stdin);
                if(addContact(phoneBook, name, phone)) {
                    printf("Contact added successfully\n");
                }
                else {
                    printf("Phone book is full\n");
                }
                break;
            case 2:
                printf("Enter the name to search: ");
                fgets(name, 50, stdin);
                searchContact(phoneBook, name);
                break;
            case 3:
                printf("Contacts in the phone book:\n");
                if(displayContacts(phoneBook) == 0) {
                    printf("Phone book is empty\n");
                }
                break;
            case 4:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 4);
    return 0;
}