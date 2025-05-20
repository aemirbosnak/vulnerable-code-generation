//FormAI DATASET v1.0 Category: Phone Book ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

//Structure containing information about a contact
struct Contact {
    char name[30];
    char number[15];
};

//Function to add a new contact to the phone book
int addContact(struct Contact *contacts, int *numContacts) {
    //Check if phone book has reached maximum capacity
    if (*numContacts == MAX_SIZE) {
        printf("Phone book is already full.\n");
        return -1;
    }
    //Get user input for new contact details
    printf("Enter name: ");
    scanf("%s", contacts[*numContacts].name);
    printf("Enter number: ");
    scanf("%s", contacts[*numContacts].number);
    //Increment number of contacts in the phone book
    (*numContacts)++;
    return 0;
}

//Function to search for a contact in the phone book and return their phone number
char* searchContact(struct Contact *contacts, int numContacts, char *name) {
    //Iterate through list of contacts and search for a contact with the given name
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            return contacts[i].number;
        }
    }
    //If contact was not found
    return "Contact not found.";
}

int main() {
    struct Contact phoneBook[MAX_SIZE];
    int numContacts = 0;
    int choice;
    char name[30];
    char *number;
    //Display menu and get user choice
    do {
        printf("Phone Book\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        //Perform action based on user choice
        switch(choice) {
            case 1:
                addContact(phoneBook, &numContacts);
                break;
            case 2:
                printf("Enter name to search: ");
                scanf("%s", name);
                number = searchContact(phoneBook, numContacts, name);
                printf("Phone number: %s\n", number);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);
    return 0;
}