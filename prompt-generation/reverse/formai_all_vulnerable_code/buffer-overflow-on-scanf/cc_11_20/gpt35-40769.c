//FormAI DATASET v1.0 Category: Phone Book ; Style: futuristic
#include <stdio.h>
#include <string.h>

typedef struct Contact { // Define the structure for contact info
    char name[50];
    char phoneNum[20];
    char email[50];
} Contact;

int main() {
    Contact phone_book[100]; // Initialize the phone book as an array of contacts
    int num_contacts = 0; // Initialize the number of contacts in the phone book to 0
    
    printf("Welcome to your futuristic phone book!\n");
    
    while(1) { // Infinite loop for menu
        printf("\nWhat would you like to do?\n");
        printf("1. Add a contact\n");
        printf("2. Remove a contact\n");
        printf("3. Update a contact\n");
        printf("4. Search for a contact\n");
        printf("5. Display all contacts\n");
        printf("6. Exit\n");
        
        int choice;
        scanf("%d", &choice); // Read user's choice
        
        switch(choice) {
            case 1:
                printf("\nEnter the contact name: ");
                scanf("%s", phone_book[num_contacts].name);
                printf("Enter the contact phone number: ");
                scanf("%s", phone_book[num_contacts].phoneNum);
                printf("Enter the contact email: ");
                scanf("%s", phone_book[num_contacts].email);
                printf("Contact added!\n");
                num_contacts++;
                break;
                
            case 2:
                printf("\nEnter the name of the contact to remove: ");
                char nameToRemove[50];
                scanf("%s", nameToRemove);
                
                int contactToRemove = -1;
                for(int i = 0; i < num_contacts; i++) { // Loop through contacts to find the one to remove
                    if(strcmp(phone_book[i].name, nameToRemove) == 0) { // Check for name match
                        contactToRemove = i;
                        break;
                    }
                }
                
                if(contactToRemove == -1) { // If contact not found
                    printf("Contact not found!\n");
                } else { // Otherwise, shift array elements down to remove contact
                    for(int i = contactToRemove; i < num_contacts-1; i++) {
                        phone_book[i] = phone_book[i+1];
                    }
                    num_contacts--;
                    printf("Contact removed!\n");
                }
                break;
                
            case 3:
                printf("\nEnter the name of the contact to update: ");
                char nameToUpdate[50];
                scanf("%s", nameToUpdate);
                
                int contactToUpdate = -1;
                for(int i = 0; i < num_contacts; i++) { // Loop through contacts to find the one to update
                    if(strcmp(phone_book[i].name, nameToUpdate) == 0) { // Check for name match
                        contactToUpdate = i;
                        break;
                    }
                }
                
                if(contactToUpdate == -1) { // If contact not found
                    printf("Contact not found!\n");
                } else { // Otherwise, prompt user for new info and update contact
                    printf("Enter the new phone number for %s: ", phone_book[contactToUpdate].name);
                    scanf("%s", phone_book[contactToUpdate].phoneNum);
                    printf("Enter the new email for %s: ", phone_book[contactToUpdate].name);
                    scanf("%s", phone_book[contactToUpdate].email);
                    printf("Contact updated!\n");
                }
                break;
                
            case 4:
                printf("\nEnter the name of the contact to search for: ");
                char nameToSearch[50];
                scanf("%s", nameToSearch);
                
                int contactToSearch = -1;
                for(int i = 0; i < num_contacts; i++) { // Loop through contacts to find the one to search for
                    if(strcmp(phone_book[i].name, nameToSearch) == 0) { // Check for name match
                        contactToSearch = i;
                        break;
                    }
                }
                
                if(contactToSearch == -1) { // If contact not found
                    printf("Contact not found!\n");
                } else { // Otherwise, display contact info
                    printf("Contact info:\n");
                    printf("Name: %s\n", phone_book[contactToSearch].name);
                    printf("Phone number: %s\n", phone_book[contactToSearch].phoneNum);
                    printf("Email: %s\n", phone_book[contactToSearch].email);
                }
                break;
                
            case 5:
                printf("\nAll contacts:\n");
                for(int i = 0; i < num_contacts; i++) { // Loop through contacts to display all
                    printf("%d. %s - %s, %s\n", i+1, phone_book[i].name, phone_book[i].phoneNum, phone_book[i].email);
                }
                break;
                
            case 6:
                printf("\nGoodbye!\n");
                return 0;
                
            default:
                printf("\nInvalid choice. Please try again!\n");
                break;
        }
    }
    
    return 0;
}