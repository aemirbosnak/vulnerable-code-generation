//FormAI DATASET v1.0 Category: Phone Book ; Style: systematic
#include<stdio.h> //header file for input/output functions
#include<stdlib.h> //header file for exit() function
#include<string.h> //header file for string functions

//structure for storing contact information
struct Contact{
    char name[50];
    char phone[20];
    char email[80];
};

//function to add new contact
void addContact(struct Contact *pContacts, int *pNumContacts){
    //check if there is space in contacts array
    if(*pNumContacts < 100){
        //prompt for contact information
        printf("Enter name: ");
        scanf("%s", pContacts[*pNumContacts].name);
        printf("Enter phone number: ");
        scanf("%s", pContacts[*pNumContacts].phone);
        printf("Enter email: ");
        scanf("%s", pContacts[*pNumContacts].email);
        //increment number of contacts
        (*pNumContacts)++;
        printf("Contact added successfully!\n");
    }
    else{
        printf("Contact book is full!\n");
    }
}

//function to display all contacts
void displayAll(struct Contact *pContacts, int numContacts){
    //check if there are any contacts
    if(numContacts == 0){
        printf("There are no contacts in the book!\n");
        return;
    }
    //iterate through all contacts
    for(int i=0; i<numContacts; i++){
        printf("Contact %d:\n", i+1);
        printf("Name: %s\n", pContacts[i].name);
        printf("Phone: %s\n", pContacts[i].phone);
        printf("Email: %s\n", pContacts[i].email);
    }
}

//function to search for a contact
void searchContact(struct Contact *pContacts, int numContacts){
    char searchTerm[50];
    printf("Enter name to search: ");
    scanf("%s", searchTerm);
    //iterate through all contacts
    for(int i=0; i<numContacts; i++){
        if(strcmp(pContacts[i].name, searchTerm) == 0){
            printf("Contact found:\n");
            printf("Name: %s\n", pContacts[i].name);
            printf("Phone: %s\n", pContacts[i].phone);
            printf("Email: %s\n", pContacts[i].email);
            return;
        }
    }
    printf("Contact not found!\n");
}

//function to delete a contact
void deleteContact(struct Contact *pContacts, int *pNumContacts){
    char searchTerm[50];
    printf("Enter name to delete: ");
    scanf("%s", searchTerm);
    //iterate through all contacts
    for(int i=0; i<*pNumContacts; i++){
        if(strcmp(pContacts[i].name, searchTerm) == 0){
            //copy last contact to this index
            *pContacts[i].name = *pContacts[*pNumContacts-1].name;
            *pContacts[i].phone = *pContacts[*pNumContacts-1].phone;
            *pContacts[i].email = *pContacts[*pNumContacts-1].email;
            //decrement number of contacts
            (*pNumContacts)--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

//function to display menu
void displayMenu(){
    printf("\n********** C PHONE BOOK **********\n");
    printf("1. Add new contact\n");
    printf("2. Display all contacts\n");
    printf("3. Search for a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

//main function
int main(){
    //array of contacts and number of contacts
    struct Contact contacts[100];
    int numContacts = 0;
    //loop for menu
    while(1){
        displayMenu();
        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 1: addContact(contacts, &numContacts); break;
            case 2: displayAll(contacts, numContacts); break;
            case 3: searchContact(contacts, numContacts); break;
            case 4: deleteContact(contacts, &numContacts); break;
            case 5: printf("Exiting phone book..."); exit(0); break;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}