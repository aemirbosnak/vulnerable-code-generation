//FormAI DATASET v1.0 Category: Phone Book ; Style: inquisitive
#include <stdio.h>
#include <string.h>

struct contact {
    char name[30];
    char phone[15];
};

// Function prototypes
void addContact(struct contact myContacts[], int *numContacts);
void searchContact(struct contact myContacts[], int numContacts);
void displayContacts(struct contact myContacts[], int numContacts);

int main() {
    struct contact myContacts[100]; // Maximum of 100 contacts
    int numContacts = 0; // No contacts initially
    
    int choice;
    
    do {
        printf("\n\n1. Add Contact\n2. Search Contact\n3. Display Contacts\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addContact(myContacts, &numContacts);
                break;
            case 2:
                searchContact(myContacts, numContacts);
                break;
            case 3:
                displayContacts(myContacts, numContacts);
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
        
    } while(choice != 4);
    
    return 0;
}

// Function to add a new contact
void addContact(struct contact myContacts[], int *numContacts) {
    // Prompt user to enter name and phone number
    printf("\nEnter name and phone number separated by a space: ");
    scanf("%s %s", myContacts[*numContacts].name, myContacts[*numContacts].phone);
    
    // Increment number of contacts
    (*numContacts)++;
    
    printf("\nContact added successfully.\n");
}

// Function to search for a contact
void searchContact(struct contact myContacts[], int numContacts) {
    char name[30];
    int found = 0; // 0 = not found, 1 = found
    
    // Prompt user to enter name to search for
    printf("\nEnter name to search for: ");
    scanf("%s", name);
    
    // Loop through contacts to find matching name
    for(int i=0; i<numContacts; i++) {
        if(strcmp(name, myContacts[i].name) == 0) {
            printf("\n%s: %s\n", myContacts[i].name, myContacts[i].phone);
            found = 1;
            break;
        }
    }
    
    if(found == 0) {
        printf("\nContact not found.\n");
    }
}

// Function to display all contacts
void displayContacts(struct contact myContacts[], int numContacts) {
    printf("\nContacts:\n");
    for(int i=0; i<numContacts; i++) {
        printf("%s: %s\n", myContacts[i].name, myContacts[i].phone);
    }
}