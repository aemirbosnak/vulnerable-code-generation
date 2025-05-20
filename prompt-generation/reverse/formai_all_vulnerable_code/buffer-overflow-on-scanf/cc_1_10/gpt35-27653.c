//FormAI DATASET v1.0 Category: Phone Book ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_CONTACTS 1000 // maximum number of contacts the phonebook can hold

struct Contact { // contact structure
    char name[50];
    char phone_no[15];
    char email[50];
};

int ContactCount = 0; // current number of contacts
struct Contact contacts[MAX_CONTACTS]; // array to store contacts

void add_contact() { // function to add contact to phonebook
    printf("\nPlease provide the following information:\n");
    printf("Name: ");
    scanf("%s", contacts[ContactCount].name);
    printf("Phone Number: ");
    scanf("%s", contacts[ContactCount].phone_no);
    printf("Email: ");
    scanf("%s", contacts[ContactCount].email);
    
    ContactCount++;
    printf("Contact added successfully!\n");
}

void search_contact() { // function to search for contact in phonebook
    char name[50];
    printf("\nEnter the name of the contact you are searching for: ");
    scanf("%s", name);
    
    int i, found=0;
    for(i=0; i<ContactCount; i++) {
        if(strcmp(contacts[i].name, name)==0) {
            found=1;
            printf("\nContact Information:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone Number: %s\n", contacts[i].phone_no);
            printf("Email: %s\n", contacts[i].email);
            break;
        }
    }
    
    if(!found) {
        printf("\nNo contact found with the given name!\n");
    }
}

void list_contacts() { // function to list all contacts in phonebook
    int i;
    printf("\nNumber of contacts: %d\n", ContactCount);
    printf("\nContact List:\n");
    printf("========================\n");
    for(i=0; i<ContactCount; i++) {
        printf("%d. %s (%s) (%s)\n", i+1, contacts[i].name, contacts[i].phone_no, contacts[i].email);
    }
}

int main() {
    int choice;
    do {
        printf("\nPhone Book\n");
        printf("==========\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. List All Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: add_contact(); break;
            case 2: search_contact(); break;
            case 3: list_contacts(); break;
            case 4: printf("\nThank you for using the futuristic Phone Book!\n"); break;
            default: printf("\nInvalid Choice! Please choose again.\n");
        }
    } while(choice!=4);
    
    return 0;
}