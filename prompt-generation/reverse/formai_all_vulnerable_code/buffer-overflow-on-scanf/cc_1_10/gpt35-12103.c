//FormAI DATASET v1.0 Category: Phone Book ; Style: protected
#include <stdio.h>
#include <string.h>

//Structure to store contact details
struct contactDetails{
    char name[50];
    char phone[15];
    char email[50];
};

//Function to add a new contact
void addContact(struct contactDetails contacts[], int *numContacts){
    printf("Enter name: ");
    scanf("%s", contacts[*numContacts].name);
    printf("Enter phone number: ");
    scanf("%s", contacts[*numContacts].phone);
    printf("Enter email address: ");
    scanf("%s", contacts[*numContacts].email);

    *numContacts = *numContacts + 1; //Increment number of contacts
    printf("Contact added successfully!\n");
}

//Function to display all contacts in the phone book
void displayContacts(struct contactDetails contacts[], int numContacts){
    printf("Contacts:\n");
    for(int i=0; i<numContacts; i++){
        printf("\nName: %s\nPhone: %s\nEmail: %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

//Function to search for a contact by name
void searchContact(struct contactDetails contacts[], int numContacts){
    char searchName[50];
    printf("Enter name to search for: ");
    scanf("%s", searchName);

    int found = 0; //Flag to check if contact was found
    for(int i=0; i<numContacts; i++){
        if(strcmp(contacts[i].name, searchName) == 0){
            printf("\nName: %s\nPhone: %s\nEmail: %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
            found = 1;
            break;
        }
    }
    if(found == 0){
        printf("Contact not found.\n");
    }
}

int main(){
    struct contactDetails phoneBook[100]; //Array to store contacts
    int numContacts = 0; //Variable to keep track of number of contacts

    int choice;
    do{
        printf("\nPhone Book\n");
        printf("1. Add a new contact\n");
        printf("2. Display all contacts\n");
        printf("3. Search for a contact by name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addContact(phoneBook, &numContacts);
                break;
            case 2:
                displayContacts(phoneBook, numContacts);
                break;
            case 3:
                searchContact(phoneBook, numContacts);
                break;
            case 4:
                printf("Exiting the phone book.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(choice != 4);

    return 0;
}