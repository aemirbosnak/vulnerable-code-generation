//FormAI DATASET v1.0 Category: Phone Book ; Style: medieval
#include<stdio.h>
#include<string.h>

// Structures:

// Person structure
struct Person
{
    char name[50];
    char number[20];
    char email[50];
};

// Address structure
struct Address
{
    char street[50];
    char city[50];
    char state[50];
    char country[50];
    char zip[10];
};

// Phone book structure
struct PhoneBook
{
    struct Person person;
    struct Address address;
};

// Main function
int main()
{
    // Declare variables
    int option, i=0, j;
    struct PhoneBook phone_book[50];
    char search_name[50];
    
    // Print welcome message
    printf("Welcome to the Medieval Phone Book!\n");
    
    // Infinite loop for menu
    while(1)
    {
        // Print menu options
        printf("\nMenu Options:\n");
        printf("1. Add a new contact\n");
        printf("2. Search for a contact\n");
        printf("3. Display all contacts\n");
        printf("4. Exit\n");
        
        // Get user option
        printf("Enter your option: ");
        scanf("%d", &option);
        
        switch(option)
        {
            case 1: // Add a new contact
                printf("\nEnter contact details:\n");
                printf("Name: ");
                scanf("%s", phone_book[i].person.name);
                printf("Number: ");
                scanf("%s", phone_book[i].person.number);
                printf("Email: ");
                scanf("%s", phone_book[i].person.email);
                printf("Street: ");
                scanf("%s", phone_book[i].address.street);
                printf("City: ");
                scanf("%s", phone_book[i].address.city);
                printf("State: ");
                scanf("%s", phone_book[i].address.state);
                printf("Country: ");
                scanf("%s", phone_book[i].address.country);
                printf("Zip Code: ");
                scanf("%s", phone_book[i].address.zip);
                i++; // Increment index
                printf("Contact added successfully!\n");
                break;
                
            case 2: // Search for a contact
                printf("\nEnter name to search: ");
                scanf("%s", search_name);
                
                // Loop through contacts to search for name
                for(j=0; j<i; j++)
                {
                    if(strcmp(search_name, phone_book[j].person.name) == 0)
                    {
                        printf("Contact found!\n");
                        printf("Name: %s\n", phone_book[j].person.name);
                        printf("Number: %s\n", phone_book[j].person.number);
                        printf("Email: %s\n", phone_book[j].person.email);
                        printf("Address: %s, %s, %s, %s, %s\n", phone_book[j].address.street, phone_book[j].address.city, phone_book[j].address.state, phone_book[j].address.country, phone_book[j].address.zip);
                        break;
                    }
                }
                if(j == i)
                {
                    printf("Contact not found!\n");
                }
                break;
                
            case 3: // Display all contacts
                printf("\nAll Contacts:\n");
                for(j=0; j<i; j++)
                {
                    printf("Name: %s\n", phone_book[j].person.name);
                    printf("Number: %s\n", phone_book[j].person.number);
                    printf("Email: %s\n", phone_book[j].person.email);
                    printf("Address: %s, %s, %s, %s, %s\n", phone_book[j].address.street, phone_book[j].address.city, phone_book[j].address.state, phone_book[j].address.country, phone_book[j].address.zip);
                }
                break;
                
            case 4: // Exit program
                printf("\nThank you for using the Medieval Phone Book!\n");
                return 0;
                
            default: // Invalid option
                printf("\nInvalid option! Please try again.\n");
        }
    }
    return 0;
}