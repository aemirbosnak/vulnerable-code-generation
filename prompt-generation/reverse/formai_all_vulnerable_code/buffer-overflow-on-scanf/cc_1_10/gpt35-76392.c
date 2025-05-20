//FormAI DATASET v1.0 Category: Phone Book ; Style: unmistakable
#include<stdio.h>
#include<string.h>

struct PhoneBook {         //Structure to hold phonebook entries
    char name[20];
    char phoneNumber[15];
};

int main() {
    struct PhoneBook contacts[100];   //Array of phonebook entries
    int numContacts = 0;              //Number of contacts currently in the phonebook
    int i, j;                         //Loop indices
    char choice;                      //Choice for adding or searching contacts
    
    do {
        printf("\nWelcome to My Phone Book! Choose an option:\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Exit\n");
        scanf(" %c", &choice);
        
        switch(choice) {   //Switch statement for menu options
            case '1':
                printf("\nEnter the name: ");
                scanf("%s", contacts[numContacts].name);
                printf("Enter the phone number: ");
                scanf("%s", contacts[numContacts].phoneNumber);
                numContacts++;
                printf("\nContact added successfully!");
                break;
            case '2':
                if(numContacts == 0) {
                    printf("\nThere are no contacts in the phonebook.\n");
                    break;
                }
                printf("\nEnter the name to search for: ");
                char searchName[20];
                scanf("%s", searchName);
                for(i=0; i<numContacts; i++) {
                    if(strcmp(searchName, contacts[i].name) == 0) {  //If the name is found, print the details
                        printf("\nName: %s\nPhone Number: %s\n", contacts[i].name, contacts[i].phoneNumber);
                        break;
                    }
                }
                if(i == numContacts) {  //If name is not found, print message
                    printf("\nContact not found.\n");
                }
                break;
            case '3':
                printf("\nThank you for using My Phone Book.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while(choice != '3'); //Loop until user chooses to exit
    
    return 0;
}