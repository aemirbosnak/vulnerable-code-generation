//FormAI DATASET v1.0 Category: Phone Book ; Style: Claude Shannon
/* C Phone Book Program */
#include <stdio.h>
#include <string.h>
#define MAX_CONTACTS 1000

/* Contacts Structure */
struct Contact {
    char name[30];
    char phone[15];
};

/* Global Variables */
struct Contact contactList[MAX_CONTACTS];
int totalContacts = 0;

/* Function Declarations */
void addContact();
void removeContact();
void searchContact();
void displayAllContacts();

/* Main Function */
int main() {
    int choice;
    do {
        printf("\nC Phone Book Menu\n");
        printf("1. Add Contact\n");
        printf("2. Remove Contact\n");
        printf("3. Search Contact\n");
        printf("4. Display All Contacts\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addContact();
                break;
            case 2:
                removeContact();
                break;
            case 3:
                searchContact();
                break;
            case 4: 
                displayAllContacts();
                break;
            case 5:
                printf("Exiting Program!\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    } while(choice!=5); 
    return 0;
}

/* Function Definitions */

/* Function to add a new contact */
void addContact() {
    if(totalContacts==MAX_CONTACTS) {
        printf("Phone Book Full! Cannot add new contact!\n");
        return;
    }
    printf("\nEnter Contact Name: ");
    scanf("%s", &contactList[totalContacts].name);
    printf("Enter Contact Phone Number: ");
    scanf("%s", &contactList[totalContacts].phone);
    printf("Contact added successfully!\n");
    totalContacts++;
}

/* Function to remove an existing contact */
void removeContact() {
    if(totalContacts==0) {
        printf("Phone Book is empty! Cannot remove contact!\n");
        return;
    }
    char name[30];
    printf("\nEnter Contact Name you want to remove: ");
    scanf("%s", &name);
    int index=-1;
    for(int i=0;i<totalContacts;i++) {
        if(strcmp(name,contactList[i].name)==0) {
            index = i;
            break;
        }
    }
    if(index==-1) {
        printf("Contact not found!\n"); 
        return;
    }
    for(int i=index;i<totalContacts-1;i++) {
        contactList[i] = contactList[i+1];
    }
    totalContacts--;
    printf("Contact removed successfully!\n");
}

/* Function to search for a contact */
void searchContact() {
    if(totalContacts==0) {
        printf("Phone Book is empty! Cannot search contact!\n");
        return;
    }
    char name[30];
    printf("\nEnter Contact Name you want to search: ");
    scanf("%s", &name);
    int index=-1;
    for(int i=0;i<totalContacts;i++) {
        if(strcmp(name,contactList[i].name)==0) {
            index = i;
            break;
        }
    }
    if(index==-1) {
        printf("Contact not found!\n"); 
        return;
    }
    printf("\nContact Found!\nName: %s \nPhone: %s\n", contactList[index].name, contactList[index].phone);
}

/* Function to display all contacts */
void displayAllContacts() {
    if(totalContacts==0) {
        printf("Phone Book is empty! Please add some contacts!\n");
        return;
    }
    printf("\nAll Contacts\n");
    printf("------------------------------------\n");
    for(int i=0;i<totalContacts;i++) {
        printf("Name: %s \t Phone: %s\n", contactList[i].name, contactList[i].phone);
    }
    printf("------------------------------------\n");
}