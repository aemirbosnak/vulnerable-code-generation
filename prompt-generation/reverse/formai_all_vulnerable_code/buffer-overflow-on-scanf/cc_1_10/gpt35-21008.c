//FormAI DATASET v1.0 Category: Phone Book ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//defining the structure that will be used to hold contact information
typedef struct Contact {
    char name[20];
    char mobileNum[15];
    char email[30];
} Contact;

//function to display menu options
void displayMenu() {
    printf("\n------Phone Book Options------\n");
    printf("1. Add Contact\n");
    printf("2. Search for Contact by Name\n");
    printf("3. Search for Contact by Mobile Number\n");
    printf("4. Display All Contacts\n");
    printf("5. Exit\n");
}

//function to add a new contact
void addContact(Contact book[], int *numContacts) {
    printf("\n------Add Contact------\n");
    printf("Name: ");
    scanf("%s", book[*numContacts].name);
    printf("Mobile Number: ");
    scanf("%s", book[*numContacts].mobileNum);
    printf("Email: ");
    scanf("%s", book[*numContacts].email);
    *numContacts += 1;
    printf("\nContact added successfully!\n");
}

//function to search for a contact by name
void searchByName(Contact book[], int numContacts) {
    char name[20];
    int found = 0;
    printf("\n------Search by Name------\n");
    printf("Enter the name of the contact: ");
    scanf("%s", name);
    for(int i=0; i<numContacts; i++) {
        if(strcmp(name, book[i].name) == 0) {
            printf("\nName: %s\nMobile Number: %s\nEmail: %s\n", book[i].name, book[i].mobileNum, book[i].email);
            found = 1;
        }
    }
    if(!found) {
        printf("\nNo contact found with that name.\n");
    }
}

//function to search for a contact by mobile number
void searchByNum(Contact book[], int numContacts) {
    char mobileNum[15];
    int found = 0;
    printf("\n------Search by Mobile Number------\n");
    printf("Enter the mobile number of the contact: ");
    scanf("%s", mobileNum);
    for(int i=0; i<numContacts; i++) {
        if(strcmp(mobileNum, book[i].mobileNum) == 0) {
            printf("\nName: %s\nMobile Number: %s\nEmail: %s\n", book[i].name, book[i].mobileNum, book[i].email);
            found = 1;
        }
    }
    if(!found) {
        printf("\nNo contact found with that mobile number.\n");
    }
}

//function to display all contacts
void displayAll(Contact book[], int numContacts) {
    printf("\n------All Contacts------\n");
    if(numContacts == 0) {
        printf("No contacts found.\n");
    } else {
        for(int i=0; i<numContacts; i++) {
            printf("\nName: %s\nMobile Number: %s\nEmail: %s\n", book[i].name, book[i].mobileNum, book[i].email);
        }
    }
}

int main() {
    Contact phoneBook[100]; //maximum of 100 contacts allowed
    int numContacts = 0;
    int choice;

    do {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addContact(phoneBook, &numContacts);
                break;
            case 2:
                searchByName(phoneBook, numContacts);
                break;
            case 3:
                searchByNum(phoneBook, numContacts);
                break;
            case 4:
                displayAll(phoneBook, numContacts);
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}