//FormAI DATASET v1.0 Category: Phone Book ; Style: Sherlock Holmes
//The Adventure of the Mysterious Phone Book

#include <stdio.h>
#include <string.h>

//Define the maximum number of contacts
#define MAX_CONTACTS 100

//Create a struct to hold contact information
typedef struct {
    char name[50];
    char phone_number[20];
} Contact;

//Function to add a contact to the phone book
void addContact(Contact phoneBook[MAX_CONTACTS], int* numContacts) {
    if (*numContacts == MAX_CONTACTS) {
        printf("The phone book is full!\n");
        return;
    }
    
    Contact newContact;
    printf("Enter the name of the contact: ");
    fgets(newContact.name, 50, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0; //remove newline character
    
    printf("Enter the phone number of the contact: ");
    fgets(newContact.phone_number, 20, stdin);
    newContact.phone_number[strcspn(newContact.phone_number, "\n")] = 0; //remove newline character
    
    phoneBook[*numContacts] = newContact;
    (*numContacts)++;
}

//Function to print all contacts in the phone book
void printContacts(Contact phoneBook[MAX_CONTACTS], int numContacts) {
    if (numContacts == 0) {
        printf("The phone book is empty!\n");
        return;
    }
    
    for (int i = 0; i < numContacts; i++) {
        printf("%s: %s\n", phoneBook[i].name, phoneBook[i].phone_number);
    }
}

//Function to search for a specific contact by name
void searchContact(Contact phoneBook[MAX_CONTACTS], int numContacts) {
    if (numContacts == 0) {
        printf("The phone book is empty!\n");
        return;
    }
    
    char searchName[50];
    printf("Enter the name of the contact: ");
    fgets(searchName, 50, stdin);
    searchName[strcspn(searchName, "\n")] = 0; //remove newline character
    
    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phoneBook[i].name, searchName) == 0) {
            printf("%s: %s\n", phoneBook[i].name, phoneBook[i].phone_number);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Contact not found!\n");
    }
}

int main() {
    Contact phoneBook[MAX_CONTACTS]; //create empty phone book
    int numContacts = 0; //initialize number of contacts to 0
    
    printf("Welcome to the Mysterious Phone Book...\n");
    printf("What would you like to do?\n");
    
    //Main menu loop
    while (1) {
        printf("\n1. Add a contact\n");
        printf("2. Print all contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Exit\n");
        
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); //eat newline character
        
        switch (choice) {
            case 1:
                printf("You have chosen to add a contact...\n");
                addContact(phoneBook, &numContacts);
                break;
            case 2:
                printf("You have chosen to print all contacts...\n");
                printContacts(phoneBook, numContacts);
                break;
            case 3:
                printf("You have chosen to search for a contact...\n");
                searchContact(phoneBook, numContacts);
                break;
            case 4:
                printf("Thank you for using the Mysterious Phone Book!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}