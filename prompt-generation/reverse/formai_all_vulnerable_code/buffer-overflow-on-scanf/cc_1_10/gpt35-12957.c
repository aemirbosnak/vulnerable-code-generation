//FormAI DATASET v1.0 Category: Phone Book ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining Structure of the contact
struct Contact
{
    char name[50];
    long int phone_num;
};

// Function to add new contact to the phone book
void add_contact(struct Contact* pb, int* size)
{
    printf("Enter the name of the contact: ");
    scanf("%s", pb[*size].name); // taking name as string input
    printf("Enter the phone number of the contact: ");
    scanf("%ld", &pb[*size].phone_num); // taking number as integer input
    (*size)++; // adding to the size tracker
    printf("Contact added successfully!\n");
}

// Function to search contact by name
void search_contact(struct Contact* pb, int size)
{
    char name_search[50];
    int flag = 0;
    printf("Enter the name of the contact to search: ");
    scanf("%s", name_search); // taking name as string input
    for(int i=0; i<size; i++) // iterating over all contacts
        if(strcmp(name_search, pb[i].name) == 0) // comparing name with names in book
        {
            printf("Contact Found!\nName: %s\nPhone Number: %ld\n", pb[i].name, pb[i].phone_num);
            flag = 1; // setting flag if contact found
            break;
        }
    if(!flag) printf("Contact Not Found!\n"); // If contact not found, print message
}

// Function to display all the contacts in phone book
void display_all_contacts(struct Contact* pb, int size)
{
    if(size == 0) // If phone book is empty
        printf("No contacts in phone book!\n");
    else
    {
        printf("All contacts in the phone book: \n");
        for(int i=0; i<size; i++) // iterating over all contacts
            printf("%d. Name: %s\nPhone Number: %ld\n", i+1, pb[i].name, pb[i].phone_num); 
    }
}

int main()
{
    int choice, size = 0; // defining variables
    struct Contact phone_book[100]; // Phone book array with 100 contacts maximum
    
    while(1)
    {
        // Menu Options
        printf("\n1. Add New Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display All Contacts\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                add_contact(phone_book, &size); // call to add contact function
                break;
            case 2:
                search_contact(phone_book, size); // call to search contact function
                break;
            case 3:
                display_all_contacts(phone_book, size); // call to display all contacts function
                break;
            case 4:
                exit(0); // exiting program
            default:
                printf("\nInvalid Choice! Enter Again...\n");
        }
    }
    return 0;
}