//FormAI DATASET v1.0 Category: Phone Book ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100 //maximum number of contacts that can be stored in the phone book

typedef struct{
    char name[50];
    long int phoneNumber;
} phoneBook;

void addNewContact(phoneBook [], int *);
void searchContact(phoneBook [], int);
void displayPhoneBook(phoneBook [], int);

int main(){
    phoneBook contacts[MAX]; //array to store contacts
    int numOfContacts = 0; //initialize number of contacts to zero
    
    int choice;
    
    while(1){
        printf("\n\n---- Phone Book ----\n");
        printf("1. Add new Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display Phone Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                addNewContact(contacts, &numOfContacts);
                break;
            case 2:
                searchContact(contacts, numOfContacts);
                break;
            case 3:
                displayPhoneBook(contacts, numOfContacts);
                break;
            case 4:
                printf("\nThank you for using Phone Book!");
                exit(0);
            default:
                printf("\nInvalid Choice! Please try again.");
        }
    }
    
    return 0;
}

//function to add new contact to the phone book
void addNewContact(phoneBook contacts[], int *numOfContacts){
    phoneBook newContact;
    
    printf("\nEnter Name: ");
    scanf("%s", newContact.name);
    printf("Enter Phone Number: ");
    scanf("%ld", &newContact.phoneNumber);
    
    contacts[*numOfContacts] = newContact;
    *numOfContacts += 1;
    
    printf("\nContact added successfully!");
}

//function to search for a contact in the phone book
void searchContact(phoneBook contacts[], int numOfContacts){
    char searchName[50];
    int foundFlag = 0;
    
    printf("\nEnter Name to search: ");
    scanf("%s", searchName);
    
    for(int i=0; i<numOfContacts; i++){
        if(strcmp(contacts[i].name, searchName) == 0){
            printf("\nName: %s\nPhone Number: %ld", contacts[i].name, contacts[i].phoneNumber);
            foundFlag = 1;
            break;
        }
    }
    
    if(foundFlag == 0){
        printf("\nContact not found in the Phone Book!");
    }
}

//function to display all the contacts in the phone book
void displayPhoneBook(phoneBook contacts[], int numOfContacts){
    printf("\n---- Phone Book ----\n");
    for(int i=0; i<numOfContacts; i++){
        printf("\nName: %s\nPhone Number: %ld", contacts[i].name, contacts[i].phoneNumber);
    }
}